#ifndef FLYWEIGHT_HPP
#define FLYWEIGHT_HPP

#include <iostream>
#include <string>
#include <memory>

// 形状接口
class IShape {
public:
    virtual ~IShape() = default;
    virtual void draw() = 0;
    virtual void fill() = 0;
};

// 圆形数据
class CircleData {
public:
    std::string color;
    float radius;
    CircleData(const std::string& color, float radius) : color(color), radius(radius) {}
};

// 圆形实现
class Circle : public IShape {
private:
    std::shared_ptr<CircleData> data;
    float x;
    float y;
public:
    Circle(std::shared_ptr<CircleData> data, float x, float y) : data(data), x(x), y(y) {}
    
    void draw() override {
        std::cout << "Draw a Circle with radius " << data->radius << " at (" << x << ", " << y << ")" << std::endl;
    }
    
    void fill() override {
        std::cout << "Fill with " << data->color << std::endl;
    }
    
    const std::shared_ptr<CircleData>& getData() const {
        return data;
    }
};


#endif // FLYWEIGHT_HPP
