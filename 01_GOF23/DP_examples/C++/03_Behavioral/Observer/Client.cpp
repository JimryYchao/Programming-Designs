#include "ConcreteSubject.hpp"

int main() {
    // 测试注册
    Subject* subject = Subject::getInstance();
    subject->RegisterAccount("test", "123456");
    subject->Notify();
    
    // 测试重复注册
    subject->RegisterAccount("test", "123456");
    subject->Notify();
    
    // 测试登录
    subject->LoginAccount("test", "123456");
    subject->Notify();
    
    // 测试登录失败
    subject->LoginAccount("test", "wrong");
    subject->Notify();
}

// g++ -std=c++23 -o Client Client.cpp ConcreteSubject.cpp ChangeManager.cpp AccountData.cpp 