#include "account_data.h"
#include <string.h>

// 账户数据的Attach方法
static void account_attach(ISubject* self, IObserver* observer) {
    AccountData* ad = (AccountData*)self;
    ad->changer->Register(ad->changer, self, observer);
}

// 账户数据的Detach方法
static void account_detach(ISubject* self, IObserver* observer) {
    AccountData* ad = (AccountData*)self;
    ad->changer->Unregister(ad->changer, self, observer);
}

// 账户数据的Notify方法
static void account_notify(ISubject* self) {
    AccountData* ad = (AccountData*)self;
    ad->changer->Notify(ad->changer);
}

// 查找账户
static int find_account(AccountData* ad, const char* account) {
    for (int i = 0; i < ad->count; i++) {
        if (strcmp(ad->accounts[i], account) == 0) {
            return i;
        }
    }
    return -1;
}

// 全局账户数据实例
static AccountData* account_instance = NULL;

// 获取账户数据实例
AccountData* get_account_data() {
    if (account_instance == NULL) {
        account_instance = (AccountData*)malloc(sizeof(AccountData));
        if (account_instance == NULL) {
            return NULL;
        }
        account_instance->base.Attach = account_attach;
        account_instance->base.Detach = account_detach;
        account_instance->base.Notify = account_notify;
        account_instance->capacity = 10;
        account_instance->accounts = (char**)malloc(sizeof(char*) * account_instance->capacity);
        account_instance->passwords = (char**)malloc(sizeof(char*) * account_instance->capacity);
        if (account_instance->accounts == NULL || account_instance->passwords == NULL) {
            free(account_instance->accounts);
            free(account_instance->passwords);
            free(account_instance);
            return NULL;
        }
        account_instance->count = 0;
        account_instance->changer = (IChangeManager*)get_logger_manager();
    }
    return account_instance;
}

// 登录账户
void login_account(AccountData* ad, const char* account, const char* password) {
    int index = find_account(ad, account);
    if (index != -1) {
        if (strcmp(ad->passwords[index], password) == 0) {
            IObserver* observer = (IObserver*)create_login_successful();
            ad->base.Attach(&ad->base, observer);
            return;
        }
    }
    IObserver* observer = (IObserver*)create_login_failed();
    ad->base.Attach(&ad->base, observer);
}

// 注册账户
void register_account(AccountData* ad, const char* account, const char* password) {
    if (find_account(ad, account) == -1) {
        if (ad->count < ad->capacity) {
            ad->accounts[ad->count] = strdup(account);
            ad->passwords[ad->count] = strdup(password);
            ad->count++;
            IObserver* observer = (IObserver*)create_register_successful();
            ad->base.Attach(&ad->base, observer);
            return;
        }
    }
    IObserver* observer = (IObserver*)create_register_failed();
    ad->base.Attach(&ad->base, observer);
}

// 登录成功观察者的Update方法
static void login_successful_update(IObserver* self, ISubject* subject) {
    printf("Login Successful\n");
}

// 创建登录成功观察者
LoginSuccessful* create_login_successful() {
    LoginSuccessful* observer = (LoginSuccessful*)malloc(sizeof(LoginSuccessful));
    if (observer == NULL) {
        return NULL;
    }
    observer->base.Update = login_successful_update;
    return observer;
}

// 登录失败观察者的Update方法
static void login_failed_update(IObserver* self, ISubject* subject) {
    printf("Login Failed\n");
}

// 创建登录失败观察者
LoginFailed* create_login_failed() {
    LoginFailed* observer = (LoginFailed*)malloc(sizeof(LoginFailed));
    if (observer == NULL) {
        return NULL;
    }
    observer->base.Update = login_failed_update;
    return observer;
}

// 注册成功观察者的Update方法
static void register_successful_update(IObserver* self, ISubject* subject) {
    printf("Register-Account Successful\n");
}

// 创建注册成功观察者
RegisterSuccessful* create_register_successful() {
    RegisterSuccessful* observer = (RegisterSuccessful*)malloc(sizeof(RegisterSuccessful));
    if (observer == NULL) {
        return NULL;
    }
    observer->base.Update = register_successful_update;
    return observer;
}

// 注册失败观察者的Update方法
static void register_failed_update(IObserver* self, ISubject* subject) {
    printf("Register-Account Failed\n");
}

// 创建注册失败观察者
RegisterFailed* create_register_failed() {
    RegisterFailed* observer = (RegisterFailed*)malloc(sizeof(RegisterFailed));
    if (observer == NULL) {
        return NULL;
    }
    observer->base.Update = register_failed_update;
    return observer;
}
