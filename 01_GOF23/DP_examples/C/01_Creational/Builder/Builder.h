#pragma once

#include "common.h"

// 建造者接口
typedef struct IBuilder {
    Item* (*Build)(void);
    
} IBuilder;

// 包装器接口
typedef struct IPacker {
    void (*Pack)(Item* item);
} IPacker;

// 产品接口
typedef struct Item {
    const char* Name;
    float Price;
    IPacker* Packer;
    void (*destroy)(Item* self);
} Item;

// 套餐建造者接口
typedef struct IMealBuilder {
    IBuilder** (*GetBuilders)(int* count);
} IMealBuilder;
