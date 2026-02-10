#pragma once

#include "Builder.h"

// 产品接口
typedef Item Burger;
typedef Item ColdDrink;

// 产品定义
extern Burger VegetableBurger;
extern Burger ChickenBurger;
extern ColdDrink CokeCola;
extern ColdDrink PepsiCola;

Item* Item_create(ItemKind kind);
