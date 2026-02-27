#ifndef CONCRETE_STATE_H
#define CONCRETE_STATE_H

#include "state.h"

// 具体状态：TCP已建立
typedef struct TCPEstablished {
    TCPState base;
} TCPEstablished;

// 具体状态：TCP监听
typedef struct TCPListen {
    TCPState base;
} TCPListen;

// 具体状态：TCP未连接
typedef struct TCPUnconnected {
    TCPState base;
} TCPUnconnected;

// 获取单例实例
TCPEstablished* GetTCPEstablishedInstance();
TCPListen* GetTCPListenInstance();
TCPUnconnected* GetTCPUnconnectedInstance();

// 初始化具体状态
void TCPEstablished_Init(TCPEstablished* state);
void TCPListen_Init(TCPListen* state);
void TCPUnconnected_Init(TCPUnconnected* state);

#endif // CONCRETE_STATE_H
