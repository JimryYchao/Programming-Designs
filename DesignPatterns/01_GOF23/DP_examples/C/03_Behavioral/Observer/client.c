#include "concrete_subject.h"

int main() {
    // 测试注册
    Subject* subject = get_subject();
    register_account_subject(subject, "test", "123456");
    subject->base.Notify(&subject->base);
    
    // 测试重复注册
    register_account_subject(subject, "test", "123456");
    subject->base.Notify(&subject->base);
    
    // 测试登录
    login_account_subject(subject, "test", "123456");
    subject->base.Notify(&subject->base);
    
    // 测试登录失败
    login_account_subject(subject, "test", "wrong");
    subject->base.Notify(&subject->base);
}

// gcc -o client client.c  concrete_subject.c change_manager.c account_data.c
