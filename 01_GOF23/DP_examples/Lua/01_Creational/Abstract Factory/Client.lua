-- Client.lua
-- 客户端代码

local factories = require("ConcreteFactory")

-- 客户端代码
---@param ab AbstractFactory
local function drawShape(ab)
    local shape = ab:getShape()
    local color = ab:getColor()
    shape:Draw()
    color:Fill()
end

-- 示例
local function AbstractFactoryDemo()
    local factoryProducer = factories.FactoryProducer
    local ProductKind = factories.ProductKind
    
    local redCircleF = factoryProducer:getFactory(ProductKind.RedCircle)
    drawShape(redCircleF)
    local blueRectangleF = factoryProducer:getFactory(ProductKind.BlueRectangle)
    drawShape(blueRectangleF)
end

AbstractFactoryDemo()
