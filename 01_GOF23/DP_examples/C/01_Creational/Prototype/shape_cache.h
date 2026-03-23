#pragma once
#include "product.h"

typedef struct ShapeProto
{
    IShape *proto;
    IShape *(*clone)(IShape *self);
    void (*destroy)(struct ShapeProto *self);
} ShapeProto;


#define SHAPE_CACHE_SIZE 8

typedef struct ShapeCache
{
    ShapeProto *ShapeProtos[SHAPE_CACHE_SIZE]; // 0: Unknown, 1: Circle, 2: Square, 3: Rectangle ....
    void (*Register)(struct ShapeCache *self, ShapeKind key, ShapeProto *shape);
    void (*Remove)(struct ShapeCache *self, ShapeKind key);
    IShape *(*GetShape)(struct ShapeCache *self, ShapeKind key);
    void (*Destroy)(struct ShapeCache *self);
} ShapeCache;

ShapeCache *ShapeCache_instance();
