const express = require('express');
const router = express.Router();
const logsController = require('../controllers/logsController');

// 모든 로그 조회 (필터링 포함)
router.get('/', logsController.getLogs);

// 통계 조회
router.get('/stats', logsController.getStats);

// 미션 타임라인 조회 (로그 기반)
router.get('/timeline', logsController.getMissionTimeline);

// 고유 로봇 목록 조회
router.get('/robots', logsController.getUniqueRobots);

// 특정 로그 조회
router.get('/:id', logsController.getLogById);

// 로봇별 로그 조회
router.get('/robot/:robotId', logsController.getLogsByRobot);

// 미션별 로그 조회
router.get('/mission/:missionId', logsController.getLogsByMission);

// 로그 생성
router.post('/', logsController.createLog);

// 오래된 로그 삭제
router.delete('/cleanup', logsController.deleteOldLogs);

module.exports = router;

