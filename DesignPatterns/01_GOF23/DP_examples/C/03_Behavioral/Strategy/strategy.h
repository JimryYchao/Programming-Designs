#ifndef STRATEGY_H
#define STRATEGY_H

// 策略接口
typedef struct IStrategy IStrategy;

struct IStrategy {
    void (*sort)(IStrategy* self, int* array, int length);
};

// 初始化策略
void IStrategy_init(IStrategy* self);

#endif // STRATEGY_H
