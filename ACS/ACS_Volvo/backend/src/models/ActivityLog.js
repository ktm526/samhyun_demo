const { getDatabase } = require('../database/connection');

/**
 * 이벤트 타입 상수
 */
const EVENT_TYPES = {
  // 미션 관련
  MISSION_CREATED: 'mission_created',
  MISSION_STARTED: 'mission_started',
  MISSION_COMPLETED: 'mission_completed',
  MISSION_FAILED: 'mission_failed',
  MISSION_CANCELLED: 'mission_cancelled',
  MISSION_ASSIGNED: 'mission_assigned',
  
  // 웨이포인트 관련
  WAYPOINT_STARTED: 'waypoint_started',
  WAYPOINT_ARRIVED: 'waypoint_arrived',
  WAYPOINT_SKIPPED: 'waypoint_skipped',
  
  // 로봇 관련
  ROBOT_CREATED: 'robot_created',
  ROBOT_DELETED: 'robot_deleted',
  ROBOT_CONNECTED: 'robot_connected',
  ROBOT_DISCONNECTED: 'robot_disconnected',
  ROBOT_STATUS_CHANGED: 'robot_status_changed',
  ROBOT_ERROR: 'robot_error',
  ROBOT_ERROR_CLEARED: 'robot_error_cleared',
  
  // 배터리 관련
  BATTERY_LOW: 'battery_low',
  BATTERY_CRITICAL: 'battery_critical',
  CHARGING_STARTED: 'charging_started',
  CHARGING_COMPLETED: 'charging_completed',
  
  // 이동 명령 관련
  MOVE_REQUESTED: 'move_requested',
  MOVE_STARTED: 'move_started',
  MOVE_COMPLETED: 'move_completed',
  MOVE_FAILED: 'move_failed',
  MOVE_CANCELLED: 'move_cancelled',
  
  // 네비게이션 관련
  NAVIGATION_ERROR: 'navigation_error',
  PATH_BLOCKED: 'path_blocked',
  COLLISION_AVOIDED: 'collision_avoided',
  
  // 시스템 관련
  SYSTEM_STARTED: 'system_started',
  SYSTEM_STOPPED: 'system_stopped',
  SERVICE_STARTED: 'service_started',
  SERVICE_STOPPED: 'service_stopped',
  
  // 일반
  GENERAL: 'general',
  INFO: 'info',
  WARNING: 'warning',
  ERROR: 'error'
};

/**
 * 카테고리 상수
 */
const CATEGORIES = {
  MISSION: 'mission',
  ROBOT: 'robot',
  NAVIGATION: 'navigation',
  SYSTEM: 'system',
  COMMAND: 'command',
  BATTERY: 'battery'
};

/**
 * 로그 레벨 상수
 */
const LOG_LEVELS = {
  SUCCESS: 'success',
  INFO: 'info',
  WARNING: 'warning',
  ERROR: 'error'
};

class ActivityLog {
  constructor(data) {
    this.id = data.id;
    
    // 기본 분류
    this.level = data.level || 'info';
    this.category = data.category || 'system';
    this.event_type = data.event_type || 'general';
    
    // 로봇 정보
    this.robot_id = data.robot_id;
    this.robot_name = data.robot_name;
    this.robot_ip = data.robot_ip;
    this.robot_status = data.robot_status;
    
    // 미션 정보
    this.mission_id = data.mission_id;
    this.mission_name = data.mission_name;
    this.mission_type = data.mission_type;
    this.mission_priority = data.mission_priority;
    this.mission_status = data.mission_status;
    
    // 웨이포인트 정보
    this.waypoint_index = data.waypoint_index;
    this.waypoint_total = data.waypoint_total;
    this.waypoint_name = data.waypoint_name;
    
    // 이동 명령 정보
    this.target_node_id = data.target_node_id;
    this.target_node_name = data.target_node_name;
    this.source_x = data.source_x;
    this.source_y = data.source_y;
    this.target_x = data.target_x;
    this.target_y = data.target_y;
    
    // 시간 정보
    this.event_start_time = data.event_start_time;
    this.event_end_time = data.event_end_time;
    this.duration = data.duration;
    
    // 메시지 및 상세 정보
    this.message = data.message;
    this.details = data.details;
    this.error_code = data.error_code;
    this.error_message = data.error_message;
    
    // 메타데이터
    this.metadata = data.metadata ? 
      (typeof data.metadata === 'string' ? JSON.parse(data.metadata) : data.metadata) : null;
    
    // 트리거 소스
    this.trigger_source = data.trigger_source || 'system';
    
    // 생성 시각
    this.created_at = data.created_at;
  }

  // 모든 로그 조회 (필터링 포함)
  static findAll(options = {}) {
    const db = getDatabase();
    return new Promise((resolve, reject) => {
      let query = 'SELECT * FROM activity_logs WHERE 1=1';
      const params = [];

      // 레벨 필터
      if (options.level && options.level !== 'all') {
        query += ' AND level = ?';
        params.push(options.level);
      }

      // 카테고리 필터
      if (options.category && options.category !== 'all') {
        query += ' AND category = ?';
        params.push(options.category);
      }

      // 이벤트 타입 필터
      if (options.event_type && options.event_type !== 'all') {
        query += ' AND event_type = ?';
        params.push(options.event_type);
      }

      // 로봇 ID 필터
      if (options.robot_id && options.robot_id !== 'all') {
        query += ' AND robot_id = ?';
        params.push(options.robot_id);
      }

      // 로봇 이름 필터
      if (options.robot_name && options.robot_name !== 'all') {
        query += ' AND robot_name = ?';
        params.push(options.robot_name);
      }

      // 미션 ID 필터
      if (options.mission_id) {
        query += ' AND mission_id = ?';
        params.push(options.mission_id);
      }

      // 날짜 범위 필터
      if (options.dateFrom) {
        query += ' AND DATE(created_at) >= DATE(?)';
        params.push(options.dateFrom);
      }

      if (options.dateTo) {
        query += ' AND DATE(created_at) <= DATE(?)';
        params.push(options.dateTo);
      }

      // 정렬
      query += ' ORDER BY created_at DESC';

      // 제한
      if (options.limit) {
        query += ' LIMIT ?';
        params.push(options.limit);
      }

      if (options.offset) {
        query += ' OFFSET ?';
        params.push(options.offset);
      }

      db.all(query, params, (err, rows) => {
        if (err) {
          reject(err);
        } else {
          resolve(rows.map(row => new ActivityLog(row)));
        }
      });
    });
  }

  // ID로 조회
  static findById(id) {
    const db = getDatabase();
    return new Promise((resolve, reject) => {
      db.get('SELECT * FROM activity_logs WHERE id = ?', [id], (err, row) => {
        if (err) {
          reject(err);
        } else {
          resolve(row ? new ActivityLog(row) : null);
        }
      });
    });
  }

  // 로봇 ID로 조회
  static findByRobotId(robotId, limit = 100) {
    const db = getDatabase();
    return new Promise((resolve, reject) => {
      db.all(
        'SELECT * FROM activity_logs WHERE robot_id = ? ORDER BY created_at DESC LIMIT ?',
        [robotId, limit],
        (err, rows) => {
          if (err) {
            reject(err);
          } else {
            resolve(rows.map(row => new ActivityLog(row)));
          }
        }
      );
    });
  }

  // 미션 ID로 조회
  static findByMissionId(missionId) {
    const db = getDatabase();
    return new Promise((resolve, reject) => {
      db.all(
        'SELECT * FROM activity_logs WHERE mission_id = ? ORDER BY created_at ASC',
        [missionId],
        (err, rows) => {
          if (err) {
            reject(err);
          } else {
            resolve(rows.map(row => new ActivityLog(row)));
          }
        }
      );
    });
  }

  // 로그 생성
  static create(data) {
    const db = getDatabase();
    return new Promise((resolve, reject) => {
      const {
        level = 'info',
        category = 'system',
        event_type = 'general',
        robot_id,
        robot_name,
        robot_ip,
        robot_status,
        mission_id,
        mission_name,
        mission_type,
        mission_priority,
        mission_status,
        waypoint_index,
        waypoint_total,
        waypoint_name,
        target_node_id,
        target_node_name,
        source_x,
        source_y,
        target_x,
        target_y,
        event_start_time,
        event_end_time,
        duration,
        message,
        details,
        error_code,
        error_message,
        metadata,
        trigger_source = 'system'
      } = data;

      const metadataJson = metadata ? JSON.stringify(metadata) : null;

      db.run(
        `INSERT INTO activity_logs (
          level, category, event_type,
          robot_id, robot_name, robot_ip, robot_status,
          mission_id, mission_name, mission_type, mission_priority, mission_status,
          waypoint_index, waypoint_total, waypoint_name,
          target_node_id, target_node_name, source_x, source_y, target_x, target_y,
          event_start_time, event_end_time, duration,
          message, details, error_code, error_message,
          metadata, trigger_source,
          created_at
        ) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, datetime('now', 'localtime'))`,
        [
          level, category, event_type,
          robot_id, robot_name, robot_ip, robot_status,
          mission_id, mission_name, mission_type, mission_priority, mission_status,
          waypoint_index, waypoint_total, waypoint_name,
          target_node_id, target_node_name, source_x, source_y, target_x, target_y,
          event_start_time, event_end_time, duration,
          message, details, error_code, error_message,
          metadataJson, trigger_source
        ],
        function(err) {
          if (err) {
            reject(err);
          } else {
            ActivityLog.findById(this.lastID)
              .then(resolve)
              .catch(reject);
          }
        }
      );
    });
  }

  // 통계 조회
  static getStats(options = {}) {
    const db = getDatabase();
    return new Promise((resolve, reject) => {
      let whereClause = '1=1';
      const params = [];

      if (options.dateFrom) {
        whereClause += ' AND DATE(created_at) >= DATE(?)';
        params.push(options.dateFrom);
      }

      if (options.dateTo) {
        whereClause += ' AND DATE(created_at) <= DATE(?)';
        params.push(options.dateTo);
      }

      if (options.robot_name && options.robot_name !== 'all') {
        whereClause += ' AND robot_name = ?';
        params.push(options.robot_name);
      }

      const query = `
        SELECT 
          COUNT(*) as total_logs,
          SUM(CASE WHEN level = 'success' THEN 1 ELSE 0 END) as success_count,
          SUM(CASE WHEN level = 'error' THEN 1 ELSE 0 END) as error_count,
          SUM(CASE WHEN level = 'warning' THEN 1 ELSE 0 END) as warning_count,
          SUM(CASE WHEN level = 'info' THEN 1 ELSE 0 END) as info_count,
          SUM(COALESCE(duration, 0)) as total_work_time,
          COUNT(DISTINCT mission_id) as total_missions,
          SUM(CASE WHEN event_type = 'mission_completed' THEN 1 ELSE 0 END) as completed_missions,
          SUM(CASE WHEN event_type = 'mission_failed' THEN 1 ELSE 0 END) as failed_missions,
          SUM(CASE WHEN event_type = 'move_requested' THEN 1 ELSE 0 END) as move_commands,
          SUM(CASE WHEN event_type = 'robot_disconnected' THEN 1 ELSE 0 END) as disconnection_count
        FROM activity_logs
        WHERE ${whereClause}
      `;

      db.get(query, params, (err, row) => {
        if (err) {
          reject(err);
        } else {
          resolve({
            totalLogs: row?.total_logs || 0,
            successCount: row?.success_count || 0,
            errorCount: row?.error_count || 0,
            warningCount: row?.warning_count || 0,
            infoCount: row?.info_count || 0,
            totalWorkTime: row?.total_work_time || 0,
            totalMissions: row?.total_missions || 0,
            completedMissions: row?.completed_missions || 0,
            failedMissions: row?.failed_missions || 0,
            moveCommands: row?.move_commands || 0,
            disconnectionCount: row?.disconnection_count || 0
          });
        }
      });
    });
  }

  // 로봇별 작업 시간 조회
  static getRobotWorkTime(options = {}) {
    const db = getDatabase();
    return new Promise((resolve, reject) => {
      let whereClause = 'duration IS NOT NULL AND robot_name IS NOT NULL';
      const params = [];

      if (options.dateFrom) {
        whereClause += ' AND DATE(created_at) >= DATE(?)';
        params.push(options.dateFrom);
      }

      if (options.dateTo) {
        whereClause += ' AND DATE(created_at) <= DATE(?)';
        params.push(options.dateTo);
      }

      const query = `
        SELECT 
          robot_name,
          SUM(duration) as total_work_time,
          COUNT(*) as task_count,
          SUM(CASE WHEN event_type = 'mission_completed' THEN 1 ELSE 0 END) as completed_count,
          AVG(duration) as avg_duration
        FROM activity_logs
        WHERE ${whereClause}
        GROUP BY robot_name
        ORDER BY total_work_time DESC
      `;

      db.all(query, params, (err, rows) => {
        if (err) {
          reject(err);
        } else {
          const result = {};
          rows.forEach(row => {
            result[row.robot_name] = {
              workTime: row.total_work_time,
              taskCount: row.task_count,
              completedCount: row.completed_count,
              avgDuration: Math.round(row.avg_duration || 0)
            };
          });
          resolve(result);
        }
      });
    });
  }

  // 로봇별 작업 건수 조회 (미션 완료 기준으로 카운트)
  static getRobotTaskCount(options = {}) {
    const db = getDatabase();
    return new Promise((resolve, reject) => {
      let whereClause = 'robot_name IS NOT NULL';
      const params = [];

      if (options.dateFrom) {
        whereClause += ' AND DATE(created_at) >= DATE(?)';
        params.push(options.dateFrom);
      }

      if (options.dateTo) {
        whereClause += ' AND DATE(created_at) <= DATE(?)';
        params.push(options.dateTo);
      }

      // 미션 완료/실패/취소 이벤트만 카운트 (실제 작업 건수)
      const query = `
        SELECT 
          robot_name,
          SUM(CASE WHEN event_type IN ('mission_completed', 'mission_failed', 'mission_cancelled') THEN 1 ELSE 0 END) as total_count,
          SUM(CASE WHEN event_type = 'mission_completed' THEN 1 ELSE 0 END) as success_count,
          SUM(CASE WHEN event_type = 'mission_failed' THEN 1 ELSE 0 END) as error_count,
          SUM(CASE WHEN event_type = 'move_requested' THEN 1 ELSE 0 END) as move_count
        FROM activity_logs
        WHERE ${whereClause}
        GROUP BY robot_name
        HAVING total_count > 0
        ORDER BY total_count DESC
      `;

      db.all(query, params, (err, rows) => {
        if (err) {
          reject(err);
        } else {
          const result = {};
          rows.forEach(row => {
            result[row.robot_name] = {
              total: row.total_count,
              success: row.success_count,
              error: row.error_count,
              moveCount: row.move_count
            };
          });
          resolve(result);
        }
      });
    });
  }

  // 미션 타임라인 조회 (미션별 시작/종료 시간)
  static getMissionTimeline(options = {}) {
    const db = getDatabase();
    return new Promise((resolve, reject) => {
      let whereClause = "event_type IN ('mission_started', 'mission_completed', 'mission_failed', 'mission_cancelled')";
      const params = [];

      if (options.dateFrom) {
        whereClause += ' AND DATE(created_at) >= DATE(?)';
        params.push(options.dateFrom);
      }

      if (options.dateTo) {
        whereClause += ' AND DATE(created_at) <= DATE(?)';
        params.push(options.dateTo);
      }

      if (options.robot_name && options.robot_name !== 'all') {
        whereClause += ' AND robot_name = ?';
        params.push(options.robot_name);
      }

      const query = `
        SELECT 
          mission_id,
          mission_name,
          mission_type,
          robot_id,
          robot_name,
          event_type,
          event_start_time,
          event_end_time,
          duration,
          created_at
        FROM activity_logs
        WHERE ${whereClause}
        ORDER BY created_at DESC
        LIMIT 200
      `;

      db.all(query, params, (err, rows) => {
        if (err) {
          reject(err);
        } else {
          // 미션 ID별로 그룹화하여 시작/종료 시간 정리
          const missionMap = new Map();
          
          rows.forEach(row => {
            const missionId = row.mission_id;
            if (!missionId) return;
            
            if (!missionMap.has(missionId)) {
              missionMap.set(missionId, {
                missionId: missionId,
                missionName: row.mission_name,
                missionType: row.mission_type,
                robotId: row.robot_id,
                robotName: row.robot_name,
                startTime: null,
                endTime: null,
                duration: null,
                status: 'in_progress'
              });
            }
            
            const mission = missionMap.get(missionId);
            
            if (row.event_type === 'mission_started') {
              mission.startTime = row.event_start_time || row.created_at;
            } else if (row.event_type === 'mission_completed') {
              mission.endTime = row.event_end_time || row.created_at;
              mission.duration = row.duration;
              mission.status = 'completed';
            } else if (row.event_type === 'mission_failed') {
              mission.endTime = row.event_end_time || row.created_at;
              mission.status = 'failed';
            } else if (row.event_type === 'mission_cancelled') {
              mission.endTime = row.event_end_time || row.created_at;
              mission.status = 'cancelled';
            }
          });
          
          // Map을 배열로 변환하고 시작시간 기준 정렬
          const result = Array.from(missionMap.values())
            .filter(m => m.startTime || m.endTime)
            .sort((a, b) => {
              const timeA = new Date(a.startTime || a.endTime);
              const timeB = new Date(b.startTime || b.endTime);
              return timeB - timeA;
            });
          
          resolve(result);
        }
      });
    });
  }

  // 이벤트 타입별 통계
  static getEventTypeStats(options = {}) {
    const db = getDatabase();
    return new Promise((resolve, reject) => {
      let whereClause = '1=1';
      const params = [];

      if (options.dateFrom) {
        whereClause += ' AND DATE(created_at) >= DATE(?)';
        params.push(options.dateFrom);
      }

      if (options.dateTo) {
        whereClause += ' AND DATE(created_at) <= DATE(?)';
        params.push(options.dateTo);
      }

      const query = `
        SELECT 
          event_type,
          COUNT(*) as count
        FROM activity_logs
        WHERE ${whereClause}
        GROUP BY event_type
        ORDER BY count DESC
      `;

      db.all(query, params, (err, rows) => {
        if (err) {
          reject(err);
        } else {
          const result = {};
          rows.forEach(row => {
            result[row.event_type] = row.count;
          });
          resolve(result);
        }
      });
    });
  }

  // 시간대별 로그 수 (대시보드용)
  static getHourlyStats(options = {}) {
    const db = getDatabase();
    return new Promise((resolve, reject) => {
      let whereClause = "DATE(created_at) = DATE('now', 'localtime')";
      const params = [];

      if (options.date) {
        whereClause = 'DATE(created_at) = DATE(?)';
        params.push(options.date);
      }

      const query = `
        SELECT 
          strftime('%H', created_at) as hour,
          COUNT(*) as count,
          SUM(CASE WHEN level = 'success' THEN 1 ELSE 0 END) as success_count,
          SUM(CASE WHEN level = 'error' THEN 1 ELSE 0 END) as error_count
        FROM activity_logs
        WHERE ${whereClause}
        GROUP BY strftime('%H', created_at)
        ORDER BY hour
      `;

      db.all(query, params, (err, rows) => {
        if (err) {
          reject(err);
        } else {
          resolve(rows.map(row => ({
            hour: parseInt(row.hour),
            count: row.count,
            successCount: row.success_count,
            errorCount: row.error_count
          })));
        }
      });
    });
  }

  // 고유 로봇 목록 조회
  static getUniqueRobots() {
    const db = getDatabase();
    return new Promise((resolve, reject) => {
      db.all(
        'SELECT DISTINCT robot_name FROM activity_logs WHERE robot_name IS NOT NULL ORDER BY robot_name',
        [],
        (err, rows) => {
          if (err) {
            reject(err);
          } else {
            resolve(rows.map(row => row.robot_name));
          }
        }
      );
    });
  }

  // 최근 미션 로그 (타임라인용)
  static getRecentMissionLogs(limit = 50) {
    const db = getDatabase();
    return new Promise((resolve, reject) => {
      const query = `
        SELECT * FROM activity_logs 
        WHERE category = 'mission' 
        ORDER BY created_at DESC 
        LIMIT ?
      `;

      db.all(query, [limit], (err, rows) => {
        if (err) {
          reject(err);
        } else {
          resolve(rows.map(row => new ActivityLog(row)));
        }
      });
    });
  }

  // 오래된 로그 삭제
  static deleteOldLogs(daysOld = 30) {
    const db = getDatabase();
    return new Promise((resolve, reject) => {
      db.run(
        `DELETE FROM activity_logs WHERE created_at < datetime('now', '-' || ? || ' days')`,
        [daysOld],
        function(err) {
          if (err) {
            reject(err);
          } else {
            resolve(this.changes);
          }
        }
      );
    });
  }

  // JSON 변환
  toJSON() {
    return {
      id: this.id,
      level: this.level,
      category: this.category,
      eventType: this.event_type,
      
      // 로봇 정보
      robotId: this.robot_id,
      robotName: this.robot_name,
      robotIp: this.robot_ip,
      robotStatus: this.robot_status,
      
      // 미션 정보
      missionId: this.mission_id,
      missionName: this.mission_name,
      missionType: this.mission_type,
      missionPriority: this.mission_priority,
      missionStatus: this.mission_status,
      
      // 웨이포인트 정보
      waypointIndex: this.waypoint_index,
      waypointTotal: this.waypoint_total,
      waypointName: this.waypoint_name,
      
      // 이동 명령 정보
      targetNodeId: this.target_node_id,
      targetNodeName: this.target_node_name,
      sourceX: this.source_x,
      sourceY: this.source_y,
      targetX: this.target_x,
      targetY: this.target_y,
      
      // 시간 정보
      eventStartTime: this.event_start_time,
      eventEndTime: this.event_end_time,
      duration: this.duration,
      
      // 메시지
      message: this.message,
      details: this.details,
      errorCode: this.error_code,
      errorMessage: this.error_message,
      
      // 기타
      metadata: this.metadata,
      triggerSource: this.trigger_source,
      timestamp: this.created_at,
      created_at: this.created_at
    };
  }
}

// 상수 export
ActivityLog.EVENT_TYPES = EVENT_TYPES;
ActivityLog.CATEGORIES = CATEGORIES;
ActivityLog.LOG_LEVELS = LOG_LEVELS;

module.exports = ActivityLog;
