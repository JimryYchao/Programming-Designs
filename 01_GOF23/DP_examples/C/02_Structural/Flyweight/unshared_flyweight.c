#include "unshared_flyweight.h"
#include <stdlib.h>

// 圆形增强绘制方法
static void CircleAddition_draw(IShape *self)
{
    CircleAddition *circleAddition = (CircleAddition *)self;
    circleAddition->circle->base.draw(&circleAddition->circle->base);
}

// 圆形增强填充方法
static void CircleAddition_fill(IShape *self)
{
    CircleAddition *circleAddition = (CircleAddition *)self;
    circleAddition->circle->base.fill(&circleAddition->circle->base);
}

// 移动位置
static void CircleAddition_move_position(CircleAddition *self, float x, float y)
{
    printf("Move Circle to (%f, %f)\n", x, y);
}

// 重置半径
static void CircleAddition_reset_radius(CircleAddition *self, float radius)
{
    printf("Reset Radius to %f\n", radius);
}

// 圆形增强销毁方法
static void CircleAddition_destroy(void* self) {
    if (!self) 
        return;
    free(self);
}

// 初始化圆形增强
IShape *CircleAddition_create(Circle *circle)
{
    CircleAddition *circleAddition = (CircleAddition *)malloc(sizeof(CircleAddition));
    if (circleAddition != NULL)
    {
        circleAddition->circle = circle;
        circleAddition->base.draw = CircleAddition_draw;
        circleAddition->base.fill = CircleAddition_fill;
        circleAddition->base.destroy = CircleAddition_destroy;
        circleAddition->move_position = CircleAddition_move_position;
        circleAddition->reset_radius = CircleAddition_reset_radius;
    }
    return (IShape *)circleAddition;
}
