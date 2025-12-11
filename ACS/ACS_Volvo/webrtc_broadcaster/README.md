# WebRTC 영상 송출기

ACS 영상 페이지에 웹캠/화면을 WebRTC로 송출하는 도구입니다.

## 사용 방법

### 1. ACS 백엔드 서버 실행
```bash
cd /home/jarvis/Desktop/hamr_simulator_251208/ACS/ACS_Volvo/backend
npm run dev
```

### 2. 송출기 페이지 열기
**방법 A: 로컬에서 직접 열기**
```
파일 탐색기에서 broadcaster.html 더블클릭
```

**방법 B: HTTP 서버로 실행** (다른 컴퓨터에서 접속 시)
```bash
cd webrtc_broadcaster
python -m http.server 8080
```
그 후 브라우저에서 `http://[IP주소]:8080/broadcaster.html` 접속

### 3. 송출 설정

| 설정 | 예시 값 |
|------|---------|
| 시그널링 서버 | `ws://192.168.0.10:8083` |
| 방 ID | `robot-front` |
| 비디오 소스 | 웹캠 또는 화면 공유 |

### 4. 송출 시작
"송출 시작" 버튼 클릭

### 5. ACS에서 시청
1. ACS 영상 페이지 열기
2. 활성 스트림 목록에서 방 ID 선택 (또는 직접 입력)
3. "연결" 버튼 클릭

## 테스트 시나리오

### 같은 컴퓨터에서 테스트
1. 백엔드 서버 실행
2. `broadcaster.html` 열기
3. 시그널링 서버: `ws://localhost:8083`
4. 방 ID: `test-stream`
5. "송출 시작" 클릭
6. ACS 프론트엔드 영상 페이지에서 `test-stream` 연결

### 다른 컴퓨터에서 송출
1. **서버 컴퓨터** (192.168.0.10):
   - ACS 백엔드 실행 중

2. **송출 컴퓨터** (192.168.0.38):
   - `broadcaster.html` 열기
   - 시그널링 서버: `ws://192.168.0.10:8083`
   - 방 ID: `robot-front`
   - "송출 시작" 클릭

3. **서버 컴퓨터**에서:
   - ACS 영상 페이지에서 `robot-front` 연결

## 주의사항

- 웹캠 접근 권한을 허용해야 합니다
- HTTPS가 아닌 환경에서는 `localhost`에서만 카메라 접근 가능
- 다른 컴퓨터에서 카메라를 사용하려면 HTTPS 또는 크롬 플래그 설정 필요:
  ```
  chrome://flags/#unsafely-treat-insecure-origin-as-secure
  ```
  에서 송출기 URL 추가

## 문제 해결

### "카메라를 찾을 수 없습니다"
- 브라우저 카메라 권한 확인
- HTTPS 환경 필요 (localhost 제외)

### "시그널링 서버 연결 오류"
- 백엔드 서버 실행 확인
- IP 주소와 포트 확인
- 방화벽 설정 확인 (8083 포트)

### 영상이 안 보임
- 송출기와 시청자의 방 ID가 동일한지 확인
- 송출기가 먼저 연결되어 있어야 함

