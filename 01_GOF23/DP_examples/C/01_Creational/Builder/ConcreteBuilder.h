// ConcreteBuilder.h
// 具体建造者
#pragma once

#include "Builder.h"

// 汉堡建造者
// extern IBuilder VegetableBurger_Builder;
// extern IBuilder ChickenBurger_Builder;

// // 冷饮建造者
// extern IBuilder CokeCola_Builder;
// extern IBuilder PepsiCola_Builder;

// 套餐建造者
extern IMealBuilder ChickenMeal_Builder;
extern IMealBuilder VegMeal_Builder;

// 套餐产品
typedef struct MealBuilder
{
    IBuilder **builders;
    int builder_count;
    Item **items;
    int item_count;

    void (*Add)(MealBuilder *self, ItemKind kind);
    void (*Remove)(MealBuilder *self, ItemKind kind);
    void (*Build)(MealBuilder *self);
    void (*Pack)(MealBuilder *self);
    float (*GetCost)(MealBuilder *self);
    void (*Destroy)(MealBuilder *self);
} MealBuilder;

MealBuilder *MealBuilder_Create(IBuilder **builders, int count);

// void MealBuilder_Add(MealBuilder *meal, ItemKind kind);
// void MealBuilder_Remove(MealBuilder *meal, ItemKind kind);
// void MealBuilder_Build(MealBuilder *meal);
// void MealBuilder_Pack(MealBuilder *meal);
// float MealBuilder_GetCost(MealBuilder *meal);
// void MealBuilder_Destroy(MealBuilder *meal);
