#pragma once
#include <stdio.h>

// 形状接口
typedef struct IShape {
    void (*draw)(struct IShape* self);
    void(*destroy)(struct IShape* self);
} IShape;

// 圆形实现
typedef struct Circle {
    IShape base;
    int radius;
} Circle;
Circle* Circle_create(int radius);
// 矩形实现
typedef struct Rectangle {
    IShape base;
    int width;
    int height;
} Rectangle;
Rectangle* Rectangle_create(int width, int height);
// 正方形实现
typedef struct Square {
    IShape base;
    int side;
} Square;
Square* Square_create(int side);