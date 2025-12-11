import React, { useState, useEffect } from 'react';
import * as THREE from 'three';
import { STLLoader } from 'three/examples/jsm/loaders/STLLoader.js';
import Scene3D from '../components/3d/Scene3D';
import Sidebar from '../components/main/Sidebar';
import MainViewOverlay from '../components/main/MainViewOverlay';
import MapControls from '../components/main/MapControls';
import RobotDetailModal from '../components/main/RobotDetailModal';
import MissionDetailModal from '../components/main/MissionDetailModal';
import TaskAddModal from '../components/main/TaskAddModal';
import { useAppContext } from '../contexts/AppContext.jsx';
import { calculateStats } from '../utils/mainPageUtils';
import { robotsAPI } from '../services/api';

const MainPage = () => {
  const { state, actions } = useAppContext();
  
  // 로봇과 미션 데이터 상태
  const [robots, setRobots] = useState([]);
  const [missions, setMissions] = useState([]);
  const [loading, setLoading] = useState({
    robots: true,
    missions: true
  });

  const [liveDataEnabled, setLiveDataEnabled] = useState(true);
  const [sidebarTab, setSidebarTab] = useState('robots');
  
  // localStorage에서 카메라 상태 로드
  const loadCameraState = () => {
    try {
      const savedCameraState = localStorage.getItem('cameraState');
      if (savedCameraState) {
        const parsed = JSON.parse(savedCameraState);
        return {
          viewMode: parsed.viewMode || 'overview',
          zoomLevel: parsed.zoomLevel || 1,
          trackedRobot: null, // 추적 로봇은 세션별로 초기화
          cameraPosition: parsed.cameraPosition || null,
          cameraTarget: parsed.cameraTarget || null,
          cameraRotation: parsed.cameraRotation || null
        };
      }
    } catch (error) {
      console.error('Failed to load camera state from localStorage:', error);
    }
    return {
      viewMode: 'overview',
      zoomLevel: 1,
      trackedRobot: null,
      cameraPosition: null,
      cameraTarget: null,
      cameraRotation: null
    };
  };

  // localStorage에 카메라 상태 저장
  const saveCameraState = (cameraState) => {
    try {
      localStorage.setItem('cameraState', JSON.stringify(cameraState));
    } catch (error) {
      console.error('Failed to save camera state to localStorage:', error);
    }
  };

  // 지도 컨트롤 상태
  const initialCameraState = loadCameraState();
  const [viewMode, setViewMode] = useState(initialCameraState.viewMode);
  const [zoomLevel, setZoomLevel] = useState(initialCameraState.zoomLevel);
  const [trackedRobot, setTrackedRobot] = useState(initialCameraState.trackedRobot);
  const [cameraState, setCameraState] = useState({
    position: initialCameraState.cameraPosition,
    target: initialCameraState.cameraTarget,
    rotation: initialCameraState.cameraRotation
  });
  
  // 맵 관련 상태
  const [availableMaps, setAvailableMaps] = useState([]);
  const [selectedMap, setSelectedMap] = useState(null);
  const [currentMapData, setCurrentMapData] = useState(null);
  const [mapLoading, setMapLoading] = useState(false);
  
  // STL 모델 관련 상태
  const [stlModel, setStlModel] = useState(null);
  const [showStlModel, setShowStlModel] = useState(false);
  const [stlLoading, setStlLoading] = useState(false);
  const [stlProgress, setStlProgress] = useState(0);
  const [stlMetadata, setStlMetadata] = useState(null);
  
  // 최소 로딩 시간 보장을 위한 상태
  const [minLoadingComplete, setMinLoadingComplete] = useState(false);
  const [dataLoadingComplete, setDataLoadingComplete] = useState(false);

  // 반응형 상태
  const [isMobile, setIsMobile] = useState(false);
  const [sidebarOpen, setSidebarOpen] = useState(false);
  
  // 로봇 상세정보 모달 상태
  const [showRobotDetail, setShowRobotDetail] = useState(false);
  const [selectedRobotDetail, setSelectedRobotDetail] = useState(null);
  
  // 미션 상세정보 모달 상태
  const [showMissionDetail, setShowMissionDetail] = useState(false);
  const [selectedMissionDetail, setSelectedMissionDetail] = useState(null);
  
  // 태스크 추가 모달 상태
  const [showTaskModal, setShowTaskModal] = useState(false);
  
  // 로봇 상세정보 모달 핸들러
  const handleShowRobotDetail = (robot) => {
    setSelectedRobotDetail(robot);
    setShowRobotDetail(true);
  };
  
  const handleCloseRobotDetail = () => {
    setShowRobotDetail(false);
    setSelectedRobotDetail(null);
  };

  // 미션 상세정보 모달 핸들러
  const handleShowMissionDetail = (mission) => {
    setSelectedMissionDetail(mission);
    setShowMissionDetail(true);
  };
  
  const handleCloseMissionDetail = () => {
    setShowMissionDetail(false);
    setSelectedMissionDetail(null);
  };

  // 미션 업데이트 핸들러
  const handleMissionUpdate = () => {

    loadMissions();
    loadRobots(); // 로봇 상태도 함께 업데이트 (미션 취소 시 로봇 상태도 변경됨)
  };

  // 활성 데이터
  const activeRobots = robots || [];
  const activeMissions = missions || [];
  
  // 통계 계산
  const stats = calculateStats(activeRobots);

  // API URL 설정
  const DEFAULT_API_URL = import.meta.env.DEV ? 'http://localhost:3000' : '';
  const API_URL = import.meta.env.VITE_API_URL || DEFAULT_API_URL;

  // 로봇 목록 로드
  const loadRobots = async () => {
    try {
      setLoading(prev => ({ ...prev, robots: true }));

      
      const response = await fetch(`${API_URL}/api/robots`);

      
      const data = await response.json();

      
      if (response.ok) {
        const robotsData = data.data || [];

        setRobots(robotsData);
        // AppContext에도 업데이트
        actions.setRobots(robotsData);
      } else {
        console.error('로봇 API 에러:', data);
        actions.addNotification && actions.addNotification({
          type: 'error',
          message: '로봇 목록을 불러오는데 실패했습니다.'
        });
      }
    } catch (error) {
      console.error('로봇 목록 가져오기 실패:', error);
      actions.addNotification && actions.addNotification({
        type: 'error',
        message: '서버 연결에 실패했습니다.'
      });
    } finally {
      setLoading(prev => ({ ...prev, robots: false }));
    }
  };

  // 미션 목록 로드
  const loadMissions = async () => {
    try {
      setLoading(prev => ({ ...prev, missions: true }));

      
      const response = await fetch(`${API_URL}/api/missions`);

      
      const data = await response.json();

      
      if (response.ok) {
        const missionsData = data.data || [];

        setMissions(missionsData);
      } else {
        console.error('미션 API 에러:', data);
        setMissions([]);
      }
    } catch (error) {
      console.error('미션 목록 가져오기 실패:', error);
      setMissions([]);
    } finally {
      setLoading(prev => ({ ...prev, missions: false }));
    }
  };

  // 맵 목록 가져오기
  const fetchAvailableMaps = async () => {

    
    try {
      const url = `${API_URL}/api/maps`;

      
      const response = await fetch(url);

      
      if (response.ok) {
        const maps = await response.json();

        setAvailableMaps(maps);
        
        // 첫 번째 맵을 기본 선택
        if (maps.length > 0 && !selectedMap) {

          setSelectedMap(maps[0]);
        }
      } else {
        console.error('fetchAvailableMaps: 맵 목록을 가져오는데 실패했습니다', response.status, response.statusText);
        const errorText = await response.text();
        console.error('fetchAvailableMaps: 에러 응답:', errorText);
      }
    } catch (error) {
      console.error('fetchAvailableMaps: 맵 목록 가져오기 실패:', error);
    }
  };

  // 맵 데이터 가져오기
  const fetchMapData = async (mapId) => {
    if (!mapId) {

      return;
    }
    

    
    try {
      setMapLoading(true);
      const url = `${API_URL}/api/maps/${mapId}/data?sample=1&limit=999999`;

      
      const response = await fetch(url);

      
      if (response.ok) {
        const mapData = await response.json();

        setCurrentMapData(mapData);
      } else {
        console.error('fetchMapData: 맵 데이터를 가져오는데 실패했습니다', response.status, response.statusText);
        const errorText = await response.text();
        console.error('fetchMapData: 에러 응답:', errorText);
      }
    } catch (error) {
      console.error('fetchMapData: 맵 데이터 가져오기 실패:', error);
    } finally {
      setMapLoading(false);
    }
  };

  // 맵 선택 핸들러
  const handleMapSelect = (map) => {
    setSelectedMap(map);
    setCurrentMapData(null);
    fetchMapData(map.id);
  };

  // 화면 크기 감지
  useEffect(() => {
    const checkScreenSize = () => {
      setIsMobile(window.innerWidth <= 768);
      // 모바일에서 데스크톱으로 변경될 때 사이드바 자동 열기
      if (window.innerWidth > 768) {
        setSidebarOpen(false);
      }
    };

    checkScreenSize();
    window.addEventListener('resize', checkScreenSize);
    return () => window.removeEventListener('resize', checkScreenSize);
  }, []);

  // 카메라 상태 변경 및 저장 핸들러
  const handleViewModeChange = (newViewMode) => {

    setViewMode(newViewMode);
    
    // 카메라 상태 저장
    const newCameraState = {
      viewMode: newViewMode,
      zoomLevel,
      cameraPosition: cameraState.position,
      cameraTarget: cameraState.target,
      cameraRotation: cameraState.rotation
    };
    saveCameraState(newCameraState);
  };

  const handleZoomChange = (newZoomLevel) => {

    setZoomLevel(newZoomLevel);
    
    // 카메라 상태 저장
    const newCameraState = {
      viewMode,
      zoomLevel: newZoomLevel,
      cameraPosition: cameraState.position,
      cameraTarget: cameraState.target,
      cameraRotation: cameraState.rotation
    };
    saveCameraState(newCameraState);
  };

  const handleRobotTrack = (robotId) => {

    setTrackedRobot(robotId);
  };

  // 3D 씬에서 카메라 상태 변경을 받는 핸들러
  const handleCameraStateChange = (newCameraState) => {
    setCameraState(newCameraState);
    
    // 카메라 상태 저장
    const stateTosave = {
      viewMode,
      zoomLevel,
      cameraPosition: newCameraState.position,
      cameraTarget: newCameraState.target,
      cameraRotation: newCameraState.rotation
    };
    saveCameraState(stateTosave);
  };

  // 컴포넌트 마운트 시 최소 로딩 시간 타이머 시작
  useEffect(() => {
    const minLoadingTimer = setTimeout(() => {
      setMinLoadingComplete(true);
    }, 3000); // 3초 최소 로딩 시간

    return () => clearTimeout(minLoadingTimer);
  }, []);

  // 컴포넌트 마운트 시 데이터 가져오기
  useEffect(() => {
    loadRobots();
    loadMissions();
    fetchAvailableMaps();
  }, []);

  // 실시간 데이터 업데이트 (500ms마다)
  useEffect(() => {
    if (!liveDataEnabled) return;

    const interval = setInterval(() => {

      loadRobots();
      loadMissions(); // 미션 데이터도 함께 업데이트
    }, 500);

    return () => clearInterval(interval);
  }, [liveDataEnabled]);

  // 선택된 맵이 변경될 때 맵 데이터 가져오기
  useEffect(() => {
    if (selectedMap) {
      fetchMapData(selectedMap.id);
    }
  }, [selectedMap]);

  // 실제 데이터 로딩 상태 체크
  useEffect(() => {
    if (!loading.robots && !loading.missions) {
      setDataLoadingComplete(true);
    }
  }, [loading.robots, loading.missions]);

  // 최소 로딩 시간과 데이터 로딩 둘 다 완료되어야 로딩 끝
  const isLoading = !minLoadingComplete || !dataLoadingComplete;

  // CSS 키프레임 스타일을 동적으로 주입
  useEffect(() => {
    const styleElement = document.createElement('style');
    styleElement.innerHTML = `
      @keyframes cyberspin {
        0% { transform: rotate(0deg); }
        100% { transform: rotate(360deg); }
      }
      
      @keyframes cyberspin-reverse {
        0% { transform: rotate(360deg); }
        100% { transform: rotate(0deg); }
      }
      
      @keyframes pulse-glow {
        0%, 100% { 
          opacity: 1;
          transform: translate(-50%, -50%) scale(1);
          box-shadow: 0 0 30px var(--primary-color);
        }
        50% { 
          opacity: 0.7;
          transform: translate(-50%, -50%) scale(1.2);
          box-shadow: 0 0 50px var(--primary-color), 0 0 80px var(--border-accent);
        }
      }
      
      @keyframes particle-orbit {
        0% { 
          transform: translate(-50%, -50%) rotate(0deg) translateY(-${isMobile ? '30px' : '45px'});
          opacity: 1;
        }
        50% { 
          opacity: 0.5;
        }
        100% { 
          transform: translate(-50%, -50%) rotate(360deg) translateY(-${isMobile ? '30px' : '45px'});
          opacity: 1;
        }
      }
      
      @keyframes text-glow {
        0% { 
          text-shadow: 0 0 20px var(--primary-color);
        }
        100% { 
          text-shadow: 0 0 30px var(--primary-color), 0 0 40px var(--accent-color);
        }
      }
      
      @keyframes text-fade {
        0% { opacity: 0.6; }
        100% { opacity: 1; }
      }
    `;
    document.head.appendChild(styleElement);

    return () => {
      document.head.removeChild(styleElement);
    };
  }, [isMobile]);

  // 사이드바 토글 함수
  const toggleSidebar = () => {
    setSidebarOpen(!sidebarOpen);
  };

  // 모바일에서 사이드바 외부 클릭 시 닫기
  const handleOverlayClick = () => {
    if (isMobile && sidebarOpen) {
      setSidebarOpen(false);
    }
  };

  // AMR 이동 요청 핸들러
  const handleMoveRequest = async (robotId, nodeId) => {
    try {

      
      // API 호출
      const result = await robotsAPI.requestMove(robotId, nodeId);

      
      // 알림 표시
      if (actions.addNotification) {
        actions.addNotification({
          type: 'success',
          message: `AMR 이동 요청이 완료되었습니다. (로봇 ID: ${robotId}, 노드 ID: ${nodeId})`
        });
      }
      
      // 로봇 데이터 새로고침 (이동 상태 반영)
      setTimeout(() => {
        loadRobots();
      }, 1000);
      
    } catch (error) {
      console.error('AMR 이동 요청 실패:', error);
      
      // 에러 알림 표시
      if (actions.addNotification) {
        actions.addNotification({
          type: 'error',
          message: error.message || 'AMR 이동 요청에 실패했습니다.'
        });
      }
    }
  };

  // STL 로컬 저장 헬퍼 (새로고침 이후 복원용)
  const saveStlToStorage = (arrayBuffer, metadata) => {
    try {
      const bytes = new Uint8Array(arrayBuffer);
      let binary = '';
      for (let i = 0; i < bytes.length; i++) {
        binary += String.fromCharCode(bytes[i]);
      }
      const base64 = btoa(binary);
      const payload = { base64, metadata };
      localStorage.setItem('stlModelData', JSON.stringify(payload));
    } catch (error) {
      console.error('STL localStorage 저장 실패:', error);
    }
  };

  // STL 표시 파라미터 초기값 로드 (V2)
  const loadStlSettingsV2 = () => {
    const defaults = {
      stlRotationDeg: 90,
      stlPosX: 0,
      stlPosY: 0,
      stlPosZ: 0,
      arrowScale: 1,
      arrowPosX: 0,
      arrowPosY: 0,
      arrowPosZ: 0,
      arrowRotationDeg: 180
    };
    try {
      const saved = localStorage.getItem('stlSettingsV2');
      if (!saved) return defaults;
      const parsed = JSON.parse(saved);
      return {
        stlRotationDeg: typeof parsed.stlRotationDeg === 'number' ? parsed.stlRotationDeg : defaults.stlRotationDeg,
        stlPosX: typeof parsed.stlPosX === 'number' ? parsed.stlPosX : defaults.stlPosX,
        stlPosY: typeof parsed.stlPosY === 'number' ? parsed.stlPosY : defaults.stlPosY,
        // 과거 데이터 호환: stlPosZ가 없으면 예전 stlPosY를 Z로 사용
        stlPosZ: typeof parsed.stlPosZ === 'number'
          ? parsed.stlPosZ
          : (typeof parsed.stlPosY === 'number' ? parsed.stlPosY : defaults.stlPosZ),
        arrowScale: typeof parsed.arrowScale === 'number' ? parsed.arrowScale : defaults.arrowScale,
        arrowPosX: typeof parsed.arrowPosX === 'number' ? parsed.arrowPosX : defaults.arrowPosX,
        arrowPosY: typeof parsed.arrowPosY === 'number' ? parsed.arrowPosY : defaults.arrowPosY,
        arrowPosZ: typeof parsed.arrowPosZ === 'number'
          ? parsed.arrowPosZ
          : (typeof parsed.arrowPosY === 'number' ? parsed.arrowPosY : defaults.arrowPosZ),
        arrowRotationDeg: typeof parsed.arrowRotationDeg === 'number' ? parsed.arrowRotationDeg : defaults.arrowRotationDeg
      };
    } catch (error) {
      console.error('STL 설정 로드 실패:', error);
      return defaults;
    }
  };

  const [stlSettings, setStlSettings] = useState(loadStlSettingsV2());

  // 배경 이미지 오프셋 초기값 로드
  const loadMapOffsetSettings = () => {
    const defaults = {
      rotationDeg: 0,
      offsetX: 0,
      offsetY: 0,
      scale: 1
    };
    try {
      const saved = localStorage.getItem('mapOffsetSettings');
      if (!saved) return defaults;
      const parsed = JSON.parse(saved);
      return {
        rotationDeg: typeof parsed.rotationDeg === 'number' ? parsed.rotationDeg : defaults.rotationDeg,
        offsetX: typeof parsed.offsetX === 'number' ? parsed.offsetX : defaults.offsetX,
        offsetY: typeof parsed.offsetY === 'number' ? parsed.offsetY : defaults.offsetY,
        scale: typeof parsed.scale === 'number' ? parsed.scale : defaults.scale
      };
    } catch (error) {
      console.error('맵 오프셋 설정 로드 실패:', error);
      return defaults;
    }
  };

  const [mapOffsetSettings, setMapOffsetSettings] = useState(loadMapOffsetSettings());

  // STL 파일 업로드 핸들러 (로컬 파싱)
  const handleStlUpload = async (file) => {
    const previousGeometry = stlModel?.geometry || null;
    try {
      console.log('🎯 MainPage: STL 파일 로드 시작:', {
        fileName: file.name,
        fileSize: `${(file.size / 1024 / 1024).toFixed(2)} MB`,
        fileType: file.type,
        lastModified: new Date(file.lastModified).toISOString()
      });

      setStlModel(null);
      setStlMetadata(null);
      setShowStlModel(false);
      setStlLoading(true);
      setStlProgress(0);

      const arrayBuffer = await new Promise((resolve, reject) => {
        const reader = new FileReader();
        reader.onload = (event) => resolve(event.target.result);
        reader.onerror = () => reject(new Error('STL 파일을 읽을 수 없습니다.'));
        reader.onprogress = (event) => {
          if (event.lengthComputable) {
            const percent = Math.min(100, Math.round((event.loaded / event.total) * 100));
            setStlProgress(percent);
          }
        };
        reader.readAsArrayBuffer(file);
      });

      const loader = new STLLoader();
      let geometry = loader.parse(arrayBuffer);
      geometry.computeVertexNormals();
      geometry.computeBoundingBox();

      let bbox = geometry.boundingBox;
      const sizeVec = new THREE.Vector3();
      bbox.getSize(sizeVec);

      // 수평(XZ) 중심 정렬 + 바닥(Y=0)에 딱 맞추기
      const offsetX = - (bbox.min.x + bbox.max.x) / 2;
      const offsetZ = - (bbox.min.z + bbox.max.z) / 2;
      const offsetY = -bbox.min.y;
      geometry.translate(offsetX, offsetY, offsetZ);
      geometry.computeBoundingBox();
      bbox = geometry.boundingBox;

      const size = {
        x: Number((bbox.max.x - bbox.min.x).toFixed(2)),
        y: Number((bbox.max.y - bbox.min.y).toFixed(2)),
        z: Number((bbox.max.z - bbox.min.z).toFixed(2))
      };

      const metadata = {
        fileName: file.name,
        size,
        uploadedAt: new Date().toISOString()
      };

      setStlModel({
        geometry,
        metadata
      });
      previousGeometry?.dispose();
      setStlMetadata(metadata);
      setShowStlModel(true);

      actions.addNotification({
        type: 'success',
        message: `STL "${file.name}" 로드 완료. 크기 ${metadata.size.x}×${metadata.size.y}×${metadata.size.z}`
      });

      // 새로고침 후 복원을 위해 저장
      saveStlToStorage(arrayBuffer, metadata);
    } catch (error) {
      console.error('💥 MainPage: STL 로드 오류:', error);
      setStlModel(null);
      setShowStlModel(false);
      actions.addNotification({
        type: 'error',
        message: error.message || 'STL 파일을 불러오지 못했습니다.'
      });
      throw error;
    } finally {
      setStlLoading(false);
      setStlProgress(0);
    }
  };

  // STL 표시/숨김 토글
  const handleToggleStlModel = () => {
    setShowStlModel(prev => !prev);

    actions.addNotification({
      type: 'info',
      message: `STL 모델이 ${!showStlModel ? '표시' : '숨김'}됩니다.`
    });
  };

  // STL 설정 변경 헬퍼
  const updateStlSettings = (patch) => {
    setStlSettings(prev => ({ ...prev, ...patch }));
  };

  // 배경 이미지 오프셋 변경 헬퍼
  const updateMapOffsetSettings = (patch) => {
    setMapOffsetSettings(prev => ({ ...prev, ...patch }));
  };

  // STL 설정 저장 (각도, 위치, 세모 크기/위치/방향)
  useEffect(() => {
    try {
      localStorage.setItem('stlSettingsV2', JSON.stringify(stlSettings));
    } catch (error) {
      console.error('STL 설정 저장 실패:', error);
    }
  }, [stlSettings]);

  // 배경 이미지 오프셋 설정 저장
  useEffect(() => {
    try {
      localStorage.setItem('mapOffsetSettings', JSON.stringify(mapOffsetSettings));
    } catch (error) {
      console.error('맵 오프셋 설정 저장 실패:', error);
    }
  }, [mapOffsetSettings]);

  // 새로고침 이후 STL 메쉬 복원
  useEffect(() => {
    (async () => {
      try {
        const saved = localStorage.getItem('stlModelData');
        if (!saved) return;

        const parsed = JSON.parse(saved);
        if (!parsed.base64 || !parsed.metadata) return;

        const binary = atob(parsed.base64);
        const len = binary.length;
        const arrayBuffer = new ArrayBuffer(len);
        const bytes = new Uint8Array(arrayBuffer);
        for (let i = 0; i < len; i++) {
          bytes[i] = binary.charCodeAt(i);
        }

        const loader = new STLLoader();
        let geometry = loader.parse(arrayBuffer);
        geometry.computeVertexNormals();
        geometry.computeBoundingBox();

        let bbox = geometry.boundingBox;
        const offsetX = - (bbox.min.x + bbox.max.x) / 2;
        const offsetZ = - (bbox.min.z + bbox.max.z) / 2;
        const offsetY = -bbox.min.y;
        geometry.translate(offsetX, offsetY, offsetZ);
        geometry.computeBoundingBox();

        setStlModel({ geometry, metadata: parsed.metadata });
        setStlMetadata(parsed.metadata);
        setShowStlModel(true);
      } catch (error) {
        console.error('저장된 STL 복원 실패:', error);
        localStorage.removeItem('stlModelData');
      }
    })();
  }, []);

  return (
    <div style={{
      width: '100%',
      height: '100vh',
      display: 'flex',
      flexDirection: 'column',
      backgroundColor: 'var(--bg-primary)',
      color: 'var(--text-primary)',
      fontFamily: 'Pretendard, sans-serif',
      overflow: 'hidden'
    }}>
      {/* 메인 콘텐츠 영역 */}
      <div style={{ flex: 1, display: 'flex', overflow: 'hidden', position: 'relative' }}>
        {/* 모바일 햄버거 메뉴 */}
        {isMobile && (
          <button
            onClick={toggleSidebar}
            style={{
              position: 'absolute',
              top: 'var(--space-md)',
              left: 'var(--space-md)',
              width: '48px',
              height: '48px',
              backgroundColor: 'var(--bg-secondary)',
              border: '1px solid var(--border-primary)',
              borderRadius: 'var(--radius-md)',
              color: 'var(--text-primary)',
              fontSize: 'var(--font-size-lg)',
              cursor: 'pointer',
              zIndex: 1000,
              display: 'flex',
              alignItems: 'center',
              justifyContent: 'center',
              transition: 'all 0.3s ease',
              boxShadow: '0 4px 12px rgba(0, 0, 0, 0.3)'
            }}
            onMouseEnter={(e) => {
              e.currentTarget.style.backgroundColor = 'var(--bg-tertiary)';
              e.currentTarget.style.borderColor = 'var(--primary-color)';
            }}
            onMouseLeave={(e) => {
              e.currentTarget.style.backgroundColor = 'var(--bg-secondary)';
              e.currentTarget.style.borderColor = 'var(--border-primary)';
            }}
          >
            <i className={sidebarOpen ? "fas fa-times" : "fas fa-bars"}></i>
          </button>
        )}

        {/* 모바일 오버레이 */}
        {isMobile && sidebarOpen && (
          <div
            onClick={handleOverlayClick}
            style={{
              position: 'absolute',
              top: 0,
              left: 0,
              width: '100%',
              height: '100%',
              backgroundColor: 'rgba(0, 0, 0, 0.5)',
              zIndex: 999,
              backdropFilter: 'blur(4px)'
            }}
          />
        )}

        {/* 왼쪽 사이드바 */}
        <div style={{
          width: isMobile ? '280px' : '350px',
          transform: isMobile ? (sidebarOpen ? 'translateX(0)' : 'translateX(-100%)') : 'translateX(0)',
          transition: 'transform 0.3s ease',
          position: isMobile ? 'absolute' : 'relative',
          height: '100vh',
          zIndex: 1000
        }}>
          <Sidebar
            sidebarTab={sidebarTab}
            setSidebarTab={setSidebarTab}
            robots={activeRobots}
            missions={activeMissions}
            trackedRobot={trackedRobot}
            onShowRobotDetail={handleShowRobotDetail}
            onShowMissionDetail={handleShowMissionDetail}
            onTrackToggle={handleRobotTrack}
            isLoading={isLoading}
            isMobile={isMobile}
            onClose={() => setSidebarOpen(false)}
            onOpenTaskModal={() => setShowTaskModal(true)}
          />
        </div>

        {/* 중앙: 3D 뷰 또는 로딩 화면 */}
        <div style={{
          flex: 1,
          position: 'relative',
          backgroundColor: 'var(--bg-primary)',
          marginLeft: isMobile ? '0' : '0' // 모바일에서는 사이드바가 오버레이되므로 마진 없음
        }}>
          {isLoading ? (
            // 로딩 화면
            <div style={{
              display: 'flex',
              alignItems: 'center',
              justifyContent: 'center',
              height: '100%',
              flexDirection: 'column',
              gap: 'var(--space-xl)'
            }}>
              {/* 사이버네틱 로딩 아이콘 */}
              <div style={{
                position: 'relative',
                width: isMobile ? '80px' : '120px',
                height: isMobile ? '80px' : '120px'
              }}>
                {/* 외부 링 */}
                <div style={{
                  position: 'absolute',
                  width: '100%',
                  height: '100%',
                  border: '3px solid transparent',
                  borderTop: '3px solid var(--primary-color)',
                  borderRight: '3px solid var(--accent-color)',
                  borderRadius: '50%',
                  animation: 'cyberspin 2s linear infinite',
                  boxShadow: '0 0 20px var(--primary-color), inset 0 0 20px var(--border-accent)'
                }}></div>
                
                {/* 중간 링 */}
                <div style={{
                  position: 'absolute',
                  top: '15px',
                  left: '15px',
                  width: 'calc(100% - 30px)',
                  height: 'calc(100% - 30px)',
                  border: '2px solid transparent',
                  borderTop: '2px solid var(--accent-color)',
                  borderLeft: '2px solid var(--primary-color)',
                  borderRadius: '50%',
                  animation: 'cyberspin-reverse 1.5s linear infinite',
                  boxShadow: '0 0 15px var(--accent-color)'
                }}></div>
                
                {/* 내부 링 */}
                <div style={{
                  position: 'absolute',
                  top: '30px',
                  left: '30px',
                  width: 'calc(100% - 60px)',
                  height: 'calc(100% - 60px)',
                  border: '1px solid transparent',
                  borderTop: '1px solid var(--primary-color)',
                  borderBottom: '1px solid var(--accent-color)',
                  borderRadius: '50%',
                  animation: 'cyberspin 1s linear infinite',
                  boxShadow: '0 0 10px var(--primary-color)'
                }}></div>
                
                {/* 중앙 코어 */}
                <div style={{
                  position: 'absolute',
                  top: '50%',
                  left: '50%',
                  transform: 'translate(-50%, -50%)',
                  width: isMobile ? '12px' : '20px',
                  height: isMobile ? '12px' : '20px',
                  backgroundColor: 'var(--primary-color)',
                  borderRadius: '50%',
                  animation: 'pulse-glow 2s ease-in-out infinite',
                  boxShadow: '0 0 30px var(--primary-color)'
                }}></div>
                
                {/* 빛 파티클들 */}
                {[...Array(8)].map((_, i) => (
                  <div
                    key={i}
                    style={{
                      position: 'absolute',
                      top: '50%',
                      left: '50%',
                      width: isMobile ? '2px' : '4px',
                      height: isMobile ? '2px' : '4px',
                      backgroundColor: 'var(--accent-color)',
                      borderRadius: '50%',
                      transform: `translate(-50%, -50%) rotate(${i * 45}deg) translateY(-${isMobile ? '30px' : '45px'})`,
                      animation: `particle-orbit 3s linear infinite ${i * 0.125}s`,
                      boxShadow: '0 0 10px var(--accent-color)'
                    }}
                  ></div>
                ))}
              </div>

              <div style={{
                color: 'var(--text-primary)',
                fontSize: isMobile ? 'var(--font-size-lg)' : 'var(--font-size-xl)',
                fontWeight: '600',
                letterSpacing: '0.1em',
                textTransform: 'uppercase',
                textAlign: 'center',
                animation: 'text-glow 2s ease-in-out infinite alternate'
              }}>
                시스템 초기화 중...
              </div>
              
              <div style={{
                color: 'var(--text-tertiary)',
                fontSize: 'var(--font-size-sm)',
                textAlign: 'center',
                animation: 'text-fade 1.5s ease-in-out infinite alternate',
                padding: isMobile ? '0 var(--space-md)' : '0'
              }}>
                ACS 제어 시스템을 준비하고 있습니다
              </div>
              
              {/* 진행률 표시 */}
              <div style={{
                color: 'var(--text-tertiary)',
                fontSize: 'var(--font-size-xs)',
                textAlign: 'center',
                marginTop: 'var(--space-md)'
              }}>
                {!dataLoadingComplete ? '데이터 로딩 중...' : 
                 !minLoadingComplete ? '시스템 준비 중...' : '완료'}
              </div>
            </div>
          ) : (
            // 정상 3D 뷰
            <>
              <Scene3D 
                robots={activeRobots}
                missions={activeMissions}
                viewMode={viewMode}
                showPaths={true}
                showStations={true}
                showGrid={true}
                showLabels={true}
                zoomLevel={zoomLevel}
                trackedRobot={trackedRobot}
                mapData={currentMapData}
                showMapData={!!currentMapData}
                initialCameraState={cameraState}
                onCameraStateChange={handleCameraStateChange}
                onMoveRequest={handleMoveRequest}
                stlModel={stlModel}
                showStlModel={showStlModel}
                stlSettings={stlSettings}
                mapOffsetSettings={mapOffsetSettings}
              />
              <MainViewOverlay stats={stats} />
              <MapControls
                robots={activeRobots}
                onViewModeChange={handleViewModeChange}
                onZoomChange={handleZoomChange}
                onRobotTrack={handleRobotTrack}
                viewMode={viewMode}
                trackedRobot={trackedRobot}
                zoomLevel={zoomLevel}
                availableMaps={availableMaps}
                selectedMap={selectedMap}
                onMapSelect={handleMapSelect}
                mapLoading={mapLoading}
                onStlUpload={handleStlUpload}
                showStlModel={showStlModel}
                onToggleStlModel={handleToggleStlModel}
                stlLoading={stlLoading}
                stlProgress={stlProgress}
                stlMetadata={stlMetadata}
                stlSettings={stlSettings}
                onStlSettingsChange={updateStlSettings}
                mapOffsetSettings={mapOffsetSettings}
                onMapOffsetChange={updateMapOffsetSettings}
              />
            </>
          )}
        </div>
      </div>
      
      {/* 로봇 상세정보 모달 */}
      <RobotDetailModal
        robot={selectedRobotDetail}
        isOpen={showRobotDetail}
        onClose={handleCloseRobotDetail}
      />

      {/* 미션 상세정보 모달 */}
      <MissionDetailModal
        mission={selectedMissionDetail}
        isOpen={showMissionDetail}
        onClose={handleCloseMissionDetail}
        onMissionUpdate={handleMissionUpdate}
      />

      {/* 태스크 추가 모달 */}
      <TaskAddModal
        isOpen={showTaskModal}
        onClose={() => setShowTaskModal(false)}
        onTaskCreated={() => {
          // 미션 및 로봇 목록 새로고침
          loadMissions();
          loadRobots(); // 로봇 상태도 업데이트 (새 작업 할당으로 인한 상태 변경)
          setShowTaskModal(false);
        }}
        robots={activeRobots}
        mapData={currentMapData}
      />
    </div>
  );
};

export default MainPage; 