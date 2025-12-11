import React, { useState, useEffect, useRef, useCallback } from 'react';

const VideoPage = () => {
  const [rooms, setRooms] = useState([]);
  const [selectedRoom, setSelectedRoom] = useState('');
  const [customRoom, setCustomRoom] = useState('');
  const [useCustomRoom, setUseCustomRoom] = useState(false);
  const [connectionStatus, setConnectionStatus] = useState('disconnected'); // disconnected, connecting, connected, error
  const [errorMessage, setErrorMessage] = useState('');
  const [signalingUrl, setSignalingUrl] = useState('');
  
  const videoRef = useRef(null);
  const wsRef = useRef(null);
  const pcRef = useRef(null);
  const viewerIdRef = useRef(null);

  // API URL 설정
  const API_URL = import.meta.env.VITE_API_URL || 'http://localhost:3000';

  // WebRTC 설정 로드
  const loadConfig = async () => {
    try {
      const response = await fetch(`${API_URL}/api/video/config`);
      const data = await response.json();
      if (data.success) {
        // 현재 호스트 기반으로 시그널링 URL 생성
        const wsHost = window.location.hostname;
        setSignalingUrl(`ws://${wsHost}:${data.signalingPort}`);
      }
    } catch (error) {
      console.error('비디오 설정 로드 실패:', error);
    }
  };

  // 활성 방 목록 로드
  const loadRooms = async () => {
    try {
      const response = await fetch(`${API_URL}/api/video/rooms`);
      const data = await response.json();
      if (data.success) {
        setRooms(data.data || []);
      }
    } catch (error) {
      console.error('방 목록 로드 실패:', error);
    }
  };

  useEffect(() => {
    loadConfig();
    loadRooms();
    
    // 주기적으로 방 목록 갱신
    const interval = setInterval(loadRooms, 5000);
    return () => clearInterval(interval);
  }, []);

  // 스트림 상태 색상
  const getStatusColor = () => {
    switch (connectionStatus) {
      case 'connected': return 'var(--status-success)';
      case 'connecting': return 'var(--status-warning)';
      case 'error': return 'var(--status-error)';
      default: return 'var(--text-tertiary)';
    }
  };

  // 스트림 상태 텍스트
  const getStatusText = () => {
    switch (connectionStatus) {
      case 'connected': return '연결됨';
      case 'connecting': return '연결 중...';
      case 'error': return '오류';
      default: return '연결 안됨';
    }
  };

  // 현재 방 ID
  const getCurrentRoomId = useCallback(() => {
    if (useCustomRoom && customRoom) {
      return customRoom;
    }
    return selectedRoom;
  }, [useCustomRoom, customRoom, selectedRoom]);

  // WebRTC 연결 시작
  const connect = useCallback(async () => {
    const roomId = getCurrentRoomId();
    
    if (!roomId) {
      setErrorMessage('방 ID를 입력하거나 선택하세요.');
      setConnectionStatus('error');
      return;
    }

    if (!signalingUrl) {
      setErrorMessage('시그널링 서버 URL을 확인할 수 없습니다.');
      setConnectionStatus('error');
      return;
    }

    // 기존 연결 정리
    disconnect();

    setConnectionStatus('connecting');
    setErrorMessage('');

    try {
      // WebSocket 연결
      const ws = new WebSocket(signalingUrl);
      wsRef.current = ws;

      ws.onopen = () => {
        console.log('[WebRTC] 시그널링 서버 연결됨');
        // 시청자로 방 참가
        ws.send(JSON.stringify({
          type: 'join-as-viewer',
          roomId
        }));
      };

      ws.onmessage = async (event) => {
        const data = JSON.parse(event.data);
        await handleSignalingMessage(data);
      };

      ws.onerror = (error) => {
        console.error('[WebRTC] WebSocket 오류:', error);
        setConnectionStatus('error');
        setErrorMessage('시그널링 서버 연결 오류');
      };

      ws.onclose = () => {
        console.log('[WebRTC] WebSocket 연결 종료');
        if (connectionStatus !== 'error') {
          setConnectionStatus('disconnected');
        }
      };

    } catch (error) {
      console.error('[WebRTC] 연결 오류:', error);
      setConnectionStatus('error');
      setErrorMessage(`연결 오류: ${error.message}`);
    }
  }, [getCurrentRoomId, signalingUrl, connectionStatus]);

  // 시그널링 메시지 처리
  const handleSignalingMessage = async (data) => {
    console.log('[WebRTC] 메시지 수신:', data.type);

    switch (data.type) {
      case 'joined':
        viewerIdRef.current = data.viewerId;
        if (data.broadcasterReady) {
          console.log('[WebRTC] 송출자 대기 중, offer 요청');
        } else {
          setConnectionStatus('connecting');
          setErrorMessage('송출자 대기 중...');
        }
        break;

      case 'broadcaster-ready':
        console.log('[WebRTC] 송출자 준비됨');
        setErrorMessage('');
        break;

      case 'offer':
        await handleOffer(data.offer);
        break;

      case 'ice-candidate':
        await handleIceCandidate(data.candidate);
        break;

      case 'broadcaster-left':
        console.log('[WebRTC] 송출자 퇴장');
        setConnectionStatus('error');
        setErrorMessage('송출자가 연결을 종료했습니다.');
        cleanupPeerConnection();
        break;

      case 'error':
        setConnectionStatus('error');
        setErrorMessage(data.message);
        break;
    }
  };

  // Offer 처리 및 Answer 생성
  const handleOffer = async (offer) => {
    try {
      // PeerConnection 생성
      const pc = new RTCPeerConnection({
        iceServers: [
          { urls: 'stun:stun.l.google.com:19302' },
          { urls: 'stun:stun1.l.google.com:19302' }
        ]
      });
      pcRef.current = pc;

      // 원격 스트림 수신
      pc.ontrack = (event) => {
        console.log('[WebRTC] 트랙 수신:', event.track.kind);
        if (videoRef.current && event.streams[0]) {
          videoRef.current.srcObject = event.streams[0];
          setConnectionStatus('connected');
          setErrorMessage('');
        }
      };

      // ICE Candidate 전송
      pc.onicecandidate = (event) => {
        if (event.candidate && wsRef.current?.readyState === WebSocket.OPEN) {
          wsRef.current.send(JSON.stringify({
            type: 'ice-candidate',
            candidate: event.candidate
          }));
        }
      };

      // 연결 상태 모니터링
      pc.onconnectionstatechange = () => {
        console.log('[WebRTC] 연결 상태:', pc.connectionState);
        if (pc.connectionState === 'connected') {
          setConnectionStatus('connected');
        } else if (pc.connectionState === 'failed' || pc.connectionState === 'disconnected') {
          setConnectionStatus('error');
          setErrorMessage('WebRTC 연결이 끊어졌습니다.');
        }
      };

      // Offer 설정
      await pc.setRemoteDescription(new RTCSessionDescription(offer));

      // Answer 생성 및 전송
      const answer = await pc.createAnswer();
      await pc.setLocalDescription(answer);

      if (wsRef.current?.readyState === WebSocket.OPEN) {
        wsRef.current.send(JSON.stringify({
          type: 'answer',
          answer: pc.localDescription
        }));
      }

    } catch (error) {
      console.error('[WebRTC] Offer 처리 오류:', error);
      setConnectionStatus('error');
      setErrorMessage(`연결 오류: ${error.message}`);
    }
  };

  // ICE Candidate 처리
  const handleIceCandidate = async (candidate) => {
    try {
      if (pcRef.current && candidate) {
        await pcRef.current.addIceCandidate(new RTCIceCandidate(candidate));
      }
    } catch (error) {
      console.error('[WebRTC] ICE Candidate 오류:', error);
    }
  };

  // PeerConnection 정리
  const cleanupPeerConnection = () => {
    if (pcRef.current) {
      pcRef.current.close();
      pcRef.current = null;
    }
    if (videoRef.current) {
      videoRef.current.srcObject = null;
    }
  };

  // 연결 해제
  const disconnect = useCallback(() => {
    if (wsRef.current) {
      if (wsRef.current.readyState === WebSocket.OPEN) {
        wsRef.current.send(JSON.stringify({ type: 'leave' }));
      }
      wsRef.current.close();
      wsRef.current = null;
    }

    cleanupPeerConnection();
    setConnectionStatus('disconnected');
  }, []);

  // 컴포넌트 언마운트 시 정리
  useEffect(() => {
    return () => {
      disconnect();
    };
  }, [disconnect]);

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
      {/* 컨트롤 섹션 */}
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
          {/* 방 선택 */}
          <div style={{ display: 'flex', alignItems: 'center', gap: 'var(--space-sm)' }}>
            <select
              value={selectedRoom}
              onChange={(e) => setSelectedRoom(e.target.value)}
              disabled={useCustomRoom}
              style={{
                padding: '6px 12px',
                fontSize: 'var(--font-size-sm)',
                backgroundColor: 'var(--bg-primary)',
                border: '1px solid var(--border-primary)',
                borderRadius: 'var(--radius-sm)',
                color: 'var(--text-primary)',
                cursor: useCustomRoom ? 'not-allowed' : 'pointer',
                opacity: useCustomRoom ? 0.5 : 1,
                minWidth: '180px'
              }}
            >
              <option value="">활성 스트림 선택...</option>
              {rooms.map(room => (
                <option key={room.roomId} value={room.roomId}>
                  {room.roomId} ({room.viewerCount}명 시청)
                </option>
              ))}
            </select>
            <button
              onClick={loadRooms}
              style={{
                padding: '6px 10px',
                backgroundColor: 'var(--bg-primary)',
                border: '1px solid var(--border-primary)',
                borderRadius: 'var(--radius-sm)',
                color: 'var(--text-secondary)',
                cursor: 'pointer',
                fontSize: 'var(--font-size-xs)'
              }}
              title="새로고침"
            >
              <i className="fas fa-sync-alt"></i>
            </button>
          </div>

          {/* 구분선 */}
          <div style={{ width: '1px', height: '24px', backgroundColor: 'var(--border-primary)' }} />

          {/* 커스텀 방 토글 */}
          <div 
            onClick={() => setUseCustomRoom(!useCustomRoom)}
            style={{ 
              display: 'flex', 
              alignItems: 'center', 
              gap: '8px',
              cursor: 'pointer',
              padding: '4px 8px',
              borderRadius: 'var(--radius-sm)',
              backgroundColor: useCustomRoom ? 'rgba(var(--primary-rgb), 0.1)' : 'transparent'
            }}
          >
            <div style={{
              width: '32px',
              height: '18px',
              backgroundColor: useCustomRoom ? 'var(--primary-color)' : 'var(--bg-tertiary)',
              borderRadius: '9px',
              position: 'relative',
              transition: 'all 0.2s ease'
            }}>
              <div style={{
                position: 'absolute',
                top: '2px',
                left: useCustomRoom ? '16px' : '2px',
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
              color: useCustomRoom ? 'var(--primary-color)' : 'var(--text-tertiary)'
            }}>
              직접 입력
            </span>
          </div>

          {/* 커스텀 방 입력 */}
          {useCustomRoom && (
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
              <i className="fas fa-broadcast-tower" style={{ color: 'var(--text-tertiary)', fontSize: '11px' }} />
              <input
                type="text"
                value={customRoom}
                onChange={(e) => setCustomRoom(e.target.value)}
                placeholder="방 ID 입력 (예: robot-front)"
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
              backgroundColor: `${getStatusColor()}15`
            }}>
              <div style={{
                width: '6px',
                height: '6px',
                borderRadius: '50%',
                backgroundColor: getStatusColor(),
                boxShadow: connectionStatus === 'connected' ? `0 0 6px ${getStatusColor()}` : 'none',
                animation: connectionStatus === 'connecting' ? 'pulse 0.8s infinite' : 'none'
              }} />
              <span style={{ fontSize: '11px', color: getStatusColor(), fontWeight: '500' }}>
                {getStatusText()}
              </span>
            </div>

            {/* 연결 버튼 */}
            <button
              onClick={connect}
              disabled={connectionStatus === 'connecting'}
              style={{
                padding: '6px 16px',
                backgroundColor: connectionStatus === 'connected' ? '#F59E0B' : 'var(--primary-color)',
                border: 'none',
                borderRadius: 'var(--radius-sm)',
                color: 'white',
                cursor: connectionStatus === 'connecting' ? 'not-allowed' : 'pointer',
                display: 'flex',
                alignItems: 'center',
                gap: '6px',
                fontSize: 'var(--font-size-xs)',
                fontWeight: '600',
                transition: 'all 0.2s ease',
                opacity: connectionStatus === 'connecting' ? 0.7 : 1
              }}
            >
              <i className={connectionStatus === 'connecting' ? 'fas fa-spinner fa-spin' : 
                           connectionStatus === 'connected' ? 'fas fa-sync-alt' : 'fas fa-play'} 
                 style={{ fontSize: '10px' }}></i>
              {connectionStatus === 'connecting' ? '연결 중' : connectionStatus === 'connected' ? '재연결' : '연결'}
            </button>
            
            {connectionStatus === 'connected' && (
              <button
                onClick={disconnect}
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
              <i className="fas fa-video" style={{ fontSize: '12px', color: 'var(--text-secondary)' }}></i>
              <span style={{ fontWeight: '500' }}>
                {getCurrentRoomId() || '스트림 선택 안됨'}
              </span>
              
              {/* 스트림 상태 */}
              <div style={{
                display: 'flex',
                alignItems: 'center',
                gap: '4px',
                padding: '2px 8px',
                backgroundColor: `${getStatusColor()}20`,
                borderRadius: 'var(--radius-sm)',
                fontSize: '11px',
                marginLeft: '4px'
              }}>
                <div style={{
                  width: '6px',
                  height: '6px',
                  borderRadius: '50%',
                  backgroundColor: getStatusColor(),
                  animation: connectionStatus === 'connected' ? 'pulse 2s infinite' : 'none'
                }} />
                <span style={{ color: getStatusColor() }}>{getStatusText()}</span>
              </div>
            </div>
            
            <div style={{
              fontSize: 'var(--font-size-xs)',
              color: 'var(--text-tertiary)'
            }}>
              WebRTC
            </div>
          </div>
        </div>
        <div className="card-content">
          <div style={{
            position: 'relative',
            width: '100%',
            paddingTop: '56.25%',
            backgroundColor: '#000',
            borderRadius: 'var(--radius-md)',
            overflow: 'hidden'
          }}>
            {/* 비디오 */}
            <video
              ref={videoRef}
              autoPlay
              playsInline
              muted
              style={{
                position: 'absolute',
                top: 0,
                left: 0,
                width: '100%',
                height: '100%',
                objectFit: 'contain',
                display: connectionStatus === 'connected' ? 'block' : 'none'
              }}
            />

            {/* 플레이스홀더 */}
            {connectionStatus !== 'connected' && (
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
                {connectionStatus === 'connecting' ? (
                  <>
                    <i className="fas fa-spinner fa-spin" style={{ fontSize: '3rem', marginBottom: 'var(--space-md)' }}></i>
                    <div style={{ fontSize: 'var(--font-size-lg)' }}>연결 중...</div>
                    <div style={{ fontSize: 'var(--font-size-sm)', marginTop: 'var(--space-xs)', opacity: 0.7 }}>
                      {errorMessage || '송출자를 기다리는 중입니다'}
                    </div>
                  </>
                ) : connectionStatus === 'error' ? (
                  <>
                    <i className="fas fa-exclamation-triangle" style={{ fontSize: '3rem', marginBottom: 'var(--space-md)', color: 'var(--status-error)' }}></i>
                    <div style={{ fontSize: 'var(--font-size-lg)', color: 'var(--status-error)' }}>연결 오류</div>
                    <div style={{ fontSize: 'var(--font-size-sm)', marginTop: 'var(--space-xs)', opacity: 0.7, maxWidth: '400px', textAlign: 'center' }}>
                      {errorMessage || '스트림에 연결할 수 없습니다.'}
                    </div>
                    <button
                      onClick={connect}
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
                    <div style={{ fontSize: 'var(--font-size-lg)' }}>스트림 대기 중</div>
                    <div style={{ fontSize: 'var(--font-size-sm)', marginTop: 'var(--space-xs)', opacity: 0.7 }}>
                      활성 스트림을 선택하거나 방 ID를 입력하세요
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
