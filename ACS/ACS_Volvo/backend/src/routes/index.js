const express = require('express');
const router = express.Router();

// 라우트 파일들 import
const robotRoutes = require('./robots');
const mapRoutes = require('./maps');
const missionRoutes = require('./missions');
const pcdRoutes = require('./pcd');
const monitoringRoutes = require('./monitoring');
const logsRoutes = require('./logs');
const videoRoutes = require('./video');

// 기본 라우트
router.get('/', (req, res) => {
  res.json({ 
    message: 'AMR 관제 시스템 API가 실행 중입니다.',
    version: '1.0.0',
    endpoints: {
      robots: '/api/robots',
      maps: '/api/maps',
      missions: '/api/missions',
      pcd: '/api/pcd',
      logs: '/api/logs',
      video: '/api/video',
      monitoring: {
        todayLogs: '/api/monitoring/network/today',
        metrics: '/api/monitoring/metrics'
      }
    }
  });
});

// API 라우트 등록
router.use('/robots', robotRoutes);
router.use('/maps', mapRoutes);
router.use('/missions', missionRoutes);
router.use('/pcd', pcdRoutes);
router.use('/monitoring', monitoringRoutes);
router.use('/logs', logsRoutes);
router.use('/video', videoRoutes);

module.exports = router; 