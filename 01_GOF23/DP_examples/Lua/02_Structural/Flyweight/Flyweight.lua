-- 形状接口
---@class IShape
---@field draw fun()
---@field fill fun()
IShape = {}
function IShape:new(o)
    o = o or {}
    setmetatable(o, self)
    self.__index = self
    return o
end
function IShape:draw()
    error("Subclass must implement draw method")
end
function IShape:fill()
    error("Subclass must implement fill method")
end

-- 圆形数据
---@class CircleData
---@field color string
---@field radius number
CircleData = {}
---@param color string
---@param radius number
---@return CircleData
function CircleData:new(color, radius)
    local o = {}
    o.color = color
    o.radius = radius
    setmetatable(o, self)
    self.__index = self
    return o
end

-- 圆形实现
---@class Circle : IShape
---@field data CircleData
---@field x number
---@field y number
Circle = IShape:new()
---@param data CircleData
---@param x number
---@param y number
---@return Circle
function Circle:new(data, x, y)
    local o = IShape.new(self)
    o.data = data
    o.x = x
    o.y = y
    return o
end
function Circle:draw()
    print(string.format("Draw a Circle with radius %.2f at (%.2f, %.2f)", self.data.radius, self.x, self.y))
end
function Circle:fill()
    print(string.format("Fill with %s", self.data.color))
end

-- 圆形工厂
---@class CircleFactory
CircleFactory = {}
---@param data CircleData
---@param x number
---@param y number
---@return Circle
function CircleFactory:getCircleByData(data, x, y)
    return Circle:new(data, x, y)
end
---@param color string
---@param radius number
---@param x number
---@param y number
---@return Circle
function CircleFactory:getCircle(color, radius, x, y)
    local data = CircleData:new(color, radius)
    return Circle:new(data, x, y)
end
---@param circle Circle
---@return CircleAddition
function CircleFactory:getSpacialCircle(circle)
    return CircleAddition:new(circle)
end

