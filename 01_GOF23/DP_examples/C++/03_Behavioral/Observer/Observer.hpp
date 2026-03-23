#ifndef OBSERVER_HPP
#define OBSERVER_HPP

#include <iostream>

// 前向声明
class ISubject;

// 观察者接口
class IObserver {
public:
    virtual ~IObserver() {}
    virtual void Update(ISubject* subject) = 0;
};

// 主题接口
class ISubject {
public:
    virtual ~ISubject() {}
    virtual void Attach(IObserver* observer) = 0;
    virtual void Detach(IObserver* observer) = 0;
    virtual void Notify() = 0;
};

// 变更管理器接口
class IChangeManager {
public:
    virtual ~IChangeManager() {}
    virtual void Register(ISubject* subject, IObserver* observer) = 0;
    virtual void Unregister(ISubject* subject, IObserver* observer) = 0;
    virtual void Notify() = 0;
};

#endif // OBSERVER_HPP
