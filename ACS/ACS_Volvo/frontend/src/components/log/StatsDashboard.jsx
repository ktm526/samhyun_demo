import React from 'react';

const StatsDashboard = ({ stats, formatDuration }) => {
  const statCards = [
    {
      id: 'total',
      title: '총 로그',
      value: stats.totalLogs || 0,
      icon: 'fas fa-list',
      color: 'var(--status-info)'
    },
    {
      id: 'success',
      title: '성공',
      value: stats.successCount || 0,
      icon: 'fas fa-check-circle',
      color: 'var(--status-success)'
    },
    {
      id: 'error',
      title: '오류',
      value: stats.errorCount || 0,
      icon: 'fas fa-times-circle',
      color: 'var(--status-error)'
    },
    {
      id: 'workTime',
      title: '총 작업시간',
      value: formatDuration(stats.totalWorkTime || 0),
      icon: 'fas fa-clock',
      color: 'var(--primary-color)'
    }
  ];

  // 추가 통계 (있는 경우)
  const additionalStats = [];
  
  if (stats.completedMissions !== undefined) {
    additionalStats.push({
      id: 'missions',
      title: '완료된 미션',
      value: stats.completedMissions || 0,
      subValue: stats.failedMissions ? `실패: ${stats.failedMissions}` : null,
      icon: 'fas fa-tasks',
      color: '#3B82F6'
    });
  }

  if (stats.moveCommands !== undefined) {
    additionalStats.push({
      id: 'moves',
      title: '이동 명령',
      value: stats.moveCommands || 0,
      icon: 'fas fa-route',
      color: '#10B981'
    });
  }

  if (stats.disconnectionCount !== undefined && stats.disconnectionCount > 0) {
    additionalStats.push({
      id: 'disconnections',
      title: '연결 끊김',
      value: stats.disconnectionCount || 0,
      icon: 'fas fa-unlink',
      color: '#EF4444'
    });
  }

  return (
    <div style={{ display: 'flex', flexDirection: 'column', gap: 'var(--space-md)' }}>
      {/* 메인 통계 2x2 그리드 */}
      <div style={{ 
        display: 'grid', 
        gridTemplateColumns: 'repeat(2, 1fr)', 
        gap: 'var(--space-md)' 
      }}>
        {statCards.map(card => (
          <div key={card.id} className="card" style={{ padding: 'var(--space-md)' }}>
            <div style={{ display: 'flex', alignItems: 'center', gap: 'var(--space-md)' }}>
              <div style={{ 
                padding: 'var(--space-sm)', 
                backgroundColor: `${card.color}20`, 
                borderRadius: 'var(--radius-md)',
                color: card.color,
                display: 'flex',
                alignItems: 'center',
                justifyContent: 'center',
                width: '40px',
                height: '40px'
              }}>
                <i className={card.icon} style={{ fontSize: 'var(--font-size-lg)' }}></i>
              </div>
              <div>
                <div style={{ fontSize: 'var(--font-size-xl)', fontWeight: '700' }}>
                  {card.value}
                </div>
                <div style={{ fontSize: 'var(--font-size-xs)', color: 'var(--text-tertiary)' }}>
                  {card.title}
                </div>
              </div>
            </div>
          </div>
        ))}
      </div>

      {/* 추가 통계 (데이터가 있는 경우에만) */}
      {additionalStats.length > 0 && (
        <div style={{ 
          display: 'grid', 
          gridTemplateColumns: `repeat(${Math.min(additionalStats.length, 3)}, 1fr)`, 
          gap: 'var(--space-sm)' 
        }}>
          {additionalStats.map(card => (
            <div 
              key={card.id} 
              style={{ 
                padding: 'var(--space-sm) var(--space-md)',
                backgroundColor: 'var(--bg-secondary)',
                borderRadius: 'var(--radius-md)',
                border: '1px solid var(--border-primary)',
                display: 'flex',
                alignItems: 'center',
                gap: 'var(--space-sm)'
              }}
            >
              <i className={card.icon} style={{ color: card.color, fontSize: 'var(--font-size-sm)' }}></i>
              <div>
                <div style={{ fontSize: 'var(--font-size-sm)', fontWeight: '600' }}>
                  {card.value}
                  {card.subValue && (
                    <span style={{ fontSize: 'var(--font-size-xs)', color: 'var(--text-tertiary)', marginLeft: 'var(--space-xs)' }}>
                      ({card.subValue})
                    </span>
                  )}
                </div>
                <div style={{ fontSize: 'var(--font-size-xs)', color: 'var(--text-tertiary)' }}>
                  {card.title}
                </div>
              </div>
            </div>
          ))}
        </div>
      )}

      {/* 데이터 없음 안내 */}
      {stats.totalLogs === 0 && (
        <div style={{
          textAlign: 'center',
          padding: 'var(--space-lg)',
          color: 'var(--text-tertiary)',
          fontSize: 'var(--font-size-sm)'
        }}>
          <i className="fas fa-chart-bar" style={{ fontSize: '2rem', marginBottom: 'var(--space-sm)', opacity: 0.5, display: 'block' }}></i>
          아직 기록된 로그가 없습니다.
        </div>
      )}
    </div>
  );
};

export default StatsDashboard;
