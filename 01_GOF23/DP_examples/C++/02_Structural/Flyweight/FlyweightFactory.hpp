#ifndef FLYWEIGHT_FACTORY_HPP
#define FLYWEIGHT_FACTORY_HPP

#include "Flyweight.hpp"
#include "UnsharedFlyweight.hpp"
#include <map>

// 享元工厂
class FlyweightFactory
{
private:
    // 存储 CircleData 的数据结构: color -> (radius -> CircleData 指针)
    static std::map<std::string, std::map<float, std::shared_ptr<CircleData>>> shapeDic;

public:
    // 获取圆形
    static std::unique_ptr<Circle> getCircle(const std::string &color, float radius, float x, float y);
    // 获取特殊圆形
    static std::unique_ptr<CircleAddition> getSpecialCircle(const std::string &color, float radius, float x, float y);
};
std::map<std::string, std::map<float, std::shared_ptr<CircleData>>> FlyweightFactory::shapeDic;
std::unique_ptr<Circle> FlyweightFactory::getCircle(const std::string &color, float radius, float x, float y)
{
    std::unique_ptr<Circle> circle;
    // 查找颜色
    auto colorIt = shapeDic.find(color);
    if (colorIt != shapeDic.end())
    {
        // 查找半径
        auto radiusIt = colorIt->second.find(radius);
        if (radiusIt != colorIt->second.end())
        {
            // 复用已有的 CircleData
            return CircleFactory::getCircle(radiusIt->second, x, y);
        }
        else
        {
            // 创建新的圆形
            circle = CircleFactory::getCircle(color, radius, x, y);
            if (circle)
            {
                colorIt->second[radius] = circle->getData();
            }
        }
    }
    else
    {
        // 创建新的颜色条目
        auto &radiusMap = shapeDic[color];
        // 创建新的圆形
        circle = CircleFactory::getCircle(color, radius, x, y);
        if (circle)
        {
            radiusMap[radius] = circle->getData();
        }
    }

    if (circle)
    {
        std::cout << "Create a New Circle Filled with " << color << std::endl;
    }
    return circle;
}
std::unique_ptr<CircleAddition> FlyweightFactory::getSpecialCircle(const std::string &color, float radius, float x, float y)
    {
        auto circle = getCircle(color, radius, x, y);
        if (circle)
        {
            return CircleFactory::getSpacialCircle(std::move(circle));
        }
        return nullptr;
    }
#endif // FLYWEIGHT_FACTORY_HPP
