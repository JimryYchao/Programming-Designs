#include "ChangeManager.hpp"

// 简单变更管理器
SimpleChangeManager::SimpleChangeManager(ISubject* subject) : subject(subject) {
}

void SimpleChangeManager::Register(ISubject* subject, IObserver* observer) {
    // 检查观察者是否已存在
    for (auto obs : observers) {
        if (obs == observer) {
            return;
        }
    }
    observers.push_back(observer);
}

void SimpleChangeManager::Unregister(ISubject* subject, IObserver* observer) {
    for (auto it = observers.begin(); it != observers.end(); ++it) {
        if (*it == observer) {
            observers.erase(it);
            break;
        }
    }
}

void SimpleChangeManager::Notify() {
    for (auto observer : observers) {
        observer->Update(subject);
    }
}

void SimpleChangeManager::ClearObserver() {
    observers.clear();
}

// 多主题变更管理器
DCGChangeManager* DCGChangeManager::instance = nullptr;

DCGChangeManager* DCGChangeManager::getInstance() {
    if (instance == nullptr) {
        instance = new DCGChangeManager();
    }
    return instance;
}

void DCGChangeManager::Register(ISubject* subject, IObserver* observer) {
    // 检查观察者是否已存在
    auto it = subjectObservers.find(subject);
    if (it == subjectObservers.end()) {
        subjectObservers[subject] = std::vector<IObserver*>();
    }
    
    for (auto obs : subjectObservers[subject]) {
        if (obs == observer) {
            return;
        }
    }
    
    subjectObservers[subject].push_back(observer);
}

void DCGChangeManager::Unregister(ISubject* subject, IObserver* observer) {
    auto it = subjectObservers.find(subject);
    if (it != subjectObservers.end()) {
        for (auto obsIt = it->second.begin(); obsIt != it->second.end(); ++obsIt) {
            if (*obsIt == observer) {
                it->second.erase(obsIt);
                break;
            }
        }
    }
}

void DCGChangeManager::Notify() {
    for (auto& pair : subjectObservers) {
        for (auto observer : pair.second) {
            observer->Update(pair.first);
        }
    }
}

// 日志管理器
LoggerManager* LoggerManager::instance = nullptr;

LoggerManager* LoggerManager::getInstance() {
    if (instance == nullptr) {
        instance = new LoggerManager();
    }
    return instance;
}

void LoggerManager::Register(ISubject* subject, IObserver* observer) {
    observer->Update(subject);
}

void LoggerManager::Unregister(ISubject* subject, IObserver* observer) {
    // 未实现
}

void LoggerManager::Notify() {
    // 未实现
}
