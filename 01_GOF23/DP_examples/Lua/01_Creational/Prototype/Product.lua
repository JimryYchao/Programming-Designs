-- 颜色枚举
---@enum Color
Color = {
    Unknown = 0,
    Red = 1,
    Green = 2,
    Blue = 3,
    Yellow = 4
}

-- 颜色转换为字符串
---@param color Color
---@return string
local function ColorToString(color)
    local colorMap = {
        [Color.Red] = "Red",
        [Color.Green] = "Green",
        [Color.Blue] = "Blue",
        [Color.Yellow] = "Yellow"
    }
    return colorMap[color] or "Unknown"
end

-- 形状接口
IShape = {
    id = 0,
    name = ""
}
function IShape:new(o)
    o = o or {}
    setmetatable(o, self)
    self.__index = self
    return o
end

function IShape:name()
    return self.name
end

function IShape:draw() end

function IShape:fill(color) end

function IShape:clone() end

-- 形状基类
---@class Shape : IShape
Shape = IShape:new()
function Shape:new(o)
    o = o or {}
    setmetatable(o, self)
    self.__index = self
    return o
end

-- 形状类型枚举
ShapeKind = {
    Unknown = 0,
    Circle = 1,
    Square = 2,
    Rectangle = 3
}

-- 圆形
---@class Circle : Shape
Circle = Shape:new()
function Circle:new(o)
    o = o or {}
    o.id = o.id or ShapeKind.Circle
    o.name = o.name or "Circle"
    setmetatable(o, self)
    self.__index = self
    return o
end

function Circle:draw()
    print("Draw a Circle")
end

function Circle:fill(color)
    print("Fill with " .. ColorToString(color))
end

function Circle:clone()
    return Circle:new({ id = self.id, name = self.name })
end

-- 正方形
---@class Square : Shape
Square = Shape:new()
function Square:new(o)
    o = o or {}
    o.id = o.id or ShapeKind.Square
    o.name = o.name or "Square"
    setmetatable(o, self)
    self.__index = self
    return o
end

function Square:draw()
    print("Draw a Square")
end

function Square:fill(color)
    print("Fill with " .. ColorToString(color))
end

function Square:clone()
    return Square:new({ id = self.id, name = self.name })
end

-- 矩形
---@class Rectangle : Shape
Rectangle = Shape:new()
function Rectangle:new(o)
    o = o or {}
    o.id = o.id or ShapeKind.Rectangle
    o.name = o.name or "Rectangle"
    setmetatable(o, self)
    self.__index = self
    return o
end

function Rectangle:draw()
    print("Draw a Rectangle")
end

function Rectangle:fill(color)
    print("Fill with " .. ColorToString(color))
end

function Rectangle:clone()
    return Rectangle:new({ id = self.id, name = self.name })
end
