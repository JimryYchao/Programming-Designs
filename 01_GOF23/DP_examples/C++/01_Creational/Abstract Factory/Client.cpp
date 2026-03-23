// Client.cpp
#include "ConcreteFactory.hpp"

void drawShape(AbstractFactory* ab) {
    IShape* shape = ab->getShape();
    IColor* color = ab->getColor();
    shape->draw();
    color->fill();
    delete shape;
    delete color;
}

void example() {
    FactoryProducer factoryProducer;
    AbstractFactory* redCircleF = factoryProducer.GetFactory(ProductKind::RedCircle);
    drawShape(redCircleF);
    AbstractFactory* blueRectangleF = factoryProducer.GetFactory(ProductKind::BlueRectangle);
    drawShape(blueRectangleF);
}

int main() {
    example();
    return 0;
}
