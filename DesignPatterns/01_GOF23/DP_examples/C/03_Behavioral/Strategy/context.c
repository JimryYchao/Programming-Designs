#include "context.h"

// 初始化上下文
void Context_init(Context* self, IStrategy* strategy) {
    self->strategy = strategy;
}

// 设置策略
void Context_setStrategy(Context* self, IStrategy* strategy) {
    self->strategy = strategy;
}

// 执行排序
void Context_sort(Context* self, int* array, int length) {
    if (self->strategy && self->strategy->sort) {
        self->strategy->sort(self->strategy, array, length);
    }
}
