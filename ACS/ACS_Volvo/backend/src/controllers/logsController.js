const ActivityLog = require('../models/ActivityLog');

// 모든 로그 조회 (필터링 포함)
const getLogs = async (req, res) => {
  try {
    const {
      level,
      category,
      event_type,
      robot,
      robot_name,
      mission_id,
      dateFrom,
      dateTo,
      limit = 500,
      offset = 0
    } = req.query;

    const options = {
      level,
      category,
      event_type,
      robot_name: robot || robot_name,
      mission_id,
      dateFrom,
      dateTo,
      limit: parseInt(limit),
      offset: parseInt(offset)
    };

    const logs = await ActivityLog.findAll(options);

    res.json({
      data: logs.map(log => log.toJSON()),
      count: logs.length
    });
  } catch (error) {
    console.error('로그 조회 오류:', error);
    res.status(500).json({ error: '로그 조회 중 오류가 발생했습니다.' });
  }
};

// 특정 로그 조회
const getLogById = async (req, res) => {
  try {
    const { id } = req.params;
    const log = await ActivityLog.findById(id);

    if (!log) {
      return res.status(404).json({ error: '로그를 찾을 수 없습니다.' });
    }

    res.json({ data: log.toJSON() });
  } catch (error) {
    console.error('로그 조회 오류:', error);
    res.status(500).json({ error: '로그 조회 중 오류가 발생했습니다.' });
  }
};

// 로봇별 로그 조회
const getLogsByRobot = async (req, res) => {
  try {
    const { robotId } = req.params;
    const { limit = 100 } = req.query;

    const logs = await ActivityLog.findByRobotId(robotId, parseInt(limit));

    res.json({
      data: logs.map(log => log.toJSON()),
      count: logs.length
    });
  } catch (error) {
    console.error('로봇 로그 조회 오류:', error);
    res.status(500).json({ error: '로봇 로그 조회 중 오류가 발생했습니다.' });
  }
};

// 미션별 로그 조회
const getLogsByMission = async (req, res) => {
  try {
    const { missionId } = req.params;

    const logs = await ActivityLog.findByMissionId(missionId);

    res.json({
      data: logs.map(log => log.toJSON()),
      count: logs.length
    });
  } catch (error) {
    console.error('미션 로그 조회 오류:', error);
    res.status(500).json({ error: '미션 로그 조회 중 오류가 발생했습니다.' });
  }
};

// 로그 생성
const createLog = async (req, res) => {
  try {
    const {
      level,
      category,
      robot_id,
      robot_name,
      mission_id,
      message,
      details,
      duration,
      metadata
    } = req.body;

    if (!message) {
      return res.status(400).json({ error: '메시지는 필수입니다.' });
    }

    const log = await ActivityLog.create({
      level,
      category,
      robot_id,
      robot_name,
      mission_id,
      message,
      details,
      duration,
      metadata
    });

    res.status(201).json({
      message: '로그가 생성되었습니다.',
      data: log.toJSON()
    });
  } catch (error) {
    console.error('로그 생성 오류:', error);
    res.status(500).json({ error: '로그 생성 중 오류가 발생했습니다.' });
  }
};

// 통계 조회
const getStats = async (req, res) => {
  try {
    const { dateFrom, dateTo, robot_name } = req.query;

    const options = { dateFrom, dateTo, robot_name };

    const [stats, robotWorkTime, robotTaskCount, eventTypeStats, hourlyStats, uniqueRobots] = await Promise.all([
      ActivityLog.getStats(options),
      ActivityLog.getRobotWorkTime(options),
      ActivityLog.getRobotTaskCount(options),
      ActivityLog.getEventTypeStats(options),
      ActivityLog.getHourlyStats({ date: dateFrom }),
      ActivityLog.getUniqueRobots()
    ]);

    // robotWorkTime을 기존 형식으로 변환 (로봇명: 작업시간(초))
    const workTimeMap = {};
    const workTimeDetails = {};
    Object.entries(robotWorkTime).forEach(([robotName, data]) => {
      workTimeMap[robotName] = data.workTime;
      workTimeDetails[robotName] = data;
    });

    // robotTaskCount를 기존 형식으로 변환 (로봇명: 건수)
    const taskCountMap = {};
    const taskCountDetails = {};
    Object.entries(robotTaskCount).forEach(([robotName, data]) => {
      taskCountMap[robotName] = data.total;
      taskCountDetails[robotName] = data;
    });

    res.json({
      stats,
      robotWorkTime: workTimeMap,
      robotWorkTimeDetails: workTimeDetails,
      robotTaskCount: taskCountMap,
      robotTaskCountDetails: taskCountDetails,
      eventTypeStats,
      hourlyStats,
      uniqueRobots
    });
  } catch (error) {
    console.error('통계 조회 오류:', error);
    res.status(500).json({ error: '통계 조회 중 오류가 발생했습니다.' });
  }
};

// 고유 로봇 목록 조회
const getUniqueRobots = async (req, res) => {
  try {
    const uniqueRobots = await ActivityLog.getUniqueRobots();

    res.json({ data: uniqueRobots });
  } catch (error) {
    console.error('로봇 목록 조회 오류:', error);
    res.status(500).json({ error: '로봇 목록 조회 중 오류가 발생했습니다.' });
  }
};

// 오래된 로그 삭제
const deleteOldLogs = async (req, res) => {
  try {
    const { daysOld = 30 } = req.query;

    const deletedCount = await ActivityLog.deleteOldLogs(parseInt(daysOld));

    res.json({
      message: `${deletedCount}개의 오래된 로그가 삭제되었습니다.`,
      deletedCount
    });
  } catch (error) {
    console.error('로그 삭제 오류:', error);
    res.status(500).json({ error: '로그 삭제 중 오류가 발생했습니다.' });
  }
};

// 미션 타임라인 조회 (로그 기반)
const getMissionTimeline = async (req, res) => {
  try {
    const { dateFrom, dateTo, robot_name } = req.query;
    
    const options = { dateFrom, dateTo, robot_name };
    const timeline = await ActivityLog.getMissionTimeline(options);
    
    res.json({
      data: timeline,
      count: timeline.length
    });
  } catch (error) {
    console.error('미션 타임라인 조회 오류:', error);
    res.status(500).json({ error: '미션 타임라인 조회 중 오류가 발생했습니다.' });
  }
};

module.exports = {
  getLogs,
  getLogById,
  getLogsByRobot,
  getLogsByMission,
  createLog,
  getStats,
  getUniqueRobots,
  deleteOldLogs,
  getMissionTimeline
};

