#pragma once
#include "Creator.hpp"

class ShapeFactory
{
private:
    std::map<ShapeKind, std::shared_ptr<ICreator>> factories;
    ShapeFactory() = default;
    ~ShapeFactory() {
        factories.clear();
    };
    std::shared_ptr<ICreator> getFactory(ShapeKind kind)
    {
        std::shared_ptr<ICreator> creator = nullptr;
        auto it = factories.find(kind);
        if (it != factories.end())
            creator = it->second;
        else
        {
            creator = Creator::GetCreator(kind);
            factories.insert({
                kind,
                creator,
            });
        }
        return creator;
    }
    static ShapeFactory& Instance()
    {
        static ShapeFactory instance;
        return instance;
    }
public:
    static std::unique_ptr<IShape> GetShape(ShapeKind kind)
    {
        return Instance().getFactory(kind)->getShape();
    }
};
