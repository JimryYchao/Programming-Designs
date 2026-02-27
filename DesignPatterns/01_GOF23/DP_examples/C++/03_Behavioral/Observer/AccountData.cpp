#include "AccountData.hpp"

// 账户数据
AccountData* AccountData::instance = nullptr;

AccountData::AccountData() {
    changer = LoggerManager::getInstance();
}

AccountData* AccountData::getInstance() {
    if (instance == nullptr) {
        instance = new AccountData();
    }
    return instance;
}

void AccountData::LoginAccount(const std::string& account, const std::string& password) {
    auto it = accounts.find(account);
    if (it != accounts.end()) {
        if (it->second == password) {
            Attach(LoginSuccessful::getInstance());
            return;
        }
    }
    Attach(LoginFailed::getInstance());
}

void AccountData::RegisterAccount(const std::string& account, const std::string& password) {
    auto it = accounts.find(account);
    if (it == accounts.end()) {
        accounts[account] = password;
        Attach(RegisterSuccessful::getInstance());
    } else {
        Attach(RegisterFailed::getInstance());
    }
}

void AccountData::Attach(IObserver* observer) {
    changer->Register(this, observer);
}

void AccountData::Detach(IObserver* observer) {
    changer->Unregister(this, observer);
}

void AccountData::Notify() {
    changer->Notify();
}

// 登录成功观察者
LoginSuccessful* LoginSuccessful::instance = nullptr;

LoginSuccessful* LoginSuccessful::getInstance() {
    if (instance == nullptr) {
        instance = new LoginSuccessful();
    }
    return instance;
}

void LoginSuccessful::Update(ISubject* subject) {
    std::cout << "Login Successful" << std::endl;
}

// 登录失败观察者
LoginFailed* LoginFailed::instance = nullptr;

LoginFailed* LoginFailed::getInstance() {
    if (instance == nullptr) {
        instance = new LoginFailed();
    }
    return instance;
}

void LoginFailed::Update(ISubject* subject) {
    std::cout << "Login Failed" << std::endl;
}

// 注册成功观察者
RegisterSuccessful* RegisterSuccessful::instance = nullptr;

RegisterSuccessful* RegisterSuccessful::getInstance() {
    if (instance == nullptr) {
        instance = new RegisterSuccessful();
    }
    return instance;
}

void RegisterSuccessful::Update(ISubject* subject) {
    std::cout << "Register-Account Successful" << std::endl;
}

// 注册失败观察者
RegisterFailed* RegisterFailed::instance = nullptr;

RegisterFailed* RegisterFailed::getInstance() {
    if (instance == nullptr) {
        instance = new RegisterFailed();
    }
    return instance;
}

void RegisterFailed::Update(ISubject* subject) {
    std::cout << "Register-Account Failed" << std::endl;
}
