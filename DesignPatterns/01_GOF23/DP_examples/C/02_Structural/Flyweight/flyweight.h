#pragma once
#include <stdio.h>

// 形状接口
typedef struct IShape {
    void (*draw)(struct IShape* self);
    void (*fill)(struct IShape* self);
    void (*destroy)(void* self);
} IShape;

// 圆形数据
typedef struct CircleData {
    const char* color;
    float radius;
    void (*destroy)(void* self);
} CircleData;

// 圆形实现
typedef struct Circle {
    IShape base;
    CircleData* data;
    float x;
    float y;
} Circle;

// 初始化圆形
IShape* Circle_create(const char* color, float radius, float x, float y);
IShape* Circle_create_with_data(CircleData* data, float x, float y);


struct CircleAddition;

// 圆形工厂
typedef struct CircleFactory {
    IShape* (*get_circle)(const char* color, float radius, float x, float y);
    IShape* (*get_circle_by_data)(CircleData* data, float x, float y);
    IShape* (*get_spacial_circle)(Circle* circle);
} CircleFactory;

// 初始化圆形工厂
void CircleFactory_init(CircleFactory* factory);
