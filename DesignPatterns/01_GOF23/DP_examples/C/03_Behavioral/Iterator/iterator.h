#ifndef ITERATOR_H
#define ITERATOR_H

#include <stdbool.h>

// 迭代器接口
typedef struct Iterator Iterator;

struct Iterator {
    void (*First)(Iterator*);
    void (*Next)(Iterator*);
    bool (*IsDone)(Iterator*);
    void* (*CurrentItem)(Iterator*);
    void (*Destroy)(Iterator*);
};

// 可迭代接口
typedef struct Iterable Iterable;

struct Iterable {
    Iterator* (*GetIterator)(Iterable*);
};

// 聚合接口
typedef struct IAggregate IAggregate;

struct IAggregate {
    Iterable iterable;
    int (*Count)(IAggregate*);
    void (*Add)(IAggregate*, void*);
    bool (*Remove)(IAggregate*, void*);
    bool (*Contains)(IAggregate*, void*);
    void (*Clear)(IAggregate*);
    void (*Destroy)(IAggregate*);
};

#endif // ITERATOR_H
