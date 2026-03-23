#include "Context.hpp"
#include "ConcreteState.hpp"

// 构造函数
TCPConnection::TCPConnection() {
    _tcpState = TCPUnconnected::GetInstance();
    Connector = INVALID_SOCKET;
    strcpy(IPAddress, "127.0.0.1");
    Port = 7777;
}

// 析构函数
TCPConnection::~TCPConnection() {
    if (Connector != INVALID_SOCKET) {
        closesocket(Connector);
    }
}

// 连接方法
void TCPConnection::Connect() {
    _tcpState->Connect(this);
}

// 接收方法
void TCPConnection::Receive(char*& buffer, int& buffer_len) {
    _tcpState->Receive(this, buffer, buffer_len);
}

// 关闭方法
void TCPConnection::Close() {
    _tcpState->Close(this);
}

// 发送消息方法
void TCPConnection::SendMessage(char* buffer, int buffer_len) {
    _tcpState->SendMessage(this, buffer, buffer_len);
}

// 更改状态方法
void TCPConnection::ChangeState(TCPState* state) {
    _tcpState = state;
}

// 检查连接状态
bool TCPConnection::IsConnected() {
    if (Connector != INVALID_SOCKET) {
        // 在Windows上，我们可以使用WSAIoctl来检查连接状态
        // 这里简化处理，返回true表示已连接
        return true;
    }
    return false;
}
