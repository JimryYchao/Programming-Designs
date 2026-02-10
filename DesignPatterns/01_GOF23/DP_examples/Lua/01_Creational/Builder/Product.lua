-- Product.lua
-- 产品和包装实现

local Builder = require("Builder")

-- 包装器
---@class Wrapper : IPacker
local Wrapper = {}
setmetatable(Wrapper, { __index = Builder.IPacker })
---@return IPacker
function Wrapper:GetInstance()
    if self.Instance == nil then
        self.Instance = {}
        setmetatable(self.Instance, { __index = Wrapper })
    end
    return self.Instance
end

---@param item Burger
function Wrapper:Pack(item)
    print("Wrapper a " .. item.Name)
end

---@class Bottle : IPacker
local Bottle = {}
setmetatable(Bottle, { __index = Builder.IPacker })
---@return IPacker
function Bottle:GetInstance()
    if self.Instance == nil then
        self.Instance = {}
        setmetatable(self.Instance, { __index = Bottle })
    end
    return self.Instance
end

---@param item ColdDrink
function Bottle:Pack(item)
    print("Bottle a " .. item.Name)
end

-- Item 实现
---@enum ItemKind
local ItemKind = {
    VegetableBurger = 1,
    ChickenBurger = 2,
    CokeCola = 3,
    PepsiCola = 4,
}

---@class Burger : Item
local Burger   = {
    ---@type ItemKind
    Kind = nil
}
setmetatable(Burger, { __index = Builder.Item })
function Burger:new()
    error("子类必须实现 new 方法")
end

---@class ColdDrink : Item
local ColdDrink = {
    ---@type ItemKind
    Kind = nil
}
setmetatable(ColdDrink, { __index = Builder.Item })
function ColdDrink:new()
    error("子类必须实现 new 方法")
end

---@class VegetableBurger : Burger
local VegetableBurger = {
    Name = "VegetableBurger",
    Price = 8.5,
    Kind = ItemKind.VegetableBurger,
    Packer = Wrapper:GetInstance(),
}
setmetatable(VegetableBurger, { __index = Burger })
function VegetableBurger:new()
    local vegetableBurger = {}
    setmetatable(vegetableBurger, { __index = VegetableBurger })
    return vegetableBurger
end

---@class ChickenBurger : Burger
local ChickenBurger = {
    Name = "ChickenBurger",
    Price = 15.0,
    Kind = ItemKind.ChickenBurger,
    Packer = Wrapper:GetInstance(),
}
setmetatable(ChickenBurger, { __index = Burger })
function ChickenBurger:new()
    local chickenBurger = {}
    setmetatable(chickenBurger, { __index = ChickenBurger })
    return chickenBurger
end

---@class CokeCola : ColdDrink
local CokeCola = {
    Name = "CokeCola",
    Price = 3.5,
    Kind = ItemKind.CokeCola,
    Packer = Bottle:GetInstance(),
}
setmetatable(CokeCola, { __index = ColdDrink })
function CokeCola:new()
    local cokeCola = {}
    setmetatable(cokeCola, { __index = CokeCola })
    return cokeCola
end

---@class PepsiCola : ColdDrink
local PepsiCola = {
    Name = "PepsiCola",
    Price = 3.0,
    Kind = ItemKind.PepsiCola,
    Packer = Bottle:GetInstance(),
}
setmetatable(PepsiCola, { __index = ColdDrink })
function PepsiCola:new()
    local pepsiCola = {}
    setmetatable(pepsiCola, { __index = PepsiCola })
    return pepsiCola
end

return {
    Wrapper = Wrapper,
    Bottle = Bottle,
    Burger = Burger,
    ColdDrink = ColdDrink,
    VegetableBurger = VegetableBurger,
    ChickenBurger = ChickenBurger,
    CokeCola = CokeCola,
    PepsiCola = PepsiCola,
    ItemKind = ItemKind,
}
