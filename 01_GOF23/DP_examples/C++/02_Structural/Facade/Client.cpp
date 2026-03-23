#include "Facade.hpp"

// 测试 Facade 模式
int main() {
    auto circle = ShapeMaker::buildShape(ShapeType::Circle, {10});
    if (circle) {
        circle->draw();
    }

    // 创建矩形
    auto rectangle = ShapeMaker::buildShape(ShapeType::Rectangle, {10, 20});
    if (rectangle) {
        rectangle->draw();
    }

    // 创建正方形
    auto square = ShapeMaker::buildShape(ShapeType::Square, {10});
    if (square) {
        square->draw();
    }
}
