const { query } = require('../database/connection');
const Logger = require('../utils/logger');

const AGGREGATION_INTERVAL_MS = Number(process.env.NETWORK_METRICS_INTERVAL_MS) || 60_000;
const LOOKBACK_WINDOW_MINUTES = Number(process.env.NETWORK_METRICS_LOOKBACK_MINUTES) || 1_440; // 24h

class NetworkMetricsService {
  constructor() {
    this.timer = null;
    this.isProcessing = false;
  }

  start() {
    if (this.timer) {
      return;
    }

    Logger.info('네트워크 지표 수집 서비스를 시작합니다.');
    // 즉시 한 번 실행
    this.aggregateMissingBuckets();

    this.timer = setInterval(() => {
      this.aggregateMissingBuckets();
    }, AGGREGATION_INTERVAL_MS);
  }

  stop() {
    if (this.timer) {
      clearInterval(this.timer);
      this.timer = null;
      Logger.info('네트워크 지표 수집 서비스를 중지했습니다.');
    }
  }

  async aggregateMissingBuckets() {
    if (this.isProcessing) {
      return;
    }

    this.isProcessing = true;

    try {
      const targetBuckets = await this.findMissingBuckets();
      for (const { bucket_start: bucketStart } of targetBuckets) {
        await this.aggregateBucket(bucketStart);
      }
    } catch (error) {
      Logger.error('네트워크 지표 집계 중 오류 발생', { error: error.message });
    } finally {
      this.isProcessing = false;
    }
  }

  async findMissingBuckets() {
    return query(
      `
        SELECT lb.bucket_start
        FROM (
          SELECT DISTINCT strftime('%Y-%m-%d %H:%M:00', datetime(created_at, 'localtime')) AS bucket_start
          FROM network_logs
          WHERE datetime(created_at, 'localtime') >= datetime('now', 'localtime', ?)
        ) AS lb
        LEFT JOIN network_metrics nm ON nm.bucket_start = lb.bucket_start
        WHERE nm.bucket_start IS NULL
        ORDER BY lb.bucket_start ASC
        LIMIT 240
      `,
      [`-${LOOKBACK_WINDOW_MINUTES} minutes`]
    );
  }

  async aggregateBucket(bucketStart) {
    const [stats = {}] = await query(
      `
        SELECT
          COUNT(*) AS total_requests,
          SUM(CASE WHEN status_code BETWEEN 200 AND 399 THEN 1 ELSE 0 END) AS success_requests,
          SUM(CASE WHEN status_code >= 400 OR status_code IS NULL THEN 1 ELSE 0 END) AS error_requests,
          AVG(response_time_ms) AS avg_response_time_ms,
          MAX(response_time_ms) AS max_response_time_ms,
          MIN(response_time_ms) AS min_response_time_ms,
          SUM(
            CASE
              WHEN method = 'GET'
                AND (
                  path = '/api/robots'
                  OR (
                    path LIKE '/api/robots/%'
                    AND path NOT LIKE '/api/robots/service%'
                    AND path NOT LIKE '/api/robots/collect%'
                    AND path NOT LIKE '/api/robots/move%'
                  )
                )
              THEN 1
              ELSE 0
            END
          ) AS robot_status_query_count
        FROM network_logs
        WHERE strftime('%Y-%m-%d %H:%M:00', datetime(created_at, 'localtime')) = ?
      `,
      [bucketStart]
    );

    if (!stats.total_requests) {
      return;
    }

    try {
      await query(
        `
          INSERT INTO network_metrics (
            bucket_start,
            total_requests,
            success_requests,
            error_requests,
            avg_response_time_ms,
            max_response_time_ms,
            min_response_time_ms,
            robot_status_query_count
          )
          VALUES (?, ?, ?, ?, ?, ?, ?, ?)
        `,
        [
          bucketStart,
          stats.total_requests || 0,
          stats.success_requests || 0,
          stats.error_requests || 0,
          stats.avg_response_time_ms || null,
          stats.max_response_time_ms || null,
          stats.min_response_time_ms || null,
          stats.robot_status_query_count || 0
        ]
      );
    } catch (error) {
      if (!error.message.includes('UNIQUE constraint failed')) {
        throw error;
      }
    }
  }
}

module.exports = new NetworkMetricsService();

