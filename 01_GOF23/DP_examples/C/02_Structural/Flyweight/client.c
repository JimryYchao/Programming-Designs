#include "flyweight_factory.h"
#include <stdlib.h>

// 构建圆形
void BuildCircles() {
    // 获取 FlyweightFactory 单例
    FlyweightFactory* factory = GetFlyweightFactoryInstance();
    if (factory == NULL) {
        printf("Failed to get FlyweightFactory instance\n");
        return;
    }
    // 创建红色圆形
    IShape* redShape = factory->get_circle("Red", 10, 0, 0);
    if (redShape) {
        redShape->draw(redShape);
        redShape->fill(redShape);
        redShape->destroy(redShape);
    }
    // 创建特殊绿色大圆形
    IShape* greenShape = factory->get_special_circle("Green", 100, 100, 100);
    if (greenShape) {
        greenShape->draw(greenShape);
        greenShape->fill(greenShape);
        CircleAddition* greenBigCircle = (CircleAddition*)greenShape;
        greenBigCircle->reset_radius(greenBigCircle, 10);
        greenBigCircle->move_position(greenBigCircle, 0, 0);
        free(greenBigCircle);
    }
}

// 构建享元圆形
void BuildFlyweightCircle() {
    // 获取 FlyweightFactory 单例
    FlyweightFactory* factory = GetFlyweightFactoryInstance();
    if (factory == NULL) {
        printf("Failed to get FlyweightFactory instance\n");
        return;
    }
    
    // 创建红色圆形（复用之前的 CircleData）
    IShape* redShape = factory->get_circle("Red", 10, 10086, 10010);
    if (redShape) {
        redShape->draw(redShape);
        redShape->fill(redShape);
        redShape->destroy(redShape);
    }
}

// 测试 Flyweight 模式
int main() {
    BuildCircles();
    BuildFlyweightCircle();
    
    // 释放资源
    FlyweightFactory* factory = GetFlyweightFactoryInstance();
    if (factory) {
        FlyweightFactory_free(factory);
    }
}

// gcc -o client client.c flyweight_factory.c unshared_flyweight.c flyweight.c