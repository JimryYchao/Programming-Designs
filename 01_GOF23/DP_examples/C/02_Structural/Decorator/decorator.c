#include "decorator.h"
#include <stdio.h>
#include <stdlib.h>

static void decorator_draw(Decorator* self) {
    if (self->component) {
        self->component->draw(self->component);
    }
}

static void decorator_fill(Decorator* self, Color color) {
    if (self->component) {
        self->component->fill(self->component, color);
    }
}

Decorator* Decorator_create(Decorator* out, IShape* shape){
    out->component = shape;
    out->draw = decorator_draw;
    out->fill = decorator_fill;
    return out;
}   

// ShapeDecorator methods
static void before_draw(ShapeDecorator* self) {
    printf("Before Draw() >> Do...\n");
}

static void after_draw(ShapeDecorator* self) {
    printf("When Draw Complete >> Do...\n");
}

static void before_fill(ShapeDecorator* self) {
    printf("Before Fill() >> Do...\n");
}

static void after_fill(ShapeDecorator* self) {
    printf("When Fill Complete >> Do...\n");
}

static void shape_decorator_draw(ShapeDecorator* self) {
    before_draw(self);
    self->base.component->draw(self->base.component);
    after_draw(self);
}

static void shape_decorator_fill(ShapeDecorator* self, Color color) {
    before_fill(self);
    self->base.component->fill(self->base.component, color);
    after_fill(self);
}

ShapeDecorator* ShapeDecorator_create(ShapeDecorator* out, IShape* shape) {
    out->base.component = shape;
    out->draw = shape_decorator_draw;
    out->fill = shape_decorator_fill;
    return out;
}