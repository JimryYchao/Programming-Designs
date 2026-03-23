// Builder.h
// 建造者接口

#pragma once

#include <string>
#include <vector>

class Item;
class IBuilder;
class IPacker;

class IMealBuilder {
public:
    virtual ~IMealBuilder() = default;
    virtual std::vector<IBuilder*> GetBuilders() = 0;
};

class IBuilder {
public:
    virtual ~IBuilder() = default;
    virtual Item* Build() = 0;
};

class IPacker {
public:
    virtual ~IPacker() = default;
    virtual void Pack(Item* item) = 0;
};

class Item {
public:
    virtual ~Item() = default;
    virtual std::string GetName() = 0;
    virtual float GetPrice() = 0;
    virtual IPacker* GetPacker() = 0;
};
