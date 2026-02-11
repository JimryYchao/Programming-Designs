#include <stdio.h>
#include <stdlib.h>
#include "creator.h"

// 工厂模式演示
int main() {
    ShapeFactory* factory = createShapeFactory();
    
    // 测试圆形
    IShape* circle = shapeFactoryGetShape(factory, CIRCLE);
    circle->draw(circle);
    circle->fill(circle);
    free(circle);
    
    // 测试大圆形
    IShape* bigCircle = shapeFactoryGetShape(factory, BIG_CIRCLE);
    bigCircle->draw(bigCircle);
    bigCircle->fill(bigCircle);
    free(bigCircle);
    
    // 测试正方形
    IShape* square = shapeFactoryGetShape(factory, SQUARE);
    square->draw(square);
    square->fill(square);
    free(square);
    
    // 释放工厂
    for (int i = 0; i < 5; i++) {
        if (factory->factories[i] != NULL) {
            free(factory->factories[i]);
        }
    }
    free(factory);
    
    return 0;
}
