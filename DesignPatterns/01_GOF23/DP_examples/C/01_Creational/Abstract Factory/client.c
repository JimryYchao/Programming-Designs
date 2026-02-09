// client.c
// 客户端代码

#include "concrete_factory.h"
#include <stdio.h>

// 客户端代码
void draw_shape(AbstractFactory *ab)
{
    Shape *shape = ab->GetShape(ab);
    Color *color = ab->GetColor(ab);
    shape->Draw(shape);
    color->Fill(color);
    shape->destroy(shape);
    color->destroy(color);
}

// 示例
void example()
{
    FactoryProducer *producer = FactoryProducerCreate();
    // 红色圆形
    AbstractFactory *red_circle_f = producer->GetFactory(producer, RED_CIRCLE);
    draw_shape(red_circle_f);
    // 蓝色矩形
    AbstractFactory *blue_rectangle_f = producer->GetFactory(producer, BLUE_RECTANGLE);
    draw_shape(blue_rectangle_f);

    DestroyFactoryProducer(producer);
}

int main() {
    example();
}
// cd 'this directory'
// gcc 'client.c' 'concrete_factory.c' 'concrete_product.c' -o a.exe