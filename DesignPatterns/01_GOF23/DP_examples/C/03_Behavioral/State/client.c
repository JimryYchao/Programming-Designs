#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include "context.h"

int main() {
    // 初始化Winsock
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        printf("WSAStartup failed\n");
        return 1;
    }
    
    // 创建服务器端socket
    SOCKET server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (server == INVALID_SOCKET) {
        printf("Cannot create server socket\n");
        WSACleanup();
        return 1;
    }
    
    // 绑定服务器地址
    struct sockaddr_in server_addr;
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(7777);
    
    if (bind(server, (struct sockaddr*)&server_addr, sizeof(server_addr)) == SOCKET_ERROR) {
        printf("Bind failed\n");
        closesocket(server);
        WSACleanup();
        return 1;
    }
    
    // 开始监听
    if (listen(server, 10) == SOCKET_ERROR) {
        printf("Listen failed\n");
        closesocket(server);
        WSACleanup();
        return 1;
    }
    
    printf("Server is Builded\n");
    
    // 创建客户端TCPConnection
    TCPConnection client;
    TCPConnection_Init(&client);
    
    char message[1024];
    char* buffer = NULL;
    int buffer_len = 0;
    
    // 等待客户端连接的线程函数
    SOCKET server_socket = INVALID_SOCKET;
    
    // 主循环
    while (1) {
        // 1. 建立连接
        if (!TCPConnection_IsConnected(&client)) {
            TCPConnection_Connect(&client);
            printf("Input Buffer: ");
            fgets(message, sizeof(message), stdin);
            // 移除换行符
            message[strcspn(message, "\n")] = '\0';
            if (strlen(message) == 0) {
                continue;
            }
        }
        
        // 2. 客户端发送消息
        TCPConnection_SendMessage(&client, message, strlen(message));
        
        // 3. 服务器接收并返回状态
        if (server_socket == INVALID_SOCKET) {
            server_socket = accept(server, NULL, NULL);
            if (server_socket != INVALID_SOCKET) {
                printf("Server accepted connection\n");
            }
        }
        
        if (server_socket != INVALID_SOCKET) {
            char receive_buffer[1024];
            int len = recv(server_socket, receive_buffer, sizeof(receive_buffer), 0);
            if (len > 0) {
                receive_buffer[len] = '\0';
                printf("Server received: %s\n", receive_buffer);
                
                // 发送响应
                const char* response = "Successful";
                send(server_socket, response, strlen(response), 0);
                
                printf("Server sent response: %s\n", response);
                closesocket(server_socket);
                server_socket = INVALID_SOCKET;
            }
        }
        
        // 4. 客户端接收状态
        TCPConnection_Receive(&client, &buffer, &buffer_len);
        
        // 5. 客户端打印状态
        if (buffer != NULL && buffer_len > 0) {
            buffer[buffer_len] = '\0';
            printf("Client received: %s\n", buffer);
            free(buffer);
            buffer = NULL;
            
            TCPConnection_Close(&client);
            printf("Test Finished, and input anyKey to exit\n");
            getchar();
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

// gcc state.c concrete_state.c context.c client.c -o client -lws2_32