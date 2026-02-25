#ifndef CONCRETE_AGGREGATE_H
#define CONCRETE_AGGREGATE_H

#include "iterator.h"

// 具体聚合类
typedef struct ConcreteAggregate ConcreteAggregate;

struct ConcreteAggregate {
    IAggregate aggregate;
    void** array;
    int size;
    int capacity;
};

// 创建具体聚合对象
ConcreteAggregate* CreateConcreteAggregate(int capacity);

#endif // CONCRETE_AGGREGATE_H
