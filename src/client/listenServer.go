package client

import (
	"DataChannelManager/src/common"
	. "github.com/apache/thrift/lib/go/thrift"
	"log"
	//	"runtime/debug"
	"sync"
	"sync/atomic"
)

type TListenServer struct {
	closed int32
	wg     sync.WaitGroup
	mu     sync.Mutex

	processorFactory       TProcessorFactory
	serverTransport        TServerTransport
	inputTransportFactory  TTransportFactory
	outputTransportFactory TTransportFactory
	inputProtocolFactory   TProtocolFactory
	outputProtocolFactory  TProtocolFactory
	transports             TTransport
}

func NewTListenServer(processor TProcessor, serverTransport TServerTransport, transportFactory TTransportFactory, protocolFactory TProtocolFactory) *TListenServer {
	return &TListenServer{
		processorFactory:       NewTProcessorFactory(processor),
		serverTransport:        serverTransport,
		inputTransportFactory:  transportFactory,
		outputTransportFactory: transportFactory,
		inputProtocolFactory:   protocolFactory,
		outputProtocolFactory:  protocolFactory,
	}
}

func (p *TListenServer) ProcessorFactory() TProcessorFactory {
	return p.processorFactory
}

func (p *TListenServer) ServerTransport() TServerTransport {
	return p.serverTransport
}

func (p *TListenServer) InputTransportFactory() TTransportFactory {
	return p.inputTransportFactory
}

func (p *TListenServer) OutputTransportFactory() TTransportFactory {
	return p.outputTransportFactory
}

func (p *TListenServer) InputProtocolFactory() TProtocolFactory {
	return p.inputProtocolFactory
}

func (p *TListenServer) OutputProtocolFactory() TProtocolFactory {
	return p.outputProtocolFactory
}

func (p *TListenServer) Listen() error {
	return p.serverTransport.Listen()
}

func (p *TListenServer) innerAccept() (int32, error) {
	client, err := p.serverTransport.Accept()
	if err == nil {
		p.transports = client
	}
	return 0, nil
}

func (p *TListenServer) AcceptLoop() error {
	for {
		closed, err := p.innerAccept()
		if err != nil {
			return err
		}
		if closed != 0 {
			return nil
		}
	}
}

func (p *TListenServer) Serve() error {
	if p == nil {
		return common.NewError(0, "server socket err")
	}
	err := p.Listen()
	if err != nil {
		return err
	}
	p.AcceptLoop()
	return nil
}
func (p *TListenServer) Stop() error {
	p.mu.Lock()
	defer p.mu.Unlock()
	if atomic.LoadInt32(&p.closed) != 0 {
		return nil
	}
	atomic.StoreInt32(&p.closed, 1)
	p.serverTransport.Interrupt()
	p.wg.Wait()
	return nil
}
func (p *TListenServer) Tranports() TTransport {
	return p.transports
}

func NewClient(ip, port string) *TListenServer {
	transportFactory := NewTFramedTransportFactory(NewTTransportFactory())
	protocolFactory := NewTBinaryProtocolFactoryDefault()
	serverTransport, err := NewTServerSocket(string(ip + ":" + port))
	if err != nil {
		log.Fatalln("监听失败:", err)
		return nil
	}
	log.Println("监听服务已启动，等待服务端的连接")
	return NewTListenServer(nil, serverTransport, transportFactory, protocolFactory)
}
func (p *TListenServer) BindProcessorerror(processor TProcessor) {
	p.processorFactory = NewTProcessorFactory(processor)
}
