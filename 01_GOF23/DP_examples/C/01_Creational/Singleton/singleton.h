#pragma once

// 非线程安全单例
typedef struct Singleton {
    int value;
    void (*destroy)(struct Singleton* self);
} Singleton;

Singleton* Singleton_getInstance();

// 线程安全单例
typedef struct Singleton_Lock{
    int value;
    void (*destroy)(struct Singleton_Lock* self);
} Singleton_Lock;

Singleton_Lock* Singleton_Lock_getInstance();


// 内联单例
typedef struct Singleton_Lazy {
    int value;
} Singleton_Lazy;

Singleton_Lazy* Singleton_Lazy_getInstance();
