---@enum Color
Color = {
    unknown = 0,
    red = 1,
    green = 2,
    blue = 3
}
---@param color Color
---@return string
local function ColorToString(color)
    if color == Color.red then
        return "red"
    elseif color == Color.green then
        return "green"
    elseif color == Color.blue then
        return "blue"
    else
        return "unknown"
    end
end

---@class DrawAPI
DrawAPI = {}
function DrawAPI:Draw()
    error("Subclass must implement draw method")
end
---@param color Color
function DrawAPI:Fill(color)
    print("Fill with " .. ColorToString(color))
end

-- 创建 DrawAPI 实例
---@return DrawAPI
function DrawAPI:new(o)
    o = o or {}
    setmetatable(o, self)
    self.__index = self
    return o
end

---@class Circle : DrawAPI
Circle = DrawAPI:new()
function Circle:Draw()
    print("Draw a Circle")
end

---@class Square : DrawAPI
Square = DrawAPI:new()
function Square:Draw()
    print("Draw a Square")
end

---@class Rectangle : DrawAPI
Rectangle = DrawAPI:new()
function Rectangle:Draw()
    print("Draw a Rectangle")
end

---@class BigCircle : Circle
BigCircle = Circle:new()
function BigCircle:Draw()
    print("Draw a Big Circle")
end
