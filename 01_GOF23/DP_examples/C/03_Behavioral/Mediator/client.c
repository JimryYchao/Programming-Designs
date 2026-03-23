#include "mediator.h"

int main() {
    // 创建用户
    User* Tom = CreateUser("Tom");
    User* Lily = CreateUser("Lily");

    // 获取聊天室实例
    PrivateChatRoom* privateRoom = GetPrivateChatRoomInstance();
    PublicChatRoom* publicRoom = GetPublicChatRoomInstance();

    // 发送消息
    Tom->SendMessage(Tom, (IMediator*)publicRoom, NULL, "Hi! I'm Tom");
    Lily->SendMessage(Lily, (IMediator*)publicRoom, NULL, "Hi! I'm Lily");
    Tom->SendMessage(Tom, (IMediator*)privateRoom, Lily, "How are U! Lily");
    Lily->SendMessage(Lily, (IMediator*)privateRoom, Tom, "Fine!");

    // 释放资源
    Tom->Destroy(Tom);
    Lily->Destroy(Lily);

    return 0;
}

// gcc -o client client.c mediator.c