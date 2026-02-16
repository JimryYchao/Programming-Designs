#pragma once
#include "implementor.h"

// 抽象类结构体
typedef struct Shape
{
    DrawAPI *draw;
    void (*draw_shape)(struct Shape *self, Color color);
} Shape;

// 初始化形状
void Shape_init(Shape *shape, DrawAPI *draw);

// 修正抽象类结构体
typedef void (*DrawCompletedCallback)(void);
typedef struct ShapeAdvance
{
    Shape base;
    DrawCompletedCallback on_draw_completed;
    void (*draw_shape)(struct ShapeAdvance *self, Color color);
} ShapeAdvance;

// 初始化高级形状
void ShapeAdvance_init(ShapeAdvance *shapeAdvance, DrawAPI *draw, DrawCompletedCallback on_draw_completed);

