#ifndef ACCOUNT_DATA_H
#define ACCOUNT_DATA_H

#include "observer.h"
#include "change_manager.h"

// 账户数据
typedef struct AccountData {
    ISubject base;
    char** accounts;
    char** passwords;
    int count;
    int capacity;
    IChangeManager* changer;
} AccountData;

// 获取账户数据实例
AccountData* get_account_data();

// 登录账户
void login_account(AccountData* ad, const char* account, const char* password);

// 注册账户
void register_account(AccountData* ad, const char* account, const char* password);

// 登录成功观察者
typedef struct LoginSuccessful {
    IObserver base;
} LoginSuccessful;

// 创建登录成功观察者
LoginSuccessful* create_login_successful();

// 登录失败观察者
typedef struct LoginFailed {
    IObserver base;
} LoginFailed;

// 创建登录失败观察者
LoginFailed* create_login_failed();

// 注册成功观察者
typedef struct RegisterSuccessful {
    IObserver base;
} RegisterSuccessful;

// 创建注册成功观察者
RegisterSuccessful* create_register_successful();

// 注册失败观察者
typedef struct RegisterFailed {
    IObserver base;
} RegisterFailed;

// 创建注册失败观察者
RegisterFailed* create_register_failed();

#endif // ACCOUNT_DATA_H
