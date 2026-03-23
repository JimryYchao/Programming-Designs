#pragma once
#include "Implementor.hpp"
#include <iostream>


// 圆形实现
class Circle : public DrawAPI {
public:
    void draw() override {
        std::cout << "Draw a Circle" << std::endl;
    }
};

// 正方形实现
class Square : public DrawAPI {
public:
    void draw() override {
        std::cout << "Draw a Square" << std::endl;
    }
};

// 矩形实现
class Rectangle : public DrawAPI {
public:
    void draw() override {
        std::cout << "Draw a Rectangle" << std::endl;
    }
};

// 大圆形实现
class BigCircle : public Circle {
public:
    void draw() override {
        std::cout << "Draw a Big Circle" << std::endl;
    }
};
