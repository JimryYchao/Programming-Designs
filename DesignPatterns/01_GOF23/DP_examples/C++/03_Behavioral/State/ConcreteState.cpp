#include "ConcreteState.hpp"
#include "Context.hpp"
#include <windows.h>

// 初始化单例实例
TCPEstablished* TCPEstablished::instance = nullptr;
TCPListen* TCPListen::instance = nullptr;
TCPUnconnected* TCPUnconnected::instance = nullptr;

// 获取TCPEstablished单例
TCPEstablished* TCPEstablished::GetInstance() {
    if (!instance) {
        instance = new TCPEstablished();
    }
    return instance;
}

// TCPEstablished的SendMessage方法
void TCPEstablished::SendMessage(TCPConnection* connection, char* buffer, int buffer_len) {
    if (connection->IsConnected()) {
        send(connection->Connector, buffer, buffer_len, 0);
    } else {
        ChangeState(connection, TCPUnconnected::GetInstance());
    }
    ChangeState(connection, TCPListen::GetInstance());
}

// TCPEstablished的Close方法
void TCPEstablished::Close(TCPConnection* connection) {
    if (connection->Connector != INVALID_SOCKET) {
        closesocket(connection->Connector);
        connection->Connector = INVALID_SOCKET;
    }
    ChangeState(connection, TCPUnconnected::GetInstance());
}

// 获取TCPListen单例
TCPListen* TCPListen::GetInstance() {
    if (!instance) {
        instance = new TCPListen();
    }
    return instance;
}

// TCPListen的Receive方法
void TCPListen::Receive(TCPConnection* connection, char*& buffer, int& buffer_len) {
    char arr[1024];
    int len = 0;
    
    len = recv(connection->Connector, arr, sizeof(arr), 0);
    if (len <= 0) {
        if (!connection->IsConnected()) {
            ChangeState(connection, TCPUnconnected::GetInstance());
        }
        buffer = nullptr;
        buffer_len = 0;
        return;
    }
    
    buffer = new char[len];
    if (buffer) {
        memcpy(buffer, arr, len);
        buffer_len = len;
    } else {
        buffer_len = 0;
    }
    
    ChangeState(connection, TCPEstablished::GetInstance());
}

// 获取TCPUnconnected单例
TCPUnconnected* TCPUnconnected::GetInstance() {
    if (!instance) {
        instance = new TCPUnconnected();
    }
    return instance;
}

// TCPUnconnected的Connect方法
void TCPUnconnected::Connect(TCPConnection* connection) {
    while (true) {
        connection->Connector = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (connection->Connector == INVALID_SOCKET) {
            std::cout << "Cannot create socket" << std::endl;
            Sleep(1000);
            continue;
        }
        
        sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = inet_addr(connection->IPAddress);
        addr.sin_port = htons(connection->Port);
        
        if (connect(connection->Connector, (sockaddr*)&addr, sizeof(addr)) == SOCKET_ERROR) {
            std::cout << "Cannot connect to >>> " << connection->IPAddress << ":" << connection->Port << std::endl;
            closesocket(connection->Connector);
            connection->Connector = INVALID_SOCKET;
            Sleep(1000);
            continue;
        }
        
        std::cout << "Connect to >>> " << connection->IPAddress << ":" << connection->Port << std::endl;
        break;
    }
    
    ChangeState(connection, TCPEstablished::GetInstance());
}
