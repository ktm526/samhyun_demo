#!/usr/bin/env python3
"""
RTSP 테스트 서버
웹캠 또는 테스트 패턴을 RTSP로 송출합니다.

사용법:
  python rtsp_server.py [옵션]

옵션:
  --port PORT       RTSP 서버 포트 (기본: 8554)
  --source SOURCE   비디오 소스 (기본: test)
                    - test: 테스트 패턴 생성
                    - webcam: 웹캠 사용 (/dev/video0)
                    - 파일경로: 비디오 파일 사용
  --stream-name     스트림 이름 (기본: front)

요구사항:
  - Python 3.6+
  - FFmpeg (설치 필요)
  - GStreamer (rtsp-simple-server 대안)

간단한 테스트 방법:
  1. rtsp-simple-server 설치 후 실행
  2. FFmpeg로 스트림 전송
"""

import subprocess
import argparse
import sys
import time
import signal
import os

class RTSPTestServer:
    def __init__(self, port=8554, source='test', stream_name='front'):
        self.port = port
        self.source = source
        self.stream_name = stream_name
        self.process = None
        self.rtsp_server_process = None

    def get_ffmpeg_input_args(self):
        """비디오 소스에 따른 FFmpeg 입력 인자 반환"""
        if self.source == 'test':
            # 테스트 패턴 생성 (색상 막대 + 시간 표시)
            return [
                '-f', 'lavfi',
                '-i', 'testsrc=size=640x480:rate=30,drawtext=fontsize=30:fontcolor=white:x=(w-text_w)/2:y=h-50:text=%{localtime}'
            ]
        elif self.source == 'webcam':
            # 웹캠 사용
            return [
                '-f', 'v4l2',
                '-video_size', '640x480',
                '-framerate', '30',
                '-i', '/dev/video0'
            ]
        else:
            # 비디오 파일 사용
            return [
                '-re',  # 실시간 속도로 재생
                '-stream_loop', '-1',  # 무한 반복
                '-i', self.source
            ]

    def start_with_ffmpeg_rtsp(self):
        """FFmpeg를 사용하여 RTSP 서버로 송출 (mediamtx/rtsp-simple-server 필요)"""
        rtsp_url = f'rtsp://localhost:{self.port}/{self.stream_name}'
        
        ffmpeg_cmd = [
            'ffmpeg',
            *self.get_ffmpeg_input_args(),
            '-c:v', 'libx264',
            '-preset', 'ultrafast',
            '-tune', 'zerolatency',
            '-f', 'rtsp',
            '-rtsp_transport', 'tcp',
            rtsp_url
        ]

        print(f"[INFO] RTSP 스트림 시작: {rtsp_url}")
        print(f"[INFO] 명령어: {' '.join(ffmpeg_cmd)}")
        print()
        print("=" * 60)
        print(f"  RTSP URL: {rtsp_url}")
        print("=" * 60)
        print()
        
        try:
            self.process = subprocess.Popen(
                ffmpeg_cmd,
                stdout=subprocess.PIPE,
                stderr=subprocess.PIPE
            )
            
            # FFmpeg 출력 모니터링
            while True:
                if self.process.poll() is not None:
                    break
                time.sleep(1)
                
        except KeyboardInterrupt:
            print("\n[INFO] 종료 요청됨...")
        except FileNotFoundError:
            print("[ERROR] FFmpeg를 찾을 수 없습니다. FFmpeg를 설치해주세요.")
            print("        Ubuntu: sudo apt install ffmpeg")
            print("        MacOS: brew install ffmpeg")
            sys.exit(1)
        finally:
            self.stop()

    def start_simple_http_mjpeg(self):
        """간단한 HTTP MJPEG 스트림 (FFmpeg만 필요)"""
        from http.server import HTTPServer, BaseHTTPRequestHandler
        import threading
        import io
        
        server = self
        
        class MJPEGHandler(BaseHTTPRequestHandler):
            def do_GET(self):
                if self.path == '/':
                    self.send_response(200)
                    self.send_header('Content-type', 'text/html')
                    self.end_headers()
                    html = f'''
                    <!DOCTYPE html>
                    <html>
                    <head><title>MJPEG 테스트 스트림</title></head>
                    <body style="background:#1a1a1a;color:white;font-family:sans-serif;text-align:center;padding:20px">
                        <h1>MJPEG 테스트 스트림</h1>
                        <p>스트림 URL: <code>http://localhost:{server.port}/stream</code></p>
                        <img src="/stream" style="max-width:100%;border:2px solid #333;border-radius:8px">
                    </body>
                    </html>
                    '''
                    self.wfile.write(html.encode())
                    
                elif self.path == '/stream':
                    self.send_response(200)
                    self.send_header('Content-type', 'multipart/x-mixed-replace; boundary=frame')
                    self.end_headers()
                    
                    # FFmpeg로 JPEG 프레임 생성
                    ffmpeg_cmd = [
                        'ffmpeg',
                        *server.get_ffmpeg_input_args(),
                        '-f', 'image2pipe',
                        '-vcodec', 'mjpeg',
                        '-q:v', '5',
                        '-'
                    ]
                    
                    process = subprocess.Popen(
                        ffmpeg_cmd,
                        stdout=subprocess.PIPE,
                        stderr=subprocess.DEVNULL
                    )
                    
                    try:
                        buffer = b''
                        while True:
                            chunk = process.stdout.read(4096)
                            if not chunk:
                                break
                            buffer += chunk
                            
                            # JPEG 프레임 찾기 (SOI: FFD8, EOI: FFD9)
                            start = buffer.find(b'\xff\xd8')
                            end = buffer.find(b'\xff\xd9')
                            
                            if start != -1 and end != -1 and end > start:
                                frame = buffer[start:end+2]
                                buffer = buffer[end+2:]
                                
                                self.wfile.write(b'--frame\r\n')
                                self.wfile.write(b'Content-Type: image/jpeg\r\n\r\n')
                                self.wfile.write(frame)
                                self.wfile.write(b'\r\n')
                    except:
                        pass
                    finally:
                        process.terminate()
                else:
                    self.send_error(404)
            
            def log_message(self, format, *args):
                pass  # 로그 비활성화
        
        print(f"[INFO] MJPEG HTTP 서버 시작: http://localhost:{self.port}")
        print(f"[INFO] 스트림 URL: http://localhost:{self.port}/stream")
        print()
        print("=" * 60)
        print(f"  브라우저에서 열기: http://localhost:{self.port}")
        print(f"  스트림 URL: http://localhost:{self.port}/stream")
        print("=" * 60)
        print()
        
        httpd = HTTPServer(('0.0.0.0', self.port), MJPEGHandler)
        try:
            httpd.serve_forever()
        except KeyboardInterrupt:
            print("\n[INFO] 서버 종료")
            httpd.shutdown()

    def stop(self):
        """서버 중지"""
        if self.process:
            self.process.terminate()
            self.process.wait()
            self.process = None
        if self.rtsp_server_process:
            self.rtsp_server_process.terminate()
            self.rtsp_server_process.wait()
            self.rtsp_server_process = None
        print("[INFO] 서버가 중지되었습니다.")


def check_dependencies():
    """필수 프로그램 확인"""
    # FFmpeg 확인
    try:
        subprocess.run(['ffmpeg', '-version'], capture_output=True, check=True)
        print("[OK] FFmpeg 설치됨")
    except (subprocess.CalledProcessError, FileNotFoundError):
        print("[ERROR] FFmpeg가 설치되어 있지 않습니다.")
        print("        Ubuntu: sudo apt install ffmpeg")
        print("        MacOS: brew install ffmpeg")
        return False
    
    return True


def main():
    parser = argparse.ArgumentParser(description='RTSP 테스트 서버')
    parser.add_argument('--port', type=int, default=8554, help='서버 포트 (기본: 8554)')
    parser.add_argument('--source', default='test', 
                       help='비디오 소스: test, webcam, 또는 파일경로 (기본: test)')
    parser.add_argument('--stream-name', default='front', help='스트림 이름 (기본: front)')
    parser.add_argument('--mode', choices=['rtsp', 'mjpeg'], default='mjpeg',
                       help='스트리밍 모드: rtsp (rtsp-simple-server 필요), mjpeg (HTTP) (기본: mjpeg)')
    
    args = parser.parse_args()
    
    print()
    print("=" * 60)
    print("  RTSP/MJPEG 테스트 서버")
    print("=" * 60)
    print()
    
    if not check_dependencies():
        sys.exit(1)
    
    print()
    print(f"[INFO] 설정:")
    print(f"       - 포트: {args.port}")
    print(f"       - 소스: {args.source}")
    print(f"       - 스트림 이름: {args.stream_name}")
    print(f"       - 모드: {args.mode}")
    print()
    
    server = RTSPTestServer(
        port=args.port,
        source=args.source,
        stream_name=args.stream_name
    )
    
    # SIGINT 처리
    signal.signal(signal.SIGINT, lambda s, f: server.stop())
    
    if args.mode == 'rtsp':
        print("[INFO] RTSP 모드를 사용하려면 rtsp-simple-server 또는 mediamtx가 필요합니다.")
        print("       설치: https://github.com/bluenviron/mediamtx/releases")
        print()
        server.start_with_ffmpeg_rtsp()
    else:
        server.start_simple_http_mjpeg()


if __name__ == '__main__':
    main()

