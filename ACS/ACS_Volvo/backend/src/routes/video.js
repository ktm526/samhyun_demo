const express = require('express');
const router = express.Router();
const webrtcSignalingService = require('../services/webrtcSignalingService');

// WebRTC 시그널링 서비스 시작
webrtcSignalingService.start();

// WebRTC 설정 정보
router.get('/config', (req, res) => {
  res.json({
    success: true,
    type: 'webrtc',
    signalingPort: webrtcSignalingService.port,
    signalingUrl: `ws://localhost:${webrtcSignalingService.port}`
  });
});

// 활성 방 목록 조회
router.get('/rooms', (req, res) => {
  try {
    const rooms = webrtcSignalingService.getActiveRooms();
    res.json({
      success: true,
      data: rooms,
      signalingPort: webrtcSignalingService.port
    });
  } catch (error) {
    console.error('방 목록 조회 오류:', error);
    res.status(500).json({ success: false, error: error.message });
  }
});

module.exports = router;
