// Product.h
// 产品和包装实现

#pragma once

#include "Builder.hpp"
#include <iostream>
#include <string>

// 包装器
class Wrapper : public IPacker
{
public:
    static Wrapper Instance;
    void Pack(Item *item) override
    {
        std::cout << "Wrapper a " << item->GetName() << std::endl;
    }
};
Wrapper Wrapper::Instance = Wrapper();
class Bottle : public IPacker
{
public:
    static Bottle Instance;
    void Pack(Item *item) override
    {
        std::cout << "Bottle a " << item->GetName() << std::endl;
    }
};
Bottle Bottle::Instance = Bottle();

// Item 实现
enum class ItemKind
{
    VEGETABLE_BURGER,
    CHICKEN_BURGER,
    COKE_COLA,
    PEPSI_COLA
};

class VegetableBurger : public Item
{
public:
    std::string GetName() override { return "VegetableBurger"; }
    float GetPrice() override { return 8.5f; }
    IPacker *GetPacker() override { return &Wrapper::Instance; }
};

class ChickenBurger : public Item
{
public:
    std::string GetName() override { return "ChickenBurger"; }
    float GetPrice() override { return 15.0f; }
    IPacker *GetPacker() override { return &Wrapper::Instance; }
};

class CokeCola : public Item
{
public:
    std::string GetName() override { return "CokeCola"; }
    float GetPrice() override { return 3.5f; }
    IPacker *GetPacker() override { return &Bottle::Instance; }
};

class PepsiCola : public Item
{
public:
    std::string GetName() override { return "PepsiCola"; }
    float GetPrice() override { return 3.0f; }
    IPacker *GetPacker() override { return &Bottle::Instance; }
};
