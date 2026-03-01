#ifndef CONTEXT_H
#define CONTEXT_H

#include "strategy.h"

// 上下文类
typedef struct Context Context;

struct Context {
    IStrategy* strategy;
};

// 初始化上下文
void Context_init(Context* self, IStrategy* strategy);

// 设置策略
void Context_setStrategy(Context* self, IStrategy* strategy);

// 执行排序
void Context_sort(Context* self, int* array, int length);

#endif // CONTEXT_H
