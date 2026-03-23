package State

import (
	"fmt"
	"net"
	"time"
)

// TCPEstablished 具体状态：TCP已建立
type TCPEstablished struct{}

// 单例实例
var establishedInstance *TCPEstablished

// GetTCPEstablishedInstance 获取TCPEstablished单例
func GetTCPEstablishedInstance() *TCPEstablished {
	if establishedInstance == nil {
		establishedInstance = &TCPEstablished{}
	}
	return establishedInstance
}

// Connect 实现TCPState接口的Connect方法
func (s *TCPEstablished) Connect(connection *TCPConnection) {
	// 空实现
}

// Receive 实现TCPState接口的Receive方法
func (s *TCPEstablished) Receive(connection *TCPConnection) ([]byte, error) {
	return nil, nil
}

// Close 实现TCPState接口的Close方法
func (s *TCPEstablished) Close(connection *TCPConnection) {
	if connection.Connector != nil {
		connection.Connector.Close()
		connection.Connector = nil
	}
	s.ChangeState(connection, GetTCPUnconnectedInstance())
}

// SendMessage 实现TCPState接口的SendMessage方法
func (s *TCPEstablished) SendMessage(connection *TCPConnection, buffer []byte) {
	if connection.Connector != nil {
		_, err := connection.Connector.Write(buffer)
		if err != nil {
			s.ChangeState(connection, GetTCPUnconnectedInstance())
			return
		}
	} else {
		s.ChangeState(connection, GetTCPUnconnectedInstance())
		return
	}
	s.ChangeState(connection, GetTCPListenInstance())
}

// ChangeState 实现TCPState接口的ChangeState方法
func (s *TCPEstablished) ChangeState(connection *TCPConnection, state TCPState) {
	ChangeState(connection, state)
}

// TCPListen 具体状态：TCP监听
type TCPListen struct{}

// 单例实例
var listenInstance *TCPListen

// GetTCPListenInstance 获取TCPListen单例
func GetTCPListenInstance() *TCPListen {
	if listenInstance == nil {
		listenInstance = &TCPListen{}
	}
	return listenInstance
}

// Connect 实现TCPState接口的Connect方法
func (s *TCPListen) Connect(connection *TCPConnection) {
	// 空实现
}

// Receive 实现TCPState接口的Receive方法
func (s *TCPListen) Receive(connection *TCPConnection) ([]byte, error) {
	if connection.Connector == nil {
		s.ChangeState(connection, GetTCPUnconnectedInstance())
		return nil, fmt.Errorf("not connected")
	}

	buffer := make([]byte, 1024)
	len, err := connection.Connector.Read(buffer)
	if err != nil {
		if connection.Connector != nil {
			connection.Connector.Close()
			connection.Connector = nil
		}
		s.ChangeState(connection, GetTCPUnconnectedInstance())
		return nil, err
	}

	result := make([]byte, len)
	copy(result, buffer[:len])
	s.ChangeState(connection, GetTCPEstablishedInstance())
	return result, nil
}

// Close 实现TCPState接口的Close方法
func (s *TCPListen) Close(connection *TCPConnection) {
	// 空实现
}

// SendMessage 实现TCPState接口的SendMessage方法
func (s *TCPListen) SendMessage(connection *TCPConnection, buffer []byte) {
	// 空实现
}

// ChangeState 实现TCPState接口的ChangeState方法
func (s *TCPListen) ChangeState(connection *TCPConnection, state TCPState) {
	ChangeState(connection, state)
}

// TCPUnconnected 具体状态：TCP未连接
type TCPUnconnected struct{}

// 单例实例
var unconnectedInstance *TCPUnconnected

// GetTCPUnconnectedInstance 获取TCPUnconnected单例
func GetTCPUnconnectedInstance() *TCPUnconnected {
	if unconnectedInstance == nil {
		unconnectedInstance = &TCPUnconnected{}
	}
	return unconnectedInstance
}

// Connect 实现TCPState接口的Connect方法
func (s *TCPUnconnected) Connect(connection *TCPConnection) {
	for {
		addr := fmt.Sprintf("%s:%d", connection.IPAddress, connection.Port)
		conn, err := net.Dial("tcp", addr)
		if err != nil {
			fmt.Printf("Cannot connect to >>> %s\n", addr)
			time.Sleep(time.Second)
			continue
		}

		connection.Connector = conn
		fmt.Printf("Connect to >>> %s\n", addr)
		s.ChangeState(connection, GetTCPEstablishedInstance())
		break
	}
}

// Receive 实现TCPState接口的Receive方法
func (s *TCPUnconnected) Receive(connection *TCPConnection) ([]byte, error) {
	return nil, fmt.Errorf("not connected")
}

// Close 实现TCPState接口的Close方法
func (s *TCPUnconnected) Close(connection *TCPConnection) {
	// 空实现
}

// SendMessage 实现TCPState接口的SendMessage方法
func (s *TCPUnconnected) SendMessage(connection *TCPConnection, buffer []byte) {
	// 空实现
}

// ChangeState 实现TCPState接口的ChangeState方法
func (s *TCPUnconnected) ChangeState(connection *TCPConnection, state TCPState) {
	ChangeState(connection, state)
}
