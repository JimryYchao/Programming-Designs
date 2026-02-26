
#pragma once
#include <string>

class User;
// 中介者接口
class IMediator {
public:
    virtual ~IMediator() = default;
    virtual void ShowMessage(User* oriUser, User* desUser, const std::string& message) = 0;
};

// 用户类
class User {
private:
    std::string name;

public:
    User(const std::string& name): name(name) {}
    ~User() = default;
    
    const std::string& GetName() const {
        return name;
    }
    void SendMessage(IMediator* room, User* desUser, const std::string& message) {
        room->ShowMessage(this, desUser, message);
    }
};

