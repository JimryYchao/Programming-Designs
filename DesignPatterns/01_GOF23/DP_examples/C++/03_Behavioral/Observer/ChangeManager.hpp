#ifndef CHANGE_MANAGER_HPP
#define CHANGE_MANAGER_HPP

#include "Observer.hpp"
#include <vector>
#include <map>

// 简单变更管理器
class SimpleChangeManager : public IChangeManager {
private:
    ISubject* subject;
    std::vector<IObserver*> observers;

public:
    SimpleChangeManager(ISubject* subject);
    void Register(ISubject* subject, IObserver* observer) override;
    void Unregister(ISubject* subject, IObserver* observer) override;
    void Notify() override;
    void ClearObserver();
};

// 多主题变更管理器
class DCGChangeManager : public IChangeManager {
private:
    static DCGChangeManager* instance;
    std::map<ISubject*, std::vector<IObserver*>> subjectObservers;
    DCGChangeManager() {}

public:
    static DCGChangeManager* getInstance();
    void Register(ISubject* subject, IObserver* observer) override;
    void Unregister(ISubject* subject, IObserver* observer) override;
    void Notify() override;
};

// 日志管理器
class LoggerManager : public IChangeManager {
private:
    static LoggerManager* instance;
    LoggerManager() {}

public:
    static LoggerManager* getInstance();
    void Register(ISubject* subject, IObserver* observer) override;
    void Unregister(ISubject* subject, IObserver* observer) override;
    void Notify() override;
};

#endif // CHANGE_MANAGER_HPP
