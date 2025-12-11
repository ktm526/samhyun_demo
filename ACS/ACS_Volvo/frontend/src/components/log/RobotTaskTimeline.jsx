import React, { useState, useRef, useEffect, useCallback } from 'react';
import { getStatusColor, getStatusIcon } from '../../constants';
import { logsAPI } from '../../services/api';

const RobotTaskTimeline = () => {
  const [timelineData, setTimelineData] = useState([]);
  const [loading, setLoading] = useState(true);
  const [timeRange, setTimeRange] = useState('6h');
  const [customStartTime, setCustomStartTime] = useState('');
  const [customEndTime, setCustomEndTime] = useState('');
  const [isExpanded, setIsExpanded] = useState(true);
  const [selectedTask, setSelectedTask] = useState(null);
  const timelineContainerRef = useRef(null);
  const timelineMainRef = useRef(null);

  // 타임라인 데이터 가져오기 (로그 기반)
  const fetchTimeline = useCallback(async () => {
    try {
      setLoading(true);
      const filters = {};
      
      // 시간 범위에 따른 필터 설정
      const now = new Date();
      switch (timeRange) {
        case '1h':
          filters.dateFrom = new Date(now.getTime() - 1 * 60 * 60 * 1000).toISOString().split('T')[0];
          break;
        case '3h':
          filters.dateFrom = new Date(now.getTime() - 3 * 60 * 60 * 1000).toISOString().split('T')[0];
          break;
        case '6h':
          filters.dateFrom = new Date(now.getTime() - 6 * 60 * 60 * 1000).toISOString().split('T')[0];
          break;
        case '12h':
          filters.dateFrom = new Date(now.getTime() - 12 * 60 * 60 * 1000).toISOString().split('T')[0];
          break;
        case 'custom':
          if (customStartTime) filters.dateFrom = customStartTime.split('T')[0];
          if (customEndTime) filters.dateTo = customEndTime.split('T')[0];
          break;
      }

      const response = await logsAPI.getTimeline(filters);
      setTimelineData(response.data || []);
    } catch (error) {
      console.error('타임라인 데이터 조회 오류:', error);
      setTimelineData([]);
    } finally {
      setLoading(false);
    }
  }, [timeRange, customStartTime, customEndTime]);

  useEffect(() => {
    fetchTimeline();
    // 30초마다 새로고침
    const interval = setInterval(fetchTimeline, 30000);
    return () => clearInterval(interval);
  }, [fetchTimeline]);

  // 로그 데이터를 타임라인 형식으로 변환
  const convertToTasks = () => {
    if (!timelineData || timelineData.length === 0) return [];

    return timelineData.map(item => {
      const startTime = item.startTime ? new Date(item.startTime) : new Date();
      let endTime;
      
      if (item.endTime) {
        endTime = new Date(item.endTime);
      } else if (item.status === 'in_progress') {
        endTime = new Date(); // 진행 중인 경우 현재 시간
      } else {
        endTime = new Date(startTime.getTime() + 30 * 60 * 1000); // 기본 30분
      }

      // 상태 매핑
      let taskStatus;
      switch (item.status) {
        case 'completed':
          taskStatus = 'completed';
          break;
        case 'in_progress':
          taskStatus = 'in-progress';
          break;
        case 'failed':
        case 'cancelled':
          taskStatus = 'blocked';
          break;
        default:
          taskStatus = 'not-started';
      }

      return {
        id: `log-${item.missionId}`,
        title: item.missionName || `미션 ${item.missionId}`,
        robotId: item.robotName || '알 수 없음',
        status: taskStatus,
        startTime: startTime,
        endTime: endTime,
        assignee: item.robotName,
        category: item.missionType || 'transport',
        progress: item.status === 'completed' ? 100 : (item.status === 'in_progress' ? 50 : 0),
        description: `${item.missionType || ''} 미션 ${item.duration ? `(${Math.floor(item.duration / 60)}분 ${item.duration % 60}초)` : ''}`
      };
    }).filter(task => task.robotId !== '알 수 없음');
  };

  const tasks = convertToTasks();

  // 시간 범위 계산
  const getTimeRange = () => {
    const now = new Date();
    let startTime, endTime;

    switch (timeRange) {
      case '1h':
        startTime = new Date(now.getTime() - 1 * 60 * 60 * 1000);
        endTime = now;
        break;
      case '3h':
        startTime = new Date(now.getTime() - 3 * 60 * 60 * 1000);
        endTime = now;
        break;
      case '6h':
        startTime = new Date(now.getTime() - 6 * 60 * 60 * 1000);
        endTime = now;
        break;
      case '12h':
        startTime = new Date(now.getTime() - 12 * 60 * 60 * 1000);
        endTime = now;
        break;
      case 'custom':
        if (customStartTime && customEndTime) {
          startTime = new Date(customStartTime);
          endTime = new Date(customEndTime);
        } else {
          startTime = new Date(now.getTime() - 6 * 60 * 60 * 1000);
          endTime = now;
        }
        break;
      default:
        startTime = new Date(now.getTime() - 6 * 60 * 60 * 1000);
        endTime = now;
    }

    return { startTime, endTime };
  };

  const { startTime, endTime } = getTimeRange();
  const totalDuration = endTime - startTime;
  const timelineWidth = Math.max(800, totalDuration / (1000 * 60) * 2);

  // 시간 범위 내의 태스크만 필터링
  const filteredTasks = tasks.filter(task => {
    return task.endTime >= startTime && task.startTime <= endTime;
  });

  // 로봇별 태스크 그룹화
  const robotGroups = filteredTasks.reduce((groups, task) => {
    if (!groups[task.robotId]) {
      groups[task.robotId] = [];
    }
    groups[task.robotId].push(task);
    return groups;
  }, {});

  // 시간을 픽셀로 변환
  const timeToPixel = (time) => {
    const ratio = (time - startTime) / totalDuration;
    return ratio * timelineWidth;
  };

  // 시간 눈금 생성
  const generateTimeMarks = () => {
    const marks = [];
    const currentTime = new Date(startTime);
    const durationInDays = (endTime - startTime) / (24 * 60 * 60 * 1000);
    
    // 일주일 이상이면 날짜+시간, 아니면 시간만
    const showDate = durationInDays >= 7;
    
    if (showDate) {
      // 일주일 이상: 12시간 간격으로 표시 (날짜 포함)
      currentTime.setHours(0, 0, 0, 0); // 자정으로 맞춤
      while (currentTime <= endTime) {
        if (currentTime >= startTime) {
          const isNewDay = currentTime.getHours() === 0;
          marks.push({
            time: new Date(currentTime),
            position: timeToPixel(currentTime),
            label: isNewDay 
              ? currentTime.toLocaleDateString('ko-KR', { 
                  month: 'short', 
                  day: 'numeric' 
                }) + ' ' + currentTime.toLocaleTimeString('ko-KR', { 
                  hour: '2-digit', 
                  minute: '2-digit',
                  hour12: false 
                })
              : currentTime.toLocaleTimeString('ko-KR', { 
                  hour: '2-digit', 
                  minute: '2-digit',
                  hour12: false 
                })
          });
        }
        currentTime.setHours(currentTime.getHours() + 12);
      }
    } else {
      // 일주일 미만: 1시간 간격으로 표시 (시간만)
      currentTime.setMinutes(0, 0, 0); // 정시로 맞춤
      while (currentTime <= endTime) {
        if (currentTime >= startTime) {
          marks.push({
            time: new Date(currentTime),
            position: timeToPixel(currentTime),
            label: currentTime.toLocaleTimeString('ko-KR', { 
              hour: '2-digit', 
              minute: '2-digit',
              hour12: false 
            })
          });
        }
        currentTime.setHours(currentTime.getHours() + 1);
      }
    }
    
    return marks;
  };

  const timeMarks = generateTimeMarks();

  const handleScroll = (e) => {
    const scrollLeft = e.target.scrollLeft;
    const containers = document.querySelectorAll('.timeline-scroll');
    
    containers.forEach(container => {
      if (container !== e.target) {
        container.scrollLeft = scrollLeft;
      }
    });
  };

  const smoothScrollTo = (targetScroll) => {
    const containers = document.querySelectorAll('.timeline-scroll');
    
    containers.forEach(container => {
      container.scrollTo({
        left: targetScroll,
        behavior: 'smooth'
      });
    });
  };

  // 로딩 상태
  if (loading && timelineData.length === 0) {
    return (
      <div className="card">
        <div className="card-header">
          <div className="card-title">
            <i className="fas fa-tasks"></i>
            로봇 태스크 타임라인
          </div>
        </div>
        <div className="card-content" style={{ textAlign: 'center', padding: 'var(--space-xl)' }}>
          <i className="fas fa-spinner fa-spin" style={{ fontSize: '1.5rem', color: 'var(--primary-color)' }}></i>
          <p style={{ marginTop: 'var(--space-md)', color: 'var(--text-tertiary)' }}>데이터를 불러오는 중...</p>
        </div>
      </div>
    );
  }

  return (
    <div className="card">
      <div className="card-header" style={{ display: 'flex', justifyContent: 'space-between', alignItems: 'center' }}>
        <div className="card-title">
          <i className="fas fa-tasks"></i>
          로봇 태스크 타임라인
          {filteredTasks.length > 0 && (
            <span style={{ 
              fontSize: 'var(--font-size-xs)', 
              color: 'var(--text-tertiary)', 
              marginLeft: 'var(--space-sm)',
              fontWeight: 'normal'
            }}>
              ({filteredTasks.length}개 태스크)
            </span>
          )}
        </div>
        
        <button
          onClick={() => setIsExpanded(!isExpanded)}
          style={{
            padding: 'var(--space-xs)',
            backgroundColor: 'transparent',
            border: 'none',
            borderRadius: 'var(--radius-sm)',
            color: 'var(--text-secondary)',
            cursor: 'pointer',
            fontSize: 'var(--font-size-sm)',
            transition: 'all 0.2s ease',
            display: 'flex',
            alignItems: 'center',
            justifyContent: 'center',
            width: '32px',
            height: '32px'
          }}
          onMouseEnter={(e) => {
            e.currentTarget.style.color = 'var(--primary-color)';
            e.currentTarget.style.backgroundColor = 'var(--bg-secondary)';
          }}
          onMouseLeave={(e) => {
            e.currentTarget.style.color = 'var(--text-secondary)';
            e.currentTarget.style.backgroundColor = 'transparent';
          }}
        >
          <i className={`fas ${isExpanded ? 'fa-chevron-up' : 'fa-chevron-down'}`}></i>
        </button>
      </div>

      <div 
        className="card-content"
        style={{
          maxHeight: isExpanded ? '1000px' : '0',
          opacity: isExpanded ? 1 : 0,
          overflow: 'hidden',
          transition: 'max-height 0.3s ease-out, opacity 0.3s ease-out, padding 0.3s ease-out',
          padding: isExpanded ? 'var(--space-lg)' : '0'
        }}
      >
        {/* 컨트롤 패널 */}
        {isExpanded && (
          <div style={{ 
            display: 'flex', 
            gap: 'var(--space-sm)', 
            alignItems: 'center',
            justifyContent: 'flex-end',
            flexWrap: 'wrap',
            marginBottom: 'var(--space-md)'
          }}>
          {/* 시간 범위 선택 */}
          <select
            value={timeRange}
            onChange={(e) => setTimeRange(e.target.value)}
            style={{
              padding: 'var(--space-xs) var(--space-sm)',
              backgroundColor: 'var(--bg-secondary)',
              border: '1px solid var(--border-primary)',
              borderRadius: 'var(--radius-sm)',
              color: 'var(--text-primary)',
              fontSize: 'var(--font-size-xs)'
            }}
          >
            <option value="1h">1시간</option>
            <option value="3h">3시간</option>
            <option value="6h">6시간</option>
            <option value="12h">12시간</option>
            <option value="custom">사용자 지정</option>
          </select>

          {/* 사용자 정의 시간 */}
          {timeRange === 'custom' && (
            <>
              <input
                type="datetime-local"
                value={customStartTime}
                onChange={(e) => setCustomStartTime(e.target.value)}
                style={{
                  padding: 'var(--space-xs)',
                  backgroundColor: 'var(--bg-secondary)',
                  border: '1px solid var(--border-primary)',
                  borderRadius: 'var(--radius-sm)',
                  color: 'var(--text-primary)',
                  fontSize: 'var(--font-size-xs)'
                }}
              />
              <span style={{ fontSize: 'var(--font-size-xs)', color: 'var(--text-tertiary)' }}>~</span>
              <input
                type="datetime-local"
                value={customEndTime}
                onChange={(e) => setCustomEndTime(e.target.value)}
                style={{
                  padding: 'var(--space-xs)',
                  backgroundColor: 'var(--bg-secondary)',
                  border: '1px solid var(--border-primary)',
                  borderRadius: 'var(--radius-sm)',
                  color: 'var(--text-primary)',
                  fontSize: 'var(--font-size-xs)'
                }}
              />
            </>
          )}
        </div>
        )}

        {Object.keys(robotGroups).length === 0 ? (
          <div style={{ textAlign: 'center', color: 'var(--text-tertiary)', fontSize: 'var(--font-size-sm)', padding: 'var(--space-xl)' }}>
            {timelineData.length === 0 
              ? '로그에 기록된 미션이 없습니다. 미션을 실행해주세요.'
              : '선택된 시간 범위에 태스크가 없습니다.'}
          </div>
        ) : (
          <div 
            ref={timelineMainRef}
            style={{ 
              border: '1px solid var(--border-primary)',
              borderRadius: 'var(--radius-md)',
              overflow: 'hidden'
            }}
          >
            {/* 시간 헤더 */}
            <div 
              style={{
                height: '40px',
                backgroundColor: 'var(--bg-secondary)',
                borderBottom: '2px solid var(--border-primary)',
                position: 'sticky',
                top: 0,
                zIndex: 10,
                display: 'flex'
              }}
            >
              {/* 로봇 이름 컬럼 헤더 */}
              <div style={{
                width: '120px',
                padding: 'var(--space-sm)',
                borderRight: '1px solid var(--border-primary)',
                fontWeight: '600',
                color: 'var(--text-primary)',
                display: 'flex',
                alignItems: 'center',
                backgroundColor: 'var(--bg-secondary)'
              }}>
                로봇
              </div>
              
              {/* 스크롤 가능한 시간 헤더 */}
              <div 
                ref={timelineContainerRef}
                className="timeline-scroll"
                style={{
                  flex: 1,
                  overflowX: 'auto',
                  overflowY: 'hidden',
                  scrollbarWidth: 'thin'
                }}
                onScroll={handleScroll}
              >
                <div style={{
                  width: `${timelineWidth}px`,
                  height: '100%',
                  position: 'relative',
                  backgroundColor: 'var(--bg-secondary)'
                }}>
                  {timeMarks.map((mark, index) => (
                    <div
                      key={index}
                      style={{
                        position: 'absolute',
                        left: `${mark.position}px`,
                        top: 0,
                        height: '100%',
                        borderLeft: index === 0 ? 'none' : '1px solid var(--border-primary)',
                        display: 'flex',
                        alignItems: 'center',
                        paddingLeft: 'var(--space-xs)',
                        fontSize: 'var(--font-size-xs)',
                        color: 'var(--text-secondary)',
                        fontWeight: '500'
                      }}
                    >
                      {mark.label}
                    </div>
                  ))}
                </div>
              </div>
            </div>

            {/* 로봇별 태스크 레인 */}
            <div 
              style={{
                maxHeight: '400px',
                overflowY: 'auto'
              }}
            >
              {Object.entries(robotGroups).map(([robotId, robotTasks], robotIndex) => (
                <div
                  key={robotId}
                  style={{
                    height: '60px',
                    display: 'flex',
                    borderBottom: '1px solid var(--border-primary)',
                    backgroundColor: robotIndex % 2 === 0 ? 'var(--bg-primary)' : 'var(--bg-secondary)'
                  }}
                >
                  {/* 로봇 이름 */}
                  <div style={{
                    width: '120px',
                    padding: 'var(--space-sm)',
                    borderRight: '1px solid var(--border-primary)',
                    display: 'flex',
                    alignItems: 'center',
                    backgroundColor: 'inherit'
                  }}>
                    <div>
                      <div style={{
                        fontSize: 'var(--font-size-sm)',
                        fontWeight: '600',
                        color: 'var(--primary-color)',
                        marginBottom: '2px'
                      }}>
                        {robotId}
                      </div>
                      <div style={{
                        fontSize: 'var(--font-size-xs)',
                        color: 'var(--text-tertiary)'
                      }}>
                        {robotTasks.length}개 태스크
                      </div>
                    </div>
                  </div>

                  {/* 태스크 타임라인 */}
                  <div 
                    className="timeline-scroll"
                    style={{
                      flex: 1,
                      overflowX: 'auto',
                      overflowY: 'hidden',
                      scrollbarWidth: 'thin'
                    }}
                    onScroll={handleScroll}
                  >
                    <div style={{
                      width: `${timelineWidth}px`,
                      height: '100%',
                      position: 'relative',
                      backgroundColor: 'inherit'
                    }}>
                      {robotTasks.map((task) => {
                        const taskStartTime = Math.max(task.startTime.getTime(), startTime.getTime());
                        const taskEndTime = Math.min(task.endTime.getTime(), endTime.getTime());
                        const startPos = timeToPixel(new Date(taskStartTime));
                        const endPos = timeToPixel(new Date(taskEndTime));
                        const width = Math.max(20, endPos - startPos);
                        
                        return (
                          <div
                            key={task.id}
                            onClick={() => setSelectedTask(task)}
                            style={{
                              position: 'absolute',
                              left: `${startPos}px`,
                              top: '10px',
                              width: `${width}px`,
                              height: '40px',
                              backgroundColor: getStatusColor(task.status),
                              borderRadius: 'var(--radius-sm)',
                              display: 'flex',
                              alignItems: 'center',
                              padding: '0 var(--space-sm)',
                              fontSize: 'var(--font-size-xs)',
                              color: 'white',
                              fontWeight: '500',
                              cursor: 'pointer',
                              boxShadow: selectedTask?.id === task.id ? '0 0 0 2px var(--primary-color)' : '0 2px 4px rgba(0,0,0,0.1)',
                              overflow: 'hidden',
                              whiteSpace: 'nowrap',
                              textOverflow: 'ellipsis',
                              transition: 'all 0.2s ease',
                              border: selectedTask?.id === task.id ? '2px solid white' : 'none'
                            }}
                            onMouseEnter={(e) => {
                              e.currentTarget.style.transform = 'translateY(-2px)';
                              e.currentTarget.style.boxShadow = selectedTask?.id === task.id 
                                ? '0 0 0 2px var(--primary-color), 0 4px 8px rgba(0,0,0,0.2)' 
                                : '0 4px 8px rgba(0,0,0,0.2)';
                            }}
                            onMouseLeave={(e) => {
                              e.currentTarget.style.transform = 'translateY(0)';
                              e.currentTarget.style.boxShadow = selectedTask?.id === task.id 
                                ? '0 0 0 2px var(--primary-color)' 
                                : '0 2px 4px rgba(0,0,0,0.1)';
                            }}
                          >
                            <div style={{ display: 'flex', alignItems: 'center', gap: '4px' }}>
                              <i className={getStatusIcon(task.status)}></i>
                              <span>{width > 80 ? task.title : task.title.substring(0, 10) + '...'}</span>
                            </div>
                          </div>
                        );
                      })}
                    </div>
                  </div>
                </div>
              ))}
            </div>
          </div>
        )}
        
        {/* 선택된 작업 상세 정보 */}
        {isExpanded && selectedTask && (
          <div style={{
            marginTop: 'var(--space-md)',
            padding: 'var(--space-md)',
            backgroundColor: 'var(--bg-secondary)',
            borderRadius: 'var(--radius-md)',
            border: `2px solid ${getStatusColor(selectedTask.status)}`,
            position: 'relative'
          }}>
            {/* 닫기 버튼 */}
            <button
              onClick={() => setSelectedTask(null)}
              style={{
                position: 'absolute',
                top: 'var(--space-sm)',
                right: 'var(--space-sm)',
                background: 'transparent',
                border: 'none',
                color: 'var(--text-tertiary)',
                cursor: 'pointer',
                fontSize: 'var(--font-size-base)',
                padding: '4px',
                borderRadius: 'var(--radius-sm)',
                transition: 'all 0.2s ease'
              }}
              onMouseEnter={(e) => {
                e.currentTarget.style.color = 'var(--text-primary)';
                e.currentTarget.style.backgroundColor = 'var(--bg-tertiary)';
              }}
              onMouseLeave={(e) => {
                e.currentTarget.style.color = 'var(--text-tertiary)';
                e.currentTarget.style.backgroundColor = 'transparent';
              }}
            >
              <i className="fas fa-times"></i>
            </button>

            {/* 헤더 */}
            <div style={{
              display: 'flex',
              alignItems: 'center',
              gap: 'var(--space-sm)',
              marginBottom: 'var(--space-md)',
              paddingBottom: 'var(--space-sm)',
              borderBottom: '1px solid var(--border-primary)'
            }}>
              <div style={{
                width: '32px',
                height: '32px',
                borderRadius: 'var(--radius-sm)',
                backgroundColor: getStatusColor(selectedTask.status),
                display: 'flex',
                alignItems: 'center',
                justifyContent: 'center',
                color: 'white'
              }}>
                <i className={getStatusIcon(selectedTask.status)}></i>
              </div>
              <div>
                <div style={{ fontSize: 'var(--font-size-base)', fontWeight: '600', color: 'var(--text-primary)' }}>
                  {selectedTask.title}
                </div>
                <div style={{ fontSize: 'var(--font-size-xs)', color: 'var(--text-tertiary)' }}>
                  {selectedTask.category} 미션
                </div>
              </div>
            </div>

            {/* 상세 정보 그리드 */}
            <div style={{
              display: 'grid',
              gridTemplateColumns: 'repeat(auto-fit, minmax(150px, 1fr))',
              gap: 'var(--space-md)',
              fontSize: 'var(--font-size-sm)'
            }}>
              <div>
                <div style={{ color: 'var(--text-tertiary)', fontSize: 'var(--font-size-xs)', marginBottom: '2px' }}>로봇</div>
                <div style={{ color: 'var(--primary-color)', fontWeight: '600' }}>{selectedTask.robotId}</div>
              </div>
              <div>
                <div style={{ color: 'var(--text-tertiary)', fontSize: 'var(--font-size-xs)', marginBottom: '2px' }}>상태</div>
                <div style={{ 
                  display: 'inline-flex',
                  alignItems: 'center',
                  gap: '4px',
                  padding: '2px 8px',
                  borderRadius: 'var(--radius-sm)',
                  backgroundColor: `${getStatusColor(selectedTask.status)}20`,
                  color: getStatusColor(selectedTask.status),
                  fontWeight: '500'
                }}>
                  <i className={getStatusIcon(selectedTask.status)} style={{ fontSize: '10px' }}></i>
                  {selectedTask.status === 'completed' ? '완료' : 
                   selectedTask.status === 'in-progress' ? '진행중' :
                   selectedTask.status === 'blocked' ? '실패/취소' : '대기'}
                </div>
              </div>
              <div>
                <div style={{ color: 'var(--text-tertiary)', fontSize: 'var(--font-size-xs)', marginBottom: '2px' }}>시작 시간</div>
                <div style={{ color: 'var(--text-primary)' }}>
                  {selectedTask.startTime.toLocaleString('ko-KR', {
                    month: 'short',
                    day: 'numeric',
                    hour: '2-digit',
                    minute: '2-digit',
                    second: '2-digit'
                  })}
                </div>
              </div>
              <div>
                <div style={{ color: 'var(--text-tertiary)', fontSize: 'var(--font-size-xs)', marginBottom: '2px' }}>종료 시간</div>
                <div style={{ color: 'var(--text-primary)' }}>
                  {selectedTask.endTime.toLocaleString('ko-KR', {
                    month: 'short',
                    day: 'numeric',
                    hour: '2-digit',
                    minute: '2-digit',
                    second: '2-digit'
                  })}
                </div>
              </div>
              <div>
                <div style={{ color: 'var(--text-tertiary)', fontSize: 'var(--font-size-xs)', marginBottom: '2px' }}>소요 시간</div>
                <div style={{ color: 'var(--accent-color)', fontWeight: '600' }}>
                  {(() => {
                    const duration = Math.floor((selectedTask.endTime - selectedTask.startTime) / 1000);
                    const minutes = Math.floor(duration / 60);
                    const seconds = duration % 60;
                    if (minutes > 0) {
                      return `${minutes}분 ${seconds}초`;
                    }
                    return `${seconds}초`;
                  })()}
                </div>
              </div>
              {selectedTask.description && (
                <div style={{ gridColumn: '1 / -1' }}>
                  <div style={{ color: 'var(--text-tertiary)', fontSize: 'var(--font-size-xs)', marginBottom: '2px' }}>설명</div>
                  <div style={{ color: 'var(--text-secondary)' }}>{selectedTask.description}</div>
                </div>
              )}
            </div>
          </div>
        )}

        {/* 범례 */}
        {isExpanded && (
          <div style={{
            display: 'flex',
            justifyContent: 'center',
            alignItems: 'center',
            marginTop: 'var(--space-md)',
            padding: 'var(--space-sm)',
            backgroundColor: 'var(--bg-secondary)',
            borderRadius: 'var(--radius-sm)',
            fontSize: 'var(--font-size-xs)'
          }}>
          {/* 상태 범례 */}
          <div style={{ display: 'flex', gap: 'var(--space-lg)' }}>
            <div style={{ display: 'flex', alignItems: 'center', gap: 'var(--space-xs)' }}>
              <div style={{ width: '12px', height: '12px', backgroundColor: getStatusColor('completed'), borderRadius: '2px' }}></div>
              <span>완료</span>
            </div>
            <div style={{ display: 'flex', alignItems: 'center', gap: 'var(--space-xs)' }}>
              <div style={{ width: '12px', height: '12px', backgroundColor: getStatusColor('in-progress'), borderRadius: '2px' }}></div>
              <span>진행중</span>
            </div>
            <div style={{ display: 'flex', alignItems: 'center', gap: 'var(--space-xs)' }}>
              <div style={{ width: '12px', height: '12px', backgroundColor: getStatusColor('blocked'), borderRadius: '2px' }}></div>
              <span>차단/실패</span>
            </div>
            <div style={{ display: 'flex', alignItems: 'center', gap: 'var(--space-xs)' }}>
              <div style={{ width: '12px', height: '12px', backgroundColor: getStatusColor('not-started'), borderRadius: '2px' }}></div>
              <span>대기</span>
            </div>
          </div>
          </div>
        )}
      </div>
    </div>
  );
};

export default RobotTaskTimeline;
