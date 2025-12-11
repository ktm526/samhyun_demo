const axios = require('axios');
const Robot = require('../models/Robot');
const ActivityLogService = require('./activityLogService');

class RobotStatusService {
  constructor() {
    this.intervalId = null;
    this.isRunning = false;
    this.pollInterval = 500; // 1초마다 상태 수집 (1Hz)
    this.httpTimeout = 5000; // HTTP 요청 타임아웃 5초
    
    // 로봇 상태 추적 (로깅 중복 방지)
    this.lastRobotStates = new Map();
    this.connectionStates = new Map();
    this.batteryWarningStates = new Map();
  }

  // 서비스 시작
  start() {
    if (this.isRunning) {
      
      return;
    }

    
    this.isRunning = true;
    
    // 즉시 한 번 실행
    this.collectAllRobotStatus();
    
    // 주기적 실행 시작
    this.intervalId = setInterval(() => {
      this.collectAllRobotStatus();
    }, this.pollInterval);

    
  }

  // 서비스 중지
  stop() {
    if (!this.isRunning) {
      
      return;
    }

    
    
    if (this.intervalId) {
      clearInterval(this.intervalId);
      this.intervalId = null;
    }
    
    this.isRunning = false;
    
  }

  // 모든 로봇의 상태 수집
  async collectAllRobotStatus() {
    try {
      // 모든 로봇 정보 가져오기
      const robots = await Robot.findAll();
      
      if (robots.length === 0) {
        
        return;
      }

      

      // 병렬로 모든 로봇의 상태 수집
      const promises = robots.map(robot => this.collectRobotStatus(robot));
      const results = await Promise.allSettled(promises);

      // 결과 통계
      const successful = results.filter(result => result.status === 'fulfilled').length;
      const failed = results.filter(result => result.status === 'rejected').length;

      

    } catch (error) {
      
    }
  }

  // 개별 로봇의 상태 수집
  async collectRobotStatus(robot) {
    if (!robot.ip_address) {
      const errorMsg = `로봇 ${robot.name}의 IP 주소가 설정되지 않았습니다.`;
      await robot.markAsDisconnected(errorMsg);
      throw new Error(errorMsg);
    }

    const previousConnectionState = this.connectionStates.get(robot.id);
    const previousStatus = this.lastRobotStates.get(robot.id);

    try {
      const port = robot.port || 80;
      const url = `http://${robot.ip_address}:${port}/api/v1/amr/status`;
      

      const response = await axios.get(url, {
        timeout: this.httpTimeout,
        headers: {
          'Accept': 'application/json',
          'Content-Type': 'application/json'
        }
      });

      if (response.status === 200 && response.data) {
        // order_status를 기반으로 status 매핑
        let mappedStatus = response.data.status; // 기본값은 로봇이 보낸 status
        
        if (response.data.order_status !== undefined) {
          switch (response.data.order_status) {
            case 0:
              mappedStatus = 'idle';
              break;
            case 1:
              mappedStatus = 'stop';
              break;
            case 2:
              mappedStatus = 'working';
              break;
            case 3:
              mappedStatus = 'pause';
              break;
            default:
              mappedStatus = response.data.status || 'unknown';
              break;
          }
        }

        // 충전 상태 확인
        if (response.data.charging_status === true) {
          mappedStatus = 'charging';
        }
        
        // 연결 성공 - 상태 정보 업데이트 (매핑된 status 사용)
        const updateData = {
          ...response.data,
          status: mappedStatus, // 매핑된 status로 덮어쓰기
          connection_status: true,
          error_code: 0,
          error_msg: null
        };
        
        await robot.updateAmrStatus(updateData);

        // === 로깅 처리 ===
        
        // 연결 복구 로그 (이전에 끊어졌다가 다시 연결된 경우)
        if (previousConnectionState === false) {
          await ActivityLogService.logRobotConnected(robot);
        }
        this.connectionStates.set(robot.id, true);

        // 상태 변경 로그
        if (previousStatus && previousStatus !== mappedStatus) {
          await ActivityLogService.logRobotStatusChanged(robot, previousStatus, mappedStatus);
        }
        this.lastRobotStates.set(robot.id, mappedStatus);

        // 배터리 경고 로그 (20% 이하일 때 한번만)
        const batteryLevel = response.data.battery_soc || 0;
        const previousBatteryWarning = this.batteryWarningStates.get(robot.id);
        if (batteryLevel <= 20 && !previousBatteryWarning) {
          await ActivityLogService.logBatteryLow(robot, batteryLevel);
          this.batteryWarningStates.set(robot.id, true);
        } else if (batteryLevel > 30) {
          this.batteryWarningStates.set(robot.id, false);
        }

        // 충전 시작 로그
        if (previousStatus !== 'charging' && mappedStatus === 'charging') {
          await ActivityLogService.logChargingStarted(robot, batteryLevel);
        }

        // 충전 완료 로그
        if (previousStatus === 'charging' && mappedStatus !== 'charging' && batteryLevel >= 95) {
          await ActivityLogService.logChargingCompleted(robot);
        }

        // 오류 로그
        if (response.data.error_code && response.data.error_code !== 0) {
          await ActivityLogService.logRobotError(robot, response.data.error_code, response.data.error_msg);
        }
        
        return response.data;
      } else {
        throw new Error(`잘못된 응답: HTTP ${response.status}`);
      }

    } catch (error) {
      const port = robot.port || 80;
      
      
      // 연결 실패 - 상태 업데이트
      const errorMsg = `연결 실패: ${error.message}`;
      await robot.markAsDisconnected(errorMsg);

      // 연결 끊김 로그 (처음 끊어졌을 때만)
      if (previousConnectionState !== false) {
        await ActivityLogService.logRobotDisconnected(robot, errorMsg);
      }
      this.connectionStates.set(robot.id, false);
      this.lastRobotStates.set(robot.id, 'disconnected');
      
      throw error;
    }
  }

  // 특정 로봇의 상태만 수집
  async collectSingleRobotStatus(robotId) {
    try {
      const robot = await Robot.findById(robotId);
      if (!robot) {
        throw new Error(`로봇 ID ${robotId}를 찾을 수 없습니다.`);
      }

      return await this.collectRobotStatus(robot);
    } catch (error) {
      
      throw error;
    }
  }

  // 설정 변경
  setPollInterval(intervalMs) {
    if (intervalMs < 1000) {
      throw new Error('폴링 간격은 최소 1초 이상이어야 합니다.');
    }
    
    this.pollInterval = intervalMs;
    
    
    // 실행 중이면 재시작
    if (this.isRunning) {
      this.stop();
      this.start();
    }
  }

  setHttpTimeout(timeoutMs) {
    if (timeoutMs < 1000) {
      throw new Error('HTTP 타임아웃은 최소 1초 이상이어야 합니다.');
    }
    
    this.httpTimeout = timeoutMs;
    
  }

  // 서비스 상태 확인
  getStatus() {
    return {
      isRunning: this.isRunning,
      pollInterval: this.pollInterval,
      httpTimeout: this.httpTimeout,
      intervalId: this.intervalId !== null
    };
  }

  // 연결된 로봇 수 확인
  async getConnectedRobotsCount() {
    try {
      const robots = await Robot.findAll();
      return robots.filter(robot => robot.connection_status === true || robot.connection_status === 1).length;
    } catch (error) {
      
      return 0;
    }
  }

  // 로봇 상태 통계
  async getRobotStatusStats() {
    try {
      const robots = await Robot.findAll();
      const stats = {
        total: robots.length,
        connected: 0,
        disconnected: 0,
        idle: 0,
        stop: 0,
        working: 0,
        pause: 0,
        charging: 0,
        error: 0
      };

      robots.forEach(robot => {
        if (robot.connection_status) {
          stats.connected++;
        } else {
          stats.disconnected++;
        }

        switch (robot.status) {
          case 'idle':
            stats.idle++;
            break;
          case 'stop':
            stats.stop++;
            break;
          case 'working':
            stats.working++;
            break;
          case 'pause':
            stats.pause++;
            break;
          case 'charging':
            stats.charging++;
            break;
          case 'error':
          case 'disconnected':
            stats.error++;
            break;
        }
      });

      return stats;
    } catch (error) {
      
      throw error;
    }
  }
}

// 싱글톤 인스턴스 생성
const robotStatusService = new RobotStatusService();

module.exports = robotStatusService; 