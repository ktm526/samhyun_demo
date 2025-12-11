import React, { useState, useEffect, useRef, useCallback } from 'react';

const VideoPage = () => {
  const [robots, setRobots] = useState([]);
  const [selectedRobot, setSelectedRobot] = useState('');
  const [selectedView, setSelectedView] = useState('front');
  const [loading, setLoading] = useState(true);
  const [streamStatus, setStreamStatus] = useState('disconnected'); // disconnected, connecting, connected, error
  const [errorMessage, setErrorMessage] = useState('');
  const [customRtspUrl, setCustomRtspUrl] = useState('');
  const [useCustomUrl, setUseCustomUrl] = useState(false);
  const [wsPort, setWsPort] = useState(8082);
  const [streamMode, setStreamMode] = useState('mjpeg'); // rtsp, mjpeg
  
  const canvasRef = useRef(null);
  const imgRef = useRef(null);
  const wsRef = useRef(null);
  const playerRef = useRef(null);

  // API URL 설정
  const API_URL = import.meta.env.VITE_API_URL || 'http://localhost:3000';

  // 카메라 방향 정의 
  const cameras = [
    { id: 'front', label: '전방', icon: 'fas fa-arrow-up' },
    { id: 'back', label: '후방', icon: 'fas fa-arrow-down' },
    { id: 'left', label: '좌측', icon: 'fas fa-arrow-left' },
    { id: 'right', label: '우측', icon: 'fas fa-arrow-right' }
  ];

  // 로봇 목록 로드
  const loadRobots = async () => {
    try {
      setLoading(true);
      const response = await fetch(`${API_URL}/api/robots`);
      const data = await response.json();
      
      if (response.ok) {
        const robotsArray = data.data || [];
        setRobots(robotsArray);
        
        if (robotsArray.length > 0) {
          setSelectedRobot(robotsArray[0].id);
        }
      } else {
        console.error('로봇 목록 로드 실패:', data.error);
        setRobots([]);
      }
    } catch (error) {
      console.error('로봇 목록 가져오기 실패:', error);
      setRobots([]);
    } finally {
      setLoading(false);
    }
  };

  // 비디오 설정 로드
  const loadVideoConfig = async () => {
    try {
      const response = await fetch(`${API_URL}/api/video/config`);
      const data = await response.json();
      if (data.success) {
        setWsPort(data.wsPort);
      }
    } catch (error) {
      console.error('비디오 설정 로드 실패:', error);
    }
  };

  useEffect(() => {
    loadRobots();
    loadVideoConfig();
  }, []);

  // 상태 색상 가져오기
  const getStatusColor = (status) => {
    switch (status?.toLowerCase()) {
      case 'moving': return '#3B82F6';
      case 'idle': return '#22C55E';
      case 'charging': return '#F59E0B';
      case 'working': return '#F59E0B';
      case 'error': return '#EF4444';
      default: return '#6B7280';
    }
  };

  // 스트림 상태 색상
  const getStreamStatusColor = () => {
    switch (streamStatus) {
      case 'connected': return 'var(--status-success)';
      case 'connecting': return 'var(--status-warning)';
      case 'error': return 'var(--status-error)';
      default: return 'var(--text-tertiary)';
    }
  };

  // 스트림 상태 텍스트
  const getStreamStatusText = () => {
    switch (streamStatus) {
      case 'connected': return '연결됨';
      case 'connecting': return '연결 중...';
      case 'error': return '오류';
      default: return '연결 안됨';
    }
  };

  // RTSP URL 생성
  const getRtspUrl = useCallback(() => {
    if (useCustomUrl && customRtspUrl) {
      return customRtspUrl;
    }
    
    const robot = robots.find(r => r.id == selectedRobot);
    if (!robot || !robot.ip_address) {
      return null;
    }
    
    // 기본 RTSP URL 형식 (실제 환경에 맞게 수정)
    return `rtsp://${robot.ip_address}:8554/${selectedView}`;
  }, [useCustomUrl, customRtspUrl, robots, selectedRobot, selectedView]);

  // 스트림 연결
  const connectStream = useCallback(() => {
    const streamUrl = getRtspUrl();
    
    if (!streamUrl) {
      setErrorMessage('스트림 URL을 생성할 수 없습니다. 로봇 IP를 확인하세요.');
      setStreamStatus('error');
      return;
    }

    // 기존 연결 정리
    disconnectStream();

    setStreamStatus('connecting');
    setErrorMessage('');

    // MJPEG 모드
    if (streamMode === 'mjpeg') {
      console.log('[Video] MJPEG 스트림 연결:', streamUrl);
      
      if (imgRef.current) {
        imgRef.current.src = streamUrl;
        imgRef.current.onload = () => {
          console.log('[Video] MJPEG 스트림 로드됨');
          setStreamStatus('connected');
        };
        imgRef.current.onerror = () => {
          console.error('[Video] MJPEG 스트림 오류');
          setStreamStatus('error');
          setErrorMessage('MJPEG 스트림 연결 실패. URL을 확인하세요.');
        };
      }
      return;
    }

    // RTSP 모드 (WebSocket + JSMpeg)
    try {
      // WebSocket 연결
      const wsUrl = `ws://localhost:${wsPort}`;
      const ws = new WebSocket(wsUrl);
      wsRef.current = ws;

      ws.binaryType = 'arraybuffer';

      ws.onopen = () => {
        console.log('[Video] WebSocket 연결됨');
        
        // 스트림 구독 요청
        const streamId = `${selectedRobot}-${selectedView}`;
        ws.send(JSON.stringify({
          action: 'subscribe',
          streamId,
          rtspUrl: streamUrl
        }));
      };

      ws.onmessage = (event) => {
        // JSON 메시지 처리
        if (typeof event.data === 'string') {
          try {
            const message = JSON.parse(event.data);
            handleStreamMessage(message);
          } catch (e) {
            // JSON이 아닌 문자열 무시
          }
          return;
        }

        // 바이너리 데이터 (비디오 프레임)
        if (event.data instanceof ArrayBuffer) {
          if (playerRef.current) {
            playerRef.current.write(new Uint8Array(event.data));
          }
        }
      };

      ws.onerror = (error) => {
        console.error('[Video] WebSocket 오류:', error);
        setStreamStatus('error');
        setErrorMessage('WebSocket 연결 오류');
      };

      ws.onclose = () => {
        console.log('[Video] WebSocket 연결 종료');
        if (streamStatus !== 'error') {
          setStreamStatus('disconnected');
        }
      };

      // JSMpeg 플레이어 초기화
      if (canvasRef.current && window.JSMpeg) {
        playerRef.current = new window.JSMpeg.VideoElement(canvasRef.current, null, {
          canvas: canvasRef.current,
          autoplay: true,
          audio: false,
          loop: false,
          disableGl: false
        });
      }

    } catch (error) {
      console.error('[Video] 스트림 연결 오류:', error);
      setStreamStatus('error');
      setErrorMessage(`연결 오류: ${error.message}`);
    }
  }, [getRtspUrl, wsPort, selectedRobot, selectedView, streamStatus, streamMode]);

  // 스트림 메시지 처리
  const handleStreamMessage = (message) => {
    switch (message.type) {
      case 'subscribed':
        console.log('[Video] 스트림 구독 성공:', message.streamId);
        setStreamStatus('connected');
        break;
      case 'error':
        console.error('[Video] 스트림 오류:', message.message);
        setStreamStatus('error');
        setErrorMessage(message.message);
        break;
      case 'closed':
        console.log('[Video] 스트림 종료');
        setStreamStatus('disconnected');
        break;
      default:
        break;
    }
  };

  // 스트림 연결 해제
  const disconnectStream = useCallback(() => {
    // MJPEG 모드
    if (imgRef.current) {
      imgRef.current.src = '';
    }

    // RTSP 모드
    if (wsRef.current) {
      if (wsRef.current.readyState === WebSocket.OPEN) {
        const streamId = `${selectedRobot}-${selectedView}`;
        wsRef.current.send(JSON.stringify({
          action: 'unsubscribe',
          streamId
        }));
      }
      wsRef.current.close();
      wsRef.current = null;
    }

    if (playerRef.current) {
      playerRef.current = null;
    }

    setStreamStatus('disconnected');
  }, [selectedRobot, selectedView]);

  // 컴포넌트 언마운트 시 정리
  useEffect(() => {
    return () => {
      disconnectStream();
    };
  }, []);

  // 로봇 또는 카메라 변경 시 재연결
  useEffect(() => {
    if (streamStatus === 'connected') {
      connectStream();
    }
  }, [selectedRobot, selectedView]);

  if (loading) {
    return (
      <div style={{
        width: '100%',
        height: '100%',
        display: 'flex',
        alignItems: 'center',
        justifyContent: 'center',
        backgroundColor: 'var(--bg-primary)',
        color: 'var(--text-primary)'
      }}>
        <div style={{ textAlign: 'center' }}>
          <i className="fas fa-spinner fa-spin" style={{ fontSize: '2rem', marginBottom: '1rem' }}></i>
          <div>로봇 정보를 불러오는 중...</div>
        </div>
      </div>
    );
  }

  return (
    <div style={{
      width: '100%',
      height: '100%',
      padding: 'var(--space-xl)',
      backgroundColor: 'var(--bg-primary)',
      color: 'var(--text-primary)',
      fontFamily: 'Pretendard, sans-serif',
      overflow: 'auto'
    }}>
      {/* 컨트롤 섹션 - 컴팩트 디자인 */}
      <div style={{ 
        marginBottom: 'var(--space-md)',
        backgroundColor: 'var(--bg-secondary)',
        borderRadius: 'var(--radius-md)',
        border: '1px solid var(--border-primary)',
        padding: 'var(--space-md) var(--space-lg)'
      }}>
        <div style={{
          display: 'flex',
          alignItems: 'center',
          flexWrap: 'wrap',
          gap: 'var(--space-md)'
        }}>
          {/* 로봇 선택 */}
          <div style={{ display: 'flex', alignItems: 'center' }}>
            <select
              value={selectedRobot}
              onChange={(e) => setSelectedRobot(e.target.value)}
              disabled={useCustomUrl}
              style={{
                padding: '6px 12px',
                fontSize: 'var(--font-size-sm)',
                backgroundColor: 'var(--bg-primary)',
                border: '1px solid var(--border-primary)',
                borderRadius: 'var(--radius-sm)',
                color: 'var(--text-primary)',
                cursor: useCustomUrl ? 'not-allowed' : 'pointer',
                opacity: useCustomUrl ? 0.5 : 1,
                minWidth: '160px'
              }}
            >
              {robots.length === 0 ? (
                <option value="">로봇 없음</option>
              ) : (
                robots.map(robot => (
                  <option key={robot.id} value={robot.id}>
                    {robot.name || robot.id}
                  </option>
                ))
              )}
            </select>
          </div>

          {/* 구분선 */}
          <div style={{ width: '1px', height: '24px', backgroundColor: 'var(--border-primary)' }} />

          {/* 카메라 방향 */}
          <div style={{ 
            display: 'flex', 
            gap: '2px',
            backgroundColor: 'var(--bg-primary)',
            padding: '3px',
            borderRadius: 'var(--radius-sm)',
            opacity: useCustomUrl ? 0.5 : 1
          }}>
            {cameras.map(camera => (
              <button
                key={camera.id}
                onClick={() => setSelectedView(camera.id)}
                disabled={useCustomUrl}
                title={camera.label}
                style={{
                  padding: '6px 10px',
                  backgroundColor: selectedView === camera.id ? 'var(--primary-color)' : 'transparent',
                  border: 'none',
                  borderRadius: 'var(--radius-xs)',
                  color: selectedView === camera.id ? 'white' : 'var(--text-tertiary)',
                  cursor: useCustomUrl ? 'not-allowed' : 'pointer',
                  display: 'flex',
                  alignItems: 'center',
                  gap: '4px',
                  fontSize: 'var(--font-size-xs)',
                  transition: 'all 0.15s ease'
                }}
              >
                <i className={camera.icon} style={{ fontSize: '11px' }}></i>
                <span>{camera.label}</span>
              </button>
            ))}
          </div>

          {/* 구분선 */}
          <div style={{ width: '1px', height: '24px', backgroundColor: 'var(--border-primary)' }} />

          {/* 스트림 모드 */}
          <div style={{ 
            display: 'flex', 
            gap: '2px',
            backgroundColor: 'var(--bg-primary)',
            padding: '3px',
            borderRadius: 'var(--radius-sm)'
          }}>
            {['mjpeg', 'rtsp'].map(mode => (
              <button
                key={mode}
                onClick={() => setStreamMode(mode)}
                style={{
                  padding: '6px 12px',
                  backgroundColor: streamMode === mode ? 'var(--primary-color)' : 'transparent',
                  border: 'none',
                  borderRadius: 'var(--radius-xs)',
                  color: streamMode === mode ? 'white' : 'var(--text-tertiary)',
                  cursor: 'pointer',
                  fontSize: 'var(--font-size-xs)',
                  fontWeight: '500',
                  transition: 'all 0.15s ease',
                  textTransform: 'uppercase'
                }}
              >
                {mode}
              </button>
            ))}
          </div>

          {/* 구분선 */}
          <div style={{ width: '1px', height: '24px', backgroundColor: 'var(--border-primary)' }} />

          {/* 커스텀 URL 토글 */}
          <div 
            onClick={() => setUseCustomUrl(!useCustomUrl)}
            style={{ 
              display: 'flex', 
              alignItems: 'center', 
              gap: '8px',
              cursor: 'pointer',
              padding: '4px 8px',
              borderRadius: 'var(--radius-sm)',
              backgroundColor: useCustomUrl ? 'rgba(var(--primary-rgb), 0.1)' : 'transparent'
            }}
          >
            <div style={{
              width: '32px',
              height: '18px',
              backgroundColor: useCustomUrl ? 'var(--primary-color)' : 'var(--bg-tertiary)',
              borderRadius: '9px',
              position: 'relative',
              transition: 'all 0.2s ease'
            }}>
              <div style={{
                position: 'absolute',
                top: '2px',
                left: useCustomUrl ? '16px' : '2px',
                width: '14px',
                height: '14px',
                backgroundColor: 'white',
                borderRadius: '50%',
                transition: 'all 0.2s ease',
                boxShadow: '0 1px 3px rgba(0,0,0,0.2)'
              }} />
            </div>
            <span style={{ 
              fontSize: 'var(--font-size-xs)', 
              color: useCustomUrl ? 'var(--primary-color)' : 'var(--text-tertiary)'
            }}>
              커스텀
            </span>
          </div>

          {/* 커스텀 URL 입력 */}
          {useCustomUrl && (
            <div style={{
              flex: 1,
              minWidth: '200px',
              display: 'flex',
              alignItems: 'center',
              gap: '8px',
              padding: '4px 12px',
              backgroundColor: 'var(--bg-primary)',
              borderRadius: 'var(--radius-sm)',
              border: '1px solid var(--primary-color)'
            }}>
              <i className="fas fa-link" style={{ color: 'var(--text-tertiary)', fontSize: '11px' }} />
              <input
                type="text"
                value={customRtspUrl}
                onChange={(e) => setCustomRtspUrl(e.target.value)}
                placeholder={streamMode === 'mjpeg' ? 'http://...' : 'rtsp://...'}
                style={{
                  flex: 1,
                  padding: '4px 0',
                  fontSize: 'var(--font-size-sm)',
                  backgroundColor: 'transparent',
                  border: 'none',
                  color: 'var(--text-primary)',
                  outline: 'none'
                }}
              />
            </div>
          )}

          {/* 연결 상태 + 버튼 */}
          <div style={{ marginLeft: 'auto', display: 'flex', alignItems: 'center', gap: 'var(--space-sm)' }}>
            {/* 상태 표시 */}
            <div style={{
              display: 'flex',
              alignItems: 'center',
              gap: '6px',
              padding: '4px 10px',
              borderRadius: '12px',
              backgroundColor: `${getStreamStatusColor()}15`
            }}>
              <div style={{
                width: '6px',
                height: '6px',
                borderRadius: '50%',
                backgroundColor: getStreamStatusColor(),
                boxShadow: streamStatus === 'connected' ? `0 0 6px ${getStreamStatusColor()}` : 'none',
                animation: streamStatus === 'connecting' ? 'pulse 0.8s infinite' : 'none'
              }} />
              <span style={{ fontSize: '11px', color: getStreamStatusColor(), fontWeight: '500' }}>
                {getStreamStatusText()}
              </span>
            </div>

            {/* 연결 버튼 */}
            <button
              onClick={connectStream}
              disabled={streamStatus === 'connecting'}
              style={{
                padding: '6px 16px',
                backgroundColor: streamStatus === 'connected' ? '#F59E0B' : 'var(--primary-color)',
                border: 'none',
                borderRadius: 'var(--radius-sm)',
                color: 'white',
                cursor: streamStatus === 'connecting' ? 'not-allowed' : 'pointer',
                display: 'flex',
                alignItems: 'center',
                gap: '6px',
                fontSize: 'var(--font-size-xs)',
                fontWeight: '600',
                transition: 'all 0.2s ease',
                opacity: streamStatus === 'connecting' ? 0.7 : 1
              }}
            >
              <i className={streamStatus === 'connecting' ? 'fas fa-spinner fa-spin' : 
                           streamStatus === 'connected' ? 'fas fa-sync-alt' : 'fas fa-play'} 
                 style={{ fontSize: '10px' }}></i>
              {streamStatus === 'connecting' ? '연결 중' : streamStatus === 'connected' ? '재연결' : '연결'}
            </button>
            
            {streamStatus === 'connected' && (
              <button
                onClick={disconnectStream}
                style={{
                  padding: '6px 12px',
                  backgroundColor: '#EF4444',
                  border: 'none',
                  borderRadius: 'var(--radius-sm)',
                  color: 'white',
                  cursor: 'pointer',
                  display: 'flex',
                  alignItems: 'center',
                  gap: '4px',
                  fontSize: 'var(--font-size-xs)',
                  fontWeight: '600'
                }}
              >
                <i className="fas fa-stop" style={{ fontSize: '10px' }}></i>
                중지
              </button>
            )}
          </div>
        </div>
      </div>

      {/* 영상 표시 영역 */}
      <div className="card">
        <div className="card-header">
          <div style={{ 
            display: 'flex', 
            justifyContent: 'space-between', 
            alignItems: 'center',
            width: '100%'
          }}>
            <div style={{ display: 'flex', alignItems: 'center', gap: '6px', fontSize: 'var(--font-size-sm)', color: 'var(--text-primary)' }}>
              <i className="fas fa-camera" style={{ fontSize: '12px', color: 'var(--text-secondary)' }}></i>
              <span style={{ fontWeight: '500' }}>
                {useCustomUrl ? '커스텀 스트림' : (
                  <>
                    {robots.find(r => r.id == selectedRobot)?.name || selectedRobot} - {cameras.find(c => c.id === selectedView)?.label}
                  </>
                )}
              </span>
              
              {/* 스트림 상태 */}
              <div style={{
                display: 'flex',
                alignItems: 'center',
                gap: '4px',
                padding: '2px 8px',
                backgroundColor: `${getStreamStatusColor()}20`,
                borderRadius: 'var(--radius-sm)',
                fontSize: '11px',
                marginLeft: '4px'
              }}>
                <div style={{
                  width: '6px',
                  height: '6px',
                  borderRadius: '50%',
                  backgroundColor: getStreamStatusColor(),
                  animation: streamStatus === 'connected' ? 'pulse 2s infinite' : 'none'
                }} />
                <span style={{ color: getStreamStatusColor() }}>{getStreamStatusText()}</span>
              </div>
            </div>
            
            <div style={{
              fontSize: 'var(--font-size-xs)',
              color: 'var(--text-tertiary)'
            }}>
              {getRtspUrl() || 'URL 없음'}
            </div>
          </div>
        </div>
        <div className="card-content">
          <div style={{
            position: 'relative',
            width: '100%',
            paddingTop: '56.25%', // 16:9 비율
            backgroundColor: '#000',
            borderRadius: 'var(--radius-md)',
            overflow: 'hidden'
          }}>
            {/* MJPEG 이미지 */}
            {streamMode === 'mjpeg' && (
              <img
                ref={imgRef}
                alt="MJPEG Stream"
                style={{
                  position: 'absolute',
                  top: 0,
                  left: 0,
                  width: '100%',
                  height: '100%',
                  objectFit: 'contain',
                  display: streamStatus === 'connected' ? 'block' : 'none'
                }}
              />
            )}

            {/* RTSP 비디오 캔버스 */}
            {streamMode === 'rtsp' && (
              <canvas
                ref={canvasRef}
                style={{
                  position: 'absolute',
                  top: 0,
                  left: 0,
                  width: '100%',
                  height: '100%',
                  display: streamStatus === 'connected' ? 'block' : 'none'
                }}
              />
            )}

            {/* 플레이스홀더 */}
            {streamStatus !== 'connected' && (
              <div style={{
                position: 'absolute',
                top: 0,
                left: 0,
                width: '100%',
                height: '100%',
                display: 'flex',
                flexDirection: 'column',
                alignItems: 'center',
                justifyContent: 'center',
                color: 'var(--text-tertiary)'
              }}>
                {streamStatus === 'connecting' ? (
                  <>
                    <i className="fas fa-spinner fa-spin" style={{ fontSize: '3rem', marginBottom: 'var(--space-md)' }}></i>
                    <div style={{ fontSize: 'var(--font-size-lg)' }}>스트림 연결 중...</div>
                    <div style={{ fontSize: 'var(--font-size-sm)', marginTop: 'var(--space-xs)', opacity: 0.7 }}>
                      {getRtspUrl()}
                    </div>
                  </>
                ) : streamStatus === 'error' ? (
                  <>
                    <i className="fas fa-exclamation-triangle" style={{ fontSize: '3rem', marginBottom: 'var(--space-md)', color: 'var(--status-error)' }}></i>
                    <div style={{ fontSize: 'var(--font-size-lg)', color: 'var(--status-error)' }}>연결 오류</div>
                    <div style={{ fontSize: 'var(--font-size-sm)', marginTop: 'var(--space-xs)', opacity: 0.7, maxWidth: '400px', textAlign: 'center' }}>
                      {errorMessage || 'RTSP 스트림에 연결할 수 없습니다.'}
                    </div>
                    <button
                      onClick={connectStream}
                      style={{
                        marginTop: 'var(--space-md)',
                        padding: 'var(--space-sm) var(--space-lg)',
                        backgroundColor: 'var(--primary-color)',
                        border: 'none',
                        borderRadius: 'var(--radius-md)',
                        color: 'white',
                        cursor: 'pointer',
                        fontSize: 'var(--font-size-sm)'
                      }}
                    >
                      다시 시도
                    </button>
                  </>
                ) : (
                  <>
                    <i className="fas fa-video" style={{ fontSize: '3rem', marginBottom: 'var(--space-md)', opacity: 0.3 }}></i>
                    <div style={{ fontSize: 'var(--font-size-lg)' }}>카메라 대기 중</div>
                    <div style={{ fontSize: 'var(--font-size-sm)', marginTop: 'var(--space-xs)', opacity: 0.7 }}>
                      '연결' 버튼을 눌러 스트림을 시작하세요
                    </div>
                  </>
                )}
              </div>
            )}
          </div>
        </div>
      </div>


      {/* pulse 애니메이션 */}
      <style>{`
        @keyframes pulse {
          0%, 100% { opacity: 1; }
          50% { opacity: 0.5; }
        }
      `}</style>
    </div>
  );
};

export default VideoPage;
