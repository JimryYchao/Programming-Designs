#pragma once

#include "product.h"

// 创建者接口结构体
typedef struct ICreator {
    IShape* (*getShape)(struct ICreator* self);
} ICreator;

// 形状工厂
typedef struct ShapeFactory {
    ICreator* creators[SHAPE_KIND_COUNT]; // 对应 4 种形状 + 1 unknown
    IShape* (*getShape)(struct ShapeFactory* self, ShapeKind kind);
    void (*destroy)(struct ShapeFactory* self);
} ShapeFactory;

ShapeFactory* getShapeFactory();
