-- ConcreteFactory.lua
-- 具体工厂和工厂生产者

local AbstractFactory = require("AbstractFactory")
local products = require("AbstractProduct")

---@class ProductFactory : AbstractFactory
local ProductFactory = {}
setmetatable(ProductFactory, { __index = AbstractFactory })
function ProductFactory:new(colorType, shapeType)
    local obj = {
        color = colorType,
        shape = shapeType
    }
    setmetatable(obj, { __index = ProductFactory })
    return obj
end
function ProductFactory:getColor()
    return self.color:new()
end
function ProductFactory:getShape()
    return self.shape:new()
end

-- 工厂生产者
---@enum ProductKind
local ProductKind = {
    RedCircle = 1,
    GreenSquare = 2,
    BlueRectangle = 3
}

---@class FactoryProducer
local FactoryProducer = {
    factories = {}
}
---@param kind ProductKind
function FactoryProducer:createFactory(kind)
    if kind == ProductKind.RedCircle then
        return ProductFactory:new(products.Red, products.Circle)
    elseif kind == ProductKind.GreenSquare then
        return ProductFactory:new(products.Green, products.Square)
    elseif kind == ProductKind.BlueRectangle then
        return ProductFactory:new(products.Blue, products.Rectangle)
    else
        return ProductFactory:new(products.UnknownColor, products.UnknownShape) -- 默认
    end
end

function FactoryProducer:getFactory(kind)
    if not self.factories[kind] then
        self.factories[kind] = self:createFactory(kind)
    end
    return self.factories[kind]
end

return {
    ProductFactory = ProductFactory,
    ProductKind = ProductKind,
    FactoryProducer = FactoryProducer
}
