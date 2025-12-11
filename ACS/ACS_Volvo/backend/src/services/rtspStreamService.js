/**
 * RTSP 스트리밍 서비스
 * RTSP 스트림을 WebSocket을 통해 브라우저로 전송합니다.
 */

const { spawn } = require('child_process');
const WebSocket = require('ws');

class RTSPStreamService {
  constructor() {
    this.streams = new Map(); // streamId -> { ffmpeg, clients: Set<WebSocket> }
    this.wss = null;
    this.port = 8082; // WebSocket 포트
  }

  /**
   * WebSocket 서버 시작
   */
  start(server = null) {
    if (this.wss) {
      console.log('[RTSP] WebSocket 서버가 이미 실행 중입니다.');
      return;
    }

    // 독립 WebSocket 서버 생성
    this.wss = new WebSocket.Server({ port: this.port });

    this.wss.on('connection', (ws, req) => {
      console.log('[RTSP] 새로운 WebSocket 연결');

      ws.on('message', (message) => {
        try {
          const data = JSON.parse(message);
          this.handleMessage(ws, data);
        } catch (error) {
          console.error('[RTSP] 메시지 파싱 오류:', error);
        }
      });

      ws.on('close', () => {
        console.log('[RTSP] WebSocket 연결 종료');
        this.removeClientFromAllStreams(ws);
      });

      ws.on('error', (error) => {
        console.error('[RTSP] WebSocket 오류:', error);
      });
    });

    console.log(`[RTSP] WebSocket 서버 시작됨 (포트: ${this.port})`);
  }

  /**
   * 메시지 처리
   */
  handleMessage(ws, data) {
    const { action, streamId, rtspUrl } = data;

    switch (action) {
      case 'subscribe':
        this.subscribeToStream(ws, streamId, rtspUrl);
        break;
      case 'unsubscribe':
        this.unsubscribeFromStream(ws, streamId);
        break;
      default:
        console.warn('[RTSP] 알 수 없는 액션:', action);
    }
  }

  /**
   * 스트림 구독
   */
  subscribeToStream(ws, streamId, rtspUrl) {
    if (!rtspUrl) {
      ws.send(JSON.stringify({ type: 'error', message: 'RTSP URL이 필요합니다.' }));
      return;
    }

    console.log(`[RTSP] 스트림 구독: ${streamId} -> ${rtspUrl}`);

    // 기존 스트림이 있으면 클라이언트 추가
    if (this.streams.has(streamId)) {
      const stream = this.streams.get(streamId);
      stream.clients.add(ws);
      ws.streamId = streamId;
      ws.send(JSON.stringify({ type: 'subscribed', streamId }));
      console.log(`[RTSP] 기존 스트림에 클라이언트 추가: ${streamId} (총 ${stream.clients.size}명)`);
      return;
    }

    // 새 스트림 생성
    this.createStream(streamId, rtspUrl, ws);
  }

  /**
   * FFmpeg를 사용하여 RTSP 스트림 생성
   */
  createStream(streamId, rtspUrl, initialClient) {
    console.log(`[RTSP] 새 스트림 생성: ${streamId}`);

    const clients = new Set([initialClient]);
    initialClient.streamId = streamId;

    // FFmpeg 프로세스 생성 - MPEG1 형식으로 변환
    const ffmpeg = spawn('ffmpeg', [
      '-rtsp_transport', 'tcp',
      '-i', rtspUrl,
      '-f', 'mpegts',
      '-codec:v', 'mpeg1video',
      '-b:v', '1000k',
      '-r', '30',
      '-s', '640x480',
      '-bf', '0',
      '-muxdelay', '0.001',
      '-'
    ]);

    ffmpeg.on('error', (error) => {
      console.error(`[RTSP] FFmpeg 오류 (${streamId}):`, error.message);
      this.notifyClients(streamId, { type: 'error', message: `FFmpeg 오류: ${error.message}` });
      this.removeStream(streamId);
    });

    ffmpeg.stderr.on('data', (data) => {
      // FFmpeg 로그 (디버깅용)
      // console.log(`[RTSP] FFmpeg (${streamId}):`, data.toString());
    });

    ffmpeg.stdout.on('data', (data) => {
      // 모든 클라이언트에게 비디오 데이터 전송
      const stream = this.streams.get(streamId);
      if (stream) {
        stream.clients.forEach(client => {
          if (client.readyState === WebSocket.OPEN) {
            client.send(data);
          }
        });
      }
    });

    ffmpeg.on('close', (code) => {
      console.log(`[RTSP] FFmpeg 종료 (${streamId}): 코드 ${code}`);
      this.notifyClients(streamId, { type: 'closed', streamId });
      this.removeStream(streamId);
    });

    this.streams.set(streamId, { ffmpeg, clients, rtspUrl });
    initialClient.send(JSON.stringify({ type: 'subscribed', streamId }));
  }

  /**
   * 스트림 구독 취소
   */
  unsubscribeFromStream(ws, streamId) {
    const stream = this.streams.get(streamId);
    if (!stream) return;

    stream.clients.delete(ws);
    console.log(`[RTSP] 클라이언트 구독 취소: ${streamId} (남은 클라이언트: ${stream.clients.size}명)`);

    // 클라이언트가 없으면 스트림 종료
    if (stream.clients.size === 0) {
      this.removeStream(streamId);
    }
  }

  /**
   * 클라이언트를 모든 스트림에서 제거
   */
  removeClientFromAllStreams(ws) {
    this.streams.forEach((stream, streamId) => {
      if (stream.clients.has(ws)) {
        stream.clients.delete(ws);
        console.log(`[RTSP] 클라이언트 제거: ${streamId} (남은 클라이언트: ${stream.clients.size}명)`);
        
        if (stream.clients.size === 0) {
          this.removeStream(streamId);
        }
      }
    });
  }

  /**
   * 스트림 제거
   */
  removeStream(streamId) {
    const stream = this.streams.get(streamId);
    if (!stream) return;

    console.log(`[RTSP] 스트림 종료: ${streamId}`);
    
    if (stream.ffmpeg && !stream.ffmpeg.killed) {
      stream.ffmpeg.kill('SIGTERM');
    }
    
    this.streams.delete(streamId);
  }

  /**
   * 클라이언트들에게 메시지 전송
   */
  notifyClients(streamId, message) {
    const stream = this.streams.get(streamId);
    if (!stream) return;

    const jsonMessage = JSON.stringify(message);
    stream.clients.forEach(client => {
      if (client.readyState === WebSocket.OPEN) {
        client.send(jsonMessage);
      }
    });
  }

  /**
   * 서비스 중지
   */
  stop() {
    console.log('[RTSP] 서비스 중지 중...');
    
    // 모든 스트림 종료
    this.streams.forEach((stream, streamId) => {
      this.removeStream(streamId);
    });

    // WebSocket 서버 종료
    if (this.wss) {
      this.wss.close();
      this.wss = null;
    }

    console.log('[RTSP] 서비스 중지됨');
  }

  /**
   * 활성 스트림 목록 조회
   */
  getActiveStreams() {
    const streams = [];
    this.streams.forEach((stream, streamId) => {
      streams.push({
        streamId,
        rtspUrl: stream.rtspUrl,
        clientCount: stream.clients.size
      });
    });
    return streams;
  }
}

// 싱글톤 인스턴스
const rtspStreamService = new RTSPStreamService();

module.exports = rtspStreamService;

