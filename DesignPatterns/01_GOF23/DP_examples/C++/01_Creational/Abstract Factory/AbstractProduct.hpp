// AbstractProduct.h
// 产品接口和具体实现

#pragma once

#include <iostream>

// 产品接口
class IColor {
public:
    virtual ~IColor() = default;
    virtual void fill() = 0;
};

class IShape {
public:
    virtual ~IShape() = default;
    virtual void draw() = 0;
};

// 具体产品 - 颜色
class Red : public IColor {
public:
    void fill() override {
        std::cout << "Fill Red" << std::endl;
    }
};
class Green : public IColor {
public:
    void fill() override {
        std::cout << "Fill Green" << std::endl;
    }
};
class Blue : public IColor {
public:
    void fill() override {
        std::cout << "Fill Blue" << std::endl;
    }
};
class UnknownColor : public IColor {
public:
    void fill() override { }
};

// 具体产品 - 形状
class Circle : public IShape {
public:
    void draw() override {
        std::cout << "Draw a Circle" << std::endl;
    }
};
class Square : public IShape {
public:
    void draw() override {
        std::cout << "Draw a Square" << std::endl;
    }
};
class Rectangle : public IShape {
public:
    void draw() override {
        std::cout << "Draw a Rectangle" << std::endl;
    }
};
class UnknownShape : public IShape {
public:
    void draw() override { }
};
