#include <stdlib.h>
#include <threads.h>
#include "singleton.h"

// 非线程安全单例
static Singleton* instance = NULL;
Singleton* Singleton_getInstance() {
    if (instance == NULL) {
        instance = (Singleton*)malloc(sizeof(Singleton));
        instance->value = 0;
    }
    return instance;
}

// 线程安全单例
static Singleton_Lock* lock_instance = NULL;
mtx_t *mutex = NULL;
static void Singleton_Lock_destroy(Singleton_Lock* self) {
    free(self);
    mtx_destroy(mutex);
    mutex = NULL;
    self = NULL;
}

Singleton_Lock* Singleton_Lock_getInstance() {
    if (mutex == NULL) {
        mtx_init(mutex, mtx_plain);
    }
    if (lock_instance == NULL) {
        mtx_lock(mutex);
        if (lock_instance == NULL) {
            lock_instance = (Singleton_Lock*)malloc(sizeof(Singleton_Lock));
            lock_instance->destroy = Singleton_Lock_destroy;
            lock_instance->value = 0;
        }
        mtx_unlock(mutex);
    }
    return lock_instance;
}

// 延迟单例
Singleton_Lazy* Singleton_Lazy_getInstance() {
    static Singleton_Lazy lazy_instance = {0};
    return &lazy_instance;
}

