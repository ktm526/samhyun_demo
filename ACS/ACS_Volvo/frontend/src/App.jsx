import React, { useEffect } from 'react';
import { AppProvider, useAppContext } from './contexts/AppContext.jsx';
import Header from './components/layout/Header';
import MainPage from './pages/MainPage';
import VideoPage from './pages/VideoPage';
import LogPage from './pages/LogPage';
import SettingsPage from './pages/SettingsPage';
import './App.css';

const AppContent = () => {
  const { state } = useAppContext();

  // 테마가 변경될 때마다 body에 클래스 적용
  useEffect(() => {
    document.body.className = state.ui.theme;
  }, [state.ui.theme]);

  // 포인트 컬러가 변경될 때마다 CSS 변수 업데이트 (다크/라이트 모드 모두)
  useEffect(() => {
    const palette = state.ui.colorPalette;
    const isDarkMode = state.ui.theme === 'dark';
    
    if (palette) {
      // .app 요소에 직접 스타일 적용 (CSS 특이성 문제 해결)
      const appElement = document.querySelector('.app');
      if (appElement) {
        appElement.style.setProperty('--primary-color', palette.primary);
        appElement.style.setProperty('--primary-glow', palette.primary);
        appElement.style.setProperty('--accent-color', palette.accent);
        appElement.style.setProperty('--accent-secondary', palette.secondary);
        appElement.style.setProperty('--status-info', palette.primary);
        appElement.style.setProperty('--primary-rgb', palette.rgb);
        appElement.style.setProperty('--border-accent', `rgba(${palette.rgb}, 0.3)`);
        
        // 테마별 그림자 투명도 조정
        if (isDarkMode) {
          appElement.style.setProperty('--shadow-glow', `0 0 20px rgba(${palette.rgb}, 0.2)`);
          appElement.style.setProperty('--shadow-glow-strong', `0 0 30px rgba(${palette.rgb}, 0.4)`);
        } else {
          // 라이트 모드에서는 그림자를 약간 더 연하게
          appElement.style.setProperty('--shadow-glow', `0 0 20px rgba(${palette.rgb}, 0.15)`);
          appElement.style.setProperty('--shadow-glow-strong', `0 0 30px rgba(${palette.rgb}, 0.25)`);
        }
      }
      
      // :root에도 설정 (일부 컴포넌트에서 :root 변수 참조할 수 있으므로)
      const root = document.documentElement;
      root.style.setProperty('--primary-color', palette.primary);
      root.style.setProperty('--primary-glow', palette.primary);
      root.style.setProperty('--accent-color', palette.accent);
      root.style.setProperty('--accent-secondary', palette.secondary);
      root.style.setProperty('--status-info', palette.primary);
      root.style.setProperty('--primary-rgb', palette.rgb);
      root.style.setProperty('--border-accent', `rgba(${palette.rgb}, 0.3)`);
    }
  }, [state.ui.colorPalette, state.ui.theme]);

  const renderCurrentPage = () => {
    switch (state.currentPage) {
      case 'main':
        return <MainPage />;
      case 'video':
        return <VideoPage />;
      case 'log':
        return <LogPage />;
      case 'settings':
        return <SettingsPage />;
      default:
        return <MainPage />;
    }
  };

  return (
    <div className={`app ${state.ui.theme}`}>
      {/* 헤더 (네비게이션 포함) */}
      <Header />
      
      {/* 메인 콘텐츠 영역 */}
      <div className="content">
        {renderCurrentPage()}
      </div>
    </div>
  );
};

const App = () => {
  return (
    <AppProvider>
      <AppContent />
    </AppProvider>
  );
};

export default App;
