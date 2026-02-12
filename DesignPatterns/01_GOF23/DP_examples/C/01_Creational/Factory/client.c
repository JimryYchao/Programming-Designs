#include <stdio.h>
#include <stdlib.h>
#include "creator.h"

// 工厂模式演示
int main() {
    ShapeFactory* factory = getShapeFactory();
    
    // 测试圆形
    IShape* circle = factory->getShape(factory, CIRCLE);
    circle->draw(circle);
    circle->fill(circle);
    circle->destroy(circle);
    
    // 测试大圆形
    IShape* bigCircle = factory->getShape(factory, BIG_CIRCLE);
    bigCircle->draw(bigCircle);
    bigCircle->fill(bigCircle);
    bigCircle->destroy(bigCircle);
    
    // 测试正方形
    IShape* square = factory->getShape(factory, SQUARE);
    square->draw(square);
    square->fill(square);
    square->destroy(square);
    
    factory->destroy(factory);
}
// gcc -o client client.c creator.c product.c