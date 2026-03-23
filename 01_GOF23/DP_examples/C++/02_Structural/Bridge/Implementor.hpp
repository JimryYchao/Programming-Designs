#pragma once

#include <iostream>

enum class Color {
    unknown,
    red, green, blue
};

inline std::string colorToString(Color color) {
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

// 实现接口
class DrawAPI {
public:
    virtual ~DrawAPI() = default;
    virtual void draw() = 0;
    virtual void fill(Color color) {
        std::cout << "Fill with " << colorToString(color) << std::endl;
    }
};