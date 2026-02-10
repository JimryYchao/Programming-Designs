// 共用类型定义
#pragma once

// 前向声明
typedef struct Item Item;
typedef struct IBuilder IBuilder;
typedef struct IPacker IPacker;
typedef struct IMealBuilder IMealBuilder;
typedef struct MealBuilder MealBuilder;

// 产品类型枚举
typedef enum {
    VEGETABLE_BURGER,
    CHICKEN_BURGER,
    COKE_COLA,
    PEPSI_COLA
} ItemKind;
