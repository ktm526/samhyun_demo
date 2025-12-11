#!/usr/bin/env python3
"""
WebRTC 영상 송출기 (Python)
웹캠 또는 화면을 WebRTC로 ACS 영상 페이지에 송출합니다.

사용법:
  python broadcaster.py [옵션]

옵션:
  --server URL      시그널링 서버 URL (기본: ws://localhost:8083)
  --room ROOM_ID    방 ID (기본: robot-front)
  --source SOURCE   비디오 소스 (기본: 0)
                    - 숫자: 웹캠 인덱스 (0, 1, 2...)
                    - 파일경로: 비디오 파일
                    - screen: 화면 캡처

요구사항:
  pip install aiortc aiohttp opencv-python av
"""

import asyncio
import argparse
import json
import logging
import cv2
import numpy as np
from datetime import datetime

# aiortc imports
from aiortc import RTCPeerConnection, RTCSessionDescription, VideoStreamTrack
from aiortc.contrib.media import MediaPlayer
from av import VideoFrame

# WebSocket
import aiohttp

logging.basicConfig(level=logging.INFO)
logger = logging.getLogger('broadcaster')


class WebcamVideoTrack(VideoStreamTrack):
    """웹캠에서 프레임을 읽어오는 VideoStreamTrack"""
    
    def __init__(self, source=0):
        super().__init__()
        self.source = source
        self.cap = None
        self._start_time = None
        self._frame_count = 0
        
    async def recv(self):
        if self.cap is None:
            self.cap = cv2.VideoCapture(self.source)
            self.cap.set(cv2.CAP_PROP_FRAME_WIDTH, 640)
            self.cap.set(cv2.CAP_PROP_FRAME_HEIGHT, 480)
            self.cap.set(cv2.CAP_PROP_FPS, 30)
            self._start_time = asyncio.get_event_loop().time()
        
        # 타이밍 조절 (30fps)
        pts = self._frame_count
        self._frame_count += 1
        
        # 다음 프레임 시간까지 대기
        target_time = self._start_time + (pts / 30)
        current_time = asyncio.get_event_loop().time()
        if target_time > current_time:
            await asyncio.sleep(target_time - current_time)
        
        # 프레임 읽기
        ret, frame = self.cap.read()
        if not ret:
            # 웹캠 재연결 시도
            self.cap.release()
            self.cap = cv2.VideoCapture(self.source)
            ret, frame = self.cap.read()
            if not ret:
                # 검은 화면 반환
                frame = np.zeros((480, 640, 3), dtype=np.uint8)
        
        # BGR -> RGB 변환
        frame = cv2.cvtColor(frame, cv2.COLOR_BGR2RGB)
        
        # 타임스탬프 오버레이 (선택사항)
        # timestamp = datetime.now().strftime('%H:%M:%S')
        # cv2.putText(frame, timestamp, (10, 30), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 255, 255), 2)
        
        # VideoFrame 생성
        video_frame = VideoFrame.from_ndarray(frame, format='rgb24')
        video_frame.pts = pts
        video_frame.time_base = '1/30'
        
        return video_frame
    
    def stop(self):
        if self.cap:
            self.cap.release()
            self.cap = None


class TestPatternTrack(VideoStreamTrack):
    """테스트 패턴을 생성하는 VideoStreamTrack"""
    
    def __init__(self):
        super().__init__()
        self._start_time = None
        self._frame_count = 0
        
    async def recv(self):
        if self._start_time is None:
            self._start_time = asyncio.get_event_loop().time()
        
        pts = self._frame_count
        self._frame_count += 1
        
        # 타이밍 조절
        target_time = self._start_time + (pts / 30)
        current_time = asyncio.get_event_loop().time()
        if target_time > current_time:
            await asyncio.sleep(target_time - current_time)
        
        # 테스트 패턴 생성
        frame = np.zeros((480, 640, 3), dtype=np.uint8)
        
        # 컬러 바
        colors = [
            (255, 255, 255),  # 흰색
            (255, 255, 0),    # 노랑
            (0, 255, 255),    # 시안
            (0, 255, 0),      # 초록
            (255, 0, 255),    # 마젠타
            (255, 0, 0),      # 빨강
            (0, 0, 255),      # 파랑
            (0, 0, 0),        # 검정
        ]
        
        bar_width = 640 // len(colors)
        for i, color in enumerate(colors):
            frame[:, i*bar_width:(i+1)*bar_width] = color
        
        # 시간 표시
        timestamp = datetime.now().strftime('%Y-%m-%d %H:%M:%S')
        cv2.putText(frame, timestamp, (200, 250), cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 0, 0), 3)
        cv2.putText(frame, timestamp, (200, 250), cv2.FONT_HERSHEY_SIMPLEX, 1, (255, 255, 255), 2)
        
        cv2.putText(frame, 'WebRTC Test Pattern', (180, 290), cv2.FONT_HERSHEY_SIMPLEX, 0.8, (0, 0, 0), 3)
        cv2.putText(frame, 'WebRTC Test Pattern', (180, 290), cv2.FONT_HERSHEY_SIMPLEX, 0.8, (255, 255, 255), 2)
        
        video_frame = VideoFrame.from_ndarray(frame, format='rgb24')
        video_frame.pts = pts
        video_frame.time_base = '1/30'
        
        return video_frame


class WebRTCBroadcaster:
    def __init__(self, server_url, room_id, source):
        self.server_url = server_url
        self.room_id = room_id
        self.source = source
        self.ws = None
        self.peer_connections = {}  # viewerId -> RTCPeerConnection
        self.video_track = None
        self.running = False
        
    def create_video_track(self):
        """비디오 트랙 생성"""
        if self.source == 'test':
            logger.info('테스트 패턴 사용')
            return TestPatternTrack()
        elif self.source == 'screen':
            logger.info('화면 캡처는 현재 지원되지 않습니다. 테스트 패턴 사용')
            return TestPatternTrack()
        else:
            try:
                source_index = int(self.source)
                logger.info(f'웹캠 {source_index} 사용')
                return WebcamVideoTrack(source_index)
            except ValueError:
                # 파일 경로
                logger.info(f'비디오 파일 사용: {self.source}')
                return WebcamVideoTrack(self.source)
    
    async def connect(self):
        """시그널링 서버에 연결"""
        logger.info(f'시그널링 서버 연결: {self.server_url}')
        
        try:
            session = aiohttp.ClientSession()
            self.ws = await session.ws_connect(self.server_url)
            logger.info('시그널링 서버 연결 성공')
            
            # 송출자로 방 참가
            await self.ws.send_json({
                'type': 'join-as-broadcaster',
                'roomId': self.room_id
            })
            
            self.running = True
            self.video_track = self.create_video_track()
            
            # 메시지 수신 루프
            async for msg in self.ws:
                if msg.type == aiohttp.WSMsgType.TEXT:
                    data = json.loads(msg.data)
                    await self.handle_message(data)
                elif msg.type == aiohttp.WSMsgType.ERROR:
                    logger.error(f'WebSocket 오류: {self.ws.exception()}')
                    break
                    
        except Exception as e:
            logger.error(f'연결 오류: {e}')
        finally:
            await self.cleanup()
            await session.close()
    
    async def handle_message(self, data):
        """시그널링 메시지 처리"""
        msg_type = data.get('type')
        
        if msg_type == 'joined':
            logger.info(f'방 참가 완료: {data.get("roomId")}')
            print(f'\n{"="*50}')
            print(f'  송출 시작!')
            print(f'  방 ID: {self.room_id}')
            print(f'  ACS 영상 페이지에서 "{self.room_id}" 로 연결하세요')
            print(f'{"="*50}\n')
            
        elif msg_type == 'viewer-joined':
            viewer_id = data.get('viewerId')
            logger.info(f'새 시청자: {viewer_id}')
            await self.create_peer_connection(viewer_id)
            
        elif msg_type == 'viewer-left':
            viewer_id = data.get('viewerId')
            logger.info(f'시청자 퇴장: {viewer_id}')
            await self.close_peer_connection(viewer_id)
            
        elif msg_type == 'answer':
            viewer_id = data.get('viewerId')
            answer = data.get('answer')
            await self.handle_answer(viewer_id, answer)
            
        elif msg_type == 'ice-candidate':
            viewer_id = data.get('viewerId')
            candidate = data.get('candidate')
            await self.handle_ice_candidate(viewer_id, candidate)
            
        elif msg_type == 'error':
            logger.error(f'오류: {data.get("message")}')
    
    async def create_peer_connection(self, viewer_id):
        """PeerConnection 생성 및 Offer 전송"""
        try:
            pc = RTCPeerConnection()
            self.peer_connections[viewer_id] = pc
            
            # 비디오 트랙 추가
            pc.addTrack(self.video_track)
            
            # ICE Candidate 처리
            @pc.on('icecandidate')
            async def on_icecandidate(candidate):
                if candidate and self.ws:
                    await self.ws.send_json({
                        'type': 'ice-candidate',
                        'viewerId': viewer_id,
                        'candidate': {
                            'candidate': candidate.candidate,
                            'sdpMid': candidate.sdpMid,
                            'sdpMLineIndex': candidate.sdpMLineIndex
                        }
                    })
            
            # 연결 상태 모니터링
            @pc.on('connectionstatechange')
            async def on_connectionstatechange():
                logger.info(f'{viewer_id} 연결 상태: {pc.connectionState}')
                if pc.connectionState == 'failed':
                    await self.close_peer_connection(viewer_id)
            
            # Offer 생성 및 전송
            offer = await pc.createOffer()
            await pc.setLocalDescription(offer)
            
            await self.ws.send_json({
                'type': 'offer',
                'viewerId': viewer_id,
                'offer': {
                    'type': pc.localDescription.type,
                    'sdp': pc.localDescription.sdp
                }
            })
            
            logger.info(f'{viewer_id}에게 Offer 전송')
            
        except Exception as e:
            logger.error(f'PeerConnection 생성 오류: {e}')
    
    async def handle_answer(self, viewer_id, answer):
        """Answer 처리"""
        pc = self.peer_connections.get(viewer_id)
        if pc:
            await pc.setRemoteDescription(RTCSessionDescription(
                type=answer['type'],
                sdp=answer['sdp']
            ))
            logger.info(f'{viewer_id}로부터 Answer 수신')
    
    async def handle_ice_candidate(self, viewer_id, candidate):
        """ICE Candidate 처리"""
        pc = self.peer_connections.get(viewer_id)
        if pc and candidate:
            from aiortc import RTCIceCandidate
            # ICE candidate 추가 (aiortc에서는 자동 처리됨)
            pass
    
    async def close_peer_connection(self, viewer_id):
        """PeerConnection 종료"""
        pc = self.peer_connections.pop(viewer_id, None)
        if pc:
            await pc.close()
    
    async def cleanup(self):
        """리소스 정리"""
        self.running = False
        
        # 모든 PeerConnection 종료
        for viewer_id, pc in list(self.peer_connections.items()):
            await pc.close()
        self.peer_connections.clear()
        
        # 비디오 트랙 정리
        if self.video_track and hasattr(self.video_track, 'stop'):
            self.video_track.stop()
        
        # WebSocket 종료
        if self.ws:
            await self.ws.close()
        
        logger.info('송출 종료')


async def main():
    parser = argparse.ArgumentParser(description='WebRTC 영상 송출기')
    parser.add_argument('--server', default='ws://localhost:8083',
                       help='시그널링 서버 URL (기본: ws://localhost:8083)')
    parser.add_argument('--room', default='robot-front',
                       help='방 ID (기본: robot-front)')
    parser.add_argument('--source', default='0',
                       help='비디오 소스: 웹캠 인덱스(0,1,2...), 파일경로, 또는 test (기본: 0)')
    
    args = parser.parse_args()
    
    print()
    print('=' * 50)
    print('  WebRTC 영상 송출기')
    print('=' * 50)
    print()
    print(f'  시그널링 서버: {args.server}')
    print(f'  방 ID: {args.room}')
    print(f'  비디오 소스: {args.source}')
    print()
    print('  Ctrl+C로 종료')
    print()
    
    broadcaster = WebRTCBroadcaster(args.server, args.room, args.source)
    
    try:
        await broadcaster.connect()
    except KeyboardInterrupt:
        print('\n종료 요청됨...')
    finally:
        await broadcaster.cleanup()


if __name__ == '__main__':
    asyncio.run(main())

