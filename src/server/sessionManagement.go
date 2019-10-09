package server

import (
	"container/list"
	"errors"
	"fmt"
	//	"github.com/apache/thrift/lib/go/thrift"
	"sync"
	"time"
)

var (
	MgErrOverMax          = errors.New("连接超过设置的最大连接数")
	MgErrInvalidConn      = errors.New("Client回收时变成nil")
	MgErrPoolClosed       = errors.New("连接池已经被关闭")
	MgErrSocketDisconnect = errors.New("客户端socket连接已断开")

	MgErrPoolNoInstance = errors.New("管理池未建立")
)

type SessionClose func(c *ConnectClientServer) error
type ConInfo struct {
	conName   string    //连接名
	conStart  time.Time //连接开始时间
	conStatus string    //连接状态
	conIp     string
	port      string
}
type Session struct {
	info ConInfo
	//Socket *thrift.TSocket
	conmg  ConnectClientServer
	Client interface{}
}

type SessionManagement struct {
	//	Close SessionClose

	lock        *sync.Mutex
	sessions    list.List
	idleTimeout time.Duration
	connTimeout time.Duration
	maxConn     uint32 //允许最大连接数
	onlineCount uint32 //在线数
	count       uint32 //当前总数
	closed      bool   //管理器是否关闭
}

func NewSessionManagement(maxConn, connTimeout uint32) *SessionManagement {

	sessionMg := &SessionManagement{
		lock:        new(sync.Mutex),
		maxConn:     maxConn,
		connTimeout: time.Duration(connTimeout) * time.Second,
		closed:      false,
		count:       0,
		onlineCount: 0,
		//	Close:close,
	}
	return sessionMg
}

func (p *SessionManagement) AddSession(s *ConnectClientServer) error {
	p.lock.Lock()
	if p == nil {
		p.lock.Unlock()
		return MgErrPoolNoInstance
	}
	if s == nil {
		p.lock.Unlock()
		return MgErrInvalidConn
	}

	if p.count > p.maxConn {
		if p.count > 0 {
			p.count -= 0
			s.tsocket.Close()
		}
		p.lock.Unlock()
		return MgErrOverMax
	}
	p.count += 1
	p.sessions.PushBack(s)
	p.lock.Unlock()
	return nil
}

func (p *SessionManagement) GetSessionByName(name string) *ConnectClientServer {
	if p == nil || p.sessions.Len() <= 0 {
		return nil
	}
	for item := p.sessions.Front(); nil != item; item.Next() {
		msession := item.Value
		connectClient := msession.(*Session)

		if connectClient.info.conName == name {
			return &connectClient.conmg
		}
		fmt.Println(msession)
	}
	return nil
}

func Close(c *ConnectClientServer) error {
	c.tsocket.Close()
	return nil
}

func (p *SessionManagement) Show() string {
	p.lock.Lock()
	s := fmt.Sprintf("maxCon: %d\ncout:%d",
		p.maxConn,
		p.count)
	p.lock.Unlock()
	return s
}
