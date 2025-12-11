import React, { useState, useEffect } from 'react';
import { useAppContext } from '../contexts/AppContext.jsx';
import RobotManagementSection from '../components/settings/RobotManagementSection.jsx';
import * as yaml from 'js-yaml';

const SettingsPage = () => {
  const { state, actions } = useAppContext();
  const [localSettings, setLocalSettings] = useState({
    // 맵 관리 관련 상태
    extractedMapName: '',
    imageFile: null,
    metadataFile: null,
    nodesFile: null,
    selectedRobotMaps: {}, // 로봇별 맵 목록 저장
    expandedRobots: {} // 로봇별 확장 상태 저장
  });

  const [serverMaps, setServerMaps] = useState([]);
  const [robots, setRobots] = useState([]);
  const [loading, setLoading] = useState({
    maps: false,
    robots: false,
    robotMaps: {}, // 로봇별 맵 로딩 상태
    downloadingMaps: {} // 맵 다운로드 중 상태 {robotId-mapId: true/false}
  });

  const [downloadedMaps, setDownloadedMaps] = useState({}); // 다운로드 완료 상태 {robotId-mapId: true/false}

  // API URL 설정
  const API_URL = import.meta.env.VITE_API_URL || 'http://localhost:3000';

  // 서버에서 맵 목록 가져오기
  const fetchServerMaps = async () => {
    setLoading(prev => ({ ...prev, maps: true }));
    try {
      const response = await fetch(`${API_URL}/api/maps`);
      if (response.ok) {
        const maps = await response.json();
        setServerMaps(maps);
      } else {
        actions.addNotification({
          type: 'error',
          message: '맵 목록을 불러오는데 실패했습니다.'
        });
        setServerMaps([]);
      }
    } catch (error) {
      console.error('맵 목록 가져오기 실패:', error);
      actions.addNotification({
        type: 'error',
        message: '서버 연결에 실패했습니다.'
      });
      setServerMaps([]);
    } finally {
      setLoading(prev => ({ ...prev, maps: false }));
    }
  };

  // 로봇 목록 로드
  const loadRobots = async () => {
    try {
      setLoading(prev => ({ ...prev, robots: true }));
      const response = await fetch(`${API_URL}/api/robots`);
      const data = await response.json();
      
      if (response.ok) {
        setRobots(data.data || []);
        // AppContext에도 업데이트
        actions.setRobots(data.data || []);
      } else {
        actions.addNotification({
          type: 'error',
          message: '로봇 목록을 불러오는데 실패했습니다.'
        });
      }
    } catch (error) {
      console.error('로봇 목록 가져오기 실패:', error);
      actions.addNotification({
        type: 'error',
        message: '서버 연결에 실패했습니다.'
      });
    } finally {
      setLoading(prev => ({ ...prev, robots: false }));
    }
  };

  // 로봇 추가
  const handleAddRobot = async (robotData) => {
    try {
      const response = await fetch(`${API_URL}/api/robots`, {
        method: 'POST',
        headers: {
          'Content-Type': 'application/json',
        },
        body: JSON.stringify(robotData),
      });

      const data = await response.json();

      if (response.ok) {
        actions.addNotification({
          type: 'success',
          message: '로봇이 성공적으로 추가되었습니다.'
        });
        loadRobots(); // 목록 새로고침
      } else {
        actions.addNotification({
          type: 'error',
          message: data.error || '로봇 추가에 실패했습니다.'
        });
      }
    } catch (error) {
      actions.addNotification({
        type: 'error',
        message: '서버 연결에 실패했습니다.'
      });
    }
  };

  // 로봇 삭제
  const handleDeleteRobot = async (robotId) => {
    if (!confirm('정말로 이 로봇을 삭제하시겠습니까?')) {
      return;
    }

    try {
      const response = await fetch(`${API_URL}/api/robots/${robotId}`, {
        method: 'DELETE',
      });

      const data = await response.json();

      if (response.ok) {
        actions.addNotification({
          type: 'success',
          message: '로봇이 성공적으로 삭제되었습니다.'
        });
        loadRobots(); // 목록 새로고침
      } else {
        actions.addNotification({
          type: 'error',
          message: data.error || '로봇 삭제에 실패했습니다.'
        });
      }
    } catch (error) {
      actions.addNotification({
        type: 'error',
        message: '서버 연결에 실패했습니다.'
      });
    }
  };

  // 컴포넌트 마운트 시 데이터 가져오기
  useEffect(() => {
    fetchServerMaps();
    loadRobots();
    
    // 애니메이션 및 스크롤바 CSS 추가
    const styleId = 'robot-maps-animations';
    if (!document.getElementById(styleId)) {
      const style = document.createElement('style');
      style.id = styleId;
      style.innerHTML = `
        @keyframes fadeInUp {
          from {
            opacity: 0;
            transform: translateY(10px);
          }
          to {
            opacity: 1;
            transform: translateY(0);
          }
        }
        
        /* 테마 스크롤바 스타일 */
        .robot-maps-scroll {
          scrollbar-width: thin;
          scrollbar-color: var(--border-accent) transparent;
        }
        
        .robot-maps-scroll::-webkit-scrollbar {
          width: 6px;
        }
        
        .robot-maps-scroll::-webkit-scrollbar-track {
          background: transparent;
        }
        
        .robot-maps-scroll::-webkit-scrollbar-thumb {
          background: var(--border-accent);
          border-radius: 3px;
          transition: all 0.3s ease;
        }
        
        .robot-maps-scroll::-webkit-scrollbar-thumb:hover {
          background: var(--primary-color);
          box-shadow: var(--shadow-glow);
        }
      `;
      document.head.appendChild(style);
    }
    
    // 컴포넌트 언마운트 시 스타일 제거
    return () => {
      const styleToRemove = document.getElementById(styleId);
      if (styleToRemove) {
        styleToRemove.remove();
      }
    };
  }, []);

  const handleSettingChange = (setting, value) => {
    setLocalSettings(prev => ({ ...prev, [setting]: value }));
  };

  const extractMapNameFromMetadata = (metadataContent) => {
    if (!metadataContent || !metadataContent.image) {
      return '';
    }
    
    const imageName = metadataContent.image;
    // .pgm, .jpg, .png, .jpeg 등의 확장자를 제거
    const mapName = imageName.replace(/\.(pgm|jpg|jpeg|png)$/i, '');
    return mapName;
  };

  const handleFileUpload = (fileType, event) => {
    const file = event.target.files[0];
    if (file) {
      setLocalSettings(prev => ({
        ...prev,
        [fileType]: file
      }));

      // 메타데이터 파일인 경우 자동으로 맵 이름 추출
      if (fileType === 'metadataFile') {
        const reader = new FileReader();
        reader.onload = (e) => {
          try {
            const yamlContent = yaml.load(e.target.result);
            const extractedName = extractMapNameFromMetadata(yamlContent);
            setLocalSettings(prev => ({
              ...prev,
              extractedMapName: extractedName
            }));
          } catch (error) {
            console.error('YAML 파싱 오류:', error);
            actions.addNotification({
              type: 'error',
              message: 'YAML 파일을 읽는 중 오류가 발생했습니다.'
            });
          }
        };
        reader.readAsText(file);
      }
    }
  };

  const removeMapFile = (fileType) => {
    setLocalSettings(prev => {
      const newSettings = {
        ...prev,
        [fileType]: null
      };
      
      // 메타데이터 파일 제거 시 추출된 맵 이름도 초기화
      if (fileType === 'metadataFile') {
        newSettings.extractedMapName = '';
      }
      
      return newSettings;
    });
  };

  const handleMapUpload = async () => {
    if (!localSettings.metadataFile && !localSettings.extractedMapName.trim()) {
      actions.addNotification({
        type: 'error',
        message: '메타데이터 파일이 없으면 맵 이름을 자동으로 추출할 수 없습니다.'
      });
      return;
    }

    if (!localSettings.imageFile && !localSettings.metadataFile && !localSettings.nodesFile) {
      actions.addNotification({
        type: 'error',
        message: '최소한 하나의 파일을 업로드해야 합니다.'
      });
      return;
    }

    try {
      const formData = new FormData();
      formData.append('name', localSettings.extractedMapName);
      
      if (localSettings.imageFile) {
        formData.append('image', localSettings.imageFile);
      }
      if (localSettings.metadataFile) {
        formData.append('metadata', localSettings.metadataFile);
      }
      if (localSettings.nodesFile) {
        formData.append('nodes', localSettings.nodesFile);
      }

      const response = await fetch(`${API_URL}/api/maps`, {
        method: 'POST',
        body: formData
      });

      const data = await response.json();

      if (response.ok) {
        actions.addNotification({
          type: 'success',
          message: '맵이 성공적으로 업로드되었습니다.'
        });
        
        // 입력 필드 초기화
        setLocalSettings(prev => ({
          ...prev,
          extractedMapName: '',
          imageFile: null,
          metadataFile: null,
          nodesFile: null
        }));
        
        // 맵 목록 새로고침
        fetchServerMaps();
      } else {
        actions.addNotification({
          type: 'error',
          message: data.error || '맵 업로드에 실패했습니다.'
        });
      }
    } catch (error) {
      console.error('맵 업로드 에러:', error);
      actions.addNotification({
        type: 'error',
        message: '서버 연결에 실패했습니다.'
      });
    }
  };

  const handleMapDownload = async (mapId, fileType) => {
    try {
      const response = await fetch(`${API_URL}/api/maps/${mapId}/download/${fileType}`);
      
      if (response.ok) {
        const blob = await response.blob();
        const url = window.URL.createObjectURL(blob);
        const a = document.createElement('a');
        a.href = url;
        a.download = `map_${mapId}_${fileType}`;
        document.body.appendChild(a);
        a.click();
        window.URL.revokeObjectURL(url);
        document.body.removeChild(a);
      } else {
        actions.addNotification({
          type: 'error',
          message: '파일 다운로드에 실패했습니다.'
        });
      }
    } catch (error) {
      console.error('파일 다운로드 에러:', error);
      actions.addNotification({
        type: 'error',
        message: '서버 연결에 실패했습니다.'
      });
    }
  };

  const handleMapDelete = async (mapId) => {
    if (!confirm('정말로 이 맵을 삭제하시겠습니까?')) {
      return;
    }

    try {
      const response = await fetch(`${API_URL}/api/maps/${mapId}`, {
        method: 'DELETE'
      });

      const data = await response.json();

      if (response.ok) {
        actions.addNotification({
          type: 'success',
          message: '맵이 성공적으로 삭제되었습니다.'
        });
        fetchServerMaps();
      } else {
        actions.addNotification({
          type: 'error',
          message: data.error || '맵 삭제에 실패했습니다.'
        });
      }
    } catch (error) {
      console.error('맵 삭제 에러:', error);
      actions.addNotification({
        type: 'error',
        message: '서버 연결에 실패했습니다.'
      });
    }
  };

  const handleToggleRobotMaps = async (robotId) => {
    const isCurrentlyExpanded = localSettings.expandedRobots[robotId];
    
    // 토글 상태 업데이트
    setLocalSettings(prev => ({
      ...prev,
      expandedRobots: {
        ...prev.expandedRobots,
        [robotId]: !isCurrentlyExpanded
      }
    }));
    
    // 확장하는 경우에만 맵 목록 가져오기
    if (!isCurrentlyExpanded) {
      // 로딩 상태 시작
      setLoading(prev => ({
        ...prev,
        robotMaps: {
          ...prev.robotMaps,
          [robotId]: true
        }
      }));
      
      try {
        // AMR에서 실제 맵 목록 가져오기
        const response = await fetch(`${API_URL}/api/robots/${robotId}/maps`);
        let robotMaps = [];
        
        if (response.ok) {
          const result = await response.json();
          
          // Backend 응답 형식: { success, data: { maps, currentMapId, currentMapName } }
          if (result.success && result.data && result.data.maps) {
            // 활성화된 맵을 제일 위로 정렬
            robotMaps = result.data.maps.sort((a, b) => {
              if (a.isActive && !b.isActive) return -1;
              if (!a.isActive && b.isActive) return 1;
              return 0;
            });
            
            const robot = robots.find(r => r.id === robotId);
            actions.addNotification({
              type: 'success',
              message: `${robot?.name || '로봇'}의 맵 목록을 조회했습니다. (현재 맵: ${result.data.currentMapName || result.data.currentMapId})`
            });
          } else {
            throw new Error('맵 데이터 형식이 올바르지 않습니다.');
          }
        } else {
          // API 실패 시 에러 메시지 표시
          const errorData = await response.json().catch(() => ({}));
          throw new Error(errorData.message || errorData.error || '맵 목록 조회 실패');
        }
        
        setLocalSettings(prev => ({
          ...prev,
          selectedRobotMaps: {
            ...prev.selectedRobotMaps,
            [robotId]: robotMaps
          }
        }));

      } catch (error) {
        console.error('로봇 맵 목록 가져오기 실패:', error);
        
        const robot = robots.find(r => r.id === robotId);
        actions.addNotification({
          type: 'error',
          message: `${robot?.name || '로봇'}의 맵 목록을 가져오는데 실패했습니다: ${error.message}`
        });
        
        // 오류 발생 시 확장 상태 되돌리기
        setLocalSettings(prev => ({
          ...prev,
          expandedRobots: {
            ...prev.expandedRobots,
            [robotId]: false
          }
        }));
      } finally {
        // 로딩 상태 종료
        setLoading(prev => ({
          ...prev,
          robotMaps: {
            ...prev.robotMaps,
            [robotId]: false
          }
        }));
      }
    }
  };

  // 개별 로봇 맵 업로드 핸들러
  const handleRobotMapUpload = (robotId) => {
    const input = document.createElement('input');
    input.type = 'file';
    input.accept = '.jpg,.jpeg,.png,.pgm,.yaml,.yml';
    input.multiple = true;
    input.onchange = async (e) => {
      const files = Array.from(e.target.files);
      if (files.length > 0) {
        await uploadMapToRobot(robotId, files);
      }
    };
    input.click();
  };

  // 전체 로봇 맵 업로드 핸들러
  const handleBulkRobotMapUpload = () => {
    const input = document.createElement('input');
    input.type = 'file';
    input.accept = '.jpg,.jpeg,.png,.pgm,.yaml,.yml';
    input.multiple = true;
    input.onchange = async (e) => {
      const files = Array.from(e.target.files);
      if (files.length > 0) {
        await uploadMapToBulk(files);
      }
    };
    input.click();
  };

  // 개별 로봇 맵 업로드 함수
  const uploadMapToRobot = async (robotId, files) => {
    try {
      const formData = new FormData();
      files.forEach(file => {
        formData.append('files', file);
      });
      
      const response = await fetch(`${API_URL}/api/robots/${robotId}/map-upload`, {
        method: 'POST',
        body: formData,
      });
      
      if (response.ok) {
        actions.addNotification({
          type: 'success',
          message: `로봇 ${robotId}에 맵이 성공적으로 업로드되었습니다.`
        });
      } else {
        actions.addNotification({
          type: 'error',
          message: '맵 업로드에 실패했습니다.'
        });
      }
    } catch (error) {
      actions.addNotification({
        type: 'error',
        message: '맵 업로드 중 오류가 발생했습니다.'
      });
    }
  };

  // 전체 로봇 맵 업로드 함수
  const uploadMapToBulk = async (files) => {
    try {
      const formData = new FormData();
      files.forEach(file => {
        formData.append('files', file);
      });
      
      const response = await fetch(`${API_URL}/api/robots/bulk-map-upload`, {
        method: 'POST',
        body: formData,
      });
      
      if (response.ok) {
        actions.addNotification({
          type: 'success',
          message: '모든 로봇에 맵이 성공적으로 업로드되었습니다.'
        });
      } else {
        actions.addNotification({
          type: 'error',
          message: '맵 업로드에 실패했습니다.'
        });
      }
    } catch (error) {
      actions.addNotification({
        type: 'error',
        message: '맵 업로드 중 오류가 발생했습니다.'
      });
    }
  };

  // AMR에서 맵을 가져와 서버에 저장하는 함수
  const handleRobotMapDownload = async (robotId, mapId, mapName) => {
    const downloadKey = `${robotId}-${mapId}`;
    
    try {
      // 로딩 상태 시작
      setLoading(prev => ({
        ...prev,
        downloadingMaps: {
          ...prev.downloadingMaps,
          [downloadKey]: true
        }
      }));

      // 로딩 알림 표시
      actions.addNotification({
        type: 'info',
        message: `${mapName} 맵을 AMR에서 가져오는 중입니다...`
      });

      const response = await fetch(`${API_URL}/api/robots/${robotId}/maps/${mapId}/download`, {
        method: 'POST',
        headers: {
          'Content-Type': 'application/json'
        }
      });
      
      if (response.ok) {
        const result = await response.json();
        
        // 성공 상태 표시
        setDownloadedMaps(prev => ({
          ...prev,
          [downloadKey]: true
        }));
        
        actions.addNotification({
          type: 'success',
          message: `${mapName} 맵이 서버에 성공적으로 저장되었습니다! (노드: ${result.nodeCount || 0}개)`
        });

        // 맵 목록 새로고침
        fetchServerMaps();

        // 3초 후 성공 아이콘 제거
        setTimeout(() => {
          setDownloadedMaps(prev => {
            const newState = { ...prev };
            delete newState[downloadKey];
            return newState;
          });
        }, 3000);
      } else {
        const errorData = await response.json().catch(() => ({}));
        actions.addNotification({
          type: 'error',
          message: errorData.message || errorData.error || '맵 저장에 실패했습니다.'
        });
      }
    } catch (error) {
      console.error('맵 저장 에러:', error);
      actions.addNotification({
        type: 'error',
        message: `맵 저장 중 오류가 발생했습니다: ${error.message}`
      });
    } finally {
      // 로딩 상태 종료
      setLoading(prev => ({
        ...prev,
        downloadingMaps: {
          ...prev.downloadingMaps,
          [downloadKey]: false
        }
      }));
    }
  };

  const saveSettings = () => {
    // 실제 앱에서는 여기서 설정을 저장하는 API 호출
    actions.addNotification({
      type: 'success',
      message: '맵 설정이 저장되었습니다.'
    });
  };

  const resetSettings = () => {
    const defaultSettings = {
      extractedMapName: '',
      imageFile: null,
      metadataFile: null,
      nodesFile: null,
      selectedRobotMaps: {},
      expandedRobots: {}
    };
    setLocalSettings(defaultSettings);
  };

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
      <div style={{
        maxWidth: '800px',
        margin: '0 auto',
        display: 'grid',
        gap: 'var(--space-xl)'
      }}>
        {/* 맵 관리 */}
        <div className="card">
          <div className="card-header">
            <div className="card-title">
              <i className="fas fa-map"></i>
              맵 관리
            </div>
          </div>
          
          <div className="card-content">
            {/* 서버 맵 리스트 */}
            <div className="card-row" style={{ flexDirection: 'column', alignItems: 'stretch' }}>
              <div style={{ marginBottom: 'var(--space-md)' }}>
                <div className="card-label" style={{ fontSize: 'var(--font-size-sm)', color: 'var(--text-primary)', marginBottom: '2px' }}>서버 맵 목록</div>
                <div style={{ fontSize: 'var(--font-size-xs)', color: 'var(--text-tertiary)' }}>서버에 저장된 맵 파일들입니다</div>
              </div>

              <div style={{
                border: '1px solid var(--border-primary)',
                borderRadius: 'var(--radius-md)',
                backgroundColor: 'var(--bg-secondary)',
                padding: 'var(--space-md)'
              }}>
                {loading.maps ? (
                  <div style={{
                    display: 'flex',
                    flexDirection: 'column',
                    alignItems: 'center',
                    justifyContent: 'center',
                    height: '100px',
                    color: 'var(--text-tertiary)',
                    gap: 'var(--space-sm)'
                  }}>
                    <i className="fas fa-spinner fa-spin" style={{ fontSize: 'var(--font-size-xl)' }}></i>
                    <div style={{ fontSize: 'var(--font-size-sm)' }}>맵 목록을 불러오는 중...</div>
                  </div>
                ) : serverMaps.length > 0 ? (
                  <div style={{ display: 'grid', gap: 'var(--space-sm)' }}>
                    {serverMaps.map((map) => (
                      <div
                        key={map.id}
                        style={{
                          display: 'flex',
                          alignItems: 'center',
                          justifyContent: 'space-between',
                          padding: 'var(--space-sm) var(--space-md)',
                          backgroundColor: 'var(--bg-tertiary)',
                          borderRadius: 'var(--radius-sm)',
                          border: '1px solid var(--border-secondary)'
                        }}
                      >
                        <div style={{ display: 'flex', alignItems: 'center', gap: 'var(--space-sm)' }}>
                          <i className="fas fa-map" style={{ color: 'var(--primary-color)' }}></i>
                          <div>
                            <div style={{ fontSize: 'var(--font-size-sm)', fontWeight: '500' }}>
                              {map.name}
                            </div>
                            <div style={{ fontSize: 'var(--font-size-xs)', color: 'var(--text-tertiary)' }}>
                              생성일: {new Date(map.created_at).toLocaleDateString()}
                            </div>
                          </div>
                        </div>
                        <div style={{ display: 'flex', gap: 'var(--space-xs)' }}>
                          {map.image_file && (
                            <button
                              onClick={() => handleMapDownload(map.id, 'image')}
                              className="control-btn"
                              style={{ 
                                fontSize: 'var(--font-size-xs)', 
                                padding: 'var(--space-xs) var(--space-sm)',
                                minWidth: 'unset'
                              }}
                              title="이미지 다운로드"
                            >
                              <i className="fas fa-image"></i>
                            </button>
                          )}
                          {map.metadata_file && (
                            <button
                              onClick={() => handleMapDownload(map.id, 'metadata')}
                              className="control-btn"
                              style={{ 
                                fontSize: 'var(--font-size-xs)', 
                                padding: 'var(--space-xs) var(--space-sm)',
                                minWidth: 'unset'
                              }}
                              title="메타데이터 다운로드"
                            >
                              <i className="fas fa-file-code"></i>
                            </button>
                          )}
                          {map.node_file && (
                            <button
                              onClick={() => handleMapDownload(map.id, 'nodes')}
                              className="control-btn"
                              style={{ 
                                fontSize: 'var(--font-size-xs)', 
                                padding: 'var(--space-xs) var(--space-sm)',
                                minWidth: 'unset'
                              }}
                              title="노드 다운로드"
                            >
                              <i className="fas fa-project-diagram"></i>
                            </button>
                          )}
                          <button
                            onClick={() => handleMapDelete(map.id)}
                            className="control-btn"
                  style={{ 
                              fontSize: 'var(--font-size-xs)', 
                              padding: 'var(--space-xs) var(--space-sm)',
                              minWidth: 'unset'
                  }}
                            title="맵 삭제"
                          >
                            <i className="fas fa-trash"></i>
                          </button>
                        </div>
                      </div>
                    ))}
                  </div>
                ) : (
                  <div style={{
                    display: 'flex',
                    flexDirection: 'column',
                    alignItems: 'center',
                    justifyContent: 'center',
                    height: '100px',
                    color: 'var(--text-tertiary)',
                    gap: 'var(--space-sm)'
                  }}>
                    <i className="fas fa-map" style={{ fontSize: 'var(--font-size-xl)', opacity: 0.5 }}></i>
                    <div style={{ fontSize: 'var(--font-size-sm)' }}>저장된 맵이 없습니다</div>
                  </div>
                )}
              </div>
            </div>

            {/* 맵 파일 업로드 */}
            <div className="card-row" style={{ flexDirection: 'column', alignItems: 'stretch' }}>
              <div style={{ marginBottom: 'var(--space-md)' }}>
                <div className="card-label" style={{ fontSize: 'var(--font-size-sm)', color: 'var(--text-primary)', marginBottom: '2px' }}>맵 파일 업로드</div>
                <div style={{ fontSize: 'var(--font-size-xs)', color: 'var(--text-tertiary)' }}>새로운 맵 파일을 업로드합니다</div>
              </div>
              
              {/* 추출된 맵 이름 표시 */}
              {localSettings.extractedMapName && (
                <div style={{ marginBottom: 'var(--space-md)' }}>
                  <label style={{ 
                    display: 'block', 
                    marginBottom: 'var(--space-xs)',
                    fontSize: 'var(--font-size-sm)',
                    color: 'var(--text-secondary)'
                  }}>
                    맵 이름 (자동 추출됨)
                  </label>
                  <div style={{
                    width: '100%',
                  padding: 'var(--space-sm) var(--space-md)',
                    border: '1px solid var(--border-primary)',
                    borderRadius: 'var(--radius-md)',
                    backgroundColor: 'var(--bg-tertiary)',
                    color: 'var(--text-primary)',
                    fontSize: 'var(--font-size-sm)',
                    fontFamily: 'inherit',
                    display: 'flex',
                    alignItems: 'center',
                    gap: 'var(--space-sm)'
                  }}>
                    <i className="fas fa-tag" style={{ color: 'var(--primary-color)' }}></i>
                    {localSettings.extractedMapName}
                  </div>
                </div>
              )}
              
              {/* 파일 업로드 섹션 */}
              <div style={{ display: 'grid', gap: 'var(--space-md)' }}>
                {/* 이미지 파일 업로드 */}
                <div style={{ 
                  display: 'flex', 
                  alignItems: 'center', 
                  gap: 'var(--space-md)',
                  padding: 'var(--space-md)',
                  backgroundColor: 'var(--bg-secondary)',
                  borderRadius: 'var(--radius-md)',
                  border: '1px solid var(--border-primary)'
                }}>
                  <div style={{ minWidth: '80px' }}>
                    <div style={{ fontSize: 'var(--font-size-sm)', fontWeight: '500', color: 'var(--text-primary)' }}>
                      이미지 파일
                    </div>
                    <div style={{ fontSize: 'var(--font-size-xs)', color: 'var(--text-tertiary)' }}>
                      .jpg, .png, .pgm
                    </div>
                  </div>
                  
                  <label style={{
                    padding: 'var(--space-sm) var(--space-md)',
                    backgroundColor: 'var(--bg-tertiary)',
                    border: '1px solid var(--border-primary)',
                    borderRadius: 'var(--radius-sm)',
                    cursor: 'pointer',
                    display: 'flex',
                    alignItems: 'center',
                    gap: 'var(--space-sm)',
                  fontSize: 'var(--font-size-sm)',
                    color: 'var(--text-secondary)',
                    transition: 'all 0.2s ease'
                  }}>
                    <i className="fas fa-image"></i>
                    {localSettings.imageFile ? '파일 변경' : '파일 선택'}
                    <input
                      type="file"
                      accept=".jpg,.jpeg,.png,.pgm"
                      onChange={(e) => handleFileUpload('imageFile', e)}
                      style={{ display: 'none' }}
                    />
                  </label>
                  
                  {localSettings.imageFile && (
                    <div style={{ 
                      display: 'flex', 
                      alignItems: 'center', 
                      gap: 'var(--space-sm)',
                      padding: 'var(--space-sm) var(--space-md)',
                      backgroundColor: 'var(--bg-tertiary)',
                      borderRadius: 'var(--radius-md)',
                      flex: 1
                    }}>
                      <i className="fas fa-file-image" style={{ color: 'var(--primary-color)' }}></i>
                      <span style={{ fontSize: 'var(--font-size-sm)', flex: 1 }}>
                        {localSettings.imageFile.name}
                      </span>
                      <button
                        onClick={() => removeMapFile('imageFile')}
                        style={{
                          background: 'none',
                          border: 'none',
                          color: 'var(--text-tertiary)',
                          cursor: 'pointer',
                          padding: 'var(--space-xs)',
                          fontSize: 'var(--font-size-sm)'
                        }}
                      >
                        <i className="fas fa-times"></i>
                      </button>
                    </div>
                  )}
            </div>

                {/* 메타데이터 파일 업로드 */}
                <div style={{ 
                  display: 'flex', 
                  alignItems: 'center', 
                  gap: 'var(--space-md)',
                  padding: 'var(--space-md)',
                  backgroundColor: 'var(--bg-secondary)',
                  borderRadius: 'var(--radius-md)',
                  border: '1px solid var(--border-primary)'
                }}>
                  <div style={{ minWidth: '80px' }}>
                    <div style={{ fontSize: 'var(--font-size-sm)', fontWeight: '500', color: 'var(--text-primary)' }}>
                      메타데이터
            </div>
                    <div style={{ fontSize: 'var(--font-size-xs)', color: 'var(--text-tertiary)' }}>
                      .yaml, .yml
          </div>
                    <div style={{ fontSize: 'var(--font-size-xs)', color: 'var(--primary-color)', fontWeight: '500' }}>
                      맵 이름 자동 추출
            </div>
          </div>

                  <label style={{
                    padding: 'var(--space-sm) var(--space-md)',
                    backgroundColor: 'var(--bg-tertiary)',
                    border: '1px solid var(--border-primary)',
                    borderRadius: 'var(--radius-sm)',
                    cursor: 'pointer',
                    display: 'flex',
                    alignItems: 'center',
                    gap: 'var(--space-sm)',
                    fontSize: 'var(--font-size-sm)',
                    color: 'var(--text-secondary)',
                    transition: 'all 0.2s ease'
                  }}>
                    <i className="fas fa-file-code"></i>
                    {localSettings.metadataFile ? '파일 변경' : '파일 선택'}
                <input
                      type="file"
                      accept=".yaml,.yml"
                      onChange={(e) => handleFileUpload('metadataFile', e)}
                      style={{ display: 'none' }}
                    />
                  </label>
                  
                  {localSettings.metadataFile && (
                    <div style={{ 
                      display: 'flex', 
                      alignItems: 'center', 
                      gap: 'var(--space-sm)',
                      padding: 'var(--space-sm) var(--space-md)',
                      backgroundColor: 'var(--bg-tertiary)',
                      borderRadius: 'var(--radius-md)',
                      flex: 1
                    }}>
                      <i className="fas fa-file-code" style={{ color: 'var(--primary-color)' }}></i>
                      <span style={{ fontSize: 'var(--font-size-sm)', flex: 1 }}>
                        {localSettings.metadataFile.name}
                      </span>
                      <button
                        onClick={() => removeMapFile('metadataFile')}
                  style={{ 
                          background: 'none',
                          border: 'none',
                          color: 'var(--text-tertiary)',
                          cursor: 'pointer',
                          padding: 'var(--space-xs)',
                          fontSize: 'var(--font-size-sm)'
                  }}
                      >
                        <i className="fas fa-times"></i>
                      </button>
                    </div>
                  )}
            </div>

                {/* 노드 파일 업로드 */}
                <div style={{ 
                  display: 'flex', 
                  alignItems: 'center', 
                  gap: 'var(--space-md)',
                  padding: 'var(--space-md)',
                  backgroundColor: 'var(--bg-secondary)',
                  borderRadius: 'var(--radius-md)',
                  border: '1px solid var(--border-primary)'
                }}>
                  <div style={{ minWidth: '80px' }}>
                    <div style={{ fontSize: 'var(--font-size-sm)', fontWeight: '500', color: 'var(--text-primary)' }}>
                      노드 파일
            </div>
                    <div style={{ fontSize: 'var(--font-size-xs)', color: 'var(--text-tertiary)' }}>
                      .yaml, .yml
          </div>
        </div>

                  <label style={{
                    padding: 'var(--space-sm) var(--space-md)',
                    backgroundColor: 'var(--bg-tertiary)',
                    border: '1px solid var(--border-primary)',
                    borderRadius: 'var(--radius-sm)',
                    cursor: 'pointer',
                    display: 'flex',
                    alignItems: 'center',
                    gap: 'var(--space-sm)',
                    fontSize: 'var(--font-size-sm)',
                    color: 'var(--text-secondary)',
                    transition: 'all 0.2s ease'
                  }}>
                    <i className="fas fa-project-diagram"></i>
                    {localSettings.nodesFile ? '파일 변경' : '파일 선택'}
                    <input
                      type="file"
                      accept=".yaml,.yml"
                      onChange={(e) => handleFileUpload('nodesFile', e)}
                      style={{ display: 'none' }}
                    />
                  </label>
                  
                  {localSettings.nodesFile && (
                    <div style={{ 
                      display: 'flex', 
                      alignItems: 'center', 
                      gap: 'var(--space-sm)',
                      padding: 'var(--space-sm) var(--space-md)',
                      backgroundColor: 'var(--bg-tertiary)',
                      borderRadius: 'var(--radius-md)',
                      flex: 1
                    }}>
                      <i className="fas fa-project-diagram" style={{ color: 'var(--primary-color)' }}></i>
                      <span style={{ fontSize: 'var(--font-size-sm)', flex: 1 }}>
                        {localSettings.nodesFile.name}
                      </span>
                      <button
                        onClick={() => removeMapFile('nodesFile')}
                        style={{
                          background: 'none',
                          border: 'none',
                          color: 'var(--text-tertiary)',
                          cursor: 'pointer',
                          padding: 'var(--space-xs)',
                          fontSize: 'var(--font-size-sm)'
                        }}
                      >
                        <i className="fas fa-times"></i>
                      </button>
            </div>
                  )}
          </div>
              </div>
              
              {/* 업로드 버튼 */}
              <div style={{ marginTop: 'var(--space-md)' }}>
                <button
                  onClick={handleMapUpload}
                  className="control-btn primary"
                  disabled={!localSettings.extractedMapName && !localSettings.metadataFile}
                  style={{ 
                    width: '100%',
                    padding: 'var(--space-md)',
                    fontSize: 'var(--font-size-sm)',
                    fontWeight: '500',
                    opacity: (!localSettings.extractedMapName && !localSettings.metadataFile) ? 0.5 : 1
                  }}
                >
                  <i className="fas fa-upload"></i>
                  맵 업로드
                </button>
                {!localSettings.extractedMapName && !localSettings.metadataFile && (
                  <div style={{ 
                    marginTop: 'var(--space-xs)',
                    fontSize: 'var(--font-size-xs)',
                    color: 'var(--text-tertiary)',
                    textAlign: 'center'
                  }}>
                    메타데이터 파일을 업로드하면 맵 이름이 자동으로 추출됩니다
                  </div>
                )}
              </div>
            </div>

            {/* 로봇 리스트 */}
            <div className="card-row" style={{ flexDirection: 'column', alignItems: 'stretch' }}>
              <div style={{ 
                display: 'flex', 
                justifyContent: 'space-between', 
                alignItems: 'center', 
                marginBottom: 'var(--space-md)' 
              }}>
                <div>
                  <div className="card-label" style={{ fontSize: 'var(--font-size-sm)', color: 'var(--text-primary)', marginBottom: '2px' }}>서버 로봇 목록</div>
                  <div style={{ fontSize: 'var(--font-size-xs)', color: 'var(--text-tertiary)' }}>서버에 등록된 로봇 목록입니다</div>
                </div>
                {robots && robots.length > 0 && (
                  <button
                    onClick={handleBulkRobotMapUpload}
                    className="control-btn primary"
                    style={{
                      fontSize: 'var(--font-size-sm)',
                      padding: 'var(--space-xs) var(--space-sm)',
                      minWidth: 'auto',
                      display: 'flex',
                      alignItems: 'center',
                      gap: 'var(--space-xs)'
                    }}
                  >
                    <i className="fas fa-upload"></i>
                    전체 맵 업로드
                  </button>
                )}
              </div>

              <div style={{
                border: '1px solid var(--border-primary)',
                borderRadius: 'var(--radius-md)',
                backgroundColor: 'var(--bg-secondary)',
                minHeight: '200px',
                padding: 'var(--space-md)'
              }}>
                {loading.robots ? (
                  <div style={{
                    display: 'flex',
                    flexDirection: 'column',
                    alignItems: 'center',
                    justifyContent: 'center',
                    height: '150px',
                    color: 'var(--text-tertiary)',
                    gap: 'var(--space-sm)'
                  }}>
                    <i className="fas fa-spinner fa-spin" style={{ fontSize: 'var(--font-size-xl)' }}></i>
                    <div style={{ fontSize: 'var(--font-size-sm)' }}>로봇 목록을 불러오는 중...</div>
                  </div>
                ) : robots && robots.length > 0 ? (
                  <div style={{ display: 'grid', gap: 'var(--space-sm)' }}>
                    {robots.map((robot) => (
                      <div key={robot.id} style={{
                        backgroundColor: 'var(--bg-tertiary)',
                        borderRadius: 'var(--radius-sm)',
                        border: '1px solid var(--border-secondary)',
                        overflow: 'hidden',
                        transition: 'all 0.3s ease-out'
                      }}>
                        <div
                          style={{
                            display: 'flex',
                            alignItems: 'center',
                            justifyContent: 'space-between',
                            padding: 'var(--space-sm) var(--space-md)'
                          }}
                        >
                          <div style={{ display: 'flex', alignItems: 'center', gap: 'var(--space-sm)' }}>
                            <div
                              style={{ 
                                width: '12px',
                                height: '12px',
                                borderRadius: '50%',
                                backgroundColor: robot.status === 'active' ? 'var(--success-color)' : 
                                               robot.status === 'error' ? 'var(--error-color)' : 
                                               'var(--warning-color)'
                              }}
                            />
                            <div style={{ display: 'flex', flexDirection: 'column', gap: '2px' }}>
                              <span style={{ fontSize: 'var(--font-size-sm)', fontWeight: '500' }}>
                                {robot.name}
                              </span>
                              <span style={{ fontSize: 'var(--font-size-xs)', color: 'var(--text-tertiary)' }}>
                                {robot.ip_address}{robot.port ? `:${robot.port}` : ''}
                              </span>
                            </div>
                            <span style={{ 
                              fontSize: 'var(--font-size-xs)', 
                              color: 'var(--text-tertiary)',
                              backgroundColor: 'var(--bg-quaternary)',
                              padding: '2px 6px',
                              borderRadius: 'var(--radius-xs)'
                            }}>
                              {robot.type}
                            </span>
                          </div>
                          <div style={{ display: 'flex', gap: 'var(--space-xs)' }}>
                            <button
                              onClick={() => handleRobotMapUpload(robot.id)}
                              className="control-btn"
                              style={{ 
                                fontSize: 'var(--font-size-xs)', 
                                padding: 'var(--space-xs) var(--space-sm)',
                                minWidth: 'unset'
                              }}
                            >
                              <i className="fas fa-upload"></i>
                              맵 업로드
                            </button>
                            <button
                              onClick={() => handleToggleRobotMaps(robot.id)}
                              className="control-btn"
                              style={{ 
                                fontSize: 'var(--font-size-xs)', 
                                padding: 'var(--space-xs)',
                                minWidth: 'unset',
                                transition: 'all 0.3s ease',
                                transform: localSettings.expandedRobots[robot.id] ? 'rotate(180deg)' : 'rotate(0deg)'
                              }}
                            >
                              <i className="fas fa-chevron-down"></i>
                            </button>
                          </div>
                        </div>
                        
                        {/* 로봇의 맵 목록 (확장 시 표시) */}
                        <div style={{
                          overflow: 'hidden',
                          transition: 'max-height 0.3s ease-out',
                          maxHeight: localSettings.expandedRobots[robot.id] ? '400px' : '0px'
                        }}>
                          {localSettings.expandedRobots[robot.id] && (
                            <div style={{
                              padding: 'var(--space-md)',
                              borderTop: '1px solid var(--border-primary)',
                              maxHeight: '400px',
                              display: 'flex',
                              flexDirection: 'column',
                              background: 'linear-gradient(180deg, var(--bg-secondary) 0%, var(--bg-tertiary) 100%)'
                            }}>
                              <div style={{ 
                                fontSize: 'var(--font-size-sm)', 
                                color: 'var(--text-secondary)', 
                                marginBottom: 'var(--space-md)',
                                fontWeight: '600',
                                flexShrink: 0,
                                display: 'flex',
                                alignItems: 'center',
                                gap: 'var(--space-sm)',
                                textTransform: 'uppercase',
                                letterSpacing: '0.05em'
                              }}>
                                <i className="fas fa-layer-group" style={{ color: 'var(--primary-color)' }}></i>
                                {robot.name}의 맵 목록
                              </div>
                              {loading.robotMaps[robot.id] ? (
                                <div style={{
                                  display: 'flex',
                                  alignItems: 'center',
                                  justifyContent: 'center',
                                  padding: 'var(--space-md)',
                                  color: 'var(--text-tertiary)',
                                  fontSize: 'var(--font-size-xs)'
                                }}>
                                  <i className="fas fa-spinner fa-spin" style={{ marginRight: 'var(--space-xs)' }}></i>
                                  맵 목록을 불러오는 중...
                                </div>
                              ) : localSettings.selectedRobotMaps[robot.id] ? (
                                <div 
                                  className="robot-maps-scroll"
                                  style={{
                                    overflowY: 'auto',
                                    maxHeight: '320px',
                                    padding: 'var(--space-xs) var(--space-xs) 0 0',
                                    display: 'flex',
                                    flexDirection: 'column',
                                    gap: '0'
                                  }}
                                >
                                  {                                localSettings.selectedRobotMaps[robot.id].map((map, index) => (
                                  <div key={map.id} style={{
                                    display: 'flex',
                                    alignItems: 'center',
                                    justifyContent: 'space-between',
                                    gap: 'var(--space-lg)',
                                    padding: 'var(--space-xs) var(--space-sm)',
                                    fontSize: 'var(--font-size-xs)',
                                    borderBottom: index < localSettings.selectedRobotMaps[robot.id].length - 1 
                                      ? '1px solid var(--border-secondary)' 
                                      : 'none',
                                    opacity: 0,
                                    animation: 'fadeInUp 0.3s ease-out forwards',
                                    animationDelay: `${0.05 * (index + 1)}s`,
                                    background: map.isActive 
                                      ? 'linear-gradient(90deg, rgba(var(--primary-rgb, 232, 46, 1), 0.08), rgba(var(--accent-rgb, 255, 87, 34), 0.02))'
                                      : 'transparent',
                                    transition: 'all 0.2s ease'
                                  }}
                                  onMouseEnter={(e) => {
                                    if (!map.isActive) {
                                      e.currentTarget.style.background = 'rgba(255, 255, 255, 0.03)';
                                    }
                                  }}
                                  onMouseLeave={(e) => {
                                    if (!map.isActive) {
                                      e.currentTarget.style.background = 'transparent';
                                    }
                                  }}
                                  >
                                    <div style={{ 
                                      display: 'flex', 
                                      alignItems: 'center', 
                                      gap: 'var(--space-sm)', 
                                      flex: 1,
                                      minWidth: 0
                                    }}>
                                      <span style={{ 
                                        fontWeight: map.isActive ? '600' : '400',
                                        color: map.isActive ? 'var(--primary-color)' : 'var(--text-secondary)',
                                        flex: 1,
                                        whiteSpace: 'nowrap',
                                        overflow: 'hidden',
                                        textOverflow: 'ellipsis'
                                      }}>
                                        {map.name}
                                      </span>
                                      {map.isActive && (
                                        <span style={{ 
                                          fontSize: 'var(--font-size-xs)',
                                          color: 'var(--primary-color)',
                                          fontWeight: '700',
                                          textTransform: 'uppercase',
                                          letterSpacing: '0.05em',
                                          flexShrink: 0
                                        }}>
                                          ACTIVE
                                        </span>
                                      )}
                                    </div>
                                    <button
                                      onClick={() => handleRobotMapDownload(robot.id, map.id, map.name)}
                                      disabled={loading.downloadingMaps[`${robot.id}-${map.id}`]}
                                      className="control-btn"
                                      style={{
                                        fontSize: 'var(--font-size-xs)',
                                        padding: '2px 6px',
                                        minWidth: 'auto',
                                        backgroundColor: downloadedMaps[`${robot.id}-${map.id}`] 
                                          ? 'var(--status-success)' 
                                          : 'transparent',
                                        border: downloadedMaps[`${robot.id}-${map.id}`]
                                          ? '1px solid var(--status-success)'
                                          : '1px solid var(--border-primary)',
                                        color: downloadedMaps[`${robot.id}-${map.id}`]
                                          ? 'var(--bg-primary)'
                                          : 'var(--text-secondary)',
                                        transition: 'all 0.3s ease',
                                        opacity: loading.downloadingMaps[`${robot.id}-${map.id}`] ? 0.6 : 1,
                                        cursor: loading.downloadingMaps[`${robot.id}-${map.id}`] ? 'not-allowed' : 'pointer'
                                      }}
                                      onMouseOver={(e) => {
                                        if (!loading.downloadingMaps[`${robot.id}-${map.id}`] && !downloadedMaps[`${robot.id}-${map.id}`]) {
                                          e.currentTarget.style.backgroundColor = 'var(--primary-color)';
                                          e.currentTarget.style.color = 'white';
                                          e.currentTarget.style.borderColor = 'var(--primary-color)';
                                        }
                                      }}
                                      onMouseOut={(e) => {
                                        if (!downloadedMaps[`${robot.id}-${map.id}`]) {
                                          e.currentTarget.style.backgroundColor = 'transparent';
                                          e.currentTarget.style.color = 'var(--text-secondary)';
                                          e.currentTarget.style.borderColor = 'var(--border-primary)';
                                        }
                                      }}
                                      title={
                                        downloadedMaps[`${robot.id}-${map.id}`]
                                          ? '서버에 저장 완료'
                                          : loading.downloadingMaps[`${robot.id}-${map.id}`]
                                          ? '다운로드 중...'
                                          : `${map.name} 맵을 서버에 저장`
                                      }
                                    >
                                      {loading.downloadingMaps[`${robot.id}-${map.id}`] ? (
                                        <i className="fas fa-spinner fa-spin"></i>
                                      ) : downloadedMaps[`${robot.id}-${map.id}`] ? (
                                        <i className="fas fa-check"></i>
                                      ) : (
                                        <i className="fas fa-download"></i>
                                      )}
                                    </button>
                                  </div>
                                  ))}
                                </div>
                              ) : (
                                <div style={{
                                  display: 'flex',
                                  alignItems: 'center',
                                  justifyContent: 'center',
                                  padding: 'var(--space-md)',
                                  color: 'var(--text-tertiary)',
                                  fontSize: 'var(--font-size-xs)'
                                }}>
                                  <i className="fas fa-exclamation-triangle" style={{ marginRight: 'var(--space-xs)' }}></i>
                                  맵 목록을 불러올 수 없습니다
                                </div>
                              )}
                            </div>
                          )}
                        </div>
                      </div>
                    ))}
                  </div>
                ) : (
                  <div style={{
                    display: 'flex',
                    flexDirection: 'column',
                    alignItems: 'center',
                    justifyContent: 'center',
                    height: '150px',
                    color: 'var(--text-tertiary)',
                    gap: 'var(--space-sm)'
                  }}>
                    <i className="fas fa-robot" style={{ fontSize: 'var(--font-size-xl)', opacity: 0.5 }}></i>
                    <div style={{ fontSize: 'var(--font-size-sm)' }}>등록된 로봇이 없습니다</div>
                  </div>
                )}
              </div>
            </div>
          </div>
        </div>

        {/* 로봇 관리 설정 */}
        <RobotManagementSection 
          robots={robots}
          loading={loading.robots}
          onLoadRobots={loadRobots}
          onAddRobot={handleAddRobot}
          onDeleteRobot={handleDeleteRobot}
        />

        {/* UI 설정 */}
        <div className="card">
          <div className="card-header">
            <div className="card-title">
              <i className="fas fa-palette"></i>
              UI 설정
            </div>
          </div>
          
          <div className="card-content">
            {/* 포인트 컬러 설정 */}
            <div className="card-row" style={{ flexDirection: 'column', alignItems: 'stretch' }}>
              <div style={{ marginBottom: 'var(--space-md)' }}>
                <div className="card-label" style={{ fontSize: 'var(--font-size-sm)', color: 'var(--text-primary)', marginBottom: '2px' }}>포인트 컬러</div>
                <div style={{ fontSize: 'var(--font-size-xs)', color: 'var(--text-tertiary)' }}>앱 전반에 적용되는 테마 포인트 컬러를 선택합니다</div>
              </div>

              {/* 컬러 프리셋 */}
              <div style={{
                display: 'flex',
                flexWrap: 'wrap',
                gap: 'var(--space-sm)',
                marginBottom: 'var(--space-md)'
              }}>
                {[
                  { color: '#38BDF8', name: '스카이 블루' },
                  { color: '#00d4ff', name: '사이버 블루' },
                  { color: '#3498db', name: '블루' },
                  { color: '#00ff88', name: '네온 그린' },
                  { color: '#1abc9c', name: '터콰이즈' },
                  { color: '#E82E01', name: '레드 오렌지' },
                  { color: '#ff6b35', name: '오렌지' },
                  { color: '#f39c12', name: '골드' },
                  { color: '#e91e63', name: '핑크' },
                  { color: '#9b59b6', name: '퍼플' },
                  { color: '#e74c3c', name: '레드' }
                ].map((preset) => (
                  <button
                    key={preset.color}
                    onClick={() => actions.updateUISetting('primaryColor', preset.color)}
                    style={{
                      width: '40px',
                      height: '40px',
                      borderRadius: 'var(--radius-md)',
                      backgroundColor: preset.color,
                      border: state.ui.primaryColor === preset.color 
                        ? '3px solid var(--text-primary)' 
                        : '2px solid var(--border-primary)',
                      cursor: 'pointer',
                      transition: 'all 0.2s ease',
                      boxShadow: state.ui.primaryColor === preset.color 
                        ? `0 0 15px ${preset.color}60`
                        : 'none'
                    }}
                    title={preset.name}
                    onMouseEnter={(e) => {
                      e.currentTarget.style.transform = 'scale(1.1)';
                      e.currentTarget.style.boxShadow = `0 0 15px ${preset.color}60`;
                    }}
                    onMouseLeave={(e) => {
                      e.currentTarget.style.transform = 'scale(1)';
                      e.currentTarget.style.boxShadow = state.ui.primaryColor === preset.color 
                        ? `0 0 15px ${preset.color}60` 
                        : 'none';
                    }}
                  />
                ))}
              </div>

              {/* 커스텀 컬러 선택 */}
              <div style={{
                display: 'flex',
                alignItems: 'center',
                gap: 'var(--space-md)',
                padding: 'var(--space-md)',
                backgroundColor: 'var(--bg-secondary)',
                borderRadius: 'var(--radius-md)',
                border: '1px solid var(--border-primary)'
              }}>
                <div style={{ 
                  fontSize: 'var(--font-size-sm)', 
                  color: 'var(--text-secondary)',
                  minWidth: '80px'
                }}>
                  커스텀 컬러
                </div>
                <input
                  type="color"
                  value={state.ui.primaryColor}
                  onChange={(e) => actions.updateUISetting('primaryColor', e.target.value)}
                  style={{
                    width: '50px',
                    height: '35px',
                    border: 'none',
                    borderRadius: 'var(--radius-sm)',
                    cursor: 'pointer',
                    backgroundColor: 'transparent'
                  }}
                />
                <input
                  type="text"
                  value={state.ui.primaryColor}
                  onChange={(e) => {
                    const value = e.target.value;
                    if (/^#[0-9A-Fa-f]{6}$/.test(value)) {
                      actions.updateUISetting('primaryColor', value);
                    }
                  }}
                  placeholder="#E82E01"
                  style={{
                    flex: 1,
                    padding: 'var(--space-sm)',
                    backgroundColor: 'var(--bg-tertiary)',
                    border: '1px solid var(--border-primary)',
                    borderRadius: 'var(--radius-sm)',
                    color: 'var(--text-primary)',
                    fontSize: 'var(--font-size-sm)',
                    fontFamily: 'monospace'
                  }}
                />
                <div style={{
                  width: '30px',
                  height: '30px',
                  borderRadius: 'var(--radius-sm)',
                  backgroundColor: state.ui.primaryColor,
                  border: '1px solid var(--border-primary)'
                }} />
              </div>
            </div>

            {/* 로고 설정 */}
            <div className="card-row" style={{ flexDirection: 'column', alignItems: 'stretch', marginTop: 'var(--space-lg)' }}>
              <div style={{ marginBottom: 'var(--space-md)' }}>
                <div className="card-label" style={{ fontSize: 'var(--font-size-sm)', color: 'var(--text-primary)', marginBottom: '2px' }}>로고 설정</div>
                <div style={{ fontSize: 'var(--font-size-xs)', color: 'var(--text-tertiary)' }}>헤더에 표시되는 로고 이미지를 변경합니다</div>
              </div>

              <div style={{
                display: 'flex',
                alignItems: 'center',
                gap: 'var(--space-md)',
                padding: 'var(--space-md)',
                backgroundColor: 'var(--bg-secondary)',
                borderRadius: 'var(--radius-md)',
                border: '1px solid var(--border-primary)'
              }}>
                {/* 현재 로고 미리보기 */}
                <div style={{
                  width: '120px',
                  height: '50px',
                  borderRadius: 'var(--radius-sm)',
                  backgroundColor: state.ui.theme === 'dark' ? '#1a1a1a' : '#f0f0f0',
                  display: 'flex',
                  alignItems: 'center',
                  justifyContent: 'center',
                  border: '1px solid var(--border-primary)',
                  overflow: 'hidden'
                }}>
                  {state.ui.customLogo ? (
                    <img 
                      src={state.ui.customLogo} 
                      alt="Custom Logo" 
                      style={{ maxWidth: '100%', maxHeight: '100%', objectFit: 'contain' }}
                    />
                  ) : (
                    <span style={{ 
                      fontSize: 'var(--font-size-xs)', 
                      color: 'var(--text-tertiary)',
                      textAlign: 'center'
                    }}>
                      기본 로고
                    </span>
                  )}
                </div>

                {/* 로고 업로드 버튼 */}
                <label style={{
                  padding: 'var(--space-sm) var(--space-md)',
                  backgroundColor: 'var(--bg-tertiary)',
                  border: '1px solid var(--border-primary)',
                  borderRadius: 'var(--radius-sm)',
                  cursor: 'pointer',
                  display: 'flex',
                  alignItems: 'center',
                  gap: 'var(--space-sm)',
                  fontSize: 'var(--font-size-sm)',
                  color: 'var(--text-secondary)',
                  transition: 'all 0.2s ease'
                }}>
                  <i className="fas fa-upload"></i>
                  로고 업로드
                  <input
                    type="file"
                    accept="image/*"
                    onChange={(e) => {
                      const file = e.target.files[0];
                      if (file) {
                        const reader = new FileReader();
                        reader.onload = (event) => {
                          actions.updateUISetting('customLogo', event.target.result);
                          actions.addNotification({
                            type: 'success',
                            message: '로고가 변경되었습니다.'
                          });
                        };
                        reader.readAsDataURL(file);
                      }
                    }}
                    style={{ display: 'none' }}
                  />
                </label>

                {/* 기본 로고로 복원 버튼 */}
                {state.ui.customLogo && (
                  <button
                    onClick={() => {
                      actions.updateUISetting('customLogo', null);
                      actions.addNotification({
                        type: 'success',
                        message: '기본 로고로 복원되었습니다.'
                      });
                    }}
                    className="control-btn"
                    style={{
                      fontSize: 'var(--font-size-sm)',
                      padding: 'var(--space-sm) var(--space-md)'
                    }}
                  >
                    <i className="fas fa-undo"></i>
                    기본 로고
                  </button>
                )}
              </div>
            </div>

            {/* 테마 설정 */}
            <div className="card-row" style={{ flexDirection: 'column', alignItems: 'stretch', marginTop: 'var(--space-lg)' }}>
              <div style={{ marginBottom: 'var(--space-md)' }}>
                <div className="card-label" style={{ fontSize: 'var(--font-size-sm)', color: 'var(--text-primary)', marginBottom: '2px' }}>테마 모드</div>
                <div style={{ fontSize: 'var(--font-size-xs)', color: 'var(--text-tertiary)' }}>다크 모드 또는 라이트 모드를 선택합니다</div>
              </div>

              <div style={{
                display: 'flex',
                gap: 'var(--space-md)'
              }}>
                <button
                  onClick={() => actions.updateUISetting('theme', 'dark')}
                  style={{
                    flex: 1,
                    padding: 'var(--space-md)',
                    backgroundColor: state.ui.theme === 'dark' ? 'var(--primary-color)' : 'var(--bg-tertiary)',
                    border: state.ui.theme === 'dark' ? '2px solid var(--primary-color)' : '1px solid var(--border-primary)',
                    borderRadius: 'var(--radius-md)',
                    cursor: 'pointer',
                    display: 'flex',
                    alignItems: 'center',
                    justifyContent: 'center',
                    gap: 'var(--space-sm)',
                    color: state.ui.theme === 'dark' ? '#ffffff' : 'var(--text-secondary)',
                    fontSize: 'var(--font-size-sm)',
                    fontWeight: state.ui.theme === 'dark' ? '600' : '400',
                    transition: 'all 0.2s ease'
                  }}
                >
                  <i className="fas fa-moon"></i>
                  다크 모드
                </button>
                <button
                  onClick={() => actions.updateUISetting('theme', 'light')}
                  style={{
                    flex: 1,
                    padding: 'var(--space-md)',
                    backgroundColor: state.ui.theme === 'light' ? 'var(--primary-color)' : 'var(--bg-tertiary)',
                    border: state.ui.theme === 'light' ? '2px solid var(--primary-color)' : '1px solid var(--border-primary)',
                    borderRadius: 'var(--radius-md)',
                    cursor: 'pointer',
                    display: 'flex',
                    alignItems: 'center',
                    justifyContent: 'center',
                    gap: 'var(--space-sm)',
                    color: state.ui.theme === 'light' ? '#ffffff' : 'var(--text-secondary)',
                    fontSize: 'var(--font-size-sm)',
                    fontWeight: state.ui.theme === 'light' ? '600' : '400',
                    transition: 'all 0.2s ease'
                  }}
                >
                  <i className="fas fa-sun"></i>
                  라이트 모드
                </button>
              </div>
            </div>
          </div>
        </div>

        {/* 버튼 영역 */}
        <div style={{
          display: 'flex',
          gap: 'var(--space-md)',
          justifyContent: 'center'
        }}>
          <button 
            onClick={saveSettings}
            className="control-btn primary"
            style={{ minWidth: '120px' }}
          >
            <i className="fas fa-save"></i>
            설정 저장
          </button>
          <button 
            onClick={resetSettings}
            className="control-btn"
            style={{ minWidth: '120px' }}
          >
            <i className="fas fa-undo"></i>
            기본값으로 복원
          </button>
        </div>
      </div>
    </div>
  );
};

export default SettingsPage; 