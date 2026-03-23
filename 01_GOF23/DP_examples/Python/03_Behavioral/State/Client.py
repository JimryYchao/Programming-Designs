import socket
import threading
from State import TCPConnection

# 处理服务器端连接
def handle_server_connection(client_socket):
    try:
        # 接收客户端消息
        receive_buffer = client_socket.recv(1024)
        if receive_buffer:
            print(f"Server received: {receive_buffer.decode()}")
            
            # 发送响应
            response = "Successful"
            client_socket.send(response.encode())
            print(f"Server sent response: {response}")
    finally:
        client_socket.close()

# 服务器线程函数
def server_thread():
    server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
    server.bind(("127.0.0.1", 7777))
    server.listen(10)
    print("Server is Builded")
    
    while True:
        client_socket, addr = server.accept()
        print(f"Server accepted connection from {addr}")
        
        # 启动新线程处理连接
        thread = threading.Thread(target=handle_server_connection, args=(client_socket,))
        thread.daemon = True
        thread.start()

def main():
    # 启动服务器线程
    server = threading.Thread(target=server_thread)
    server.daemon = True
    server.start()
    
    # 创建客户端TCPConnection
    client = TCPConnection()
    
    # 主循环
    while True:
        # 1. 建立连接
        if not client.is_connected():
            client.connect()
            message = input("Input Buffer: ")
            if not message:
                continue
            
            # 2. 客户端发送消息
            client.send_message(message)
            
            # 3. 等待服务器处理
            import time
            time.sleep(0.1)
            
            # 4. 客户端接收状态
            buffer = client.receive()
            
            # 5. 客户端打印状态
            if buffer:
                print(f"Client received: {buffer.decode()}")
                client.close()
                print("Test Finished, and input anyKey to exit")
                input()
                break

if __name__ == "__main__":
    main()
