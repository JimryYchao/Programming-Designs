#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
    Unknown = 0,
    Red,
    Green,
    Blue,
    Yellow
} Color;

const char* color_to_string(Color color);

typedef struct IShape IShape;

struct IShape {
    int id;
    char name[20];
    void (*draw)(IShape* self);
    void (*fill)(IShape* self, Color color);
    IShape* (*clone)(IShape* self);
    void (*destroy)(IShape* self);
};

typedef enum {
    ShapeUnknown = 0,
    ShapeCircle,
    ShapeSquare,
    ShapeRectangle
} ShapeKind;

typedef struct {
    IShape base;
} Shape;

void shape_init(Shape* self, int id, const char* name);
const char* shape_name(IShape* self);
void shape_draw(IShape* self);
void shape_fill(IShape* self, Color color);
void shape_destroy(IShape* self);

typedef struct {
    Shape base;
} Circle;

Circle* circle_create();
void circle_draw(IShape* self);
void circle_fill(IShape* self, Color color);
IShape* circle_clone(IShape* self);
void circle_destroy(IShape* self);

typedef struct {
    Shape base;
} Square;

Square* square_create();
void square_draw(IShape* self);
void square_fill(IShape* self, Color color);
IShape* square_clone(IShape* self);
void square_destroy(IShape* self);

typedef struct {
    Shape base;
} Rectangle;

Rectangle* rectangle_create();
void rectangle_draw(IShape* self);
void rectangle_fill(IShape* self, Color color);
IShape* rectangle_clone(IShape* self);
void rectangle_destroy(IShape* self);
