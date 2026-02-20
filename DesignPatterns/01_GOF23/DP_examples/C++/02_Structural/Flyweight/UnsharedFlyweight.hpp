#ifndef UNSHARED_FLYWEIGHT_HPP
#define UNSHARED_FLYWEIGHT_HPP

#include "Flyweight.hpp"

// 非共享具体享元类 - 圆形增强
class CircleAddition : public IShape {
private:
    std::unique_ptr<Circle> shape;
public:
    CircleAddition(std::unique_ptr<Circle> shape) : shape(std::move(shape)) {}
    void draw() override {
        shape->draw();
    }
    void fill() override {
        shape->fill();
    }
    void movePosition(float x, float y) {
        std::cout << "Move Circle to (" << x << ", " << y << ")" << std::endl;
    }
    void resetRadius(float radius) {
        std::cout << "Reset Radius to " << radius << std::endl;
    }
};

class CircleFactory {
public:
   static std::unique_ptr<Circle> getCircle(const std::string& color, float radius, float x, float y) {
        std::shared_ptr<CircleData> data = std::make_shared<CircleData>(color, radius);
        return std::make_unique<Circle>(data, x, y);
    }
   static std::unique_ptr<Circle> getCircle(std::shared_ptr<CircleData> data, float x, float y) {   
        return std::make_unique<Circle>(data, x, y);
    }
    static std::unique_ptr<CircleAddition> getSpacialCircle(std::unique_ptr<Circle> circle) {
        return std::make_unique<CircleAddition>(std::move(circle));
    }
};

#endif // UNSHARED_FLYWEIGHT_HPP
