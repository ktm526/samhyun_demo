const express = require('express');
const cors = require('cors');
const helmet = require('helmet');
const morgan = require('morgan');
const path = require('path');
const fs = require('fs');
const requestMonitor = require('./src/middleware/requestMonitor');

// 라우트 import
const routes = require('./src/routes');

// Express 앱 생성
const app = express();

// 미들웨어 설정
app.use(
  helmet({
    // Vite 빌드된 프론트(React)의 blob: 이미지(텍스처)와
    // 별도 포트(ws://:8083) 시그널링(WebRTC)을 허용하기 위한 CSP 완화
    // helmet() 기본 CSP는 아래에서 커스텀으로 다시 세팅
    contentSecurityPolicy: false
  })
); // 보안 강화

// CSP(지도 텍스처 blob: / WebRTC ws://) 허용
app.use(
  helmet.contentSecurityPolicy({
    useDefaults: true,
    directives: {
      'img-src': ["'self'", 'data:', 'blob:'],
      'media-src': ["'self'", 'blob:'],
      'connect-src': ["'self'", 'ws:', 'wss:'],
      'worker-src': ["'self'", 'blob:']
    }
  })
);
app.use(cors());   // CORS 활성화
app.use(express.json());
app.use(requestMonitor());
//app.use(morgan('dev')); // 로깅

// 라우트 설정
app.use('/api', routes);

// 프론트엔드 정적 파일 서빙 (Vite build 결과: ../frontend/dist)
const frontendDistPath = path.resolve(__dirname, '../frontend/dist');
const hasFrontendBuild =
  fs.existsSync(frontendDistPath) &&
  fs.existsSync(path.join(frontendDistPath, 'index.html'));

if (hasFrontendBuild) {
  app.use(express.static(frontendDistPath));

  // SPA 라우팅 fallback (파일 요청/ API 요청 제외)
  app.get('*', (req, res, next) => {
    if (req.path.startsWith('/api')) return next();
    if (path.extname(req.path)) return next(); // /assets/xxx.js 같은 정적 파일은 제외
    return res.sendFile(path.join(frontendDistPath, 'index.html'));
  });
}

// 404 에러 핸들러
app.use('*', (req, res) => {
  res.status(404).json({ 
    error: '요청한 리소스를 찾을 수 없습니다.',
    path: req.originalUrl 
  });
});

// 전역 에러 핸들러
app.use((err, req, res, next) => {
  console.error('서버 에러:', err);
  res.status(500).json({ 
    error: '내부 서버 오류가 발생했습니다.',
    ...(process.env.NODE_ENV === 'development' && { stack: err.stack })
  });
});

module.exports = app; 