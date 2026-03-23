#include "shape_cache.h"


static void ShapeProto_destroy(ShapeProto *self)
{
    if (self)
    {
        if (self->proto)
            self->proto->destroy(self->proto);
        free(self);
    }
}

static ShapeProto *ShapeProto_create(ShapeKind kind, IShape *proto)
{
    ShapeProto *sp = (ShapeProto *)malloc(sizeof(ShapeProto));
    if (sp)
    {
        sp->proto = proto;
        sp->clone = proto->clone;
        sp->destroy = ShapeProto_destroy;
    }
    return sp;
}

static void ShapeCache_load(ShapeCache *self)
{
    // 注册各种形状的原型
    ShapeProto *circle = ShapeProto_create(ShapeCircle, (IShape *)circle_create());
    self->ShapeProtos[ShapeCircle] = circle;
    ShapeProto *square = ShapeProto_create(ShapeSquare, (IShape *)square_create());
    self->ShapeProtos[ShapeSquare] = square;
    ShapeProto *rectangle = ShapeProto_create(ShapeRectangle, (IShape *)rectangle_create());
    self->ShapeProtos[ShapeRectangle] = rectangle;
}

static void ShapeCache_destroy(ShapeCache *self)
{
    if (self)
    {
        for (int i = 0; i < SHAPE_CACHE_SIZE; i++)
        {
            if (self->ShapeProtos[i])
            {
                self->ShapeProtos[i]->destroy(self->ShapeProtos[i]);
                self->ShapeProtos[i] = NULL;
            }
        }
    }
}

static void ShapeCache_register(ShapeCache *self, ShapeKind key, ShapeProto *shape)
{
    if (!self->ShapeProtos[key])
        self->ShapeProtos[key] = shape;
}

static void ShapeCache_remove(ShapeCache *self, ShapeKind key)
{
        self->ShapeProtos[key]->destroy(self->ShapeProtos[key]);
        self->ShapeProtos[key] = NULL;
}

static IShape *ShapeCache_getShape(ShapeCache *self, ShapeKind key)
{
    if (key >= 0 && key < SHAPE_CACHE_SIZE && self->ShapeProtos[key])
        return self->ShapeProtos[key]->clone(self->ShapeProtos[key]->proto);
    return NULL;
}

ShapeCache *ShapeCache_instance()
{
    static ShapeCache cache = {
        .ShapeProtos = {}, 
        .Register = ShapeCache_register,
        .Remove = ShapeCache_remove,
        .GetShape = ShapeCache_getShape,
        .Destroy = ShapeCache_destroy
    };
    ShapeCache_load(&cache);
    return &cache;
}

