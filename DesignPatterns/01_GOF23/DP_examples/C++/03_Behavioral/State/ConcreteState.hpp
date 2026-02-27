#ifndef CONCRETE_STATE_HPP
#define CONCRETE_STATE_HPP

#include "State.hpp"

// 具体状态：TCP已建立
class TCPEstablished : public TCPState {
private:
    static TCPEstablished* instance;
    
    TCPEstablished() = default;
public:
    static TCPEstablished* GetInstance();
    
    void SendMessage(TCPConnection* connection, char* buffer, int buffer_len) override;
    void Close(TCPConnection* connection) override;
};

// 具体状态：TCP监听
class TCPListen : public TCPState {
private:
    static TCPListen* instance;
    
    TCPListen() = default;
public:
    static TCPListen* GetInstance();
    
    void Receive(TCPConnection* connection, char*& buffer, int& buffer_len) override;
};

// 具体状态：TCP未连接
class TCPUnconnected : public TCPState {
private:
    static TCPUnconnected* instance;
    
    TCPUnconnected() = default;
public:
    static TCPUnconnected* GetInstance();
    
    void Connect(TCPConnection* connection) override;
};

#endif // CONCRETE_STATE_HPP
