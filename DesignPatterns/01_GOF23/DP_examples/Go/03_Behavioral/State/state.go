package State

import (
	"fmt"
	"net"
)

// TCPConnection 上下文结构体
type TCPConnection struct {
	tcpState  TCPState
	Connector net.Conn
	IPAddress string
	Port      int
}

// NewTCPConnection 创建新的TCPConnection实例
func NewTCPConnection() *TCPConnection {
	return &TCPConnection{
		tcpState:  GetTCPUnconnectedInstance(),
		IPAddress: "127.0.0.1",
		Port:      7777,
	}
}

// Connect 连接方法
func (c *TCPConnection) Connect() {
	c.tcpState.Connect(c)
}

// Receive 接收方法
func (c *TCPConnection) Receive() ([]byte, error) {
	return c.tcpState.Receive(c)
}

// Close 关闭方法
func (c *TCPConnection) Close() {
	c.tcpState.Close(c)
}

// SendMessage 发送消息方法
func (c *TCPConnection) SendMessage(buffer []byte) {
	c.tcpState.SendMessage(c, buffer)
}

// IsConnected 检查连接状态
func (c *TCPConnection) IsConnected() bool {
	return c.Connector != nil
}

// TCPState 状态接口
type TCPState interface {
	Connect(connection *TCPConnection)
	Receive(connection *TCPConnection) ([]byte, error)
	Close(connection *TCPConnection)
	SendMessage(connection *TCPConnection, buffer []byte)
	ChangeState(connection *TCPConnection, state TCPState)
}

// ChangeState 更改状态的默认实现
func ChangeState(connection *TCPConnection, state TCPState) {
	fmt.Printf("Switch state to >> %T\n", state)
	connection.tcpState = state
}
