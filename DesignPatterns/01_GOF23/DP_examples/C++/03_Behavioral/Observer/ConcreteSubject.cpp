#include "ConcreteSubject.hpp"
#include "AccountData.hpp"

// 具体主题
Subject* Subject::instance = nullptr;

Subject::Subject() {
    changeMgr = new SimpleChangeManager(this);
}

Subject* Subject::getInstance() {
    if (instance == nullptr) {
        instance = new Subject();
    }
    return instance;
}

void Subject::RegisterAccount(const std::string& name, const std::string& password) {
    this->name = name;
    this->password = password;
    Attach(RegisterObserver::getInstance());
}

void Subject::LoginAccount(const std::string& name, const std::string& password) {
    this->name = name;
    this->password = password;
    Attach(LoginObserver::getInstance());
}

const std::string& Subject::GetState(int state) const {
    static std::string empty = "";
    switch (state) {
    case 0:
        return name;
    case 1:
        return password;
    default:
        return empty;
    }
}

void Subject::Attach(IObserver* observer) {
    changeMgr->Register(this, observer);
}

void Subject::Detach(IObserver* observer) {
    changeMgr->Unregister(this, observer);
}

void Subject::Notify() {
    changeMgr->Notify();
    changeMgr->ClearObserver();
}

// 登录观察者
LoginObserver* LoginObserver::instance = nullptr;

LoginObserver* LoginObserver::getInstance() {
    if (instance == nullptr) {
        instance = new LoginObserver();
    }
    return instance;
}

void LoginObserver::Update(ISubject* subject) {
    Subject* s = dynamic_cast<Subject*>(subject);
    if (s) {
        AccountData::getInstance()->LoginAccount(s->GetState(0), s->GetState(1));
    }
}

// 注册观察者
RegisterObserver* RegisterObserver::instance = nullptr;

RegisterObserver* RegisterObserver::getInstance() {
    if (instance == nullptr) {
        instance = new RegisterObserver();
    }
    return instance;
}

void RegisterObserver::Update(ISubject* subject) {
    Subject* s = dynamic_cast<Subject*>(subject);
    if (s) {
        AccountData::getInstance()->RegisterAccount(s->GetState(0), s->GetState(1));
    }
}
