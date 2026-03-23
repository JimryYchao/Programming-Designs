#ifndef STATE_HPP
#define STATE_HPP

#include <iostream>
#include <string>
#include <winsock2.h>

// 前向声明
class TCPConnection;

// 状态接口
class TCPState {
public:
    virtual ~TCPState() = default;
    
    virtual void Connect(TCPConnection* connection) {}
    virtual void Receive(TCPConnection* connection, char*& buffer, int& buffer_len) { buffer = nullptr; buffer_len = 0; }
    virtual void Close(TCPConnection* connection) {}
    virtual void SendMessage(TCPConnection* connection, char* buffer, int buffer_len) {}
    
protected:
    virtual void ChangeState(TCPConnection* connection, TCPState* state);
};

#endif // STATE_HPP
