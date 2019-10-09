package common

//自定义返回错误
type Error struct {
	ErrCode int
	ErrMsg  string
}

func NewError(code int, msg string) *Error {
	return &Error{code, msg}
}

func (p *Error) Error() string {
	return p.ErrMsg
}
