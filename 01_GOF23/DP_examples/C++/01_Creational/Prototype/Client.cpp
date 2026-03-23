#include "ShapeCache.hpp"

int main() {
    // 克隆不同形状
    auto cache = ShapeCache::GetInstance();

    std::unique_ptr<IShape> circle = cache->getShape(ShapeKind::Circle);
    if (circle) {
        circle->draw();
        circle->fill(Color::Red);
    }

    std::unique_ptr<IShape> square = cache->getShape(ShapeKind::Square);
    if (square) {
        square->draw();
        square->fill(Color::Green);
    }

    // 移除原型后，再次获取 Circle 应该为 null
    cache->removePrototype(ShapeKind::Circle);

    std::unique_ptr<IShape> circle2 = cache->getShape(ShapeKind::Circle);
    if (!circle2) {
        std::cout << "Circle2 is null after removal." << std::endl;
    }
    else {
        circle2->draw();
        circle2->fill(Color::Blue);
    }
}
