#include "concrete_class.h"

// 咖啡冲泡方法
static void CoffeeMaker_brew(BeverageMaker* self) {
    printf("Brewing coffee grounds\n");
}

// 咖啡添加调料方法
static void CoffeeMaker_addCondiments(BeverageMaker* self) {
    printf("Adding sugar and milk\n");
}

// 咖啡顾客是否需要调料
static int CoffeeMaker_customerWantsCondiments(BeverageMaker* self) {
    printf("Customer wants sugar and milk\n");
    return 1;
}

// 初始化咖啡制作类
void CoffeeMaker_init(CoffeeMaker* self) {
    BeverageMaker_init(&self->base);
    self->base.brew = CoffeeMaker_brew;
    self->base.addCondiments = CoffeeMaker_addCondiments;
    self->base.customerWantsCondiments = CoffeeMaker_customerWantsCondiments;
}

// 茶冲泡方法
static void TeaMaker_brew(BeverageMaker* self) {
    printf("Steeping the tea bag\n");
}

// 茶添加调料方法
static void TeaMaker_addCondiments(BeverageMaker* self) {
    printf("Adding lemon\n");
}

// 茶顾客是否需要调料
static int TeaMaker_customerWantsCondiments(BeverageMaker* self) {
    printf("Customer wants lemon\n");
    return 1;
}

// 初始化茶制作类
void TeaMaker_init(TeaMaker* self) {
    BeverageMaker_init(&self->base);
    self->base.brew = TeaMaker_brew;
    self->base.addCondiments = TeaMaker_addCondiments;
    self->base.customerWantsCondiments = TeaMaker_customerWantsCondiments;
}
