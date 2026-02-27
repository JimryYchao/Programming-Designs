#ifndef CHANGE_MANAGER_H
#define CHANGE_MANAGER_H

#include "observer.h"

// 简单变更管理器
typedef struct SimpleChangeManager {
    IChangeManager base;
    ISubject* subject;
    IObserver** observers;
    int count;
    int capacity;
} SimpleChangeManager;

// 创建简单变更管理器
SimpleChangeManager* create_simple_change_manager(ISubject* subject, int capacity);

// 清空观察者
void clear_observer(SimpleChangeManager* cm);

// 多主题变更管理器
typedef struct DCGChangeManager {
    IChangeManager base;
    ISubject** subjects;
    IObserver*** observers;
    int* observer_counts;
    int subject_count;
    int capacity;
} DCGChangeManager;

// 获取DCG变更管理器实例
DCGChangeManager* get_dcg_change_manager();

// 日志管理器
typedef struct LoggerManager {
    IChangeManager base;
} LoggerManager;

// 获取日志管理器实例
LoggerManager* get_logger_manager();

#endif // CHANGE_MANAGER_H
