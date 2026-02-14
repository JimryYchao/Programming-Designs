#include "Singleton.hpp"

int main()
{
    // 测试非线程安全单例
    Singleton *s = Singleton::getInstance();
    if (std::is_same_v<decltype(s), decltype(Singleton::getInstance())>)
        s->showMessage();   

    // 测试线程安全单例
    Singleton_Lock *sl = Singleton_Lock::getInstance();
    if (std::is_same_v<decltype(sl), decltype(Singleton_Lock::getInstance())>)
        sl->showMessage();

    // 测试延迟加载单例
    Singleton_Lazy &slazy = Singleton_Lazy::getInstance();
    if (std::is_same_v<decltype(slazy), decltype(Singleton_Lazy::getInstance())>)
        slazy.showMessage();

    // 测试继承单例
    MonoSingleton *ms = MonoSingleton::getInstance();
    ms->showMessage();
    GameSingleton *gs = GameSingleton::getInstance();
    gs->showMessage();
}