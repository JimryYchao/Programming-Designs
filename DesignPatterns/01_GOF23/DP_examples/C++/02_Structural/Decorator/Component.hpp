#pragma once

enum class Color {
    unknown,
    red, green, blue,
};

class IShape {
public:
    virtual ~IShape() = default;
    virtual void Draw() = 0;
    virtual void Fill(Color color) = 0;
};

