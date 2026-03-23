#include "ConcreteCreator.hpp"

void FactoryDemo() {
    auto circle =  ShapeFactory::GetShape(ShapeKind::Circle);
    circle->draw();
    circle->fill();

    auto square = ShapeFactory::GetShape(ShapeKind::Square);
    square->draw();
    square->fill();

    auto rectangle = ShapeFactory::GetShape(ShapeKind::Rectangle);
    rectangle->draw();
    rectangle->fill();

    auto bigCircle = ShapeFactory::GetShape(ShapeKind::BigCircle);
    bigCircle->draw();
    bigCircle->fill();
}

int main() {
    FactoryDemo();
}