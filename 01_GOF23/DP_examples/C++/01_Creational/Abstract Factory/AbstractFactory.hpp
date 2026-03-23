// AbstractFactory.h
#pragma once

class IColor;
class IShape;

class AbstractFactory {
public:
    virtual ~AbstractFactory() = default;
    virtual IColor* getColor() = 0;
    virtual IShape* getShape() = 0;
};
