const ActivityLog = require('../models/ActivityLog');

const { EVENT_TYPES, CATEGORIES, LOG_LEVELS } = ActivityLog;

/**
 * 활동 로그 서비스 (고도화 버전)
 * 시스템의 모든 중요 이벤트를 체계적으로 로깅합니다.
 */
class ActivityLogService {
  
  // ==================== 미션 관련 로그 ====================
  
  /**
   * 미션 생성 로그
   */
  static async logMissionCreated(mission, robot = null, triggerSource = 'system') {
    try {
      const robotName = robot?.name || (mission.robot_id ? `AMR-${mission.robot_id}` : null);
      const waypointCount = mission.waypoints?.length || 0;
      
      await ActivityLog.create({
        level: LOG_LEVELS.INFO,
        category: CATEGORIES.MISSION,
        event_type: EVENT_TYPES.MISSION_CREATED,
        
        robot_id: robot?.id || mission.robot_id,
        robot_name: robotName,
        robot_ip: robot?.ip_address,
        
        mission_id: mission.id,
        mission_name: mission.name,
        mission_type: mission.mission_type,
        mission_priority: mission.priority,
        mission_status: 'pending',
        
        waypoint_total: waypointCount,
        
        event_start_time: new Date().toISOString(),
        
        message: `미션 생성: ${mission.name}`,
        details: `타입: ${mission.mission_type}, 우선순위: ${mission.priority}, 웨이포인트: ${waypointCount}개${mission.description ? `, 설명: ${mission.description}` : ''}`,
        
        trigger_source: triggerSource,
        
        metadata: {
          waypoints: mission.waypoints,
          description: mission.description
        }
      });
    } catch (error) {
      console.error('미션 생성 로그 기록 실패:', error);
    }
  }

  /**
   * 미션 로봇 할당 로그
   */
  static async logMissionAssigned(mission, robot) {
    try {
      await ActivityLog.create({
        level: LOG_LEVELS.INFO,
        category: CATEGORIES.MISSION,
        event_type: EVENT_TYPES.MISSION_ASSIGNED,
        
        robot_id: robot.id,
        robot_name: robot.name,
        robot_ip: robot.ip_address,
        robot_status: robot.status,
        
        mission_id: mission.id,
        mission_name: mission.name,
        mission_type: mission.mission_type,
        mission_priority: mission.priority,
        mission_status: 'pending',
        
        waypoint_total: mission.waypoints?.length || 0,
        
        message: `미션 할당: ${mission.name} → ${robot.name}`,
        details: `${robot.name}에 "${mission.name}" 미션이 할당되었습니다.`,
        
        trigger_source: 'system'
      });
    } catch (error) {
      console.error('미션 할당 로그 기록 실패:', error);
    }
  }

  /**
   * 미션 시작 로그
   */
  static async logMissionStarted(mission, robot = null) {
    try {
      const startTime = new Date().toISOString();
      
      await ActivityLog.create({
        level: LOG_LEVELS.INFO,
        category: CATEGORIES.MISSION,
        event_type: EVENT_TYPES.MISSION_STARTED,
        
        robot_id: robot?.id || mission.robot_id,
        robot_name: robot?.name || (mission.robot_id ? `AMR-${mission.robot_id}` : null),
        robot_ip: robot?.ip_address,
        robot_status: 'working',
        
        mission_id: mission.id,
        mission_name: mission.name,
        mission_type: mission.mission_type,
        mission_priority: mission.priority,
        mission_status: 'in_progress',
        
        waypoint_index: 0,
        waypoint_total: mission.waypoints?.length || 0,
        waypoint_name: mission.waypoints?.[0]?.stationName,
        
        event_start_time: startTime,
        
        message: `미션 시작: ${mission.name}`,
        details: `${robot?.name || `AMR-${mission.robot_id}`}이(가) "${mission.name}" 미션을 시작합니다. (웨이포인트 ${mission.waypoints?.length || 0}개)`,
        
        trigger_source: 'system'
      });
    } catch (error) {
      console.error('미션 시작 로그 기록 실패:', error);
    }
  }

  /**
   * 웨이포인트 시작 로그
   */
  static async logWaypointStarted(robot, mission, waypointIndex, waypoint) {
    try {
      await ActivityLog.create({
        level: LOG_LEVELS.INFO,
        category: CATEGORIES.NAVIGATION,
        event_type: EVENT_TYPES.WAYPOINT_STARTED,
        
        robot_id: robot.id,
        robot_name: robot.name,
        robot_ip: robot.ip_address,
        robot_status: robot.status,
        
        mission_id: mission.id,
        mission_name: mission.name,
        mission_type: mission.mission_type,
        
        waypoint_index: waypointIndex,
        waypoint_total: mission.waypoints?.length || 0,
        waypoint_name: waypoint?.stationName || `웨이포인트 ${waypointIndex + 1}`,
        
        target_node_id: waypoint?.stationId,
        target_node_name: waypoint?.stationName,
        target_x: waypoint?.x,
        target_y: waypoint?.y,
        source_x: robot.location_x,
        source_y: robot.location_y,
        
        event_start_time: new Date().toISOString(),
        
        message: `웨이포인트 이동 시작: ${waypoint?.stationName || `#${waypointIndex + 1}`}`,
        details: `${robot.name}이(가) ${waypointIndex + 1}/${mission.waypoints?.length}번째 웨이포인트로 이동을 시작합니다.`,
        
        trigger_source: 'system'
      });
    } catch (error) {
      console.error('웨이포인트 시작 로그 기록 실패:', error);
    }
  }

  /**
   * 웨이포인트 도착 로그
   */
  static async logWaypointArrived(robot, mission, waypointIndex, waypoint, duration = null) {
    try {
      await ActivityLog.create({
        level: LOG_LEVELS.SUCCESS,
        category: CATEGORIES.NAVIGATION,
        event_type: EVENT_TYPES.WAYPOINT_ARRIVED,
        
        robot_id: robot.id,
        robot_name: robot.name,
        robot_ip: robot.ip_address,
        robot_status: robot.status,
        
        mission_id: mission.id,
        mission_name: mission.name,
        mission_type: mission.mission_type,
        
        waypoint_index: waypointIndex,
        waypoint_total: mission.waypoints?.length || 0,
        waypoint_name: waypoint?.stationName || `웨이포인트 ${waypointIndex + 1}`,
        
        target_node_id: waypoint?.stationId,
        target_node_name: waypoint?.stationName,
        target_x: waypoint?.x,
        target_y: waypoint?.y,
        
        duration: duration,
        event_end_time: new Date().toISOString(),
        
        message: `웨이포인트 도착: ${waypoint?.stationName || `#${waypointIndex + 1}`}`,
        details: `${robot.name}이(가) ${waypointIndex + 1}/${mission.waypoints?.length}번째 웨이포인트에 도착했습니다. (진행률: ${Math.round(((waypointIndex + 1) / (mission.waypoints?.length || 1)) * 100)}%)`,
        
        trigger_source: 'system'
      });
    } catch (error) {
      console.error('웨이포인트 도착 로그 기록 실패:', error);
    }
  }

  /**
   * 미션 완료 로그
   */
  static async logMissionCompleted(mission, robot = null, duration = null) {
    try {
      let calculatedDuration = duration;
      if (!calculatedDuration && mission.start_time && mission.end_time) {
        const startTime = new Date(mission.start_time);
        const endTime = new Date(mission.end_time);
        calculatedDuration = Math.floor((endTime - startTime) / 1000);
      }

      const durationText = calculatedDuration ? 
        `${Math.floor(calculatedDuration / 60)}분 ${calculatedDuration % 60}초` : '알 수 없음';

      await ActivityLog.create({
        level: LOG_LEVELS.SUCCESS,
        category: CATEGORIES.MISSION,
        event_type: EVENT_TYPES.MISSION_COMPLETED,
        
        robot_id: robot?.id || mission.robot_id,
        robot_name: robot?.name || (mission.robot_id ? `AMR-${mission.robot_id}` : null),
        robot_ip: robot?.ip_address,
        robot_status: 'idle',
        
        mission_id: mission.id,
        mission_name: mission.name,
        mission_type: mission.mission_type,
        mission_priority: mission.priority,
        mission_status: 'completed',
        
        waypoint_index: mission.waypoints?.length || 0,
        waypoint_total: mission.waypoints?.length || 0,
        
        event_start_time: mission.start_time,
        event_end_time: mission.end_time || new Date().toISOString(),
        duration: calculatedDuration,
        
        message: `미션 완료: ${mission.name}`,
        details: `${mission.mission_type} 미션이 성공적으로 완료되었습니다. (소요시간: ${durationText}, 웨이포인트: ${mission.waypoints?.length || 0}개 완료)`,
        
        trigger_source: 'system'
      });
    } catch (error) {
      console.error('미션 완료 로그 기록 실패:', error);
    }
  }

  /**
   * 미션 실패 로그
   */
  static async logMissionFailed(mission, robot = null, reason = '', errorCode = null) {
    try {
      await ActivityLog.create({
        level: LOG_LEVELS.ERROR,
        category: CATEGORIES.MISSION,
        event_type: EVENT_TYPES.MISSION_FAILED,
        
        robot_id: robot?.id || mission.robot_id,
        robot_name: robot?.name || (mission.robot_id ? `AMR-${mission.robot_id}` : null),
        robot_ip: robot?.ip_address,
        robot_status: robot?.status,
        
        mission_id: mission.id,
        mission_name: mission.name,
        mission_type: mission.mission_type,
        mission_priority: mission.priority,
        mission_status: 'failed',
        
        event_end_time: new Date().toISOString(),
        
        message: `미션 실패: ${mission.name}`,
        details: reason || '미션 수행 중 오류가 발생했습니다.',
        error_code: errorCode,
        error_message: reason,
        
        trigger_source: 'system'
      });
    } catch (error) {
      console.error('미션 실패 로그 기록 실패:', error);
    }
  }

  /**
   * 미션 취소 로그
   */
  static async logMissionCancelled(mission, robot = null, reason = '', triggerSource = 'manual') {
    try {
      await ActivityLog.create({
        level: LOG_LEVELS.WARNING,
        category: CATEGORIES.MISSION,
        event_type: EVENT_TYPES.MISSION_CANCELLED,
        
        robot_id: robot?.id || mission.robot_id,
        robot_name: robot?.name || (mission.robot_id ? `AMR-${mission.robot_id}` : null),
        robot_ip: robot?.ip_address,
        robot_status: robot?.status,
        
        mission_id: mission.id,
        mission_name: mission.name,
        mission_type: mission.mission_type,
        mission_priority: mission.priority,
        mission_status: 'cancelled',
        
        waypoint_index: robot?.current_waypoint_index,
        waypoint_total: mission.waypoints?.length || 0,
        
        event_end_time: new Date().toISOString(),
        
        message: `미션 취소: ${mission.name}`,
        details: reason || '미션이 취소되었습니다.',
        
        trigger_source: triggerSource
      });
    } catch (error) {
      console.error('미션 취소 로그 기록 실패:', error);
    }
  }

  // ==================== 로봇 관련 로그 ====================

  /**
   * 로봇 생성 로그
   */
  static async logRobotCreated(robot) {
    try {
      await ActivityLog.create({
        level: LOG_LEVELS.INFO,
        category: CATEGORIES.ROBOT,
        event_type: EVENT_TYPES.ROBOT_CREATED,
        
        robot_id: robot.id,
        robot_name: robot.name,
        robot_ip: robot.ip_address,
        robot_status: robot.status,
        
        message: `로봇 등록: ${robot.name}`,
        details: `새로운 로봇이 등록되었습니다. (IP: ${robot.ip_address}:${robot.port || 80})`,
        
        trigger_source: 'manual'
      });
    } catch (error) {
      console.error('로봇 생성 로그 기록 실패:', error);
    }
  }

  /**
   * 로봇 삭제 로그
   */
  static async logRobotDeleted(robot) {
    try {
      await ActivityLog.create({
        level: LOG_LEVELS.WARNING,
        category: CATEGORIES.ROBOT,
        event_type: EVENT_TYPES.ROBOT_DELETED,
        
        robot_id: robot.id,
        robot_name: robot.name,
        robot_ip: robot.ip_address,
        
        message: `로봇 삭제: ${robot.name}`,
        details: `로봇이 시스템에서 삭제되었습니다.`,
        
        trigger_source: 'manual'
      });
    } catch (error) {
      console.error('로봇 삭제 로그 기록 실패:', error);
    }
  }

  /**
   * 로봇 연결 로그
   */
  static async logRobotConnected(robot) {
    try {
      await ActivityLog.create({
        level: LOG_LEVELS.SUCCESS,
        category: CATEGORIES.ROBOT,
        event_type: EVENT_TYPES.ROBOT_CONNECTED,
        
        robot_id: robot.id,
        robot_name: robot.name,
        robot_ip: robot.ip_address,
        robot_status: robot.status,
        
        message: `로봇 연결됨: ${robot.name}`,
        details: `${robot.name}이(가) 시스템에 연결되었습니다. (IP: ${robot.ip_address})`,
        
        trigger_source: 'system'
      });
    } catch (error) {
      console.error('로봇 연결 로그 기록 실패:', error);
    }
  }

  /**
   * 로봇 연결 끊김 로그
   */
  static async logRobotDisconnected(robot, reason = '') {
    try {
      await ActivityLog.create({
        level: LOG_LEVELS.ERROR,
        category: CATEGORIES.ROBOT,
        event_type: EVENT_TYPES.ROBOT_DISCONNECTED,
        
        robot_id: robot.id,
        robot_name: robot.name,
        robot_ip: robot.ip_address,
        robot_status: 'disconnected',
        
        message: `로봇 연결 끊김: ${robot.name}`,
        details: reason || `${robot.name}과(와)의 연결이 끊어졌습니다.`,
        error_message: reason,
        
        trigger_source: 'system'
      });
    } catch (error) {
      console.error('로봇 연결 끊김 로그 기록 실패:', error);
    }
  }

  /**
   * 로봇 상태 변경 로그
   */
  static async logRobotStatusChanged(robot, oldStatus, newStatus, reason = '') {
    try {
      // 같은 상태면 로그 안 남김
      if (oldStatus === newStatus) return;

      const levelMap = {
        'idle': LOG_LEVELS.INFO,
        'working': LOG_LEVELS.INFO,
        'moving': LOG_LEVELS.INFO,
        'charging': LOG_LEVELS.INFO,
        'pause': LOG_LEVELS.WARNING,
        'stop': LOG_LEVELS.WARNING,
        'error': LOG_LEVELS.ERROR,
        'disconnected': LOG_LEVELS.ERROR
      };

      await ActivityLog.create({
        level: levelMap[newStatus] || LOG_LEVELS.INFO,
        category: CATEGORIES.ROBOT,
        event_type: EVENT_TYPES.ROBOT_STATUS_CHANGED,
        
        robot_id: robot.id,
        robot_name: robot.name,
        robot_ip: robot.ip_address,
        robot_status: newStatus,
        
        message: `로봇 상태 변경: ${robot.name}`,
        details: `${oldStatus} → ${newStatus}${reason ? ` (${reason})` : ''}`,
        
        metadata: {
          old_status: oldStatus,
          new_status: newStatus
        },
        
        trigger_source: 'system'
      });
    } catch (error) {
      console.error('로봇 상태 변경 로그 기록 실패:', error);
    }
  }

  /**
   * 로봇 오류 로그
   */
  static async logRobotError(robot, errorCode, errorMessage) {
    try {
      await ActivityLog.create({
        level: LOG_LEVELS.ERROR,
        category: CATEGORIES.ROBOT,
        event_type: EVENT_TYPES.ROBOT_ERROR,
        
        robot_id: robot.id,
        robot_name: robot.name,
        robot_ip: robot.ip_address,
        robot_status: 'error',
        
        message: `로봇 오류: ${robot.name}`,
        details: errorMessage || '로봇에서 오류가 발생했습니다.',
        error_code: String(errorCode),
        error_message: errorMessage,
        
        trigger_source: 'system'
      });
    } catch (error) {
      console.error('로봇 오류 로그 기록 실패:', error);
    }
  }

  // ==================== 배터리 관련 로그 ====================

  /**
   * 배터리 부족 경고 로그
   */
  static async logBatteryLow(robot, batteryLevel) {
    try {
      const level = batteryLevel <= 10 ? LOG_LEVELS.ERROR : LOG_LEVELS.WARNING;
      const eventType = batteryLevel <= 10 ? EVENT_TYPES.BATTERY_CRITICAL : EVENT_TYPES.BATTERY_LOW;
      
      await ActivityLog.create({
        level: level,
        category: CATEGORIES.BATTERY,
        event_type: eventType,
        
        robot_id: robot.id,
        robot_name: robot.name,
        robot_ip: robot.ip_address,
        robot_status: robot.status,
        
        message: batteryLevel <= 10 ? `배터리 위험: ${robot.name}` : `배터리 부족: ${robot.name}`,
        details: `배터리 잔량 ${batteryLevel}%. ${batteryLevel <= 10 ? '즉시 충전이 필요합니다!' : '충전이 필요합니다.'}`,
        
        metadata: { battery_level: batteryLevel },
        
        trigger_source: 'system'
      });
    } catch (error) {
      console.error('배터리 경고 로그 기록 실패:', error);
    }
  }

  /**
   * 충전 시작 로그
   */
  static async logChargingStarted(robot, batteryLevel) {
    try {
      await ActivityLog.create({
        level: LOG_LEVELS.INFO,
        category: CATEGORIES.BATTERY,
        event_type: EVENT_TYPES.CHARGING_STARTED,
        
        robot_id: robot.id,
        robot_name: robot.name,
        robot_ip: robot.ip_address,
        robot_status: 'charging',
        
        event_start_time: new Date().toISOString(),
        
        message: `충전 시작: ${robot.name}`,
        details: `현재 배터리: ${batteryLevel}%`,
        
        metadata: { battery_level: batteryLevel },
        
        trigger_source: 'system'
      });
    } catch (error) {
      console.error('충전 시작 로그 기록 실패:', error);
    }
  }

  /**
   * 충전 완료 로그
   */
  static async logChargingCompleted(robot, duration = null) {
    try {
      await ActivityLog.create({
        level: LOG_LEVELS.SUCCESS,
        category: CATEGORIES.BATTERY,
        event_type: EVENT_TYPES.CHARGING_COMPLETED,
        
        robot_id: robot.id,
        robot_name: robot.name,
        robot_ip: robot.ip_address,
        robot_status: 'idle',
        
        event_end_time: new Date().toISOString(),
        duration: duration,
        
        message: `충전 완료: ${robot.name}`,
        details: `배터리 충전이 완료되었습니다.${duration ? ` (충전시간: ${Math.floor(duration / 60)}분)` : ''}`,
        
        trigger_source: 'system'
      });
    } catch (error) {
      console.error('충전 완료 로그 기록 실패:', error);
    }
  }

  // ==================== 이동 명령 관련 로그 ====================

  /**
   * 이동 요청 로그 (수동 이동 - 지도에서 우클릭)
   */
  static async logMoveRequested(robot, targetNodeId, targetNodeName = null, triggerSource = 'manual') {
    try {
      await ActivityLog.create({
        level: LOG_LEVELS.INFO,
        category: CATEGORIES.COMMAND,
        event_type: EVENT_TYPES.MOVE_REQUESTED,
        
        robot_id: robot.id,
        robot_name: robot.name,
        robot_ip: robot.ip_address,
        robot_status: robot.status,
        
        target_node_id: String(targetNodeId),
        target_node_name: targetNodeName,
        source_x: robot.location_x,
        source_y: robot.location_y,
        
        event_start_time: new Date().toISOString(),
        
        message: `이동 요청: ${robot.name} → ${targetNodeName || `노드 ${targetNodeId}`}`,
        details: `${triggerSource === 'manual' ? '수동 ' : ''}이동 명령이 요청되었습니다.`,
        
        trigger_source: triggerSource
      });
    } catch (error) {
      console.error('이동 요청 로그 기록 실패:', error);
    }
  }

  /**
   * 이동 성공 로그
   */
  static async logMoveCompleted(robot, targetNodeId, targetNodeName = null, duration = null) {
    try {
      await ActivityLog.create({
        level: LOG_LEVELS.SUCCESS,
        category: CATEGORIES.COMMAND,
        event_type: EVENT_TYPES.MOVE_COMPLETED,
        
        robot_id: robot.id,
        robot_name: robot.name,
        robot_ip: robot.ip_address,
        robot_status: robot.status,
        
        target_node_id: String(targetNodeId),
        target_node_name: targetNodeName,
        target_x: robot.location_x,
        target_y: robot.location_y,
        
        event_end_time: new Date().toISOString(),
        duration: duration,
        
        message: `이동 완료: ${robot.name} → ${targetNodeName || `노드 ${targetNodeId}`}`,
        details: `목적지에 도착했습니다.${duration ? ` (소요시간: ${Math.floor(duration / 60)}분 ${duration % 60}초)` : ''}`,
        
        trigger_source: 'system'
      });
    } catch (error) {
      console.error('이동 완료 로그 기록 실패:', error);
    }
  }

  /**
   * 이동 실패 로그
   */
  static async logMoveFailed(robot, targetNodeId, targetNodeName = null, reason = '') {
    try {
      await ActivityLog.create({
        level: LOG_LEVELS.ERROR,
        category: CATEGORIES.COMMAND,
        event_type: EVENT_TYPES.MOVE_FAILED,
        
        robot_id: robot.id,
        robot_name: robot.name,
        robot_ip: robot.ip_address,
        robot_status: robot.status,
        
        target_node_id: String(targetNodeId),
        target_node_name: targetNodeName,
        
        event_end_time: new Date().toISOString(),
        
        message: `이동 실패: ${robot.name}`,
        details: reason || '이동 명령 수행에 실패했습니다.',
        error_message: reason,
        
        trigger_source: 'system'
      });
    } catch (error) {
      console.error('이동 실패 로그 기록 실패:', error);
    }
  }

  // ==================== 네비게이션 관련 로그 ====================

  /**
   * 네비게이션 오류 로그
   */
  static async logNavigationError(robot, destination, reason) {
    try {
      await ActivityLog.create({
        level: LOG_LEVELS.ERROR,
        category: CATEGORIES.NAVIGATION,
        event_type: EVENT_TYPES.NAVIGATION_ERROR,
        
        robot_id: robot.id,
        robot_name: robot.name,
        robot_ip: robot.ip_address,
        robot_status: robot.status,
        
        target_node_name: destination,
        
        message: `네비게이션 오류: ${robot.name}`,
        details: `목적지: ${destination}, 원인: ${reason}`,
        error_message: reason,
        
        trigger_source: 'system'
      });
    } catch (error) {
      console.error('네비게이션 오류 로그 기록 실패:', error);
    }
  }

  /**
   * 경로 차단 로그
   */
  static async logPathBlocked(robot, reason) {
    try {
      await ActivityLog.create({
        level: LOG_LEVELS.WARNING,
        category: CATEGORIES.NAVIGATION,
        event_type: EVENT_TYPES.PATH_BLOCKED,
        
        robot_id: robot.id,
        robot_name: robot.name,
        robot_ip: robot.ip_address,
        robot_status: robot.status,
        
        source_x: robot.location_x,
        source_y: robot.location_y,
        
        message: `경로 차단: ${robot.name}`,
        details: reason || '경로에 장애물이 감지되었습니다.',
        
        trigger_source: 'system'
      });
    } catch (error) {
      console.error('경로 차단 로그 기록 실패:', error);
    }
  }

  // ==================== 시스템 관련 로그 ====================

  /**
   * 시스템 시작 로그
   */
  static async logSystemStarted() {
    try {
      await ActivityLog.create({
        level: LOG_LEVELS.INFO,
        category: CATEGORIES.SYSTEM,
        event_type: EVENT_TYPES.SYSTEM_STARTED,
        
        event_start_time: new Date().toISOString(),
        
        message: '시스템 시작',
        details: 'AMR 관제 시스템이 시작되었습니다.',
        
        trigger_source: 'system'
      });
    } catch (error) {
      console.error('시스템 시작 로그 기록 실패:', error);
    }
  }

  /**
   * 서비스 시작 로그
   */
  static async logServiceStarted(serviceName) {
    try {
      await ActivityLog.create({
        level: LOG_LEVELS.INFO,
        category: CATEGORIES.SYSTEM,
        event_type: EVENT_TYPES.SERVICE_STARTED,
        
        event_start_time: new Date().toISOString(),
        
        message: `서비스 시작: ${serviceName}`,
        details: `${serviceName} 서비스가 시작되었습니다.`,
        
        trigger_source: 'system'
      });
    } catch (error) {
      console.error('서비스 시작 로그 기록 실패:', error);
    }
  }

  /**
   * 서비스 중지 로그
   */
  static async logServiceStopped(serviceName) {
    try {
      await ActivityLog.create({
        level: LOG_LEVELS.INFO,
        category: CATEGORIES.SYSTEM,
        event_type: EVENT_TYPES.SERVICE_STOPPED,
        
        event_end_time: new Date().toISOString(),
        
        message: `서비스 중지: ${serviceName}`,
        details: `${serviceName} 서비스가 중지되었습니다.`,
        
        trigger_source: 'system'
      });
    } catch (error) {
      console.error('서비스 중지 로그 기록 실패:', error);
    }
  }

  // ==================== 일반 로그 ====================

  /**
   * 일반 로그 생성
   */
  static async log(data) {
    try {
      return await ActivityLog.create(data);
    } catch (error) {
      console.error('로그 기록 실패:', error);
      return null;
    }
  }
}

// 상수 export
ActivityLogService.EVENT_TYPES = EVENT_TYPES;
ActivityLogService.CATEGORIES = CATEGORIES;
ActivityLogService.LOG_LEVELS = LOG_LEVELS;

module.exports = ActivityLogService;
