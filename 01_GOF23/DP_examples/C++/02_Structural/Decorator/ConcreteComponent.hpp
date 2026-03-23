#pragma once

#include "Component.hpp"
#include <iostream>

static std::string color_to_string(Color color) {
    switch (color) {
        case Color::red:
            return "red";
        case Color::green:
            return "green";
        case Color::blue:
            return "blue";
        default:
            return "unknown";
    }
}

class Circle : public IShape {
public:
    void Draw() override {
        std::cout << "Draw a Circle." << std::endl;
    }
    void Fill(Color color) override {
        std::cout << "Fill with " << color_to_string(color) << std::endl;
    }
};

class Rectangle : public IShape {
public:
    void Draw() override {
        std::cout << "Draw a Rectangle." << std::endl;
    }
    void Fill(Color color) override {
        std::cout << "Fill with " << color_to_string(color) << std::endl;
    }
};
