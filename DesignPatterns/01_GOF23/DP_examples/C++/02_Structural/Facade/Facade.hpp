#pragma once

#include "Subsystem.hpp"
#include <memory>
#include <vector>

// 形状类型枚举
enum class ShapeType
{
    Circle,
    Rectangle,
    Square
};

// 形状创建者（外观类）
class ShapeMaker
{
public:
    static std::unique_ptr<IShape> buildShape(ShapeType shapeType, const std::vector<int> &args)
    {
        switch (shapeType)
        {
        case ShapeType::Circle:
            if (args.size() >= 1)
                return std::make_unique<Circle>(args[0]);
            break;
        case ShapeType::Rectangle:
            if (args.size() >= 2)
                return std::make_unique<Rectangle>(args[0], args[1]);
            break;
        case ShapeType::Square:
            if (args.size() >= 1)
                return std::make_unique<Square>(args[0]);
            break;
        }
        return nullptr;
    }
};
