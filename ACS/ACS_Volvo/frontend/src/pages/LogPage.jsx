import React, { useState, useEffect, useCallback } from 'react';
import { useRobots } from '../hooks/useRobots';
import { useMissions } from '../hooks/useMissions';
import { logsAPI } from '../services/api';
import TabComponent from '../components/log/TabComponent';
import DashboardTab from '../components/log/DashboardTab';
import LogTab from '../components/log/LogTab';

const LogPage = () => {
  const { robots } = useRobots();
  const { missions } = useMissions();
  const [logs, setLogs] = useState([]);
  const [loading, setLoading] = useState(true);
  const [error, setError] = useState(null);
  const [expandedLogs, setExpandedLogs] = useState(new Set());
  const [activeTab, setActiveTab] = useState('dashboard');
  const [filters, setFilters] = useState({
    level: 'all',
    category: 'all',
    eventType: 'all',
    robot: 'all',
    dateFrom: '',
    dateTo: ''
  });
  
  // 통계 데이터
  const [stats, setStats] = useState({
    totalLogs: 0,
    successCount: 0,
    errorCount: 0,
    warningCount: 0,
    infoCount: 0,
    totalWorkTime: 0,
    totalMissions: 0,
    completedMissions: 0,
    failedMissions: 0,
    moveCommands: 0,
    disconnectionCount: 0
  });
  const [robotWorkTime, setRobotWorkTime] = useState({});
  const [robotTaskCount, setRobotTaskCount] = useState({});
  const [uniqueRobots, setUniqueRobots] = useState([]);

  // 로그 데이터 가져오기
  const fetchLogs = useCallback(async () => {
    try {
      setLoading(true);
      setError(null);

      // 로그 데이터 가져오기
      const logsResponse = await logsAPI.getAll({
        level: filters.level,
        category: filters.category,
        event_type: filters.eventType,
        robot: filters.robot,
        dateFrom: filters.dateFrom,
        dateTo: filters.dateTo,
        limit: 500
      });

      // 날짜 문자열을 Date 객체로 변환
      const logsData = (logsResponse.data || []).map(log => ({
        ...log,
        timestamp: new Date(log.timestamp || log.created_at)
      }));

      setLogs(logsData);
    } catch (err) {
      console.error('로그 조회 오류:', err);
      setError('로그 데이터를 불러오는데 실패했습니다.');
    } finally {
      setLoading(false);
    }
  }, [filters]);

  // 통계 데이터 가져오기
  const fetchStats = useCallback(async () => {
    try {
      const statsResponse = await logsAPI.getStats({
        dateFrom: filters.dateFrom,
        dateTo: filters.dateTo,
        robot_name: filters.robot !== 'all' ? filters.robot : undefined
      });

      if (statsResponse.stats) {
        setStats(statsResponse.stats);
      }
      if (statsResponse.robotWorkTime) {
        setRobotWorkTime(statsResponse.robotWorkTime);
      }
      if (statsResponse.robotTaskCount) {
        setRobotTaskCount(statsResponse.robotTaskCount);
      }
      if (statsResponse.uniqueRobots) {
        setUniqueRobots(statsResponse.uniqueRobots);
      }
    } catch (err) {
      console.error('통계 조회 오류:', err);
    }
  }, [filters.dateFrom, filters.dateTo, filters.robot]);

  // 초기 데이터 로드
  useEffect(() => {
    fetchLogs();
    fetchStats();
  }, [fetchLogs, fetchStats]);

  // 자동 새로고침 (30초마다)
  useEffect(() => {
    const interval = setInterval(() => {
      fetchLogs();
      fetchStats();
    }, 30000);

    return () => clearInterval(interval);
  }, [fetchLogs, fetchStats]);

  const handleFilterChange = (filterType, value) => {
    setFilters(prev => ({ ...prev, [filterType]: value }));
  };

  // 클라이언트 측 필터링 (서버에서 처리되지 않은 경우)
  const filteredLogs = logs;

  const getLevelColor = (level) => {
    switch (level) {
      case 'success': return 'var(--status-success)';
      case 'info': return 'var(--status-info)';
      case 'warning': return 'var(--status-warning)';
      case 'error': return 'var(--status-error)';
      default: return 'var(--text-secondary)';
    }
  };

  const getLevelIcon = (level) => {
    switch (level) {
      case 'success': return 'fas fa-check-circle';
      case 'info': return 'fas fa-info-circle';
      case 'warning': return 'fas fa-exclamation-triangle';
      case 'error': return 'fas fa-times-circle';
      default: return 'fas fa-circle';
    }
  };

  const formatTimestamp = (timestamp) => {
    if (!timestamp) return '-';
    const date = timestamp instanceof Date ? timestamp : new Date(timestamp);
    return date.toLocaleString('ko-KR', {
      year: 'numeric',
      month: '2-digit',
      day: '2-digit',
      hour: '2-digit',
      minute: '2-digit',
      second: '2-digit'
    });
  };

  const formatDuration = (seconds) => {
    if (!seconds) return '-';
    const hours = Math.floor(seconds / 3600);
    const minutes = Math.floor((seconds % 3600) / 60);
    const secs = seconds % 60;
    if (hours > 0) {
      return `${hours}시간 ${minutes}분`;
    }
    if (minutes > 0) {
      return `${minutes}분 ${secs}초`;
    }
    return `${secs}초`;
  };

  const toggleLogExpansion = (logId) => {
    setExpandedLogs(prev => {
      const newSet = new Set(prev);
      if (newSet.has(logId)) {
        newSet.delete(logId);
      } else {
        newSet.add(logId);
      }
      return newSet;
    });
  };

  // 수동 새로고침
  const handleRefresh = () => {
    fetchLogs();
    fetchStats();
  };

  // 탭 설정
  const tabs = [
    { id: 'dashboard', label: '대시보드', icon: 'fas fa-chart-bar' },
    { id: 'logs', label: '로그', icon: 'fas fa-list-alt' }
  ];

  const isMobile = typeof window !== 'undefined' && window.innerWidth <= 768;
  
  return (
    <div style={{
      width: '100%',
      height: '100%',
      padding: isMobile ? 'var(--space-md)' : 'var(--space-xl)',
      backgroundColor: 'var(--bg-primary)',
      color: 'var(--text-primary)',
      fontFamily: 'Pretendard, sans-serif',
      overflow: 'auto'
    }}>
      {/* 에러 상태 */}
      {error && (
        <div className="card" style={{ 
          backgroundColor: 'rgba(239, 71, 111, 0.1)', 
          borderColor: 'var(--status-error)',
          marginBottom: 'var(--space-lg)'
        }}>
          <div style={{ 
            display: 'flex', 
            alignItems: 'center', 
            gap: 'var(--space-md)',
            padding: 'var(--space-md)'
          }}>
            <i className="fas fa-exclamation-circle" style={{ color: 'var(--status-error)', fontSize: '1.5rem' }}></i>
            <div>
              <div style={{ fontWeight: '600', color: 'var(--status-error)' }}>오류 발생</div>
              <div style={{ color: 'var(--text-secondary)' }}>{error}</div>
            </div>
            <button
              onClick={handleRefresh}
              style={{
                marginLeft: 'auto',
                padding: 'var(--space-sm) var(--space-md)',
                backgroundColor: 'var(--primary-color)',
                border: 'none',
                borderRadius: 'var(--radius-md)',
                color: 'white',
                cursor: 'pointer'
              }}
            >
              다시 시도
            </button>
          </div>
        </div>
      )}

      {/* 탭 컴포넌트 */}
      <TabComponent 
        activeTab={activeTab}
        setActiveTab={setActiveTab}
        tabs={tabs}
      />

      {/* 탭 내용 */}
      {activeTab === 'dashboard' && (
        <DashboardTab 
          filters={filters}
          onFilterChange={handleFilterChange}
          uniqueRobots={uniqueRobots}
          stats={stats}
          formatDuration={formatDuration}
          robotWorkTime={robotWorkTime}
          robotTaskCount={robotTaskCount}
        />
      )}

      {activeTab === 'logs' && (
        <LogTab 
          filteredLogs={filteredLogs}
          expandedLogs={expandedLogs}
          onToggleExpansion={toggleLogExpansion}
          getLevelColor={getLevelColor}
          getLevelIcon={getLevelIcon}
          formatDuration={formatDuration}
          filters={filters}
          onFilterChange={handleFilterChange}
          uniqueRobots={uniqueRobots}
        />
      )}

      {/* 로딩 오버레이 */}
      {loading && logs.length === 0 && (
        <div style={{
          position: 'absolute',
          top: 0,
          left: 0,
          right: 0,
          bottom: 0,
          display: 'flex',
          justifyContent: 'center',
          alignItems: 'center',
          backgroundColor: 'rgba(0, 0, 0, 0.3)',
          zIndex: 100
        }}>
          <div style={{ 
            textAlign: 'center',
            padding: 'var(--space-xl)',
            backgroundColor: 'var(--bg-secondary)',
            borderRadius: 'var(--radius-lg)',
            boxShadow: '0 4px 20px rgba(0, 0, 0, 0.3)'
          }}>
            <i className="fas fa-spinner fa-spin" style={{ fontSize: '2rem', color: 'var(--primary-color)' }}></i>
            <p style={{ marginTop: 'var(--space-md)', color: 'var(--text-secondary)' }}>로그 데이터를 불러오는 중...</p>
          </div>
        </div>
      )}
    </div>
  );
};

export default LogPage;
