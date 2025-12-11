# WebRTC 영상 송출기

ACS 영상 페이지에 웹캠/화면을 WebRTC로 송출하는 도구입니다.

## 설치

```bash
cd webrtc_broadcaster
pip install -r requirements.txt
```

## 사용법

### 기본 실행 (웹캠 0번)
```bash
python broadcaster.py
```

### 옵션

| 옵션 | 설명 | 기본값 |
|------|------|--------|
| `--server` | 시그널링 서버 URL | `ws://localhost:8083` |
| `--room` | 방 ID | `robot-front` |
| `--source` | 비디오 소스 | `0` |

### 비디오 소스 옵션
- `0`, `1`, `2`... : 웹캠 인덱스
- `test` : 테스트 패턴 (컬러바 + 시간)
- `/path/to/video.mp4` : 비디오 파일

### 예시

**다른 서버로 송출:**
```bash
python broadcaster.py --server ws://192.168.0.10:8083 --room robot-front
```

**테스트 패턴 사용:**
```bash
python broadcaster.py --source test
```

**두 번째 웹캠 사용:**
```bash
python broadcaster.py --source 1
```

**비디오 파일 송출:**
```bash
python broadcaster.py --source /path/to/video.mp4
```

## 테스트 시나리오

### 같은 컴퓨터에서 테스트

1. **터미널 1**: ACS 백엔드 실행
   ```bash
   cd /path/to/ACS/backend
   npm run dev
   ```

2. **터미널 2**: 송출기 실행
   ```bash
   cd webrtc_broadcaster
   python broadcaster.py --source test
   ```

3. **브라우저**: ACS 프론트엔드 영상 페이지에서 `robot-front` 연결

### 다른 컴퓨터에서 송출

**서버 (192.168.0.10):**
- ACS 백엔드 실행 중

**송출 컴퓨터 (192.168.0.38):**
```bash
python broadcaster.py --server ws://192.168.0.10:8083 --room camera-1
```

**서버에서 시청:**
- ACS 영상 페이지에서 `camera-1` 연결

## 문제 해결

### "ModuleNotFoundError: No module named 'aiortc'"
```bash
pip install -r requirements.txt
```

### "웹캠을 열 수 없습니다"
- 웹캠이 연결되어 있는지 확인
- 다른 프로그램이 웹캠을 사용 중인지 확인
- `--source 1`로 다른 웹캠 시도

### "시그널링 서버 연결 오류"
- ACS 백엔드 서버가 실행 중인지 확인
- IP 주소와 포트(8083) 확인
- 방화벽 설정 확인

### 영상이 안 보임
- 송출기가 먼저 실행되어야 함
- 방 ID가 동일한지 확인
- 네트워크 연결 확인

## 브라우저 버전 (대안)

Python 설치가 어려운 경우 `broadcaster.html`을 브라우저에서 열어 사용할 수 있습니다.

```
파일 탐색기에서 broadcaster.html 더블클릭
```
