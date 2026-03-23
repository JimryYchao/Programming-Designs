#pragma once
#include <stdio.h>

// 颜色枚举
typedef enum {
    UNKNOWN,
    RED,
    GREEN,
    BLUE
} Color;

// 实现接口结构体
typedef struct DrawAPI {
    void (*draw)(struct DrawAPI* self);
    void (*fill)(struct DrawAPI* self, Color color);
} DrawAPI;

// 圆形实现
typedef struct Circle {
    DrawAPI base;
} Circle;
DrawAPI* Circle_init(Circle* circle);

// 正方形实现
typedef struct Square {
    DrawAPI base;
} Square;
DrawAPI* Square_init(Square* square);

// 矩形实现
typedef struct Rectangle {
    DrawAPI base;
} Rectangle;
DrawAPI* Rectangle_init(Rectangle* rectangle);

// 大圆形实现
typedef struct BigCircle {
    Circle base;
} BigCircle;
DrawAPI* BigCircle_init(BigCircle* bigCircle);
