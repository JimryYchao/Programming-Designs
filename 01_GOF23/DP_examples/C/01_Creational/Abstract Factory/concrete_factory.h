// concrete_factory.h
// 具体工厂和工厂生产者
#pragma once

#include "abstract_factory.h"

// 产品工厂
//@class ProductFactory:AbstractFactory
typedef struct
{
    Color *(*GetColor)(void);
    Shape *(*GetShape)(void);
} ProductFactory;

// 产品类型枚举
typedef enum
{
    RED_CIRCLE = 0,
    GREEN_SQUARE = 1,
    BLUE_RECTANGLE = 2,
    UNKNOWN_PRODUCT,
} ProductKind;

// 工厂生产者
typedef struct FactoryProducer{
    int factory_count;
    AbstractFactory *(*GetFactory)(struct FactoryProducer *self, ProductKind kind);
    AbstractFactory *factories[];
} FactoryProducer;
void DestroyFactoryProducer(FactoryProducer *producer);
[[nodiscard]] FactoryProducer *FactoryProducerCreate();