#pragma once
#include "Product.hpp"
#include <memory>
#include <map>

// 创建者接口
class ICreator
{
public:
    template <class T>
        requires std::is_base_of_v<ICreator, T>
    static std::shared_ptr<T> Instance;
    virtual ~ICreator() = default;
    virtual std::unique_ptr<IShape> getShape() = 0;
};

// 未知形状创建者
class UnknownShapeCreator : public ICreator
{
public:
    std::unique_ptr<IShape> getShape() override
    {
        return std::make_unique<UnknownShape>();
    }
};

template <>
std::shared_ptr<UnknownShapeCreator> ICreator::Instance<UnknownShapeCreator> = std::make_shared<UnknownShapeCreator>();

// 圆形创建者
class CircleCreator : public ICreator
{
public:
    std::unique_ptr<IShape> getShape() override
    {
        return std::make_unique<Circle>();
    }
};

template <>
std::shared_ptr<CircleCreator> ICreator::Instance<CircleCreator> = std::make_shared<CircleCreator>();

// 正方形创建者
class SquareCreator : public ICreator
{
public:
    std::unique_ptr<IShape> getShape() override
    {
        return std::make_unique<Square>();
    }
};

template <>
std::shared_ptr<SquareCreator> ICreator::Instance<SquareCreator> = std::make_shared<SquareCreator>();

// 矩形创建者
class RectangleCreator : public ICreator
{
public:
    std::unique_ptr<IShape> getShape() override
    {
        return std::make_unique<Rectangle>();
    }
};

template <>
std::shared_ptr<RectangleCreator> ICreator::Instance<RectangleCreator> = std::make_shared<RectangleCreator>();

// 大圆形创建者
class BigCircleCreator : public CircleCreator
{
private:
    void setRadius()
    {
        std::cout << "Set Radius to 10" << std::endl;
    }

public:
    std::unique_ptr<IShape> getShape() override
    {
        setRadius();
        return CircleCreator::getShape();
    }
};

template <>
std::shared_ptr<BigCircleCreator> ICreator::Instance<BigCircleCreator> = std::make_shared<BigCircleCreator>();

class Creator
{
public:
    static std::shared_ptr<ICreator> GetCreator(ShapeKind kind)
    {
        switch (kind)
        {
        case ShapeKind::Circle:
            return ICreator::Instance<CircleCreator>;
        case ShapeKind::Square:
            return ICreator::Instance<SquareCreator>;
        case ShapeKind::Rectangle:
            return ICreator::Instance<RectangleCreator>;
        case ShapeKind::BigCircle:
            return ICreator::Instance<BigCircleCreator>;
        default:
            return ICreator::Instance<UnknownShapeCreator>;
        }
    }
};