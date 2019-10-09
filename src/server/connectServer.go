package server

import (
	"context"
	"sync/atomic"

	//rpc "../../gen-go/dc"
	//	Server "DataChannelManager/src/server"
	"fmt"
	"github.com/apache/thrift/lib/go/thrift"
	"log"
	"net"
	"runtime/debug"
	//	"os"
	//	"os/signal"
	//"sync"
	//	"syscall"
	"time"
)

const (
	NetworkAddr = "127.0.0.1:9090"
)

type ConnectClientServer struct {
	tsocket *thrift.TSocket

	closed                 int32
	processorFactory       thrift.TProcessorFactory
	inputTransportFactory  thrift.TTransportFactory
	outputTransportFactory thrift.TTransportFactory
	inputProtocolFactory   thrift.TProtocolFactory
	outputProtocolFactory  thrift.TProtocolFactory
}

/**新建连接*/
func NewConnect(host, port string) *ConnectClientServer {
	transportFactory := thrift.NewTFramedTransportFactory(thrift.NewTTransportFactory())
	protocolFactory := thrift.NewTBinaryProtocolFactoryDefault()
	//handler := &rpcService{}
	//processor := rpc.NewDatecServiceProcessor(handler)
	socket, err := thrift.NewTSocket(net.JoinHostPort(host, port))
	if err != nil {
		fmt.Println("连接建立失败：", err)
		return nil
	}

	if err := socket.Open(); err == nil {
		//fmt.Println("连接成功")
	}
	//等待连接
	for true {
		if socket.IsOpen() == true {
			break
		}
		fmt.Println("尝试连接客户端:", host, port)
		time.Sleep(3 * time.Second)
		socket.Open()
	}
	log.Println("连接客户端成功", socket.Conn().RemoteAddr())
	ConnectClient := &ConnectClientServer{socket, 0, nil, transportFactory, transportFactory, protocolFactory, protocolFactory}
	return ConnectClient
}

//添加处理
func (this *ConnectClientServer) Addhandler(processor thrift.TProcessor) {
	this.processorFactory = thrift.NewTProcessorFactory(processor)
	go func() {
		this.BinRequests(this.tsocket)
	}()

}

func (p *ConnectClientServer) BinRequests(client thrift.TTransport) error {
	processor := p.processorFactory.GetProcessor(client)
	inputTransport, err := p.inputTransportFactory.GetTransport(client)
	if err != nil {
		return err
	}
	outputTransport, err := p.outputTransportFactory.GetTransport(client)
	if err != nil {
		return err
	}
	inputProtocol := p.inputProtocolFactory.GetProtocol(inputTransport)
	outputProtocol := p.outputProtocolFactory.GetProtocol(outputTransport)
	defer func() {
		if e := recover(); e != nil {
			log.Printf("panic in processor: %s: %s", e, debug.Stack())
		}
	}()

	for {
		if atomic.LoadInt32(&p.closed) != 0 {
			return nil
		}
		ok, err := processor.Process(context.Background(), inputProtocol, outputProtocol)
		if err, ok := err.(thrift.TTransportException); ok && err.TypeId() == thrift.END_OF_FILE {
			return nil
		} else if err != nil {
			return err
		}
		if err, ok := err.(thrift.TApplicationException); ok && err.TypeId() == thrift.UNKNOWN_METHOD {
			continue
		}
		if !ok {
			break
		}
	}
	return nil
}
