#ifndef CONCRETE_SUBJECT_H
#define CONCRETE_SUBJECT_H

#include "observer.h"
#include "change_manager.h"

// 具体主题
typedef struct Subject {
    ISubject base;
    char* name;
    char* password;
    SimpleChangeManager* changeMgr;
} Subject;

// 获取主题实例
Subject* get_subject();

// 注册账户
void register_account_subject(Subject* s, const char* name, const char* password);

// 登录账户
void login_account_subject(Subject* s, const char* name, const char* password);

// 获取状态
const char* get_state(Subject* s, int state);

// 登录观察者
typedef struct LoginObserver {
    IObserver base;
} LoginObserver;

// 创建登录观察者
LoginObserver* create_login_observer();

// 注册观察者
typedef struct RegisterObserver {
    IObserver base;
} RegisterObserver;

// 创建注册观察者
RegisterObserver* create_register_observer();

#endif // CONCRETE_SUBJECT_H
