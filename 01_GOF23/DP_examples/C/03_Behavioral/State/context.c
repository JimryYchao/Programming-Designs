#include "context.h"
#include "concrete_state.h"

// 初始化TCPConnection
void TCPConnection_Init(TCPConnection* connection) {
    connection->_tcpState = (TCPState*)GetTCPUnconnectedInstance();
    connection->Connector = INVALID_SOCKET;
    strcpy(connection->IPAddress, "127.0.0.1");
    connection->Port = 7777;
}

// 连接方法
void TCPConnection_Connect(TCPConnection* connection) {
    connection->_tcpState->Connect(connection->_tcpState, connection);
}

// 接收方法
void TCPConnection_Receive(TCPConnection* connection, char** buffer, int* buffer_len) {
    connection->_tcpState->Receive(connection->_tcpState, connection, buffer, buffer_len);
}

// 关闭方法
void TCPConnection_Close(TCPConnection* connection) {
    connection->_tcpState->Close(connection->_tcpState, connection);
}

// 发送消息方法
void TCPConnection_SendMessage(TCPConnection* connection, char* buffer, int buffer_len) {
    connection->_tcpState->SendMessage(connection->_tcpState, connection, buffer, buffer_len);
}

// 更改状态方法
void TCPConnection_ChangeState(TCPConnection* connection, TCPState* state) {
    connection->_tcpState = state;
}

// 检查连接状态
int TCPConnection_IsConnected(TCPConnection* connection) {
    if (connection->Connector != INVALID_SOCKET) {
        // 在Windows上，我们可以使用WSAIoctl来检查连接状态
        // 这里简化处理，返回true表示已连接
        return 1;
    }
    return 0;
}
