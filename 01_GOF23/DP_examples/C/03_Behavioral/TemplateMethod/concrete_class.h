#ifndef CONCRETE_CLASS_H
#define CONCRETE_CLASS_H

#include "abstract_class.h"

// 咖啡制作类
typedef struct CoffeeMaker CoffeeMaker;

struct CoffeeMaker {
    BeverageMaker base;
};

// 初始化咖啡制作类
void CoffeeMaker_init(CoffeeMaker* self);

// 茶制作类
typedef struct TeaMaker TeaMaker;

struct TeaMaker {
    BeverageMaker base;
};

// 初始化茶制作类
void TeaMaker_init(TeaMaker* self);

#endif // CONCRETE_CLASS_H
