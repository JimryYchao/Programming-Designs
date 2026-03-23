#include "flyweight.h"
#include "unshared_flyweight.h"
#include <stdlib.h>
#include <string.h>

static void Circle_destroy(void* circle) {
    if (!circle) 
        return;
    free(circle);
}

static void CircleData_destroy(void* data) {
    if (!data) 
        return;
    free(data);
}

void Circle_draw(IShape* self) {
    Circle* circle = (Circle*)self;
    printf("Draw a circle with color %s, radius %f at (%f, %f)\n",
           circle->data->color, circle->data->radius,
           circle->x, circle->y);
}

void Circle_fill(IShape* self) {
    Circle* circle = (Circle*)self;
    printf("Fill with %s\n", circle->data->color);
}

IShape* Circle_create_with_data(CircleData* data, float x, float y){
    if (!data) 
        return NULL;
    Circle* circle = (Circle*)malloc(sizeof(Circle));
    if (circle) {
        circle->base.destroy = Circle_destroy;
        circle->base.draw = Circle_draw;
        circle->base.fill = Circle_fill;
        circle->data = data;
        circle->x = x;
        circle->y = y;
        return (IShape*)circle;
    }
    return NULL;
}

IShape* Circle_create(const char* color, float radius, float x, float y) {
    CircleData* data = (CircleData*)malloc(sizeof(CircleData));
    IShape* circle = NULL;
    if (data) {
        data->destroy = CircleData_destroy;
        data->color = color;
        data->radius = radius;
        circle = Circle_create_with_data(data, x, y);
        if (!circle) {
            free(data);
            data = NULL;
        }
    }
    return circle;
}


// 初始化圆形工厂
void CircleFactory_init(CircleFactory* factory) {
    factory->get_circle = Circle_create;
    factory->get_circle_by_data = Circle_create_with_data;
    factory->get_spacial_circle = CircleAddition_create;
}
