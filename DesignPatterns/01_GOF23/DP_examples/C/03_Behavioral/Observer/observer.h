#ifndef OBSERVER_H
#define OBSERVER_H

#include <stdio.h>
#include <stdlib.h>

// 前向声明
typedef struct ISubject ISubject;

// 观察者接口
typedef struct IObserver {
    void (*Update)(struct IObserver* self, ISubject* subject);
} IObserver;

// 主题接口
typedef struct ISubject {
    void (*Attach)(struct ISubject* self, IObserver* observer);
    void (*Detach)(struct ISubject* self, IObserver* observer);
    void (*Notify)(struct ISubject* self);
} ISubject;

// 变更管理器接口
typedef struct IChangeManager {
    void (*Register)(struct IChangeManager* self, ISubject* subject, IObserver* observer);
    void (*Unregister)(struct IChangeManager* self, ISubject* subject, IObserver* observer);
    void (*Notify)(struct IChangeManager* self);
} IChangeManager;

#endif // OBSERVER_H
