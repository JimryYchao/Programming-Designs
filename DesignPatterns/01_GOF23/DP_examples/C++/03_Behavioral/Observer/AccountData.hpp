#ifndef ACCOUNT_DATA_HPP
#define ACCOUNT_DATA_HPP

#include "Observer.hpp"
#include "ChangeManager.hpp"
#include <map>
#include <string>

// 账户数据
class AccountData : public ISubject {
private:
    static AccountData* instance;
    std::map<std::string, std::string> accounts;
    IChangeManager* changer;
    AccountData();

public:
    static AccountData* getInstance();
    void LoginAccount(const std::string& account, const std::string& password);
    void RegisterAccount(const std::string& account, const std::string& password);
    void Attach(IObserver* observer) override;
    void Detach(IObserver* observer) override;
    void Notify() override;
};

// 登录成功观察者
class LoginSuccessful : public IObserver {
private:
    static LoginSuccessful* instance;
    LoginSuccessful() {}

public:
    static LoginSuccessful* getInstance();
    void Update(ISubject* subject) override;
};

// 登录失败观察者
class LoginFailed : public IObserver {
private:
    static LoginFailed* instance;
    LoginFailed() {}

public:
    static LoginFailed* getInstance();
    void Update(ISubject* subject) override;
};

// 注册成功观察者
class RegisterSuccessful : public IObserver {
private:
    static RegisterSuccessful* instance;
    RegisterSuccessful() {}

public:
    static RegisterSuccessful* getInstance();
    void Update(ISubject* subject) override;
};

// 注册失败观察者
class RegisterFailed : public IObserver {
private:
    static RegisterFailed* instance;
    RegisterFailed() {}

public:
    static RegisterFailed* getInstance();
    void Update(ISubject* subject) override;
};

#endif // ACCOUNT_DATA_HPP
