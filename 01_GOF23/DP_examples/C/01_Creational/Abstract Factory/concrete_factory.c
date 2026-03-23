// concrete_factory.c
// 具体工厂和工厂生产者实现

#include <stdlib.h>
#include "concrete_factory.h"

// 具体工厂创建函数
static Color *(*switch_color(ColorType color_type))()
{
    switch (color_type)
    {
    case RED:
        return red_create;
    case GREEN:
        return green_create;
    case BLUE:
        return blue_create;
    default:
        return unknownColor_create;
    }
}
static Shape *(*switch_shape(ShapeType shape_type))()
{
    switch (shape_type)
    {
    case CIRCLE:
        return circle_create;
    case SQUARE:
        return square_create;
    case RECTANGLE:
        return rectangle_create;
    default:
        return unknownShape_create;
    }
}
static Color *product_factory_get_color(AbstractFactory *self)
{
    return ((ProductFactory *)self->data)->GetColor();
}
static Shape *product_factory_get_shape(AbstractFactory *self)
{
    return ((ProductFactory *)self->data)->GetShape();
}
static void product_factory_destroy(AbstractFactory *self)
{
    if (self && self->data)
        free(self->data);
    if (self)
        free(self);
}
AbstractFactory *product_factory_create(ColorType color_type, ShapeType shape_type)
{
    AbstractFactory *factory = (AbstractFactory *)malloc(sizeof(AbstractFactory));
    factory->destroy = product_factory_destroy;
    ProductFactory *data = (ProductFactory *)malloc(sizeof(ProductFactory));
    data->GetColor = switch_color(color_type);
    data->GetShape = switch_shape(shape_type);
    factory->data = data;
    factory->GetColor = product_factory_get_color;
    factory->GetShape = product_factory_get_shape;
    return factory;
}

// 工厂生产者创建
AbstractFactory *get_factory(FactoryProducer *producer, ProductKind kind)
{
    if (producer && producer->factories[kind] == NULL)
    {
        switch (kind)
        {
        case RED_CIRCLE:
            producer->factories[kind] = product_factory_create(RED, CIRCLE);
            break;
        case GREEN_SQUARE:
            producer->factories[kind] = product_factory_create(GREEN, SQUARE);
            break;
        case BLUE_RECTANGLE:
            producer->factories[kind] = product_factory_create(BLUE, RECTANGLE);
            break;
        default:
            producer->factories[kind] = product_factory_create(UNKNOWN_COLOR, UNKNOWN_SHAPE);
            break;
        }
    }
    return producer->factories[kind];
}
[[nodiscard]] FactoryProducer *FactoryProducerCreate(void) {
    FactoryProducer *producer = (FactoryProducer *)malloc(sizeof(FactoryProducer) + sizeof(AbstractFactory *) * UNKNOWN_PRODUCT);
    producer->factory_count = UNKNOWN_PRODUCT;
    producer->GetFactory = get_factory;
    for (int i = 0; i < producer->factory_count; i++)
        producer->factories[i] = NULL;
    return producer;
}

void DestroyFactoryProducer(FactoryProducer *producer)
{
    if (producer)
        for (int i = 0; i < producer->factory_count; i++)
            if (producer->factories[i])
                producer->factories[i]->destroy(producer->factories[i]);
    free(producer);
}
