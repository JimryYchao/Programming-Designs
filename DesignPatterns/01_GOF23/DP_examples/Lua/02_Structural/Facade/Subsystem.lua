-- 形状接口
---@class IShape
---@field draw fun()
---@field new fun(o?: table)
IShape = {}
function IShape:draw()
    error("Subclass must implement draw method")
end
function IShape:new(o)
    o = o or {}
    setmetatable(o, self)
    self.__index = self
    return o
end

-- 圆形实现
---@class Circle : IShape
---@field radius number
Circle = IShape:new()
function Circle:new(radius)
    local o = IShape.new(self)
    o.radius = radius
    return o
end
function Circle:draw()
    print(string.format("Draw a circle with radius %d", self.radius))
end

-- 矩形实现
---@class Rectangle : IShape
---@field width number
---@field height number
Rectangle = IShape:new()
function Rectangle:new(width, height)
    local o = IShape.new(self)
    o.width = width
    o.height = height
    return o
end
function Rectangle:draw()
    print(string.format("Draw a rectangle with width %d and height %d", self.width, self.height))
end

-- 正方形实现
---@class Square : IShape
---@field side number
Square = IShape:new()
function Square:new(side)
    local o = IShape.new(self)
    o.side = side
    return o
end
function Square:draw()
    print(string.format("Draw a square with side %d", self.side))
end
