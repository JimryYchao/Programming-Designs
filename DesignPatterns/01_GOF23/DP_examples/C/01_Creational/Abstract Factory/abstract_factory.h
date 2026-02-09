// abstract_factory.h
// 抽象工厂
#pragma once
#include "abstract_product.h"

// 抽象工厂结构体
typedef struct AbstractFactory {
    void* data;
    Color* (*GetColor)(struct AbstractFactory* self);
    Shape* (*GetShape)(struct AbstractFactory* self);
    void (*destroy)(struct AbstractFactory* self);
} AbstractFactory;
