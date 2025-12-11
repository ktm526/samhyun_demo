const express = require('express');
const router = express.Router();
const rtspStreamService = require('../services/rtspStreamService');

// RTSP 서비스 시작
rtspStreamService.start();

// 활성 스트림 목록 조회
router.get('/streams', (req, res) => {
  try {
    const streams = rtspStreamService.getActiveStreams();
    res.json({
      success: true,
      data: streams,
      wsPort: rtspStreamService.port
    });
  } catch (error) {
    console.error('스트림 목록 조회 오류:', error);
    res.status(500).json({ success: false, error: error.message });
  }
});

// WebSocket 포트 정보
router.get('/config', (req, res) => {
  res.json({
    success: true,
    wsPort: rtspStreamService.port,
    wsUrl: `ws://localhost:${rtspStreamService.port}`
  });
});

// 로봇별 카메라 RTSP URL 설정 (실제로는 DB나 설정 파일에서 관리)
// 기본 RTSP URL 형식: rtsp://{robot_ip}:{port}/camera/{direction}
router.get('/robot/:robotId/cameras', async (req, res) => {
  try {
    const { robotId } = req.params;
    const Robot = require('../models/Robot');
    
    const robot = await Robot.findById(robotId);
    if (!robot) {
      return res.status(404).json({ success: false, error: '로봇을 찾을 수 없습니다.' });
    }

    // 로봇 IP 기반으로 RTSP URL 생성 (실제 환경에 맞게 수정 필요)
    const rtspPort = 8554; // 기본 RTSP 포트
    const baseUrl = `rtsp://${robot.ip_address}:${rtspPort}`;

    const cameras = {
      front: `${baseUrl}/front`,
      back: `${baseUrl}/back`,
      left: `${baseUrl}/left`,
      right: `${baseUrl}/right`
    };

    res.json({
      success: true,
      robotId: robot.id,
      robotName: robot.name,
      robotIp: robot.ip_address,
      cameras,
      wsPort: rtspStreamService.port
    });
  } catch (error) {
    console.error('카메라 정보 조회 오류:', error);
    res.status(500).json({ success: false, error: error.message });
  }
});

// 커스텀 RTSP URL로 스트림 테스트
router.post('/test-stream', (req, res) => {
  const { rtspUrl } = req.body;
  
  if (!rtspUrl) {
    return res.status(400).json({ success: false, error: 'RTSP URL이 필요합니다.' });
  }

  res.json({
    success: true,
    message: 'WebSocket을 통해 스트림을 구독하세요.',
    wsPort: rtspStreamService.port,
    wsUrl: `ws://localhost:${rtspStreamService.port}`,
    instructions: {
      subscribe: {
        action: 'subscribe',
        streamId: 'test-stream',
        rtspUrl: rtspUrl
      },
      unsubscribe: {
        action: 'unsubscribe',
        streamId: 'test-stream'
      }
    }
  });
});

module.exports = router;

