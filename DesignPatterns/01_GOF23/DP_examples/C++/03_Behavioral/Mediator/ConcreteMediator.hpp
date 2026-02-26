#ifndef MEDIATOR_HPP
#define MEDIATOR_HPP

#include "Mediator.hpp"

#include <iostream>
#include <string>

// 具体中介者 - 私聊房间
class PrivateChatRoom : public IMediator {
private:
    static PrivateChatRoom* instance;
    
    PrivateChatRoom() = default;
    PrivateChatRoom(const PrivateChatRoom&) = delete;
    PrivateChatRoom& operator=(const PrivateChatRoom&) = delete;

public:
    ~PrivateChatRoom() = default;
    
    static PrivateChatRoom* GetInstance();
    void ShowMessage(User* oriUser, User* desUser, const std::string& message) override;
};

// 具体中介者 - 公共聊天室
class PublicChatRoom : public IMediator {
private:
    static PublicChatRoom* instance;
    
    PublicChatRoom() = default;
    PublicChatRoom(const PublicChatRoom&) = delete;
    PublicChatRoom& operator=(const PublicChatRoom&) = delete;

public:
    ~PublicChatRoom() = default;
    
    static PublicChatRoom* GetInstance();
    void ShowMessage(User* user, User* desUser, const std::string& message) override;
    void ShowMessage(User* user, const std::string& message);
};

// 静态实例初始化
PrivateChatRoom* PrivateChatRoom::instance = nullptr;
PublicChatRoom* PublicChatRoom::instance = nullptr;
// PrivateChatRoom 类实现
PrivateChatRoom* PrivateChatRoom::GetInstance() {
    if (!instance) {
        instance = new PrivateChatRoom();
    }
    return instance;
}

void PrivateChatRoom::ShowMessage(User* oriUser, User* desUser, const std::string& message) {
    std::cout << "[PrivateChatRoom][" << oriUser->GetName() << "] sent to [" << desUser->GetName() << "]: " << message << std::endl;
}

// PublicChatRoom 类实现
PublicChatRoom* PublicChatRoom::GetInstance() {
    if (!instance) {
        instance = new PublicChatRoom();
    }
    return instance;
}

void PublicChatRoom::ShowMessage(User* user, User* desUser, const std::string& message) {
    std::cout << "[PublicChatRoom][" << user->GetName() << "]: " << message << std::endl;
}

void PublicChatRoom::ShowMessage(User* user, const std::string& message) {
    ShowMessage(user, nullptr, message);
}



#endif // MEDIATOR_HPP
