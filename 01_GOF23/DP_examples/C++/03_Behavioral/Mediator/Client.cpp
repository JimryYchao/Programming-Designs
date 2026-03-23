#include "ConcreteMediator.hpp"

int main() {
    // 创建用户
    User* Tom = new User("Tom");
    User* Lily = new User("Lily");

    // 获取聊天室实例
    PrivateChatRoom* privateRoom = PrivateChatRoom::GetInstance();
    PublicChatRoom* publicRoom = PublicChatRoom::GetInstance();

    // 发送消息
    Tom->SendMessage(publicRoom, nullptr, "Hi! I'm Tom");
    Lily->SendMessage(publicRoom, nullptr, "Hi! I'm Lily");
    Tom->SendMessage(privateRoom, Lily, "How are U! Lily");
    Lily->SendMessage(privateRoom, Tom, "Fine!");

    // 释放资源
    delete Tom;
    delete Lily;
}
