#include <stdio.h>
#include <stdlib.h>
#include "product.h"

// 圆形产品方法
static void circleDraw(IShape* self) {
    printf("Draw a Circle\n");
}

static void circleFill(IShape* self) {
    printf("Fill red\n");
}

// 正方形产品方法
static void squareDraw(IShape* self) {
    printf("Draw a Square\n");
}

static void squareFill(IShape* self) {
    printf("Fill Green\n");
}

// 矩形产品方法
static void rectangleDraw(IShape* self) {
    printf("Draw a Rectangle\n");
}

static void rectangleFill(IShape* self) {
    printf("Fill Blue\n");
}

// 未知形状产品方法
static void unknownShapeDraw(IShape* self) {
    // 空实现
}

static void unknownShapeFill(IShape* self) {
    // 空实现
}

// 构造函数
Circle* createCircle() {
    Circle* circle = (Circle*)malloc(sizeof(Circle));
    circle->base.draw = circleDraw;
    circle->base.fill = circleFill;
    return circle;
}

Square* createSquare() {
    Square* square = (Square*)malloc(sizeof(Square));
    square->base.draw = squareDraw;
    square->base.fill = squareFill;
    return square;
}

Rectangle* createRectangle() {
    Rectangle* rectangle = (Rectangle*)malloc(sizeof(Rectangle));
    rectangle->base.draw = rectangleDraw;
    rectangle->base.fill = rectangleFill;
    return rectangle;
}

UnknownShape* createUnknownShape() {
    UnknownShape* unknownShape = (UnknownShape*)malloc(sizeof(UnknownShape));
    unknownShape->base.draw = unknownShapeDraw;
    unknownShape->base.fill = unknownShapeFill;
    return unknownShape;
}
