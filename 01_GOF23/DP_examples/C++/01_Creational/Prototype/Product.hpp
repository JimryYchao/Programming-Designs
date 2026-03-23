#pragma once

#include <iostream>
#include <string>
#include <memory>

enum class Color
{
    Unknown,
    Red,
    Green,
    Blue,
    Yellow
};

inline std::string colorToString(Color color)
{
    switch (color)
    {
    case Color::Red:
        return "Red";
    case Color::Green:
        return "Green";
    case Color::Blue:
        return "Blue";
    case Color::Yellow:
        return "Yellow";
    default:
        return "Unknown";
    }
}

class IShape
{
public:
    virtual ~IShape() = default;
    virtual std::string name() const = 0;
    virtual void draw() const = 0;
    virtual void fill(Color color) const = 0;
    virtual std::unique_ptr<IShape> clone() const = 0;
};

class Shape : public IShape
{
protected:
    int id;
    std::string name_;

public:
    Shape(int id = 0, const std::string &name = "") : id(id), name_(name) {}
    virtual ~Shape() { std::cout << "~Shape()" << std::endl; };

    std::string name() const override
    {
        return name_;
    }

    void draw() const override {}

    void fill(Color color) const override {}

    virtual std::unique_ptr<IShape> clone() const override
    {
        return nullptr;
    }
};

enum class ShapeKind
{
    Unknown,
    Circle,
    Square,
    Rectangle
};

class Circle : public Shape
{
public:
    Circle(int id = static_cast<int>(ShapeKind::Circle), const std::string &name = "Circle")
        : Shape(id, name) {}

    void draw() const override
    {
        std::cout << "Draw a Circle" << std::endl;
    }

    void fill(Color color) const override
    {
        std::cout << "Fill with " << colorToString(color) << std::endl;
    }

    std::unique_ptr<IShape> clone() const override
    {
        return std::make_unique<Circle>(id, name_);
    }
};

class Square : public Shape
{
public:
    Square(int id = static_cast<int>(ShapeKind::Square), const std::string &name = "Square")
        : Shape(id, name) {}

    void draw() const override
    {
        std::cout << "Draw a Square" << std::endl;
    }

    void fill(Color color) const override
    {
        std::cout << "Fill with " << colorToString(color) << std::endl;
    }

    std::unique_ptr<IShape> clone() const override
    {
        return std::make_unique<Square>(id, name_);
    }
};

class Rectangle : public Shape
{
public:
    Rectangle(int id = static_cast<int>(ShapeKind::Rectangle), const std::string &name = "Rectangle")
        : Shape(id, name) {}

    void draw() const override
    {
        std::cout << "Draw a Rectangle" << std::endl;
    }

    void fill(Color color) const override
    {
        std::cout << "Fill with " << colorToString(color) << std::endl;
    }

    std::unique_ptr<IShape> clone() const override
    {
        return std::make_unique<Rectangle>(id, name_);
    }
};
