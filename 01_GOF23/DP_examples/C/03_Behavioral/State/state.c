#include "state.h"
#include "context.h"

// 默认的Connect方法
static void DefaultConnect(TCPState* self, TCPConnection* connection) {
    // 空实现
}

// 默认的Receive方法
static void DefaultReceive(TCPState* self, TCPConnection* connection, char** buffer, int* buffer_len) {
    *buffer = NULL;
    *buffer_len = 0;
}

// 默认的Close方法
static void DefaultClose(TCPState* self, TCPConnection* connection) {
    // 空实现
}

// 默认的SendMessage方法
static void DefaultSendMessage(TCPState* self, TCPConnection* connection, char* buffer, int buffer_len) {
    // 空实现
}

// 默认的ChangeState方法
static void DefaultChangeState(TCPState* self, TCPConnection* connection, TCPState* state) {
    printf("Switch state to >> %p\n", state);
    TCPConnection_ChangeState(connection, state);
}

// 初始化状态
void TCPState_Init(TCPState* state) {
    state->Connect = DefaultConnect;
    state->Receive = DefaultReceive;
    state->Close = DefaultClose;
    state->SendMessage = DefaultSendMessage;
    state->ChangeState = DefaultChangeState;
}
