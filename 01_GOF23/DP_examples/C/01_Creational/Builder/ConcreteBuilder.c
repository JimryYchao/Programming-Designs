// ConcreteBuilder.c
// 具体建造者实现

#include "ConcreteBuilder.h"
#include "Product.h"
#include <stdlib.h>

// 建造者实现
static Item *build_vegetable_burger(void)
{
    return Item_create(VEGETABLE_BURGER);
}

static Item *build_chicken_burger(void)
{
    return Item_create(CHICKEN_BURGER);
}

static Item *build_coke_cola(void)
{
    return Item_create(COKE_COLA);
}

static Item *build_pepsi_cola(void)
{
    return Item_create(PEPSI_COLA);
}

// 建造者实例
static IBuilder VegetableBurger_Builder = {build_vegetable_burger};
static IBuilder ChickenBurger_Builder = {build_chicken_burger};
static IBuilder CokeCola_Builder = {build_coke_cola};
static IBuilder PepsiCola_Builder = {build_pepsi_cola};

// 套餐建造者实现

static IBuilder **ChickenMealBuilder_GetBuilders(int *count)
{
    static IBuilder *builders[2];
    builders[0] = &ChickenBurger_Builder;
    builders[1] = &PepsiCola_Builder;
    *count = 2;
    return builders;
}
IMealBuilder ChickenMeal_Builder = {ChickenMealBuilder_GetBuilders};

static IBuilder **VegMealBuilder_GetBuilders(int *count)
{
    static IBuilder *builders[2];
    builders[0] = &VegetableBurger_Builder;
    builders[1] = &CokeCola_Builder;
    *count = 2;
    return builders;
}
IMealBuilder VegMeal_Builder = {VegMealBuilder_GetBuilders};


static void MealBuilder_Add(MealBuilder *meal, ItemKind kind)
{
    IBuilder *builder = NULL;
    switch (kind)
    {
    case VEGETABLE_BURGER:
        builder = &VegetableBurger_Builder;
        break;
    case CHICKEN_BURGER:
        builder = &ChickenBurger_Builder;
        break;
    case COKE_COLA:
        builder = &CokeCola_Builder;
        break;
    case PEPSI_COLA:
        builder = &PepsiCola_Builder;
        break;
    }

    if (builder)
    {
        meal->builders = (IBuilder **)realloc(meal->builders, sizeof(IBuilder *) * (meal->builder_count + 1));
        meal->builders[meal->builder_count++] = builder;
    }
}

static void MealBuilder_Remove(MealBuilder *meal, ItemKind kind)
{
    IBuilder *builder_to_remove = NULL;
    switch (kind)
    {
    case VEGETABLE_BURGER:
        builder_to_remove = &VegetableBurger_Builder;
        break;
    case CHICKEN_BURGER:
        builder_to_remove = &ChickenBurger_Builder;
        break;
    case COKE_COLA:
        builder_to_remove = &CokeCola_Builder;
        break;
    case PEPSI_COLA:
        builder_to_remove = &PepsiCola_Builder;
        break;
    }

    if (builder_to_remove)
    {
        for (int i = 0; i < meal->builder_count; i++)
        {
            if (meal->builders[i] == builder_to_remove)
            {
                // 移除 builder
                for (int j = i; j < meal->builder_count - 1; j++)
                {
                    meal->builders[j] = meal->builders[j + 1];
                }
                meal->builder_count--;
                meal->builders = (IBuilder **)realloc(meal->builders, sizeof(IBuilder *) * meal->builder_count);
                break;
            }
        }
    }
}

static void MealBuilder_Build(MealBuilder *meal)
{
    // 清理之前的项目
    meal->item_count = 0;
    if (meal->builder_count > meal->item_count)
        meal->items = (Item **)realloc(meal->items, sizeof(Item *) * (meal->builder_count));
    for (int i = 0; i < meal->builder_count; i++) 
        meal->items[meal->item_count++] = meal->builders[i]->Build();
}

static void MealBuilder_Pack(MealBuilder *meal)
{
    for (int i = 0; i < meal->item_count; i++)
        meal->items[i]->Packer->Pack(meal->items[i]);
}

static float MealBuilder_GetCost(MealBuilder *meal)
{
    float sum = 0;
    for (int i = 0; i < meal->item_count; i++)
        sum += meal->items[i]->Price;
    return sum;
}

static void MealBuilder_Destroy(MealBuilder *meal)
{
    if (meal)
    {
        free(meal->builders);
        free(meal->items);
        free(meal);
    }
}
// MealBuilder 实现
MealBuilder *MealBuilder_Create(IBuilder **builders, int count)
{
    MealBuilder *meal = (MealBuilder *)malloc(sizeof(MealBuilder));
    // 复制 builders 数组
    meal->builders = (IBuilder **)malloc(sizeof(IBuilder *) * count);
    for (int i = 0; i < count; i++)
        meal->builders[i] = builders[i];
    meal->builder_count = count;
    // 初始化 items 数组
    meal->items = (Item **)malloc(sizeof(Item *) * 10);  // capacity
    meal->item_count = 0;

    meal->Add = MealBuilder_Add;
    meal->Remove = MealBuilder_Remove;
    meal->Build = MealBuilder_Build;
    meal->Pack = MealBuilder_Pack;
    meal->GetCost = MealBuilder_GetCost;
    meal->Destroy = MealBuilder_Destroy;

    return meal;
}