import React from 'react';

const ActivityLogList = ({ 
  filteredLogs, 
  expandedLogs, 
  onToggleExpansion,
  getLevelColor,
  getLevelIcon,
  formatDuration
}) => {
  // 타임스탬프를 Date 객체로 변환하는 헬퍼 함수
  const parseTimestamp = (timestamp) => {
    if (!timestamp) return new Date();
    if (timestamp instanceof Date) return timestamp;
    return new Date(timestamp);
  };

  // 이벤트 타입 한글 변환
  const getEventTypeLabel = (eventType) => {
    const labels = {
      // 미션 관련
      'mission_created': '미션 생성',
      'mission_started': '미션 시작',
      'mission_completed': '미션 완료',
      'mission_failed': '미션 실패',
      'mission_cancelled': '미션 취소',
      'mission_assigned': '미션 할당',
      
      // 웨이포인트 관련
      'waypoint_started': '웨이포인트 이동',
      'waypoint_arrived': '웨이포인트 도착',
      
      // 로봇 관련
      'robot_created': '로봇 등록',
      'robot_deleted': '로봇 삭제',
      'robot_connected': '로봇 연결',
      'robot_disconnected': '연결 끊김',
      'robot_status_changed': '상태 변경',
      'robot_error': '로봇 오류',
      
      // 배터리 관련
      'battery_low': '배터리 부족',
      'battery_critical': '배터리 위험',
      'charging_started': '충전 시작',
      'charging_completed': '충전 완료',
      
      // 이동 명령 관련
      'move_requested': '이동 요청',
      'move_completed': '이동 완료',
      'move_failed': '이동 실패',
      
      // 네비게이션 관련
      'navigation_error': '네비게이션 오류',
      'path_blocked': '경로 차단',
      
      // 시스템 관련
      'system_started': '시스템 시작',
      'service_started': '서비스 시작',
      'service_stopped': '서비스 중지',
      
      // 기본
      'general': '일반',
      'info': '정보',
      'warning': '경고',
      'error': '오류'
    };
    return labels[eventType] || eventType || '-';
  };

  // 카테고리 한글 변환
  const getCategoryLabel = (category) => {
    const labels = {
      'mission': '미션',
      'robot': '로봇',
      'navigation': '네비게이션',
      'system': '시스템',
      'command': '명령',
      'battery': '배터리'
    };
    return labels[category] || category || '-';
  };

  // 카테고리 색상
  const getCategoryColor = (category) => {
    const colors = {
      'mission': '#3B82F6',
      'robot': '#8B5CF6',
      'navigation': '#10B981',
      'system': '#6B7280',
      'command': '#F59E0B',
      'battery': '#EF4444'
    };
    return colors[category] || '#6B7280';
  };

  // CSV 다운로드 기능
  const handleCsvDownload = () => {
    const csvHeaders = ['시간', '레벨', '카테고리', '이벤트', '로봇', '미션', '메시지', '세부정보', '소요시간'];
    const csvData = filteredLogs.map(log => [
      parseTimestamp(log.timestamp).toLocaleString('ko-KR'),
      log.level,
      getCategoryLabel(log.category),
      getEventTypeLabel(log.eventType),
      log.robotName || '',
      log.missionName || '',
      log.message || '',
      log.details || '',
      log.duration ? `${Math.floor(log.duration / 60)}분 ${log.duration % 60}초` : ''
    ]);
    
    const csvContent = [csvHeaders, ...csvData]
      .map(row => row.map(cell => `"${String(cell).replace(/"/g, '""')}"`).join(','))
      .join('\n');
    
    const BOM = '\uFEFF';
    const blob = new Blob([BOM + csvContent], { type: 'text/csv;charset=utf-8;' });
    const link = document.createElement('a');
    const url = URL.createObjectURL(blob);
    link.setAttribute('href', url);
    link.setAttribute('download', `activity_logs_${new Date().toISOString().split('T')[0]}.csv`);
    link.style.visibility = 'hidden';
    document.body.appendChild(link);
    link.click();
    document.body.removeChild(link);
  };

  return (
    <div className="card">
      <div className="card-header">
        <div className="card-title">
          <i className="fas fa-list-alt"></i>
          활동 로그 ({filteredLogs.length})
        </div>
        <button
          onClick={handleCsvDownload}
          className="control-btn"
          style={{ 
            fontSize: 'var(--font-size-sm)',
            padding: 'var(--space-xs) var(--space-sm)',
            minWidth: 'auto',
            display: 'flex',
            alignItems: 'center',
            gap: 'var(--space-xs)'
          }}
        >
          <i className="fas fa-download"></i>
          CSV 다운로드
        </button>
      </div>
      <div className="card-content">
        <div style={{
          maxHeight: '600px',
          overflowY: 'auto',
          border: '1px solid var(--border-primary)',
          borderRadius: 'var(--radius-lg)'
        }}>
          {filteredLogs.length === 0 ? (
            <div style={{
              textAlign: 'center',
              color: 'var(--text-tertiary)',
              fontSize: 'var(--font-size-lg)',
              padding: 'var(--space-2xl)'
            }}>
              <i className="fas fa-inbox" style={{ fontSize: '3rem', marginBottom: 'var(--space-md)', opacity: 0.5 }}></i>
              <div>로그가 없습니다.</div>
              <div style={{ fontSize: 'var(--font-size-sm)', marginTop: 'var(--space-sm)' }}>
                미션을 생성하거나 로봇을 조작하면 로그가 기록됩니다.
              </div>
            </div>
          ) : (
            filteredLogs.map((log, index) => {
              const isExpanded = expandedLogs.has(log.id);
              const hasDetails = log.details || log.missionName || log.waypointName || log.targetNodeName;
              const levelColor = getLevelColor(log.level);
              
              const rowBgColor = index % 2 === 0 ? 'var(--bg-primary)' : 'var(--bg-secondary)';
              
              return (
                <div 
                  key={log.id}
                  style={{
                    borderLeft: isExpanded ? `4px solid ${levelColor}` : `4px solid ${rowBgColor}`,
                    borderBottom: (!isExpanded && index < filteredLogs.length - 1) ? '1px solid var(--border-primary)' : 'none',
                    backgroundColor: rowBgColor,
                    transition: 'border-left-color 0.2s ease, background-color 0.2s ease'
                  }}
                >
                  {/* 메인 로그 행 */}
                  <div
                    style={{
                      display: 'flex',
                      alignItems: 'center',
                      padding: 'var(--space-md) var(--space-lg)',
                      backgroundColor: isExpanded ? 'rgba(56, 189, 248, 0.08)' : 'transparent',
                      cursor: hasDetails ? 'pointer' : 'default',
                      transition: 'background-color 0.2s ease',
                      minHeight: '60px'
                    }}
                    onClick={() => hasDetails && onToggleExpansion(log.id)}
                    onMouseEnter={(e) => {
                      if (hasDetails) {
                        e.currentTarget.style.backgroundColor = isExpanded ? 'rgba(56, 189, 248, 0.12)' : 'var(--bg-tertiary)';
                      }
                    }}
                    onMouseLeave={(e) => {
                      e.currentTarget.style.backgroundColor = isExpanded ? 'rgba(56, 189, 248, 0.08)' : 'transparent';
                    }}
                  >
                    {/* 시간 */}
                    <div style={{
                      width: '70px',
                      fontSize: 'var(--font-size-sm)',
                      color: 'var(--text-tertiary)',
                      fontFamily: '"Pretendard Variable", "Pretendard", "SF Mono", Monaco, monospace',
                      flexShrink: 0
                    }}>
                      {parseTimestamp(log.timestamp).toLocaleTimeString('ko-KR', { 
                        hour: '2-digit', 
                        minute: '2-digit',
                        second: '2-digit'
                      })}
                    </div>

                    {/* 레벨 */}
                    <div style={{
                      width: '60px',
                      flexShrink: 0,
                      marginRight: 'var(--space-sm)'
                    }}>
                      <span style={{
                        display: 'inline-block',
                        padding: '2px 8px',
                        borderRadius: 'var(--radius-sm)',
                        fontSize: 'var(--font-size-xs)',
                        fontWeight: '600',
                        textTransform: 'uppercase',
                        backgroundColor: getLevelColor(log.level),
                        color: 'white',
                        minWidth: '45px',
                        textAlign: 'center'
                      }}>
                        {log.level === 'success' ? '성공' :
                         log.level === 'error' ? '오류' :
                         log.level === 'warning' ? '경고' : '정보'}
                      </span>
                    </div>

                    {/* 카테고리 */}
                    <div style={{
                      width: '75px',
                      flexShrink: 0,
                      marginRight: 'var(--space-sm)'
                    }}>
                      <span style={{
                        display: 'inline-block',
                        padding: '2px 6px',
                        borderRadius: 'var(--radius-sm)',
                        fontSize: 'var(--font-size-xs)',
                        fontWeight: '500',
                        backgroundColor: `${getCategoryColor(log.category)}20`,
                        color: getCategoryColor(log.category),
                        border: `1px solid ${getCategoryColor(log.category)}40`
                      }}>
                        {getCategoryLabel(log.category)}
                      </span>
                    </div>

                    {/* 이벤트 타입 */}
                    <div style={{
                      width: '100px',
                      fontSize: 'var(--font-size-xs)',
                      color: 'var(--text-secondary)',
                      fontWeight: '500',
                      flexShrink: 0,
                      marginRight: 'var(--space-sm)'
                    }}>
                      {getEventTypeLabel(log.eventType)}
                    </div>

                    {/* 로봇 */}
                    <div style={{
                      width: '80px',
                      fontSize: 'var(--font-size-sm)',
                      color: 'var(--primary-color)',
                      fontWeight: '600',
                      flexShrink: 0,
                      marginRight: 'var(--space-sm)',
                      overflow: 'hidden',
                      textOverflow: 'ellipsis',
                      whiteSpace: 'nowrap'
                    }}>
                      {log.robotName || '-'}
                    </div>

                    {/* 메시지 */}
                    <div style={{
                      flex: 1,
                      fontSize: 'var(--font-size-sm)',
                      color: 'var(--text-primary)',
                      lineHeight: '1.4',
                      paddingRight: 'var(--space-md)',
                      overflow: 'hidden',
                      textOverflow: 'ellipsis',
                      whiteSpace: 'nowrap'
                    }}>
                      {log.message}
                    </div>

                    {/* 소요시간 */}
                    {log.duration && (
                      <div style={{
                        width: '70px',
                        fontSize: 'var(--font-size-xs)',
                        color: 'var(--accent-color)',
                        textAlign: 'right',
                        flexShrink: 0,
                        marginRight: 'var(--space-md)',
                        fontWeight: '500'
                      }}>
                        {formatDuration(log.duration)}
                      </div>
                    )}

                    {/* 확장 표시 */}
                    {hasDetails && (
                      <div style={{
                        width: '20px',
                        display: 'flex',
                        justifyContent: 'center',
                        alignItems: 'center',
                        flexShrink: 0
                      }}>
                        <i 
                          className={`fas fa-chevron-${isExpanded ? 'up' : 'down'}`}
                          style={{
                            fontSize: 'var(--font-size-xs)',
                            color: 'var(--text-tertiary)',
                            transition: 'transform 0.2s ease'
                          }}
                        ></i>
                      </div>
                    )}
                  </div>

                  {/* 확장 상세 정보 */}
                  {hasDetails && isExpanded && (
                    <div style={{
                      padding: 'var(--space-md) var(--space-lg)',
                      backgroundColor: 'rgba(56, 189, 248, 0.05)',
                      position: 'relative'
                    }}>
                      {/* 상세 정보 헤더 - 어떤 로그인지 명확히 표시 */}
                      <div style={{
                        display: 'flex',
                        alignItems: 'center',
                        gap: 'var(--space-sm)',
                        marginBottom: 'var(--space-md)',
                        paddingBottom: 'var(--space-sm)',
                        borderBottom: '1px solid var(--border-secondary)'
                      }}>
                        <i className={getLevelIcon(log.level)} style={{ 
                          color: getLevelColor(log.level),
                          fontSize: 'var(--font-size-base)'
                        }}></i>
                        <span style={{ 
                          fontSize: 'var(--font-size-sm)', 
                          fontWeight: '600',
                          color: getLevelColor(log.level)
                        }}>
                          {getEventTypeLabel(log.eventType)}
                        </span>
                        <span style={{ 
                          fontSize: 'var(--font-size-xs)', 
                          color: 'var(--text-tertiary)',
                          marginLeft: 'auto'
                        }}>
                          {log.robotName && `🤖 ${log.robotName}`}
                          {log.robotName && log.timestamp && ' • '}
                          {parseTimestamp(log.timestamp).toLocaleString('ko-KR')}
                        </span>
                      </div>
                      
                      <div style={{
                        display: 'grid',
                        gridTemplateColumns: 'repeat(auto-fit, minmax(200px, 1fr))',
                        gap: 'var(--space-md)',
                        fontSize: 'var(--font-size-sm)'
                      }}>
                        {/* 상세 내용 */}
                        {log.details && (
                          <div style={{ gridColumn: '1 / -1' }}>
                            <div style={{ color: 'var(--text-tertiary)', fontSize: 'var(--font-size-xs)', marginBottom: '4px' }}>상세 내용</div>
                            <div style={{ color: 'var(--text-primary)' }}>{log.details}</div>
                          </div>
                        )}

                        {/* 미션 정보 */}
                        {log.missionName && (
                          <div>
                            <div style={{ color: 'var(--text-tertiary)', fontSize: 'var(--font-size-xs)', marginBottom: '4px' }}>미션</div>
                            <div style={{ color: 'var(--text-primary)' }}>
                              {log.missionName}
                              {log.missionType && <span style={{ color: 'var(--text-secondary)' }}> ({log.missionType})</span>}
                            </div>
                          </div>
                        )}

                        {/* 웨이포인트 정보 */}
                        {(log.waypointIndex !== undefined && log.waypointIndex !== null) && (
                          <div>
                            <div style={{ color: 'var(--text-tertiary)', fontSize: 'var(--font-size-xs)', marginBottom: '4px' }}>웨이포인트</div>
                            <div style={{ color: 'var(--text-primary)' }}>
                              {log.waypointName || `#${log.waypointIndex + 1}`}
                              {log.waypointTotal && <span style={{ color: 'var(--text-secondary)' }}> ({log.waypointIndex + 1}/{log.waypointTotal})</span>}
                            </div>
                          </div>
                        )}

                        {/* 대상 노드 */}
                        {log.targetNodeName && (
                          <div>
                            <div style={{ color: 'var(--text-tertiary)', fontSize: 'var(--font-size-xs)', marginBottom: '4px' }}>목적지</div>
                            <div style={{ color: 'var(--text-primary)' }}>{log.targetNodeName}</div>
                          </div>
                        )}

                        {/* 좌표 정보 - 실제 값이 있을 때만 표시 */}
                        {(typeof log.targetX === 'number' && typeof log.targetY === 'number' && 
                          !isNaN(log.targetX) && !isNaN(log.targetY) && 
                          (log.targetX !== 0 || log.targetY !== 0)) && (
                          <div>
                            <div style={{ color: 'var(--text-tertiary)', fontSize: 'var(--font-size-xs)', marginBottom: '4px' }}>좌표</div>
                            <div style={{ color: 'var(--text-primary)', fontFamily: 'monospace' }}>
                              ({log.targetX.toFixed(2)}, {log.targetY.toFixed(2)})
                            </div>
                          </div>
                        )}

                        {/* 시작 시간 */}
                        {log.eventStartTime && (
                          <div>
                            <div style={{ color: 'var(--text-tertiary)', fontSize: 'var(--font-size-xs)', marginBottom: '4px' }}>시작 시간</div>
                            <div style={{ color: 'var(--text-primary)' }}>
                              {new Date(log.eventStartTime).toLocaleString('ko-KR')}
                            </div>
                          </div>
                        )}

                        {/* 종료 시간 */}
                        {log.eventEndTime && (
                          <div>
                            <div style={{ color: 'var(--text-tertiary)', fontSize: 'var(--font-size-xs)', marginBottom: '4px' }}>종료 시간</div>
                            <div style={{ color: 'var(--text-primary)' }}>
                              {new Date(log.eventEndTime).toLocaleString('ko-KR')}
                            </div>
                          </div>
                        )}

                        {/* 오류 정보 */}
                        {log.errorMessage && (
                          <div style={{ gridColumn: '1 / -1' }}>
                            <div style={{ color: 'var(--status-error)', fontSize: 'var(--font-size-xs)', marginBottom: '4px' }}>오류</div>
                            <div style={{ color: 'var(--status-error)' }}>
                              {log.errorCode && <span>[{log.errorCode}] </span>}
                              {log.errorMessage}
                            </div>
                          </div>
                        )}

                        {/* 트리거 소스 */}
                        {log.triggerSource && log.triggerSource !== 'system' && (
                          <div>
                            <div style={{ color: 'var(--text-tertiary)', fontSize: 'var(--font-size-xs)', marginBottom: '4px' }}>트리거</div>
                            <div style={{ color: 'var(--text-secondary)' }}>
                              {log.triggerSource === 'manual' ? '수동 조작' : log.triggerSource}
                            </div>
                          </div>
                        )}
                      </div>
                    </div>
                  )}
                </div>
              );
            })
          )}
        </div>
      </div>
    </div>
  );
};

export default ActivityLogList;
