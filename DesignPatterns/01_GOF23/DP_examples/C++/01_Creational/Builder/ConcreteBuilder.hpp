// ConcreteBuilder.hpp
// 具体建造者

#pragma once

#include "Builder.hpp"
#include "Product.hpp"
#include <vector>
#include <algorithm>

// 汉堡建造者
template <typename T>
class BurgerBuilder : public IBuilder
{
public:
    static BurgerBuilder<T>& Instance() {
        static BurgerBuilder<T> instance;
        return instance;
    }
    
    Item *Build() override
    {
        return new T();
    }
    
    ~BurgerBuilder() override = default;
    
private:
    BurgerBuilder() = default; // 私有构造函数
    BurgerBuilder(const BurgerBuilder&) = delete;
    BurgerBuilder& operator=(const BurgerBuilder&) = delete;
};

// 冷饮建造者
template <typename T>
class ColdDrinkBuilder : public IBuilder
{
public:
    static ColdDrinkBuilder<T>& Instance() {
        static ColdDrinkBuilder<T> instance;
        return instance;
    }
    
    Item *Build() override
    {
        return new T();
    }
    
    ~ColdDrinkBuilder() override = default;
    
private:
    ColdDrinkBuilder() = default; // 私有构造函数
    ColdDrinkBuilder(const ColdDrinkBuilder&) = delete;
    ColdDrinkBuilder& operator=(const ColdDrinkBuilder&) = delete;
};

// 鸡肉套餐建造者
class ChickenMealBuilder : public IMealBuilder
{
public:
    std::vector<IBuilder *> GetBuilders() override
    {
        return {
            &BurgerBuilder<ChickenBurger>::Instance(),
            &ColdDrinkBuilder<PepsiCola>::Instance()};
    }
};

// 素食套餐建造者
class VegMealBuilder : public IMealBuilder
{
public:
    std::vector<IBuilder *> GetBuilders() override
    {
        return {
            &BurgerBuilder<VegetableBurger>::Instance(),
            &ColdDrinkBuilder<CokeCola>::Instance()};
    }
};

class MealBuilder
{
private:
    std::vector<IBuilder *> builders;
    std::vector<Item *> items;

public:
    MealBuilder(std::vector<IBuilder *> builders) : builders(builders), items({}) {}
    
    void Add(ItemKind kind)
    {
        switch (kind)
        {
        case ItemKind::VEGETABLE_BURGER:
            builders.push_back(&BurgerBuilder<VegetableBurger>::Instance());
            break;
        case ItemKind::CHICKEN_BURGER:
            builders.push_back(&BurgerBuilder<ChickenBurger>::Instance());
            break;
        case ItemKind::COKE_COLA:
            builders.push_back(&ColdDrinkBuilder<CokeCola>::Instance());
            break;
        case ItemKind::PEPSI_COLA:
            builders.push_back(&ColdDrinkBuilder<PepsiCola>::Instance());
            break;
        default:
            break;
        }
    }
    
    void Remove(ItemKind kind)
    {
        switch (kind)
        {
        case ItemKind::VEGETABLE_BURGER:
            builders.erase(std::remove(builders.begin(), builders.end(), &BurgerBuilder<VegetableBurger>::Instance()), builders.end());
            break;
        case ItemKind::CHICKEN_BURGER:
            builders.erase(std::remove(builders.begin(), builders.end(), &BurgerBuilder<ChickenBurger>::Instance()), builders.end());
            break;
        case ItemKind::COKE_COLA:
            builders.erase(std::remove(builders.begin(), builders.end(), &ColdDrinkBuilder<CokeCola>::Instance()), builders.end());
            break;
        case ItemKind::PEPSI_COLA:
            builders.erase(std::remove(builders.begin(), builders.end(), &ColdDrinkBuilder<PepsiCola>::Instance()), builders.end());
            break;
        default:
            break;
        }
    }

    void Build()
    {
        // 清理之前的项目
        for (auto *item : items) {
            delete item;
        }
        items.clear();
        
        for (auto builder : builders) {
            items.push_back(builder->Build());
        }
    }
    
    void Pack()
    {
        for (auto item : items) {
            item->GetPacker()->Pack(item);
        }
    }
    
    float GetPrice()
    {
        float price = 0.0f;
        for (auto *item : items) {
            price += item->GetPrice();
        }
        return price;
    }

    ~MealBuilder() {
        for (auto *item : items) {
            delete item;
        }
    }
};
