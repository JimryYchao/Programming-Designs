#ifndef CREATOR_H
#define CREATOR_H

#include "product.h"

#define SHAPE_KIND_COUNT 4

// 创建者接口结构体
typedef struct ICreator {
    IShape* (*getShape)(struct ICreator* self);
} ICreator;

// 具体创建者结构体
typedef struct UnknownShapeCreator {
    ICreator base;
} UnknownShapeCreator;

typedef struct CircleCreator {
    ICreator base;
} CircleCreator;

typedef struct SquareCreator {
    ICreator base;
} SquareCreator;

typedef struct RectangleCreator {
    ICreator base;
} RectangleCreator;

typedef struct BigCircleCreator {
    CircleCreator base;
} BigCircleCreator;

// 形状工厂
typedef struct ShapeFactory {
    ICreator* factories[SHAPE_KIND_COUNT + 1]; // 对应 4 种形状 + 1 unknown
} ShapeFactory;

// 构造函数
UnknownShapeCreator* createUnknownShapeCreator();
CircleCreator* createCircleCreator();
SquareCreator* createSquareCreator();
RectangleCreator* createRectangleCreator();
BigCircleCreator* createBigCircleCreator();

// 工厂方法
ShapeFactory* createShapeFactory();
IShape* shapeFactoryGetShape(ShapeFactory* factory, ShapeKind kind);

#endif // CREATOR_H
