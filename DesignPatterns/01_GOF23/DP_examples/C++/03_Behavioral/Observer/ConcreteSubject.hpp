#ifndef CONCRETE_SUBJECT_HPP
#define CONCRETE_SUBJECT_HPP

#include "Observer.hpp"
#include "ChangeManager.hpp"
#include <string>

// 具体主题
class Subject : public ISubject {
private:
    static Subject* instance;
    std::string name;
    std::string password;
    SimpleChangeManager* changeMgr;
    Subject();

public:
    static Subject* getInstance();
    void RegisterAccount(const std::string& name, const std::string& password);
    void LoginAccount(const std::string& name, const std::string& password);
    const std::string& GetState(int state) const;
    void Attach(IObserver* observer) override;
    void Detach(IObserver* observer) override;
    void Notify() override;
};

// 登录观察者
class LoginObserver : public IObserver {
private:
    static LoginObserver* instance;
    LoginObserver() {}

public:
    static LoginObserver* getInstance();
    void Update(ISubject* subject) override;
};

// 注册观察者
class RegisterObserver : public IObserver {
private:
    static RegisterObserver* instance;
    RegisterObserver() {}

public:
    static RegisterObserver* getInstance();
    void Update(ISubject* subject) override;
};

#endif // CONCRETE_SUBJECT_HPP
