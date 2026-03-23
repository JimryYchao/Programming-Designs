#pragma once
#include "component.h"

typedef struct Decorator{
    IShape* component;
    void (*draw)(struct Decorator* self);
    void (*fill)(struct Decorator* self, Color color);
} Decorator;

typedef struct ShapeDecorator {
    Decorator base;
    void (*draw)( struct ShapeDecorator* self);
    void (*fill)(struct ShapeDecorator* self, Color color);
} ShapeDecorator;

Decorator* Decorator_create(Decorator* out, IShape* shape);
ShapeDecorator* ShapeDecorator_create(ShapeDecorator* out, IShape* shape);
