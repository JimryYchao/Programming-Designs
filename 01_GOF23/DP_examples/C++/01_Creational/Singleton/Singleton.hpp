#pragma once

#include <iostream>
#include <mutex>
#include <memory>

// 非线程安全单例
class Singleton
{
private:
    static Singleton *instance;
    Singleton() = default;
    ~Singleton() = default;
    Singleton(const Singleton &) = delete;
    Singleton &operator=(const Singleton &) = delete;

public:
    static Singleton *getInstance()
    {
        if (instance == nullptr)
            instance = new Singleton();
        return instance;
    }
    void showMessage()
    {
        std::cout << "Singleton instance" << std::endl;
    }
};
Singleton *Singleton::instance = nullptr;

// 线程安全单例
class Singleton_Lock
{
private:
    static Singleton_Lock *instance;
    static std::mutex mutex;
    Singleton_Lock() = default;
    ~Singleton_Lock() = default;
    Singleton_Lock(const Singleton_Lock &) = delete;
    Singleton_Lock &operator=(const Singleton_Lock &) = delete;

public:
    static Singleton_Lock *getInstance()
    {
        if (instance == nullptr)
        {
            std::lock_guard<std::mutex> lock(mutex);
            if (instance == nullptr)
                instance = new Singleton_Lock();
        }
        return instance;
    }
    void showMessage()
    {
        std::cout << "Singleton_Lock instance" << std::endl;
    }
};

Singleton_Lock *Singleton_Lock::instance = nullptr;
std::mutex Singleton_Lock::mutex;

// 延迟加载单例
class Singleton_Lazy
{
private:
    Singleton_Lazy() = default;
    ~Singleton_Lazy() = default;
    Singleton_Lazy(const Singleton_Lazy &) = delete;
    Singleton_Lazy &operator=(const Singleton_Lazy &) = delete;

public:
    static Singleton_Lazy &getInstance()
    {
        static Singleton_Lazy instance;
        return instance;
    }

    void showMessage()
    {
        std::cout << "Singleton_Lazy instance" << std::endl;
    }
};

// 模板单例基类
template <typename T>
class Singleton_Inherit
{
protected:
    static T *instance;

    Singleton_Inherit() = default;
    virtual ~Singleton_Inherit() = default;
    Singleton_Inherit(const Singleton_Inherit &) = delete;
    Singleton_Inherit &operator=(const Singleton_Inherit &) = delete;

public:
    static T *getInstance()
    {
        if (instance == nullptr)
            instance = new T();
        return instance;
    }

    virtual void showMessage() = 0;
};

template <typename T>
T *Singleton_Inherit<T>::instance = nullptr;

// 具体单例类
class MonoSingleton : public Singleton_Inherit<MonoSingleton>
{
public:
    void showMessage() override
    {
        std::cout << "MonoSingleton is created" << std::endl;
    }
};

class GameSingleton : public Singleton_Inherit<GameSingleton>
{
public:
    void showMessage() override
    {
        std::cout << "GameSingleton is created" << std::endl;
    }
};
