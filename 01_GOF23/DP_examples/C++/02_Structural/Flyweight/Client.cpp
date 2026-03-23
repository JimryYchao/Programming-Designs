#include "FlyweightFactory.hpp"

// 构建圆形
void BuildCircles() {
    // 创建红色圆形
    auto redCircle = FlyweightFactory::getCircle("Red", 10, 0, 0);
    if (redCircle) {
        redCircle->draw();
        redCircle->fill();
    }
    
    // 创建特殊绿色大圆形
    auto greenBigCircle = FlyweightFactory::getSpecialCircle("Green", 100, 100, 100);
    if (greenBigCircle) {
        greenBigCircle->draw();
        greenBigCircle->fill();
        greenBigCircle->resetRadius(10);
        greenBigCircle->movePosition(0, 0);
    }
}

// 构建享元圆形
void BuildFlyweightCircle() {
    // 创建红色圆形（复用之前的 CircleData）
    auto redCircle = FlyweightFactory::getCircle("Red", 10, 10086, 10010);
    if (redCircle) {
        redCircle->draw();
        redCircle->fill();
    }
}

// 测试 Flyweight 模式
int main() {
    BuildCircles();
    BuildFlyweightCircle();
}
