package State_test

import (
	state "State"
	"fmt"
	"net"
	"testing"
	"time"
)

func TestStateDemo(t *testing.T) {

	// 关闭服务器
	// 创建服务器端
	ln, err := net.Listen("tcp", "127.0.0.1:7777")
	if err != nil {
		fmt.Println("Failed to start server:", err)
		return
	}
	defer ln.Close()

	fmt.Println("Server is Builded")

	// 创建客户端TCPConnection
	client := state.NewTCPConnection()

	// 启动服务器接受连接的goroutine
	go func() {
		for {
			conn, err := ln.Accept()
			if err != nil {
				fmt.Println("Accept error:", err)
				return
			}
			fmt.Println("Server accepted connection")

			// 处理服务器端接收和发送
			go handleServerConnection(conn)
		}
	}()

	// 主循环
	for {
		// 1. 建立连接
		if !client.IsConnected() {
			client.Connect()
			fmt.Print("Input Buffer: ")
			// scanner := bufio.NewScanner(os.Stdin)
			// if !scanner.Scan() {
			// 	continue
			// }
			// message := scanner.Text()
			// if message == "" {
			// 	continue
			// }
			// 测试用消息
			message := "Hello, Server!"
			client.SendMessage([]byte(message))
			time.Sleep(time.Millisecond * 100)
			buffer, err := client.Receive()
			if err != nil {
				fmt.Println("Receive error:", err)
				continue
			}

			// 5. 客户端打印状态
			if len(buffer) > 0 {
				fmt.Printf("Client received: %s\n", buffer)
				client.Close()
				fmt.Println("Test Finished, and input anyKey to exit")
				// scanner.Scan()
				return
			}
		}
	}
}

// 处理服务器端连接
func handleServerConnection(conn net.Conn) {
	defer conn.Close()

	// 接收客户端消息
	buffer := make([]byte, 1024)
	len, err := conn.Read(buffer)
	if err != nil {
		fmt.Println("Server read error:", err)
		return
	}

	fmt.Printf("Server received: %s\n", buffer[:len])

	// 发送响应
	response := "Successful"
	_, err = conn.Write([]byte(response))
	if err != nil {
		fmt.Println("Server write error:", err)
		return
	}

	fmt.Printf("Server sent response: %s\n", response)
}
