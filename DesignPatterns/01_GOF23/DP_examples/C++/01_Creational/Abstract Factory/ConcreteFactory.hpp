// ConcreteFactory.h
// 具体工厂和工厂生产者

#pragma once
#include "AbstractFactory.hpp"
#include "AbstractProduct.hpp"
#include <map>

// 具体工厂
enum class ProductKind {
    RedCircle,
    GreenSquare,
    BlueRectangle
};
template <typename Color, typename Shape>
class ProductFactory : public AbstractFactory {
public:
    IColor* getColor() override {
        return new Color();
    }
    
    IShape* getShape() override {
        return new Shape();
    }
};

class FactoryProducer {
private:
    std::map<ProductKind, AbstractFactory*> factories;
    AbstractFactory* createFactory(ProductKind kind) {
        switch (kind) {
            case ProductKind::RedCircle:
                return new ProductFactory<Red, Circle>();
            case ProductKind::GreenSquare:
                return new ProductFactory<Green, Square>();
            case ProductKind::BlueRectangle:
                return new ProductFactory<Blue, Rectangle>();
            default:
                return new ProductFactory<UnknownColor, UnknownShape>(); // 默认
        }
    }

public:
    ~FactoryProducer() {
        for (auto& pair : factories) {
            delete pair.second;
        }
    }
    AbstractFactory* GetFactory(ProductKind kind) {
        if (factories.find(kind) == factories.end()) {
            factories[kind] = createFactory(kind);
        }
        return factories[kind];
    }
};
