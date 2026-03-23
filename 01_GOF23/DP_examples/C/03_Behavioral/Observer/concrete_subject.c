#include "concrete_subject.h"
#include "account_data.h"
#include <string.h>

// 主题的Attach方法
static void subject_attach(ISubject* self, IObserver* observer) {
    Subject* s = (Subject*)self;
    s->changeMgr->base.Register(&s->changeMgr->base, self, observer);
}

// 主题的Detach方法
static void subject_detach(ISubject* self, IObserver* observer) {
    Subject* s = (Subject*)self;
    s->changeMgr->base.Unregister(&s->changeMgr->base, self, observer);
}

// 主题的Notify方法
static void subject_notify(ISubject* self) {
    Subject* s = (Subject*)self;
    s->changeMgr->base.Notify(&s->changeMgr->base);
    clear_observer(s->changeMgr);
}

// 全局主题实例
static Subject* subject_instance = NULL;

// 获取主题实例
Subject* get_subject() {
    if (subject_instance == NULL) {
        subject_instance = (Subject*)malloc(sizeof(Subject));
        if (subject_instance == NULL) {
            return NULL;
        }
        subject_instance->base.Attach = subject_attach;
        subject_instance->base.Detach = subject_detach;
        subject_instance->base.Notify = subject_notify;
        subject_instance->name = NULL;
        subject_instance->password = NULL;
        subject_instance->changeMgr = create_simple_change_manager((ISubject*)subject_instance, 10);
    }
    return subject_instance;
}

// 注册账户
void register_account_subject(Subject* s, const char* name, const char* password) {
    if (s->name) free(s->name);
    if (s->password) free(s->password);
    s->name = strdup(name);
    s->password = strdup(password);
    IObserver* observer = (IObserver*)create_register_observer();
    s->base.Attach(&s->base, observer);
}

// 登录账户
void login_account_subject(Subject* s, const char* name, const char* password) {
    if (s->name) free(s->name);
    if (s->password) free(s->password);
    s->name = strdup(name);
    s->password = strdup(password);
    IObserver* observer = (IObserver*)create_login_observer();
    s->base.Attach(&s->base, observer);
}

// 获取状态
const char* get_state(Subject* s, int state) {
    switch (state) {
        case 0:
            return s->name;
        case 1:
            return s->password;
        default:
            return "";
    }
}

// 登录观察者的Update方法
static void login_observer_update(IObserver* self, ISubject* subject) {
    Subject* s = (Subject*)subject;
    AccountData* ad = get_account_data();
    login_account(ad, get_state(s, 0), get_state(s, 1));
}

// 创建登录观察者
LoginObserver* create_login_observer() {
    LoginObserver* observer = (LoginObserver*)malloc(sizeof(LoginObserver));
    if (observer == NULL) {
        return NULL;
    }
    observer->base.Update = login_observer_update;
    return observer;
}

// 注册观察者的Update方法
static void register_observer_update(IObserver* self, ISubject* subject) {
    Subject* s = (Subject*)subject;
    AccountData* ad = get_account_data();
    register_account(ad, get_state(s, 0), get_state(s, 1));
}

// 创建注册观察者
RegisterObserver* create_register_observer() {
    RegisterObserver* observer = (RegisterObserver*)malloc(sizeof(RegisterObserver));
    if (observer == NULL) {
        return NULL;
    }
    observer->base.Update = register_observer_update;
    return observer;
}
