#include <stdio.h>
#include <stdlib.h>
#include "creator.h"

// 未知形状创建者方法
static IShape* unknownShapeCreatorGetShape(ICreator* self) {
    return (IShape*)createUnknownShape();
}

// 圆形创建者方法
static IShape* circleCreatorGetShape(ICreator* self) {
    return (IShape*)createCircle();
}

// 正方形创建者方法
static IShape* squareCreatorGetShape(ICreator* self) {
    return (IShape*)createSquare();
}

// 矩形创建者方法
static IShape* rectangleCreatorGetShape(ICreator* self) {
    return (IShape*)createRectangle();
}

// 大圆形创建者方法
static void setRadius() {
    printf("Set Radius to 10\n");
}

static IShape* bigCircleCreatorGetShape(ICreator* self) {
    setRadius();
    // 调用父类的方法
    return circleCreatorGetShape(self);
}

// 构造函数
UnknownShapeCreator* createUnknownShapeCreator() {
    UnknownShapeCreator* creator = (UnknownShapeCreator*)malloc(sizeof(UnknownShapeCreator));
    creator->base.getShape = unknownShapeCreatorGetShape;
    return creator;
}

CircleCreator* createCircleCreator() {
    CircleCreator* creator = (CircleCreator*)malloc(sizeof(CircleCreator));
    creator->base.getShape = circleCreatorGetShape;
    return creator;
}

SquareCreator* createSquareCreator() {
    SquareCreator* creator = (SquareCreator*)malloc(sizeof(SquareCreator));
    creator->base.getShape = squareCreatorGetShape;
    return creator;
}

RectangleCreator* createRectangleCreator() {
    RectangleCreator* creator = (RectangleCreator*)malloc(sizeof(RectangleCreator));
    creator->base.getShape = rectangleCreatorGetShape;
    return creator;
}

BigCircleCreator* createBigCircleCreator() {
    BigCircleCreator* creator = (BigCircleCreator*)malloc(sizeof(BigCircleCreator));
    creator->base.base.getShape = bigCircleCreatorGetShape;
    return creator;
}

// 工厂方法
ShapeFactory* createShapeFactory() {
    ShapeFactory* factory = (ShapeFactory*)malloc(sizeof(ShapeFactory));
    // 初始化所有工厂为 NULL
    for (int i = 0; i < 5; i++) {
        factory->factories[i] = NULL;
    }
    return factory;
}

IShape* shapeFactoryGetShape(ShapeFactory* factory, ShapeKind kind) {
    if (factory->factories[kind] == NULL) {
        switch (kind) {
            case CIRCLE:
                factory->factories[kind] = (ICreator*)createCircleCreator();
                break;
            case SQUARE:
                factory->factories[kind] = (ICreator*)createSquareCreator();
                break;
            case RECTANGLE:
                factory->factories[kind] = (ICreator*)createRectangleCreator();
                break;
            case BIG_CIRCLE:
                factory->factories[kind] = (ICreator*)createBigCircleCreator();
                break;
            default:
                factory->factories[kind] = (ICreator*)createUnknownShapeCreator();
                break;
        }
    }
    return factory->factories[kind]->getShape(factory->factories[kind]);
}
