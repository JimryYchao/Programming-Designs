#pragma once
#include "flyweight.h"

// 非共享具体享元类 - 圆形增强
typedef struct CircleAddition {
    IShape base;
    Circle* circle;
    void (*move_position)(struct CircleAddition* self, float x, float y);
    void (*reset_radius)(struct CircleAddition* self, float radius);
} CircleAddition;

// 初始化圆形增强
IShape* CircleAddition_create(Circle* circle);
