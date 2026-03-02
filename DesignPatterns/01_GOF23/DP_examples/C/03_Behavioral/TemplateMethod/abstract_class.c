#include "abstract_class.h"

// 初始化抽象类
void BeverageMaker_init(BeverageMaker* self) {
    self->makeBeverage = BeverageMaker_makeBeverage;
    self->customerWantsCondiments = BeverageMaker_customerWantsCondiments;
}

// 模板方法：制作饮料的流程
void BeverageMaker_makeBeverage(BeverageMaker* self) {
    BeverageMaker_boilWater();
    if (self->brew) {
        self->brew(self);
    }
    BeverageMaker_pourInCup();
    if (self->customerWantsCondiments && self->customerWantsCondiments(self)) {
        if (self->addCondiments) {
            self->addCondiments(self);
        }
    }
}

// 具体方法：烧水
void BeverageMaker_boilWater() {
    printf("Boiling water\n");
}

// 具体方法：倒入杯子
void BeverageMaker_pourInCup() {
    printf("Pouring into cup\n");
}

// 钩子方法：顾客是否需要调料
int BeverageMaker_customerWantsCondiments(BeverageMaker* self) {
    return 1;
}
