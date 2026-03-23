#pragma once
#include "flyweight.h"
#include "unshared_flyweight.h"

// 颜色节点
typedef struct ColorNode {
    const char* color;
    struct RadiusNode* radiusHead;
    struct ColorNode* next;
} ColorNode;

// 半径节点
typedef struct RadiusNode {
    float radius;
    CircleData* data;
    struct RadiusNode* next;
} RadiusNode;

// 享元工厂
typedef struct FlyweightFactory {
    ColorNode* colorHead;
    CircleFactory circleFactory;
    IShape* (*get_circle)(const char* color, float radius, float x, float y);
    IShape* (*get_special_circle)(const char* color, float radius, float x, float y);
} FlyweightFactory;
FlyweightFactory* GetFlyweightFactoryInstance();
void FlyweightFactory_free(FlyweightFactory* factory);

