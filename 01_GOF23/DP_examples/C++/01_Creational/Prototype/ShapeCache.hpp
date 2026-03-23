#pragma once

#include "Product.hpp"
#include <unordered_map>

class ShapeCache
{
private:
    std::unordered_map<ShapeKind, std::unique_ptr<IShape>> shapeMap;
    

    void loadCache()
    {
        registerPrototype(ShapeKind::Circle, new Circle());
        registerPrototype(ShapeKind::Square, new Square());
        registerPrototype(ShapeKind::Rectangle, new Rectangle());
    }

public:
    ShapeCache()
    {
        loadCache();
    }
    static std::shared_ptr<ShapeCache> GetInstance();
 
    void registerPrototype(ShapeKind key, IShape *shape)
    {
        auto it = shapeMap.find(key);
        if (it == shapeMap.end())
            shapeMap.insert({key, std::unique_ptr<IShape>(shape)});
    }

    void removePrototype(ShapeKind key)
    {
        auto it = shapeMap.find(key);
        if (it != shapeMap.end())
        {
            shapeMap.erase(it);
        }
    }

    std::unique_ptr<IShape> getShape(ShapeKind key)
    {
        auto it = shapeMap.find(key);
        if (it != shapeMap.end())
            return it->second->clone();
        return nullptr;
    }

    ~ShapeCache()
    {
        for (auto &pair : shapeMap)
            pair.second.release();
        shapeMap.clear();
    }
};

// 初始化静态成员
std::shared_ptr<ShapeCache> ShapeCache::GetInstance() {
    static std::shared_ptr<ShapeCache> instance;
    if (!instance)
        instance = std::make_shared<ShapeCache>();
    return instance;
};