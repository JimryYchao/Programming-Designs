require("Component")
require("ConcreteComponent")
require("Decorator")

-- 创建红色圆形
local redCircle = Decorator:new(nil, Circle:new())
redCircle:Draw()
redCircle:Fill(Color.red)

-- 创建绿色矩形
local greenRectangle = ShapeDecorator:new(nil, Rectangle:new())
greenRectangle:Draw()
greenRectangle:Fill(Color.green)

--- lua Client.lua