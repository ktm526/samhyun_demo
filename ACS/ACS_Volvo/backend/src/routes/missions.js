const express = require('express');
const router = express.Router();
const Mission = require('../models/Mission');
const ActivityLogService = require('../services/activityLogService');

// 모든 미션 조회
router.get('/', async (req, res) => {
  try {
    const missions = await Mission.findAll();
    res.json({ data: missions.map(mission => mission.toJSON()) });
  } catch (error) {
    
    res.status(500).json({ error: '미션 조회 중 오류가 발생했습니다.' });
  }
});

// 새 미션 생성
router.post('/', async (req, res) => {
  try {
    
    
    // 데이터 유효성 검증
    const validationErrors = Mission.validate(req.body);
    if (validationErrors.length > 0) {
      return res.status(400).json({ error: validationErrors[0] });
    }
    
    // 미션 생성
    const mission = await Mission.create(req.body);
    
    // 미션 생성 로그 기록
    await ActivityLogService.logMissionCreated(mission);
    
    res.status(201).json({ 
      message: '미션이 성공적으로 생성되었습니다.', 
      data: mission.toJSON() 
    });
  } catch (error) {
    
    res.status(500).json({ error: '미션 생성 중 오류가 발생했습니다.' });
  }
});

// 특정 미션 조회
router.get('/:id', async (req, res) => {
  try {
    const { id } = req.params;
    const mission = await Mission.findById(id);
    
    if (!mission) {
      return res.status(404).json({ error: '미션을 찾을 수 없습니다.' });
    }
    
    res.json({ data: mission.toJSON() });
  } catch (error) {
    
    res.status(500).json({ error: '미션 조회 중 오류가 발생했습니다.' });
  }
});

// 미션 상태 업데이트
router.patch('/:id/status', async (req, res) => {
  try {
    const { id } = req.params;
    const { status } = req.body;
    
    if (!status) {
      return res.status(400).json({ error: '상태는 필수입니다.' });
    }
    
    const mission = await Mission.findById(id);
    if (!mission) {
      return res.status(404).json({ error: '미션을 찾을 수 없습니다.' });
    }

    const oldStatus = mission.status;
    let robot = null;

    // 미션 취소 시 해당 로봇에게 정지 명령 전송
    if (status === 'cancelled' && mission.robot_id) {
      try {
        const Robot = require('../models/Robot');
        const axios = require('axios');
        
        robot = await Robot.findById(mission.robot_id);
        if (robot) {
          
          
          const stopCommand = {
            action: "stop"
          };
          
          const robotApiUrl = `http://${robot.ip_address}:${robot.port || 5001}/api/v1/amr/command`;
          
          try {
            await axios.post(robotApiUrl, stopCommand, { timeout: 3000 });
            
            
            // 로봇 상태 초기화
            await robot.update({
              current_task_id: null,
              current_waypoint_index: 0,
              task_status: 'idle',
              status: 'idle'
            });
            
          } catch (robotError) {
            
          }
        }
      } catch (robotError) {
        
      }
    }
    
    await mission.updateStatus(status);

    // 상태 변경 로그 기록
    if (status === 'in_progress' && oldStatus !== 'in_progress') {
      await ActivityLogService.logMissionStarted(mission, robot);
    } else if (status === 'completed') {
      await ActivityLogService.logMissionCompleted(mission, robot);
    } else if (status === 'failed') {
      await ActivityLogService.logMissionFailed(mission, robot);
    } else if (status === 'cancelled') {
      await ActivityLogService.logMissionCancelled(mission, robot);
    }
    
    res.json({ 
      message: '미션 상태가 업데이트되었습니다.',
      data: mission.toJSON() 
    });
  } catch (error) {
    
    res.status(500).json({ error: '미션 상태 업데이트 중 오류가 발생했습니다.' });
  }
});

// 미션 진행률 업데이트
router.patch('/:id/progress', async (req, res) => {
  try {
    const { id } = req.params;
    const { progress } = req.body;
    
    if (progress === undefined || progress === null) {
      return res.status(400).json({ error: '진행률은 필수입니다.' });
    }
    
    const mission = await Mission.findById(id);
    if (!mission) {
      return res.status(404).json({ error: '미션을 찾을 수 없습니다.' });
    }
    
    await mission.updateProgress(progress);
    
    res.json({ 
      message: '미션 진행률이 업데이트되었습니다.',
      data: mission.toJSON() 
    });
  } catch (error) {
    
    res.status(500).json({ error: '미션 진행률 업데이트 중 오류가 발생했습니다.' });
  }
});

// 미션 삭제
router.delete('/:id', async (req, res) => {
  try {
    const { id } = req.params;
    const mission = await Mission.findById(id);
    
    if (!mission) {
      return res.status(404).json({ error: '미션을 찾을 수 없습니다.' });
    }
    
    await mission.delete();
    
    res.json({ message: '미션이 삭제되었습니다.' });
  } catch (error) {
    
    res.status(500).json({ error: '미션 삭제 중 오류가 발생했습니다.' });
  }
});

module.exports = router; 