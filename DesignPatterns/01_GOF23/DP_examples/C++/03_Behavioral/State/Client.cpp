#include <iostream>
#include <string>
#include <winsock2.h>
#include "Context.hpp"

int main() {
    // 初始化Winsock
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        std::cout << "WSAStartup failed" << std::endl;
        return 1;
    }
    
    // 创建服务器端socket
    SOCKET server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (server == INVALID_SOCKET) {
        std::cout << "Cannot create server socket" << std::endl;
        WSACleanup();
        return 1;
    }
    
    // 绑定服务器地址
    sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(7777);
    
    if (bind(server, (sockaddr*)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
        std::cout << "Bind failed" << std::endl;
        closesocket(server);
        WSACleanup();
        return 1;
    }
    
    // 开始监听
    if (listen(server, 10) == SOCKET_ERROR) {
        std::cout << "Listen failed" << std::endl;
        closesocket(server);
        WSACleanup();
        return 1;
    }
    
    std::cout << "Server is Builded" << std::endl;
    
    // 创建客户端TCPConnection
    TCPConnection client;
    
    char message[1024];
    char* buffer = nullptr;
    int buffer_len = 0;
    
    // 等待客户端连接的socket
    SOCKET server_socket = INVALID_SOCKET;
    
    // 主循环
    while (true) {
        // 1. 建立连接
        if (!client.IsConnected()) {
            client.Connect();
            std::cout << "Input Buffer: ";
            std::cin.getline(message, sizeof(message));
            if (strlen(message) == 0) {
                continue;
            }
        }
        
        // 2. 客户端发送消息
        client.SendMessage(message, strlen(message));
        
        // 3. 服务器接收并返回状态
        if (server_socket == INVALID_SOCKET) {
            server_socket = accept(server, nullptr, nullptr);
            if (server_socket != INVALID_SOCKET) {
                std::cout << "Server accepted connection" << std::endl;
            }
        }
        
        if (server_socket != INVALID_SOCKET) {
            char receive_buffer[1024];
            int len = recv(server_socket, receive_buffer, sizeof(receive_buffer), 0);
            if (len > 0) {
                receive_buffer[len] = '\0';
                std::cout << "Server received: " << receive_buffer << std::endl;
                
                // 发送响应
                const char* response = "Successful";
                send(server_socket, response, strlen(response), 0);
                
                std::cout << "Server sent response: " << response << std::endl;
                closesocket(server_socket);
                server_socket = INVALID_SOCKET;
            }
        }
        
        // 4. 客户端接收状态
        client.Receive(buffer, buffer_len);
        
        // 5. 客户端打印状态
        if (buffer != nullptr && buffer_len > 0) {
            buffer[buffer_len] = '\0';
            std::cout << "Client received: " << buffer << std::endl;
            delete[] buffer;
            buffer = nullptr;
            
            client.Close();
            std::cout << "Test Finished, and input anyKey to exit" << std::endl;
            std::cin.get();
            break;
        }
    }
    
    // 清理
    if (server_socket != INVALID_SOCKET) {
        closesocket(server_socket);
    }
    closesocket(server);
    WSACleanup();
}

// g++ -o client Client.cpp State.cpp Context.cpp ConcreteState.cpp -lws2_32
