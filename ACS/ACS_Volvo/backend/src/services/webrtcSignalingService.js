/**
 * WebRTC 시그널링 서비스
 * 영상 송출자(broadcaster)와 시청자(viewer) 간의 WebRTC 연결을 중개합니다.
 */

const WebSocket = require('ws');

class WebRTCSignalingService {
  constructor() {
    this.wss = null;
    this.port = 8083;
    this.rooms = new Map(); // roomId -> { broadcaster: ws, viewers: Set<ws> }
  }

  /**
   * WebSocket 서버 시작
   */
  start() {
    if (this.wss) {
      console.log('[WebRTC] 시그널링 서버가 이미 실행 중입니다.');
      return;
    }

    this.wss = new WebSocket.Server({ port: this.port });

    this.wss.on('connection', (ws) => {
      console.log('[WebRTC] 새 클라이언트 연결');
      
      ws.isAlive = true;
      ws.on('pong', () => { ws.isAlive = true; });

      ws.on('message', (message) => {
        try {
          const data = JSON.parse(message);
          this.handleMessage(ws, data);
        } catch (error) {
          console.error('[WebRTC] 메시지 파싱 오류:', error);
        }
      });

      ws.on('close', () => {
        console.log('[WebRTC] 클라이언트 연결 종료');
        this.handleDisconnect(ws);
      });

      ws.on('error', (error) => {
        console.error('[WebRTC] WebSocket 오류:', error);
      });
    });

    // 하트비트 체크
    this.heartbeatInterval = setInterval(() => {
      this.wss.clients.forEach((ws) => {
        if (!ws.isAlive) {
          return ws.terminate();
        }
        ws.isAlive = false;
        ws.ping();
      });
    }, 30000);

    console.log(`[WebRTC] 시그널링 서버 시작됨 (포트: ${this.port})`);
  }

  /**
   * 메시지 처리
   */
  handleMessage(ws, data) {
    const { type, roomId } = data;

    switch (type) {
      case 'join-as-broadcaster':
        this.joinAsBroadcaster(ws, roomId);
        break;
      case 'join-as-viewer':
        this.joinAsViewer(ws, roomId);
        break;
      case 'offer':
        this.forwardToViewer(ws, data);
        break;
      case 'answer':
        this.forwardToBroadcaster(ws, data);
        break;
      case 'ice-candidate':
        this.forwardIceCandidate(ws, data);
        break;
      case 'leave':
        this.handleLeave(ws, roomId);
        break;
      case 'get-rooms':
        this.sendRoomList(ws);
        break;
      default:
        console.warn('[WebRTC] 알 수 없는 메시지 타입:', type);
    }
  }

  /**
   * 송출자로 방 참가
   */
  joinAsBroadcaster(ws, roomId) {
    if (!roomId) {
      ws.send(JSON.stringify({ type: 'error', message: 'roomId가 필요합니다.' }));
      return;
    }

    // 기존 방이 있으면 제거
    if (this.rooms.has(roomId)) {
      const room = this.rooms.get(roomId);
      if (room.broadcaster) {
        room.broadcaster.send(JSON.stringify({ type: 'replaced', message: '새 송출자가 연결됨' }));
      }
    }

    // 방 생성/갱신
    if (!this.rooms.has(roomId)) {
      this.rooms.set(roomId, { broadcaster: null, viewers: new Set() });
    }

    const room = this.rooms.get(roomId);
    room.broadcaster = ws;
    ws.roomId = roomId;
    ws.role = 'broadcaster';

    console.log(`[WebRTC] 송출자 참가: ${roomId}`);
    ws.send(JSON.stringify({ type: 'joined', role: 'broadcaster', roomId }));

    // 대기 중인 시청자들에게 알림
    room.viewers.forEach(viewer => {
      viewer.send(JSON.stringify({ type: 'broadcaster-ready', roomId }));
    });
  }

  /**
   * 시청자로 방 참가
   */
  joinAsViewer(ws, roomId) {
    if (!roomId) {
      ws.send(JSON.stringify({ type: 'error', message: 'roomId가 필요합니다.' }));
      return;
    }

    if (!this.rooms.has(roomId)) {
      this.rooms.set(roomId, { broadcaster: null, viewers: new Set() });
    }

    const room = this.rooms.get(roomId);
    room.viewers.add(ws);
    ws.roomId = roomId;
    ws.role = 'viewer';
    ws.viewerId = `viewer-${Date.now()}-${Math.random().toString(36).substr(2, 9)}`;

    console.log(`[WebRTC] 시청자 참가: ${roomId} (${ws.viewerId})`);
    ws.send(JSON.stringify({ 
      type: 'joined', 
      role: 'viewer', 
      roomId,
      viewerId: ws.viewerId,
      broadcasterReady: !!room.broadcaster
    }));

    // 송출자에게 새 시청자 알림
    if (room.broadcaster) {
      room.broadcaster.send(JSON.stringify({ 
        type: 'viewer-joined', 
        viewerId: ws.viewerId 
      }));
    }
  }

  /**
   * Offer를 시청자에게 전달
   */
  forwardToViewer(ws, data) {
    const room = this.rooms.get(ws.roomId);
    if (!room) return;

    const targetViewer = Array.from(room.viewers).find(v => v.viewerId === data.viewerId);
    if (targetViewer) {
      targetViewer.send(JSON.stringify({
        type: 'offer',
        offer: data.offer,
        viewerId: data.viewerId
      }));
    }
  }

  /**
   * Answer를 송출자에게 전달
   */
  forwardToBroadcaster(ws, data) {
    const room = this.rooms.get(ws.roomId);
    if (!room || !room.broadcaster) return;

    room.broadcaster.send(JSON.stringify({
      type: 'answer',
      answer: data.answer,
      viewerId: ws.viewerId
    }));
  }

  /**
   * ICE Candidate 전달
   */
  forwardIceCandidate(ws, data) {
    const room = this.rooms.get(ws.roomId);
    if (!room) return;

    if (ws.role === 'broadcaster') {
      // 송출자 -> 특정 시청자
      const targetViewer = Array.from(room.viewers).find(v => v.viewerId === data.viewerId);
      if (targetViewer) {
        targetViewer.send(JSON.stringify({
          type: 'ice-candidate',
          candidate: data.candidate
        }));
      }
    } else {
      // 시청자 -> 송출자
      if (room.broadcaster) {
        room.broadcaster.send(JSON.stringify({
          type: 'ice-candidate',
          candidate: data.candidate,
          viewerId: ws.viewerId
        }));
      }
    }
  }

  /**
   * 방 나가기
   */
  handleLeave(ws, roomId) {
    this.handleDisconnect(ws);
  }

  /**
   * 연결 종료 처리
   */
  handleDisconnect(ws) {
    const roomId = ws.roomId;
    if (!roomId || !this.rooms.has(roomId)) return;

    const room = this.rooms.get(roomId);

    if (ws.role === 'broadcaster') {
      console.log(`[WebRTC] 송출자 퇴장: ${roomId}`);
      room.broadcaster = null;
      
      // 모든 시청자에게 알림
      room.viewers.forEach(viewer => {
        viewer.send(JSON.stringify({ type: 'broadcaster-left', roomId }));
      });

      // 시청자가 없으면 방 삭제
      if (room.viewers.size === 0) {
        this.rooms.delete(roomId);
      }
    } else if (ws.role === 'viewer') {
      console.log(`[WebRTC] 시청자 퇴장: ${roomId} (${ws.viewerId})`);
      room.viewers.delete(ws);

      // 송출자에게 알림
      if (room.broadcaster) {
        room.broadcaster.send(JSON.stringify({ 
          type: 'viewer-left', 
          viewerId: ws.viewerId 
        }));
      }

      // 방이 비었으면 삭제
      if (!room.broadcaster && room.viewers.size === 0) {
        this.rooms.delete(roomId);
      }
    }
  }

  /**
   * 방 목록 전송
   */
  sendRoomList(ws) {
    const roomList = [];
    this.rooms.forEach((room, roomId) => {
      if (room.broadcaster) {
        roomList.push({
          roomId,
          viewerCount: room.viewers.size
        });
      }
    });
    ws.send(JSON.stringify({ type: 'room-list', rooms: roomList }));
  }

  /**
   * 서비스 중지
   */
  stop() {
    if (this.heartbeatInterval) {
      clearInterval(this.heartbeatInterval);
    }
    
    if (this.wss) {
      this.wss.close();
      this.wss = null;
    }

    this.rooms.clear();
    console.log('[WebRTC] 시그널링 서버 중지됨');
  }

  /**
   * 활성 방 목록 조회
   */
  getActiveRooms() {
    const rooms = [];
    this.rooms.forEach((room, roomId) => {
      rooms.push({
        roomId,
        hasBroadcaster: !!room.broadcaster,
        viewerCount: room.viewers.size
      });
    });
    return rooms;
  }
}

// 싱글톤 인스턴스
const webrtcSignalingService = new WebRTCSignalingService();

module.exports = webrtcSignalingService;

