#pragma once

#include <iostream>

// 产品类型枚举
enum class ShapeKind {
    None,
    Circle,
    Square,
    Rectangle,
    BigCircle
};

// 产品接口
class IShape {
public:
    virtual ~IShape() = default;
    virtual void draw() = 0;
    virtual void fill() = 0;
};

// 圆形产品
class Circle : public IShape {
public:
    void draw() override {
        std::cout << "Draw a Circle" << std::endl;
    }
    void fill() override {
        std::cout << "Fill red" << std::endl;
    }
};

// 正方形产品
class Square : public IShape {
public:
    void draw() override {
        std::cout << "Draw a Square" << std::endl;
    }
    void fill() override {
        std::cout << "Fill Green" << std::endl;
    }
};

// 矩形产品
class Rectangle : public IShape {
public:
    void draw() override {
        std::cout << "Draw a Rectangle" << std::endl;
    }
    void fill() override {
        std::cout << "Fill Blue" << std::endl;
    }
};

// 未知形状产品
class UnknownShape : public IShape {
public:
    void draw() override {}
    void fill() override {}
};

