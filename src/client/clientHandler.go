package client

import (
	"context"
	"fmt"
)

var defaultCtx = context.Background()

type clienthandler struct {
	period int  //心跳周期
	start  bool //是否开始
}

func (this *clienthandler) Heart(ctx context.Context, str string) (err error) {
	fmt.Println("client Heart :", str)
	return nil
}

func (this *clienthandler) StringInfo(ctx context.Context, s string) (r string, err error) {
	fmt.Println("client StringInfo:" + s)
	return s + " get it", nil
}

func NewClientHandler(period int) *clienthandler {
	return &clienthandler{period, true}
}
