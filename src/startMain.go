package main

import (
	//	"fmt"
	//	"time"
	rpc "../gen-go/dc"
	Client "DataChannelManager/src/client"
	Server "DataChannelManager/src/server"
	"context"
	"fmt"
	"log"
	"os"
	"os/signal"
	"strconv"
	"syscall"
	"time"
)

const (
	NetworkAddr = "127.0.0.1:9090"
)

var GlobalRpcPool *Server.SessionManagement

func runClient(ip, port string) {
	client := Client.NewClient(ip, port)
	go client.Serve() //开启监听
	for true {
		transport := client.Tranports()
		if transport == nil {
			time.Sleep(10 * time.Second)
			continue
		}
		newclient, _ := client.OutputTransportFactory().GetTransport(transport)
		tclient := rpc.NewDatecServiceClientFactory(newclient, client.OutputProtocolFactory())
		log.Println("发送心跳........")
		tclient.Heart(context.Background(), time.Now().String())
		//	str,_:=tclient.StringInfo(context.Background(),time.Now().String())
		time.Sleep(5 * time.Second)

	}
}

func runServer(host, port string) {
	server := Server.NewConnect(host, port)
	if server == nil {
		log.Println("无法与客户端建立连接")
		return
	}
	handler := Server.NewServerHandler()
	processor := rpc.NewDatecServiceProcessor(handler)
	server.Addhandler(processor)
	err := GlobalRpcPool.AddSession(server)
	if err != nil {
		log.Fatalln("添加到连接池失败：", err)
		return
	}
	log.Println("将会话添加到连接池成功")
}
func main() {

	go NewConnManager()
	go runClient("127.0.0.1", "9001")
	for i := 9001; i < 9001+100; i++ {
		go runClient("127.0.0.1", strconv.FormatInt(int64(i), 10))

	}
	go runServer("127.0.0.1", "9001")
	go runServer("127.0.0.1", "9011")
	go runServer("127.0.0.1", "9021")
	go func() { showinfo() }()

	signals := make(chan os.Signal, 1)
	signal.Notify(signals, syscall.SIGINT, syscall.SIGTERM, syscall.SIGKILL)
	<-signals
	os.Exit(-1)
}
func NewConnManager() { //t *testing.T
	GlobalRpcPool = Server.NewSessionManagement(20, 60)
}
func showinfo() { //t *testing.T
	for true {
		time.Sleep(5 * time.Second)
		fmt.Println(GlobalRpcPool.Show())
	}

}
