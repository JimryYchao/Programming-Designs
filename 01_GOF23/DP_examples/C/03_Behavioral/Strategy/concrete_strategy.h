#ifndef CONCRETE_STRATEGY_H
#define CONCRETE_STRATEGY_H

#include "strategy.h"

// 冒泡排序策略
typedef struct BubbleSortStrategy BubbleSortStrategy;

struct BubbleSortStrategy {
    IStrategy base;
};

void BubbleSortStrategy_init(BubbleSortStrategy* self);

// 快速排序策略
typedef struct QuickSortStrategy QuickSortStrategy;

struct QuickSortStrategy {
    IStrategy base;
};

void QuickSortStrategy_init(QuickSortStrategy* self);

// 插入排序策略
typedef struct InsertionSortStrategy InsertionSortStrategy;

struct InsertionSortStrategy {
    IStrategy base;
};

void InsertionSortStrategy_init(InsertionSortStrategy* self);

// 选择排序策略
typedef struct SelectionSortStrategy SelectionSortStrategy;

struct SelectionSortStrategy {
    IStrategy base;
};

void SelectionSortStrategy_init(SelectionSortStrategy* self);

#endif // CONCRETE_STRATEGY_H
