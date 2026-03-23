#pragma once
#include <iostream>

// 形状接口
class IShape {
public:
    virtual ~IShape() = default;
    virtual void draw() = 0;
};

// 圆形实现
class Circle : public IShape {
private:
    int radius;
public:
    Circle(int radius) : radius(radius) {}
    void draw() override {
        std::cout << "Draw a circle with radius " << radius << std::endl;
    }
};

// 矩形实现
class Rectangle : public IShape {
private:
    int width;
    int height;
public:
    Rectangle(int width, int height) : width(width), height(height) {}
    void draw() override {
        std::cout << "Draw a rectangle with width " << width << " and height " << height << std::endl;
    }
};

// 正方形实现
class Square : public IShape {
private:
    int side;
public:
    Square(int side) : side(side) {}
    void draw() override {
        std::cout << "Draw a square with side " << side << std::endl;
    }
};