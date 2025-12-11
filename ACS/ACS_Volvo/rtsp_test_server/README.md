# RTSP 테스트 서버

AMR 관제 시스템의 영상 페이지 테스트를 위한 RTSP/MJPEG 스트림 송출 서버입니다.

## 요구사항

- Python 3.6 이상
- FFmpeg

### FFmpeg 설치

**Ubuntu/Debian:**
```bash
sudo apt update
sudo apt install ffmpeg
```

**MacOS:**
```bash
brew install ffmpeg
```

**Windows:**
- [FFmpeg 공식 사이트](https://ffmpeg.org/download.html)에서 다운로드
- 환경 변수 PATH에 FFmpeg 경로 추가

## 사용법

### 1. 기본 실행 (MJPEG HTTP 스트림)

```bash
python rtsp_server.py
```

기본적으로 테스트 패턴을 `http://localhost:8554/stream`으로 송출합니다.

### 2. 웹캠 사용

```bash
python rtsp_server.py --source webcam
```

### 3. 비디오 파일 사용

```bash
python rtsp_server.py --source /path/to/video.mp4
```

### 4. 포트 변경

```bash
python rtsp_server.py --port 8555
```

### 5. RTSP 모드 (mediamtx 필요)

```bash
# 먼저 mediamtx 설치 및 실행
# https://github.com/bluenviron/mediamtx/releases

python rtsp_server.py --mode rtsp
```

## 전체 옵션

```
옵션:
  --port PORT       서버 포트 (기본: 8554)
  --source SOURCE   비디오 소스 (기본: test)
                    - test: 테스트 패턴 생성
                    - webcam: 웹캠 사용 (/dev/video0)
                    - 파일경로: 비디오 파일 사용
  --stream-name     스트림 이름 (기본: front)
  --mode            스트리밍 모드: rtsp 또는 mjpeg (기본: mjpeg)
```

## 연동 방법

### MJPEG 모드 (기본)

1. 테스트 서버 실행:
   ```bash
   python rtsp_server.py --port 8554
   ```

2. ACS 영상 페이지에서:
   - "커스텀 RTSP URL 사용" 체크
   - URL 입력: `http://<서버IP>:8554/stream`
   - "연결" 클릭

### RTSP 모드

1. mediamtx 설치 및 실행
2. 테스트 서버 실행:
   ```bash
   python rtsp_server.py --mode rtsp --port 8554
   ```

3. ACS 영상 페이지에서:
   - "커스텀 RTSP URL 사용" 체크
   - URL 입력: `rtsp://<서버IP>:8554/front`
   - "연결" 클릭

## 다른 컴퓨터에서 테스트

1. 테스트 서버가 실행 중인 컴퓨터의 IP 확인:
   ```bash
   ip addr  # Linux
   ipconfig  # Windows
   ```

2. 방화벽에서 포트 허용 (필요시):
   ```bash
   sudo ufw allow 8554/tcp
   ```

3. ACS 영상 페이지에서 해당 IP로 연결:
   - MJPEG: `http://<IP주소>:8554/stream`
   - RTSP: `rtsp://<IP주소>:8554/front`

## 문제 해결

### FFmpeg를 찾을 수 없음
```
[ERROR] FFmpeg를 찾을 수 없습니다.
```
→ FFmpeg 설치 후 PATH 확인

### 웹캠 접근 불가
```
/dev/video0: Permission denied
```
→ 사용자를 video 그룹에 추가:
```bash
sudo usermod -a -G video $USER
```
로그아웃 후 다시 로그인

### 포트 사용 중
```
Address already in use
```
→ 다른 포트 사용: `--port 8555`

