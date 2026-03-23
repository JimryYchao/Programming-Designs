#pragma once
#include "Implementor.hpp"
#include <functional>
#include <memory>

// 抽象类
class Shape
{
protected:
    std::shared_ptr<DrawAPI> draw;

public:
    Shape(std::shared_ptr<DrawAPI> draw) : draw(draw) {}
    virtual ~Shape() = default;

    virtual void Draw(Color color)
    {
        draw->draw();
        draw->fill(color);
    }
};

// 拓展抽象类
class ShapeAdvance : public Shape
{
private:
    std::function<void()> onDrawCompleted;

public:
    ShapeAdvance(std::shared_ptr<DrawAPI> draw, std::function<void()> onDrawCompleted)
        : Shape(draw), onDrawCompleted(onDrawCompleted) {}

    void Draw(Color color) override 
    {
        Shape::Draw(color);
        if (onDrawCompleted)
            onDrawCompleted();
    }
};
