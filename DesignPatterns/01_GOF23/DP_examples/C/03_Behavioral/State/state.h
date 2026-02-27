#ifndef STATE_H
#define STATE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

// 前向声明
typedef struct TCPConnection TCPConnection;

// 状态接口
typedef struct TCPState {
    void (*Connect)(struct TCPState* self, TCPConnection* connection);
    void (*Receive)(struct TCPState* self, TCPConnection* connection, char** buffer, int* buffer_len);
    void (*Close)(struct TCPState* self, TCPConnection* connection);
    void (*SendMessage)(struct TCPState* self, TCPConnection* connection, char* buffer, int buffer_len);
    void (*ChangeState)(struct TCPState* self, TCPConnection* connection, struct TCPState* state);
} TCPState;

// 初始化状态
void TCPState_Init(TCPState* state);

#endif // STATE_H
