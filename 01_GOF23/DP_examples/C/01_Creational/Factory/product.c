#include <stdio.h>
#include <stdlib.h>
#include "product.h"

// 圆形产品方法
static void circleDraw(IShape *self)
{
    printf("Draw a Circle\n");
}

static void circleFill(IShape *self)
{
    printf("Fill red\n");
}

// 正方形产品方法
static void squareDraw(IShape *self)
{
    // use self->data
    printf("Draw a Square\n");
}

static void squareFill(IShape *self)
{
    printf("Fill Green\n");
}

// 矩形产品方法
static void rectangleDraw(IShape *self)
{
    printf("Draw a Rectangle\n");
}

static void rectangleFill(IShape *self)
{
    printf("Fill Blue\n");
}

// 未知形状产品方法
static void unknownShapeDraw(IShape *self) {}

static void unknownShapeFill(IShape *self) {}

// shape create
void shape_destroy(IShape *self)
{
    if (self == NULL)
        return;
    if (self->data != NULL)
    {
        free(self->data);
        self->data = NULL;
        self->draw = NULL;
        self->fill = NULL;
    }
    free(self);
}
IShape *createShape(ShapeKind kind)
{
    IShape *shape = (IShape *)malloc(sizeof(IShape));
    switch (kind)
    {
    case CIRCLE:
        shape->data = malloc(sizeof(CircleData));
        shape->draw = circleDraw;
        shape->fill = circleFill;
        break;
    case SQUARE:
        shape->data = malloc(sizeof(SquareData));
        shape->draw = squareDraw;
        shape->fill = squareFill;
        break;
    case RECTANGLE:
        shape->data = malloc(sizeof(RectangleData));                
        shape->draw = rectangleDraw;
        shape->fill = rectangleFill;
        break;
    default:
        shape->data = malloc(sizeof(UnknownShapeData));
        shape->draw = unknownShapeDraw;
        shape->fill = unknownShapeFill;
        break;
    }
    shape->destroy = shape_destroy;
    return shape;
}