package server

import (
	"context"
	"errors"
	"fmt"
	"github.com/apache/thrift/lib/go/thrift"
)

type rpcService struct {
	clientTransport thrift.TTransport
	serverSocket    thrift.TServerSocket
}

func (this *rpcService) StringInfo(ctx context.Context, s string) (r string, err error) {
	fmt.Println("send info to client:" + s)
	return s + " get it", nil
}

func (this *rpcService) Heart(ctx context.Context, s string) error {
	fmt.Println("Heart is called")
	return errors.New("noerror")
}
func NewServerHandler() *rpcService {
	return &rpcService{}
}
