#include <stdio.h>
#include <stdlib.h>
#include "creator.h"

// 形状工厂销毁方法
static void shapeFactory_destroy(ShapeFactory *factory)
{
    for (int i = 0; i < SHAPE_KIND_COUNT; i++)
    {
        if (factory->creators[i] != NULL)
        {
            free(factory->creators[i]);
            factory->creators[i] = NULL;
        }
    }
    free(factory);
}

static IShape *CircleCreator_getShape(ICreator *self)
{
    return createShape(CIRCLE);
}
static IShape *SquareCreator_getShape(ICreator *self)
{
    return createShape(SQUARE);
}
static IShape *RectangleCreator_getShape(ICreator *self)
{
    return createShape(RECTANGLE);
}

inline static IShape *set_radius(IShape *shape)
{
    printf("set radius to 10\n");
    return shape;
}
static IShape *BigCircleCreator_getShape(ICreator *self)
{
    return set_radius(createShape(CIRCLE));
}
static IShape *UnknownShapeCreator_getShape(ICreator *self)
{
    return createShape(UNKNOWN_SHAPE);
}

static ICreator* createICreator(ShapeKind kind){
    ICreator* creator = (ICreator*)malloc(sizeof(ICreator));
    switch (kind)
    {
    case CIRCLE:
        creator->getShape = CircleCreator_getShape;
        break;
    case SQUARE:
        creator->getShape = SquareCreator_getShape;
        break;
    case RECTANGLE:
        creator->getShape = RectangleCreator_getShape;
        break;
    case BIG_CIRCLE:
        creator->getShape = BigCircleCreator_getShape;
        break;
    default:
        creator->getShape = UnknownShapeCreator_getShape;
        break;
    }
    return creator;
}

IShape *ShapeFactory_getShape(ShapeFactory *self, ShapeKind kind)
{
    if (self->creators[kind] == NULL)
        self->creators[kind] = createICreator(kind);
    return self->creators[kind]->getShape(self->creators[kind]);
}

ShapeFactory* getShapeFactory(){
    ShapeFactory* factory = (ShapeFactory*)malloc(sizeof(ShapeFactory));
    for (int i = 0; i < SHAPE_KIND_COUNT; i++)
        factory->creators[i] = NULL;
    factory->getShape = ShapeFactory_getShape;
    factory->destroy = shapeFactory_destroy;
    return factory;
}