#ifndef CONTEXT_HPP
#define CONTEXT_HPP

#include "State.hpp"

// 上下文类
class TCPConnection {
private:
    TCPState* _tcpState;
public:
    SOCKET Connector;
    char IPAddress[16];
    int Port;
    
    TCPConnection();
    ~TCPConnection();
    
    void Connect();
    void Receive(char*& buffer, int& buffer_len);
    void Close();
    void SendMessage(char* buffer, int buffer_len);
    
    void ChangeState(TCPState* state);
    bool IsConnected();
};

#endif // CONTEXT_HPP
