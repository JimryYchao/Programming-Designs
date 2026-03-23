require("Component")

---@param color Color
---@return string
local function color_to_string(color)
    if color == Color.red then
        return "red"
    elseif color == Color.green then
        return "green"
    elseif color == Color.blue then
        return "blue"
    end
    return "unknown"
end

-- 圆形
---@class Circle : IShape
Circle = IShape:new()
---@param o table
---@return Circle
function Circle:new(o)
    o = o or IShape:new()
    setmetatable(o, self)
    self.__index = self
    return o
end
function Circle:Draw()
    print("Draw a Circle.")
end

function Circle:Fill(color)
    print("Fill with " .. color_to_string(color) .. ".")
end

-- 矩形
---@class Rectangle : IShape
Rectangle = IShape:new()
---@param o table
---@return Rectangle
function Rectangle:new(o)
    o = o or IShape:new()
    setmetatable(o, self)
    self.__index = self
    return o
end
function Rectangle:Draw()
    print("Draw a Rectangle.")
end
function Rectangle:Fill(color)
    print("Fill with " .. color_to_string(color) .. ".")
end
