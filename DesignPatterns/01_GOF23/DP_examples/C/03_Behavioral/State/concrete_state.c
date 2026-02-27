#include "concrete_state.h"
#include "context.h"
#include <windows.h>

// 单例实例
static TCPEstablished g_established_instance;
static TCPListen g_listen_instance;
static TCPUnconnected g_unconnected_instance;
static int g_instances_initialized = 0;

// 初始化单例
static void InitializeInstances() {
    if (!g_instances_initialized) {
        TCPEstablished_Init(&g_established_instance);
        TCPListen_Init(&g_listen_instance);
        TCPUnconnected_Init(&g_unconnected_instance);
        g_instances_initialized = 1;
    }
}

// TCPEstablished的SendMessage方法
static void TCPEstablished_SendMessage(TCPState* self, TCPConnection* connection, char* buffer, int buffer_len) {
    if (TCPConnection_IsConnected(connection)) {
        send(connection->Connector, buffer, buffer_len, 0);
    } else {
        self->ChangeState(self, connection, (TCPState*)GetTCPUnconnectedInstance());
    }
    self->ChangeState(self, connection, (TCPState*)GetTCPListenInstance());
}

// TCPEstablished的Close方法
static void TCPEstablished_Close(TCPState* self, TCPConnection* connection) {
    if (connection->Connector != INVALID_SOCKET) {
        closesocket(connection->Connector);
        connection->Connector = INVALID_SOCKET;
    }
    self->ChangeState(self, connection, (TCPState*)GetTCPUnconnectedInstance());
}

// 初始化TCPEstablished
void TCPEstablished_Init(TCPEstablished* state) {
    TCPState_Init(&state->base);
    state->base.SendMessage = TCPEstablished_SendMessage;
    state->base.Close = TCPEstablished_Close;
}

// TCPListen的Receive方法
static void TCPListen_Receive(TCPState* self, TCPConnection* connection, char** buffer, int* buffer_len) {
    char arr[1024];
    int len = 0;
    
    len = recv(connection->Connector, arr, sizeof(arr), 0);
    if (len <= 0) {
        if (!TCPConnection_IsConnected(connection)) {
            self->ChangeState(self, connection, (TCPState*)GetTCPUnconnectedInstance());
        }
        *buffer = NULL;
        *buffer_len = 0;
        return;
    }
    
    *buffer = (char*)malloc(len);
    if (*buffer) {
        memcpy(*buffer, arr, len);
        *buffer_len = len;
    } else {
        *buffer_len = 0;
    }
    
    self->ChangeState(self, connection, (TCPState*)GetTCPEstablishedInstance());
}

// 初始化TCPListen
void TCPListen_Init(TCPListen* state) {
    TCPState_Init(&state->base);
    state->base.Receive = TCPListen_Receive;
}

// TCPUnconnected的Connect方法
static void TCPUnconnected_Connect(TCPState* self, TCPConnection* connection) {
    while (1) {
        connection->Connector = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
        if (connection->Connector == INVALID_SOCKET) {
            printf("Cannot create socket\n");
            Sleep(1000);
            continue;
        }
        
        struct sockaddr_in addr;
        addr.sin_family = AF_INET;
        addr.sin_addr.s_addr = inet_addr(connection->IPAddress);
        addr.sin_port = htons(connection->Port);
        
        if (connect(connection->Connector, (struct sockaddr*)&addr, sizeof(addr)) == SOCKET_ERROR) {
            printf("Cannot connect to >>> %s:%d\n", connection->IPAddress, connection->Port);
            closesocket(connection->Connector);
            connection->Connector = INVALID_SOCKET;
            Sleep(1000);
            continue;
        }
        
        printf("Connect to >>> %s:%d\n", connection->IPAddress, connection->Port);
        break;
    }
    
    self->ChangeState(self, connection, (TCPState*)GetTCPEstablishedInstance());
}

// 初始化TCPUnconnected
void TCPUnconnected_Init(TCPUnconnected* state) {
    TCPState_Init(&state->base);
    state->base.Connect = TCPUnconnected_Connect;
}

// 获取TCPEstablished单例
TCPEstablished* GetTCPEstablishedInstance() {
    InitializeInstances();
    return &g_established_instance;
}

// 获取TCPListen单例
TCPListen* GetTCPListenInstance() {
    InitializeInstances();
    return &g_listen_instance;
}

// 获取TCPUnconnected单例
TCPUnconnected* GetTCPUnconnectedInstance() {
    InitializeInstances();
    return &g_unconnected_instance;
}
