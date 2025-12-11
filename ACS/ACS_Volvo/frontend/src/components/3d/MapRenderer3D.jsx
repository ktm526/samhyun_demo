import React, { useRef, useEffect, useState, useMemo } from 'react';
import { Line, Html } from '@react-three/drei';
import { useFrame, useThree } from '@react-three/fiber';
import { useAppContext } from '../../contexts/AppContext';
import { COLORS } from '../../constants';
import * as THREE from 'three';

// 테슬라 스타일 CSS 애니메이션 추가
const teslaStyleSheet = `
  @keyframes pulse {
    0% { 
      box-shadow: 0 0 20px rgba(0, 255, 255, 0.3);
      border-color: #00FFFF;
    }
    50% { 
      box-shadow: 0 0 30px rgba(0, 255, 255, 0.6);
      border-color: #40FFFF;
    }
    100% { 
      box-shadow: 0 0 20px rgba(0, 255, 255, 0.3);
      border-color: #00FFFF;
    }
  }
  
  @keyframes glow {
    0% { 
      box-shadow: 0 0 10px rgba(0, 255, 255, 0.5);
    }
    50% { 
      box-shadow: 0 0 20px rgba(0, 255, 255, 0.8);
    }
    100% { 
      box-shadow: 0 0 10px rgba(0, 255, 255, 0.5);
    }
  }
  
  .tesla-ui {
    font-family: 'Consolas', 'Monaco', 'Lucida Console', monospace;
    letter-spacing: 0.05em;
  }
`;

// 스타일 시트 추가
if (typeof document !== 'undefined' && !document.getElementById('tesla-style')) {
  const style = document.createElement('style');
  style.id = 'tesla-style';
  style.textContent = teslaStyleSheet;
  document.head.appendChild(style);
}

// 맵 이미지 텍스처 렌더링 컴포넌트
function MapTexture({ mapInfo, visible = true, mapOffsetSettings = null }) {
  const meshRef = useRef();
  const [texture, setTexture] = useState(null);
  const [loading, setLoading] = useState(false);
  const [error, setError] = useState(null);
  const { gl } = useThree(); // Three.js 렌더러 인스턴스 접근
  
  useEffect(() => {
    if (!mapInfo || !visible) {
      //console.log('MapTexture: mapInfo나 visible이 없음', { mapInfo, visible });
      return;
    }
    
    //console.log('MapTexture: 맵 정보 전체:', mapInfo);
    //console.log('MapTexture: 맵 ID:', mapInfo.id);
    //console.log('MapTexture: 맵 이름:', mapInfo.name);
    
    const processImage = async () => {
      try {
        setLoading(true);
        setError(null);
        
        //console.log('MapTexture: 이미지 로드 시작', `/api/maps/${mapInfo.id}/download/image`);
        
        // 이미지 파일 로드 (백엔드 서버 URL 사용)
        const API_URL = import.meta.env.VITE_API_URL || 'http://localhost:3000';
        const imageUrl = `${API_URL}/api/maps/${mapInfo.id}/download/image`;
        //console.log('MapTexture: fetch URL:', imageUrl);
        
        const imageResponse = await fetch(imageUrl);
        //console.log('MapTexture: fetch 응답:', imageResponse.status, imageResponse.statusText);
        
        if (!imageResponse.ok) {
          const errorText = await imageResponse.text();
          console.error('MapTexture: fetch 에러 응답:', errorText);
          throw new Error(`이미지 로드 실패: ${imageResponse.status} ${imageResponse.statusText} - ${errorText}`);
        }
        
        const imageBlob = await imageResponse.blob();
        //console.log('MapTexture: 이미지 블롭 크기', imageBlob.size);
        
        // 이미지 객체 생성
        const img = new Image();
        img.crossOrigin = 'anonymous';
        
        img.onload = () => {
          //console.log('MapTexture: 이미지 로드 완료', { width: img.width, height: img.height });
          
          // Three.js 텍스처 생성 (고화질 설정)
          const texture = new THREE.Texture(img);
          texture.flipY = false; // Y축 뒤집기 방지
          texture.wrapS = THREE.ClampToEdgeWrapping;
          texture.wrapT = THREE.ClampToEdgeWrapping;
          
          // 고화질 필터링 설정
          texture.minFilter = THREE.LinearMipmapLinearFilter; // 미프맵 사용으로 화질 향상
          texture.magFilter = THREE.LinearFilter;
          texture.generateMipmaps = true; // 미프맵 생성
          
          // 렌더러의 최대 anisotropy 값 사용 (동적 감지)
          texture.anisotropy = gl.capabilities.getMaxAnisotropy();
          
          // 색상 공간 설정
          texture.colorSpace = THREE.SRGBColorSpace;
          texture.needsUpdate = true;
          
          //console.log('MapTexture: 고화질 텍스처 생성 완료', { anisotropy: texture.anisotropy });
          setTexture(texture);
          setLoading(false);
        };
        
        img.onerror = (err) => {
          console.error('MapTexture: 이미지 로드 실패', err);
          console.error('MapTexture: 이미지 URL:', img.src);
          setError(`이미지 로드 실패: ${img.src}`);
          setLoading(false);
        };
        
        img.src = URL.createObjectURL(imageBlob);
      } catch (error) {
        console.error('MapTexture: 이미지 처리 중 오류:', error);
        setError(error.message);
        setLoading(false);
      }
    };
    
    processImage();
  }, [mapInfo, visible, gl]);
  
  if (!visible || !mapInfo) {
    //console.log('MapTexture: 렌더링 안함 (visible 또는 mapInfo 없음)');
    return null;
  }
  
  if (loading) {
    //console.log('MapTexture: 로딩 중');
    return (
      <Html position={[0, 2, 0]}>
        <div style={{ color: 'white', background: 'rgba(0,0,0,0.8)', padding: '8px', borderRadius: '4px' }}>
          맵 이미지 로딩 중...
        </div>
      </Html>
    );
  }
  
  if (error) {
    //console.log('MapTexture: 오류 발생', error);
    return (
      <Html position={[0, 2, 0]}>
        <div style={{ color: 'red', background: 'rgba(0,0,0,0.8)', padding: '8px', borderRadius: '4px' }}>
          맵 이미지 로드 실패: {error}
        </div>
      </Html>
    );
  }
  
  if (!texture) {
    //console.log('MapTexture: 텍스처 없음');
    return null;
  }
  
  // 맵 크기 계산 (메타데이터 기반)
  const mapWidth = (mapInfo.width || 1000) * (mapInfo.resolution || 0.05);
  const mapHeight = (mapInfo.height || 1000) * (mapInfo.resolution || 0.05);
  
  // ROS 맵 좌표계: origin은 맵 이미지의 좌하단 모서리를 나타냄
  // 3D 공간에서 이미지 중심을 origin + mapSize/2 위치에 배치
  const mapCenterX = (mapInfo.origin_x || 0) + mapWidth / 2;
  const mapCenterY = (mapInfo.origin_y || 0) + mapHeight / 2;
  
  // 오프셋 적용 (사용자 지정 이동, 회전, 확대/축소)
  const offsetX = mapOffsetSettings?.offsetX ?? 0;
  const offsetY = mapOffsetSettings?.offsetY ?? 0;
  const rotationDeg = mapOffsetSettings?.rotationDeg ?? 0;
  const scale = mapOffsetSettings?.scale ?? 1;
  const rotationRad = (rotationDeg * Math.PI) / 180;
  
  // console.log('MapTexture: 렌더링', { 
  //   mapWidth, 
  //   mapHeight, 
  //   origin: { x: mapInfo.origin_x || 0, y: mapInfo.origin_y || 0 },
  //   center: { x: mapCenterX, y: mapCenterY },
  //   offset: { x: offsetX, y: offsetY },
  //   rotation: rotationDeg,
  //   scale: scale
  // });
  
  return (
    <mesh 
      ref={meshRef} 
      position={[mapCenterX + offsetX, 0.01, -(mapCenterY + offsetY)]}
      rotation={[Math.PI/2, 0, rotationRad]} // 90도 회전하여 바닥에 수평으로 놓기 + 사용자 회전 추가
      scale={[scale, scale, 1]} // XY 평면에서 확대/축소
    >
      <planeGeometry args={[mapWidth, mapHeight]} />
      <meshBasicMaterial 
        map={texture} 
        transparent={true}
        side={THREE.DoubleSide}
      />
    </mesh>
  );
}



// 심플한 맵 노드 렌더링 컴포넌트
function MapNode({ node, mapInfo, theme = 'dark', isSelected = false, onHover, onHoverEnd, onRightClick, robots = [], onMoveRequest }) {
  const meshRef = useRef();
  const [hovered, setHovered] = useState(false);
  const [contextMenuMode, setContextMenuMode] = useState(false);
  const [selectedRobot, setSelectedRobot] = useState(null);
  const [isLoading, setIsLoading] = useState(false);
  
  // ROS 맵 좌표계: 노드 좌표는 이미 실제 미터 단위 좌표이므로 그대로 사용
  const transformedPos = {
    x: node.position_x,
    y: node.position_y
  };
  
  // console.log('노드 좌표 (미터 단위):', {
  //   node: node.name,
  //   position: transformedPos,
  //   type: node.type
  // });
  
  // 테마에 따른 노드 설정
  const nodeConfig = useMemo(() => {
    const isDark = theme === 'dark';
    return { 
      color: isDark ? COLORS.PRIMARY : '#0088ff', // 라이트 테마에서 더 밝은 파란색
      size: 0.15,       // 기본 크기 (2배)
      height: 0.2,      // 기본 높이 (2배)
      hoverSize: 0.3    // 호버 영역 크기 (2배로 확대)
    };
  }, [theme]);
  
  // 심플한 애니메이션 효과
  useFrame((state) => {
    if (meshRef.current) {
      // 선택/호버 시에만 부드러운 펄스 효과
      if (isSelected || hovered) {
        const pulse = Math.sin(state.clock.elapsedTime * 3) * 0.1 + 1;
        meshRef.current.scale.setScalar(pulse);
      } else {
        meshRef.current.scale.setScalar(1);
      }
    }
  });

  const handleRightClick = (e) => {
    e.stopPropagation();
    setContextMenuMode(true);
    setSelectedRobot(null);
    setHovered(true); // 강제로 hover 상태 유지
  };

  const handleCloseContextMenu = () => {
    setContextMenuMode(false);
    setSelectedRobot(null);
    setIsLoading(false);
    setHovered(false); // hover 상태도 해제
  };

  const handleMoveRequest = async () => {
    if (!selectedRobot || !node || !onMoveRequest) return;
    
    setIsLoading(true);
    try {
      // node.id 대신 node.node_index를 사용 (AMR이 인식할 수 있는 값)
      const targetNodeId = node.node_index || node.id;

      await onMoveRequest(selectedRobot.id, targetNodeId);
      handleCloseContextMenu();
    } catch (error) {

    } finally {
      setIsLoading(false);
    }
  };

  // 모든 로봇 표시 (필터링 제거)
  const allRobots = robots || [];

  // 로봇 상태별 색상과 아이콘 (새로운 order_status 기반)
  const getStatusInfo = (status) => {
    switch (status) {
      case 'idle':
        return { color: '#22C55E', icon: '⏸', text: '대기중', available: true };
      case 'stop':
        return { color: '#EF4444', icon: '⏹', text: '정지', available: false };
      case 'working':
        return { color: '#3B82F6', icon: '▶', text: '작업중', available: false };
      case 'pause':
        return { color: '#F59E0B', icon: '⏸', text: '일시정지', available: false };
      case 'charging':
        return { color: '#F59E0B', icon: '⚡', text: '충전중', available: true };
      case 'error':
        return { color: '#EF4444', icon: '✕', text: '오류', available: false };
      case 'disconnected':
        return { color: '#6B7280', icon: '⚠', text: '연결끊김', available: false };
      // 하위 호환성
      case 'moving':
        return { color: '#3B82F6', icon: '▶', text: '작업중', available: false };
      default:
        return { color: '#6B7280', icon: '●', text: '알수없음', available: false };
    }
  };

  const themeColors = {
    background: theme === 'dark' ? '#1a1a1a' : '#ffffff',
    textPrimary: theme === 'dark' ? '#ffffff' : '#2c3e50',
    textSecondary: theme === 'dark' ? '#cccccc' : '#6c757d',
    border: theme === 'dark' ? '#333333' : '#e0e0e0',
    buttonPrimary: '#38BDF8',
    buttonHover: '#0EA5E9',
    robotItem: theme === 'dark' ? '#2a2a2a' : '#f8f9fa',
    robotItemHover: theme === 'dark' ? '#363636' : '#e9ecef',
    robotItemDisabled: theme === 'dark' ? '#1a1a1a' : '#f0f0f0'
  };

  // 외부 클릭 감지를 위한 useEffect
  useEffect(() => {
    const handleOutsideClick = (event) => {
      if (contextMenuMode) {
        // 툴팁 내부 클릭이 아닌 경우에만 닫기
        const target = event.target;
        const isInsideTooltip = target.closest('[data-tooltip-content]');
        if (!isInsideTooltip) {
          handleCloseContextMenu();
        }
      }
    };

    if (contextMenuMode) {
      // 약간의 지연을 두어 우클릭 이벤트와 충돌 방지
      setTimeout(() => {
        document.addEventListener('click', handleOutsideClick);
        document.addEventListener('contextmenu', handleOutsideClick);
      }, 100);
    }

    return () => {
      document.removeEventListener('click', handleOutsideClick);
      document.removeEventListener('contextmenu', handleOutsideClick);
    };
  }, [contextMenuMode]);
  
  return (
    <group>
      {/* 투명한 호버 영역 (더 큰 범위) */}
      <mesh
        position={[transformedPos.x, nodeConfig.height / 2, -transformedPos.y]}
        onPointerOver={(e) => {
          e.stopPropagation();
          if (!contextMenuMode) {
            setHovered(true);
            onHover?.(node);
          }
        }}
        onPointerOut={(e) => {
          e.stopPropagation();
          if (!contextMenuMode) {
            setHovered(false);
            onHoverEnd?.();
          }
        }}
        onContextMenu={handleRightClick}
      >
        <boxGeometry args={[nodeConfig.hoverSize * 2, nodeConfig.height * 2, nodeConfig.hoverSize * 2]} />
        <meshBasicMaterial transparent opacity={0} />
      </mesh>
      
      {/* 실제 노드 표시 (네모 모양) */}
      <mesh
        ref={meshRef}
        position={[transformedPos.x, nodeConfig.height / 2, -transformedPos.y]}
      >
        <boxGeometry args={[nodeConfig.size * 2, nodeConfig.height, nodeConfig.size * 2]} />
        <meshStandardMaterial
          color={nodeConfig.color}
          transparent={false}
          opacity={1}
          emissive={nodeConfig.color}
          emissiveIntensity={isSelected ? 0.3 : (hovered ? 0.2 : 0.1)}
        />
      </mesh>
      
      {/* 툴팁 (일반 모드 또는 컨텍스트 메뉴 모드) */}
      {(hovered || isSelected) && (
        <Html 
          position={[transformedPos.x, nodeConfig.height + 0.8, -transformedPos.y]}
          center
          style={{
            transform: 'translate(-50%, -100%)',
            zIndex: 10000,
            pointerEvents: contextMenuMode ? 'all' : 'none'
          }}
        >
          <div 
            data-tooltip-content
            style={{
              background: themeColors.background,
              backdropFilter: 'blur(10px)',
              borderRadius: '16px',
              padding: '16px 20px',
              color: themeColors.textPrimary,
              fontFamily: 'Pretendard, -apple-system, BlinkMacSystemFont, system-ui, sans-serif',
              fontSize: '13px',
              fontWeight: '500',
              textAlign: 'left',
              minWidth: contextMenuMode ? '280px' : '240px',
              maxWidth: contextMenuMode ? '350px' : '300px',
              boxShadow: theme === 'dark' 
                ? `0 0 20px ${nodeConfig.color}40, 0 4px 16px rgba(0, 0, 0, 0.5)`
                : `0 0 20px ${nodeConfig.color}30, 0 4px 16px rgba(0, 0, 0, 0.15)`,
              position: 'relative'
            }}
          >
            {contextMenuMode ? (
              /* AMR 선택 메뉴 */
              <>
                {/* 헤더 */}
                <div style={{
                  display: 'flex',
                  justifyContent: 'space-between',
                  alignItems: 'center',
                  marginBottom: '12px',
                  paddingBottom: '8px',
                  borderBottom: `1px solid ${themeColors.border}`
                }}>
                  <div>
                    <div style={{
                      fontSize: '16px',
                      fontWeight: '700',
                      color: themeColors.textPrimary
                    }}>
                      AMR 이동
                    </div>
                    <div style={{
                      fontSize: '12px',
                      color: themeColors.textSecondary,
                      marginTop: '2px'
                    }}>
                      {node.name} (#{node.node_index})
                    </div>
                  </div>
                  <button
                    onClick={handleCloseContextMenu}
                    style={{
                      background: 'none',
                      border: 'none',
                      color: themeColors.textSecondary,
                      fontSize: '18px',
                      cursor: 'pointer',
                      padding: '4px',
                      borderRadius: '4px'
                    }}
                  >
                    ✕
                  </button>
                </div>

                {/* AMR 리스트 */}
                <div style={{ marginBottom: '16px' }}>
                  <div style={{
                    fontSize: '14px',
                    fontWeight: '600',
                    color: themeColors.textPrimary,
                    marginBottom: '8px'
                  }}>
                    모든 AMR ({allRobots.length}개)
                  </div>
                  
                  {allRobots.length === 0 ? (
                    <div style={{
                      padding: '12px',
                      textAlign: 'center',
                      color: themeColors.textSecondary,
                      fontSize: '13px',
                      backgroundColor: themeColors.robotItem,
                      borderRadius: '8px'
                    }}>
                      등록된 AMR이 없습니다
                    </div>
                  ) : (
                    <div style={{
                      maxHeight: '200px',
                      overflowY: 'auto'
                    }}>
                      {allRobots.map(robot => {
                        const statusInfo = getStatusInfo(robot.status);
                        const isAvailable = statusInfo.available;
                        const isSelectedRobot = selectedRobot?.id === robot.id;
                        
                        return (
                          <div
                            key={robot.id}
                            onClick={() => isAvailable && setSelectedRobot(robot)}
                            style={{
                              padding: '8px 12px',
                              margin: '3px 0',
                              borderRadius: '6px',
                              cursor: isAvailable ? 'pointer' : 'not-allowed',
                              backgroundColor: isSelectedRobot 
                                ? themeColors.buttonPrimary 
                                : 'transparent',
                              color: isSelectedRobot 
                                ? '#ffffff' 
                                : isAvailable 
                                  ? themeColors.textPrimary 
                                  : themeColors.textSecondary,
                              border: isSelectedRobot 
                                ? `1px solid ${themeColors.buttonPrimary}` 
                                : '1px solid transparent',
                              display: 'flex',
                              alignItems: 'center',
                              gap: '12px',
                              transition: 'all 0.2s ease',
                              opacity: isAvailable ? 1 : 0.5
                            }}
                            onMouseEnter={(e) => {
                              if (isAvailable && !isSelectedRobot) {
                                e.currentTarget.style.backgroundColor = themeColors.robotItem;
                              }
                            }}
                            onMouseLeave={(e) => {
                              if (isAvailable && !isSelectedRobot) {
                                e.currentTarget.style.backgroundColor = 'transparent';
                              }
                            }}
                          >
                            {/* 상태 인디케이터 점 */}
                            <div style={{
                              width: '10px',
                              height: '10px',
                              borderRadius: '50%',
                              backgroundColor: statusInfo.color,
                              border: `2px solid ${statusInfo.color}40`,
                              boxShadow: `0 0 8px ${statusInfo.color}60`,
                              flexShrink: 0
                            }}></div>
                            
                            {/* 로봇 이름 */}
                            <div style={{
                              fontSize: '14px',
                              fontWeight: '500',
                              flex: 1
                            }}>
                              {robot.name || robot.id}
                            </div>
                          </div>
                        );
                      })}
                    </div>
                  )}
                </div>

                {/* 버튼들 */}
                <div style={{
                  display: 'flex',
                  gap: '8px',
                  justifyContent: 'flex-end'
                }}>
                  <button
                    onClick={handleCloseContextMenu}
                    style={{
                      padding: '8px 16px',
                      border: `1px solid ${themeColors.border}`,
                      borderRadius: '6px',
                      backgroundColor: 'transparent',
                      color: themeColors.textSecondary,
                      fontSize: '14px',
                      cursor: 'pointer',
                      fontWeight: '500'
                    }}
                  >
                    취소
                  </button>
                  <button
                    onClick={handleMoveRequest}
                    disabled={!selectedRobot || isLoading || allRobots.length === 0 || !getStatusInfo(selectedRobot?.status).available}
                    style={{
                      padding: '8px 16px',
                      border: 'none',
                      borderRadius: '6px',
                      backgroundColor: (!selectedRobot || isLoading || allRobots.length === 0 || !getStatusInfo(selectedRobot?.status).available) 
                        ? themeColors.textSecondary 
                        : themeColors.buttonPrimary,
                      color: '#ffffff',
                      fontSize: '14px',
                      cursor: (!selectedRobot || isLoading || allRobots.length === 0 || !getStatusInfo(selectedRobot?.status).available) 
                        ? 'not-allowed' 
                        : 'pointer',
                      fontWeight: '600',
                      display: 'flex',
                      alignItems: 'center',
                      gap: '6px',
                      transition: 'all 0.2s ease',
                      boxShadow: (!selectedRobot || isLoading || allRobots.length === 0 || !getStatusInfo(selectedRobot?.status).available) 
                        ? 'none' 
                        : `0 0 10px ${themeColors.buttonPrimary}40`
                    }}
                    onMouseEnter={(e) => {
                      if (!e.target.disabled) {
                        e.currentTarget.style.backgroundColor = themeColors.buttonHover;
                        e.currentTarget.style.boxShadow = `0 0 15px ${themeColors.buttonPrimary}60`;
                      }
                    }}
                    onMouseLeave={(e) => {
                      if (!e.target.disabled) {
                        e.currentTarget.style.backgroundColor = themeColors.buttonPrimary;
                        e.currentTarget.style.boxShadow = `0 0 10px ${themeColors.buttonPrimary}40`;
                      }
                    }}
                  >
                    {isLoading && (
                      <div style={{
                        width: '12px',
                        height: '12px',
                        border: '2px solid transparent',
                        borderTop: '2px solid #ffffff',
                        borderRadius: '50%',
                        animation: 'spin 1s linear infinite'
                      }} />
                    )}
                    {isLoading ? '이동 중...' : '이동'}
                  </button>
                </div>
              </>
            ) : (
              /* 일반 노드 정보 툴팁 */
              <>
                {/* 헤더 */}
                <div style={{ 
                  marginBottom: '12px', 
                  paddingBottom: '8px',
                  borderBottom: `1px solid ${theme === 'dark' ? '#333333' : '#e0e0e0'}`,
                  fontSize: '15px', 
                  fontWeight: '700', 
                  color: nodeConfig.color,
                  display: 'flex',
                  alignItems: 'center',
                  gap: '8px'
                }}>
                  <div style={{
                    width: '16px',
                    height: '16px',
                    borderRadius: '50%',
                    backgroundColor: nodeConfig.color,
                    display: 'flex',
                    alignItems: 'center',
                    justifyContent: 'center',
                    fontSize: '8px',
                    color: '#ffffff',
                    fontWeight: '600'
                  }}>
                    {node.node_index}
                  </div>
                  {node.name}
                </div>
                
                {/* 상세 정보 */}
                <div style={{ 
                  fontSize: '12px', 
                  color: theme === 'dark' ? '#cccccc' : '#6c757d', 
                  lineHeight: '1.5',
                  display: 'grid',
                  gridTemplateColumns: 'auto 1fr',
                  gap: '6px 12px'
                }}>
                  <span style={{ fontWeight: '600', color: theme === 'dark' ? '#ffffff' : '#2c3e50' }}>Index:</span>
                  <span>{node.node_index}</span>
                  
                  <span style={{ fontWeight: '600', color: theme === 'dark' ? '#ffffff' : '#2c3e50' }}>Type:</span>
                  <span>{node.type}</span>
                  
                  <span style={{ fontWeight: '600', color: theme === 'dark' ? '#ffffff' : '#2c3e50' }}>Position:</span>
                  <span style={{ fontFamily: 'monospace' }}>
                    ({node.position_x.toFixed(2)}, {node.position_y.toFixed(2)})
                  </span>
                </div>

                {/* 우클릭 안내 */}
                <div style={{
                  marginTop: '12px',
                  paddingTop: '8px',
                  borderTop: `1px solid ${theme === 'dark' ? '#333333' : '#e0e0e0'}`,
                  fontSize: '11px',
                  color: theme === 'dark' ? '#888888' : '#999999',
                  textAlign: 'center'
                }}>
                  우클릭하여 AMR 이동
                </div>
              </>
            )}
            
            {/* 말풍선 꼬리 */}
            <div style={{
              position: 'absolute',
              top: '100%',
              left: '50%',
              transform: 'translateX(-50%)',
              width: '0',
              height: '0',
              borderLeft: '16px solid transparent',
              borderRight: '16px solid transparent',
              borderTop: `16px solid ${themeColors.background}`,
              filter: `drop-shadow(0 2px 4px ${theme === 'dark' ? 'rgba(0,0,0,0.3)' : 'rgba(0,0,0,0.1)'})`
            }}></div>
          </div>

          <style>{`
            @keyframes spin {
              0% { transform: rotate(0deg); }
              100% { transform: rotate(360deg); }
            }
          `}</style>
        </Html>
      )}
    </group>
  );
}

// 심플한 맵 노드 연결선 렌더링 컴포넌트
function MapConnection({ connection, nodes, mapInfo, theme = 'dark' }) {
  const lineRef = useRef();
  
  const fromNode = nodes.find(n => n.node_index === connection.from_node_index);
  const toNode = nodes.find(n => n.node_index === connection.to_node_index);
  
  if (!fromNode || !toNode) return null;
  
  // ROS 맵 좌표계: 노드 좌표는 이미 실제 미터 단위 좌표이므로 그대로 사용
  const fromTransformed = {
    x: fromNode.position_x,
    y: fromNode.position_y
  };
  
  const toTransformed = {
    x: toNode.position_x,
    y: toNode.position_y
  };
  
  // 테마에 따른 연결선 색상
  const connectionColor = theme === 'dark' ? COLORS.PRIMARY : '#0056b3';
  
  // 심플한 직선 연결 (로봇 높이에 맞춰 조정)
  const points = [
    [fromTransformed.x, 0.05, -fromTransformed.y],
    [toTransformed.x, 0.05, -toTransformed.y]
  ];
  
  // 심플한 빛나는 효과
  useFrame((state) => {
    if (lineRef.current) {
      // 부드러운 빛나는 효과
      const glow = Math.sin(state.clock.elapsedTime * 2) * 0.2 + 0.8;
      lineRef.current.material.opacity = glow;
    }
  });
  
  return (
    <Line
      ref={lineRef}
      points={points}
      color={connectionColor}
      lineWidth={1}
      transparent
      opacity={0.7}
    />
  );
}

// STL 모델 렌더링 컴포넌트
function StlModelRenderer({ stlModel, visible = true, theme = 'dark' }) {

  const geometry = stlModel?.geometry;
  const metadata = stlModel?.metadata;

  useEffect(() => {
    if (geometry && !geometry.boundingBox) {
      geometry.computeBoundingBox();
    }
  }, [geometry]);

  const orientedBox = useMemo(() => {
    if (!geometry || !geometry.boundingBox) return null;
    const box = geometry.boundingBox.clone();
    const rotationMatrix = new THREE.Matrix4().makeRotationX(-Math.PI / 2);
    box.applyMatrix4(rotationMatrix);
    return box;
  }, [geometry]);

  const indicatorConfig = useMemo(() => {
    if (!orientedBox) return null;
    const size = new THREE.Vector3();
    orientedBox.getSize(size);
    const radius = Math.max(0.15, Math.min(size.x, size.z) * 0.04);
    const length = Math.max(0.6, size.z * 0.18);
    const positionZ = orientedBox.min.z - length * 0.35;
    return {
      radius,
      length,
      position: [0, radius * 0.25, positionZ]
    };
  }, [orientedBox]);

  const surfaceSize = useMemo(() => {
    if (!orientedBox) {
      return { x: 10, z: 10 };
    }
    const size = new THREE.Vector3();
    orientedBox.getSize(size);
    return {
      x: Math.max(6, size.x * 1.1),
      z: Math.max(6, size.z * 1.1)
    };
  }, [orientedBox]);

  if (!visible || !geometry) return null;

  const surfaceColor = theme === 'dark' ? '#0f172a' : '#e2e8f0';

  return (
    <group>
      <mesh rotation={[-Math.PI / 2, 0, 0]} position={[0, -0.05, 0]}>
        <planeGeometry args={[surfaceSize.x, surfaceSize.z]} />
        <meshStandardMaterial
          color={surfaceColor}
          transparent
          opacity={0.25}
        />
      </mesh>

      <mesh
        geometry={geometry}
        rotation={[-Math.PI / 2, 0, 0]}
        castShadow={false}
        receiveShadow={true}
      >
        <meshStandardMaterial
          color={theme === 'dark' ? '#4b5563' : '#94a3b8'}
          metalness={0.2}
          roughness={0.75}
          transparent
          opacity={0.95}
        />
      </mesh>

      {indicatorConfig && (
        <mesh
          position={indicatorConfig.position}
          rotation={[-Math.PI / 2, 0, Math.PI / 4]}
        >
          <coneGeometry args={[indicatorConfig.radius, indicatorConfig.length, 4]} />
          <meshStandardMaterial
            color="#ff5500"
            emissive="#ff5500"
            emissiveIntensity={0.7}
            metalness={0.4}
            roughness={0.3}
          />
        </mesh>
      )}

      {metadata && (
        <Html position={[0, 4, 0]}>
          <div
            className="tesla-ui"
            style={{
              background: 'rgba(0,0,0,0.8)',
              color: '#e2e8f0',
              padding: '12px 16px',
              borderRadius: '10px',
              border: '1px solid rgba(56,189,248,0.4)',
              fontSize: '12px',
              minWidth: '220px'
            }}
          >
            <div style={{ fontWeight: '700', marginBottom: '6px', color: '#00e0ff' }}>
              STL 지형 활성화
            </div>
            <div style={{ lineHeight: 1.4 }}>
              <div>파일: {metadata.fileName}</div>
              <div>
                크기: {metadata.size.x} x {metadata.size.y} x {metadata.size.z} m
              </div>
              <div style={{ color: '#94a3b8', marginTop: '4px' }}>
                {new Date(metadata.uploadedAt).toLocaleString()}
              </div>
            </div>
          </div>
        </Html>
      )}
    </group>
  );
}

// 메인 맵 렌더러 컴포넌트
const MapRenderer3D = ({ 
  mapData,
  showTexture = true,
  showNodes = true,
  showConnections = true,
  selectedNode = null,
  onNodeHover,
  onNodeHoverEnd,
  robots = [],
  onMoveRequest,
  mapOffsetSettings = null
}) => {
  const { state } = useAppContext();
  const theme = state.ui.theme;
  const [hoveredNode, setHoveredNode] = useState(null);
  
  // console.log('MapRenderer3D: props received', { 
  //   mapData: mapData ? { id: mapData.map?.id, name: mapData.map?.name } : null,
  //   showTexture,
  //   showNodes,
  //   showConnections,
  //   robotsCount: robots.length
  // });
  
  if (!mapData) {
    //console.log('MapRenderer3D: mapData가 없음');
    return null;
  }
  
  const { map, nodes = [], connections = [] } = mapData;
  // console.log('MapRenderer3D: 맵 데이터 파싱', { 
  //   map: map ? { id: map.id, name: map.name } : null,
  //   nodesCount: nodes.length,
  //   connectionsCount: connections.length
  // });
  
  return (
    <group>
      
      {/* 맵 텍스처 렌더링 */}
      {showTexture && (
        <MapTexture 
          mapInfo={map}
          visible={showTexture}
          mapOffsetSettings={mapOffsetSettings}
        />
      )}
      
      {/* 노드 연결선 렌더링 */}
      {showConnections && connections.map((connection, index) => (
        <MapConnection
          key={index}
          connection={connection}
          nodes={nodes}
          mapInfo={map}
          theme={theme}
        />
      ))}
      
      {/* 노드 렌더링 */}
      {showNodes && nodes.map((node) => (
        <MapNode
          key={node.id}
          node={node}
          mapInfo={map}
          theme={theme}
          isSelected={selectedNode?.id === node.id}
          onHover={(node) => {
            setHoveredNode(node);
            onNodeHover?.(node);
          }}
          onHoverEnd={() => {
            setHoveredNode(null);
            onNodeHoverEnd?.();
          }}
          robots={robots}
          onMoveRequest={onMoveRequest}
        />
      ))}

    </group>
  );
};

export default MapRenderer3D; 