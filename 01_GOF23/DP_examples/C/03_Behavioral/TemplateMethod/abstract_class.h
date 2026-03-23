#ifndef ABSTRACT_CLASS_H
#define ABSTRACT_CLASS_H

#include <stdio.h>

// 饮料制作抽象类
typedef struct BeverageMaker BeverageMaker;

struct BeverageMaker {
    void (*makeBeverage)(BeverageMaker* self);
    void (*brew)(BeverageMaker* self);
    void (*addCondiments)(BeverageMaker* self);
    int (*customerWantsCondiments)(BeverageMaker* self);
};

// 初始化抽象类
void BeverageMaker_init(BeverageMaker* self);

// 模板方法：制作饮料的流程
void BeverageMaker_makeBeverage(BeverageMaker* self);

// 具体方法：烧水
void BeverageMaker_boilWater();

// 具体方法：倒入杯子
void BeverageMaker_pourInCup();

// 钩子方法：顾客是否需要调料
int BeverageMaker_customerWantsCondiments(BeverageMaker* self);

#endif // ABSTRACT_CLASS_H
