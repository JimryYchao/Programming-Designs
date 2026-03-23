-- ConcreteBuilder.lua
-- 具体建造者

local Builder = require("Builder")
local Product = require("Product")

-- 汉堡建造者
---@class BurgerBuilder
local BurgerBuilder = {
    ---@type table<ItemKind, IBuilder>
    instances = {},
}
---@param BurgerClass Burger
---@return IBuilder
function BurgerBuilder:GetInstance(BurgerClass)
    if self.instances[BurgerClass.Kind] == nil then
        local instance = {
            burgerClass = BurgerClass,
        }
        setmetatable(instance, { __index = Builder.IBuilder })
        instance.Build = function()
            return instance.burgerClass:new()
        end
        instance.Kind = BurgerClass.Kind
        self.instances[BurgerClass.Kind] = instance
    end
    return self.instances[BurgerClass.Kind]
end

-- 冷饮建造者
---@class ColdDrinkBuilder
local ColdDrinkBuilder = {
    ---@type table<ItemKind, IBuilder>
    instances = {},
}
---@param ColdDrinkClass ColdDrink
---@return IBuilder
function ColdDrinkBuilder:GetInstance(ColdDrinkClass)
    if self.instances[ColdDrinkClass.Kind] == nil then
        local instance = {
            coldDrinkClass = ColdDrinkClass,
        }
        setmetatable(instance, { __index = Builder.IBuilder })
        instance.Build = function()
            return instance.coldDrinkClass:new()
        end
        instance.Kind = ColdDrinkClass.Kind
        self.instances[ColdDrinkClass.Kind] = instance
    end
    return self.instances[ColdDrinkClass.Kind]
end

-- 鸡肉套餐建造者
---@class ChickenMealBuilder : IMealBuilder
local ChickenMealBuilder = {}
---@return table<IBuilder>
setmetatable(ChickenMealBuilder, { __index = Builder.IMealBuilder })
function ChickenMealBuilder:GetBuilders()
    return {
        BurgerBuilder:GetInstance(Product.ChickenBurger),
        ColdDrinkBuilder:GetInstance(Product.PepsiCola)
    }
end
---@return IMealBuilder
function ChickenMealBuilder:GetInstance()
    if ChickenMealBuilder.Instance == nil then
        ChickenMealBuilder.Instance = {}
        setmetatable(ChickenMealBuilder.Instance, { __index = ChickenMealBuilder })
    end
    return ChickenMealBuilder.Instance
end

-- 素食套餐建造者
---@class VegMealBuilder : IMealBuilder
local VegMealBuilder = {}
setmetatable(VegMealBuilder, { __index = Builder.IMealBuilder })
---comment
---@return IMealBuilder
function VegMealBuilder:GetInstance()
    if VegMealBuilder.Instance == nil then
        VegMealBuilder.Instance = {}
        setmetatable(VegMealBuilder.Instance, { __index = VegMealBuilder })
    end
    return VegMealBuilder.Instance
end

---@return table<IBuilder>
function VegMealBuilder:GetBuilders()
    return {
        BurgerBuilder:GetInstance(Product.VegetableBurger),
        ColdDrinkBuilder:GetInstance(Product.CokeCola)
    }
end

---@class MealBuilder
local MealBuilder = {
    ---@type table<IBuilder>  
    builders = {},
    ---@type table<Item>
    items = {},
}
---@param builders table<IBuilder>
---@return MealBuilder
local function NewMealBuilder(builders)
    local mealBuilder = {}
    setmetatable(mealBuilder, { __index = MealBuilder })
    for _, builder in ipairs(builders) do
        table.insert(mealBuilder.builders, builder)
    end
    return mealBuilder
end

--- @param Kind ItemKind
function MealBuilder:Add(Kind)
    if Kind == Product.ItemKind.VegetableBurger then
        table.insert(self.builders, BurgerBuilder:GetInstance(Product.VegetableBurger))
    elseif Kind == Product.ItemKind.ChickenBurger then
        table.insert(self.builders, BurgerBuilder:GetInstance(Product.ChickenBurger))
    elseif Kind == Product.ItemKind.CokeCola then
        table.insert(self.builders, ColdDrinkBuilder:GetInstance(Product.CokeCola))
    elseif Kind == Product.ItemKind.PepsiCola then
        table.insert(self.builders, ColdDrinkBuilder:GetInstance(Product.PepsiCola))
    end
end

--- @param Kind ItemKind
function MealBuilder:Remove(Kind)
    for i, builder in ipairs(self.builders) do
        if builder.Kind == Kind then
            table.remove(self.builders, i)
            break
        end
    end
end

function MealBuilder:Build()
    for _, builder in ipairs(self.builders) do
        table.insert(self.items, builder:Build())
    end
end

function MealBuilder:Pack()
    for _, item in ipairs(self.items) do
        item.Packer:Pack(item)
    end
end

---@return number
function MealBuilder:GetCost()
    local cost = 0
    for _, item in ipairs(self.items) do
        cost = cost + item.Price
    end
    return cost
end

return {
    MealBuilder = MealBuilder,
    ChickenMealBuilder = ChickenMealBuilder,
    VegMealBuilder = VegMealBuilder,
    NewMealBuilder = NewMealBuilder,
}
