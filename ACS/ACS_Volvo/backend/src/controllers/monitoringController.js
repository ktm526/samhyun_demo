const { query } = require('../database/connection');
const Logger = require('../utils/logger');

const safeParseJSON = (value) => {
  if (!value) {
    return null;
  }

  try {
    return JSON.parse(value);
  } catch (error) {
    Logger.warn('네트워크 로그 메타데이터 파싱 실패', { error: error.message });
    return null;
  }
};

const toNumberOrNull = (value) => {
  if (value === null || value === undefined) {
    return null;
  }
  const num = Number(value);
  return Number.isFinite(num) ? num : null;
};

const buildDateFilter = (clientType) => {
  const params = [];
  let clause = `DATE(created_at, 'localtime') = DATE('now', 'localtime')`;

  if (clientType) {
    clause += ' AND client_type = ?';
    params.push(clientType);
  }

  return { clause, params };
};

const getTodayNetworkStats = async (req, res, next) => {
  try {
    const clientType = req.query.clientType ? req.query.clientType.toLowerCase() : undefined;
    const limit = Math.min(Math.max(parseInt(req.query.limit, 10) || 200, 1), 1000);
    const { clause, params } = buildDateFilter(clientType);

    const logs = await query(
      `
        SELECT
          id,
          client_type,
          source_ip,
          user_agent,
          method,
          path,
          status_code,
          response_time_ms,
          reported_delay_ms,
          packet_loss_rate,
          metadata,
          created_at
        FROM network_logs
        WHERE ${clause}
        ORDER BY datetime(created_at) DESC
        LIMIT ?
      `,
      [...params, limit]
    );

    const summaryRows = await query(
      `
        SELECT
          COUNT(*) AS request_count,
          AVG(response_time_ms) AS avg_response_time_ms,
          MAX(response_time_ms) AS max_response_time_ms,
          MIN(response_time_ms) AS min_response_time_ms,
          AVG(packet_loss_rate) AS avg_packet_loss_rate,
          AVG(reported_delay_ms) AS avg_reported_delay_ms
        FROM network_logs
        WHERE ${clause}
      `,
      params
    );

    const summary = summaryRows[0] || {};
    const normalizedLogs = logs.map((log) => ({
      ...log,
      response_time_ms: toNumberOrNull(log.response_time_ms),
      reported_delay_ms: toNumberOrNull(log.reported_delay_ms),
      packet_loss_rate: toNumberOrNull(log.packet_loss_rate),
      metadata: safeParseJSON(log.metadata)
    }));

    res.json({
      date: new Date().toISOString().split('T')[0],
      filters: {
        clientType: clientType || null,
        limit
      },
      summary: {
        totalRequests: summary.request_count || 0,
        avgResponseTimeMs: toNumberOrNull(summary.avg_response_time_ms),
        maxResponseTimeMs: toNumberOrNull(summary.max_response_time_ms),
        minResponseTimeMs: toNumberOrNull(summary.min_response_time_ms),
        avgPacketLossRate: toNumberOrNull(summary.avg_packet_loss_rate),
        avgReportedDelayMs: toNumberOrNull(summary.avg_reported_delay_ms)
      },
      logs: normalizedLogs
    });
  } catch (error) {
    next(error);
  }
};

const getNetworkMetricsHistory = async (req, res, next) => {
  try {
    const limit = Math.min(Math.max(parseInt(req.query.limit, 10) || 120, 1), 1440);

    const rows = await query(
      `
        SELECT
          bucket_start,
          total_requests,
          success_requests,
          error_requests,
          avg_response_time_ms,
          max_response_time_ms,
          min_response_time_ms,
          robot_status_query_count,
          created_at
        FROM network_metrics
        ORDER BY bucket_start DESC
        LIMIT ?
      `,
      [limit]
    );

    const buckets = rows
      .map((row) => ({
        bucketStart: row.bucket_start,
        totalRequests: row.total_requests || 0,
        successRequests: row.success_requests || 0,
        errorRequests: row.error_requests || 0,
        successRate:
          row.total_requests && row.success_requests !== null
            ? Number((row.success_requests / row.total_requests).toFixed(4))
            : null,
        avgResponseTimeMs: toNumberOrNull(row.avg_response_time_ms),
        maxResponseTimeMs: toNumberOrNull(row.max_response_time_ms),
        minResponseTimeMs: toNumberOrNull(row.min_response_time_ms),
        robotStatusQueriesPerMinute: row.robot_status_query_count || 0
      }))
      .reverse(); // 오래된 데이터부터 전달

    const totals = buckets.reduce(
      (acc, bucket) => {
        acc.totalRequests += bucket.totalRequests;
        acc.successRequests += bucket.successRequests;
        acc.errorRequests += bucket.errorRequests;
        if (
          bucket.avgResponseTimeMs !== null &&
          bucket.avgResponseTimeMs !== undefined
        ) {
          acc.weightedResponseTimeSum += bucket.avgResponseTimeMs * bucket.totalRequests;
        }
        if (
          bucket.maxResponseTimeMs !== null &&
          bucket.maxResponseTimeMs !== undefined
        ) {
          acc.maxResponseTimeMs = acc.maxResponseTimeMs === null
            ? bucket.maxResponseTimeMs
            : Math.max(acc.maxResponseTimeMs, bucket.maxResponseTimeMs);
        }
        if (
          bucket.minResponseTimeMs !== null &&
          bucket.minResponseTimeMs !== undefined
        ) {
          acc.minResponseTimeMs = acc.minResponseTimeMs === null
            ? bucket.minResponseTimeMs
            : Math.min(acc.minResponseTimeMs, bucket.minResponseTimeMs);
        }
        acc.totalRobotStatusQueries += bucket.robotStatusQueriesPerMinute;
        return acc;
      },
      {
        totalRequests: 0,
        successRequests: 0,
        errorRequests: 0,
        weightedResponseTimeSum: 0,
        maxResponseTimeMs: null,
        minResponseTimeMs: null,
        totalRobotStatusQueries: 0
      }
    );

    res.json({
      limit,
      bucketCount: buckets.length,
      summary: {
        totalRequests: totals.totalRequests,
        successRate:
          totals.totalRequests > 0
            ? Number((totals.successRequests / totals.totalRequests).toFixed(4))
            : null,
        avgResponseTimeMs:
          totals.totalRequests > 0
            ? Number((totals.weightedResponseTimeSum / totals.totalRequests).toFixed(2))
            : null,
        maxResponseTimeMs: totals.maxResponseTimeMs,
        minResponseTimeMs: totals.minResponseTimeMs,
        avgRobotStatusQueriesPerMinute:
          buckets.length > 0
            ? Number((totals.totalRobotStatusQueries / buckets.length).toFixed(2))
            : 0
      },
      buckets
    });
  } catch (error) {
    next(error);
  }
};

module.exports = {
  getTodayNetworkStats,
  getNetworkMetricsHistory
};

