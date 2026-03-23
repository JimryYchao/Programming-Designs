#ifndef CONTEXT_H
#define CONTEXT_H

#include "state.h"

// 上下文结构体
typedef struct TCPConnection {
    TCPState* _tcpState;
    SOCKET Connector;
    char IPAddress[16]; // 存储IP地址字符串
    int Port;
} TCPConnection;

// 初始化TCPConnection
void TCPConnection_Init(TCPConnection* connection);

// 公共方法
void TCPConnection_Connect(TCPConnection* connection);
void TCPConnection_Receive(TCPConnection* connection, char** buffer, int* buffer_len);
void TCPConnection_Close(TCPConnection* connection);
void TCPConnection_SendMessage(TCPConnection* connection, char* buffer, int buffer_len);

// 内部方法
void TCPConnection_ChangeState(TCPConnection* connection, TCPState* state);

// 检查连接状态
int TCPConnection_IsConnected(TCPConnection* connection);

#endif // CONTEXT_H
