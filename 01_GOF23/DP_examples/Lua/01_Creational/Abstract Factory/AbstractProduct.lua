-- AbstractProduct.lua
-- 产品接口

---@class IColor
local IColor = {
    Fill = function(self)
        error("子类必须实现 fill 方法")
    end
}

---@class Red : IColor
local Red = {}
setmetatable(Red, { __index = IColor })
function Red:new()
    local obj = {}
    setmetatable(obj, { __index = Red })
    return obj
end
function Red:Fill()
    print("Fill Red")
end

---@class Green : IColor
local Green = {}
setmetatable(Green, { __index = IColor })
function Green:new()
    local obj = {}
    setmetatable(obj, { __index = Green })
    return obj
end
function Green:Fill()
    print("Fill Green")
end

---@class Blue : IColor
local Blue = {}
setmetatable(Blue, { __index = IColor })
function Blue:new()
    local obj = {}
    setmetatable(obj, { __index = Blue })
    return obj
end
function Blue:Fill()
    print("Fill Blue")
end

-- 具体产品 - 形状

---@class IShape
local IShape = {
    Draw = function(self)
        error("子类必须实现 draw 方法")
    end
}

---@class Circle : IShape
local Circle = {}
setmetatable(Circle, { __index = IShape })
function Circle:new()
    local obj = {}
    setmetatable(obj, { __index = Circle })
    return obj
end
function Circle:Draw()
    print("Draw a Circle")
end

---@class Square : IShape
local Square = {}
setmetatable(Square, { __index = IShape })
function Square:new()
    local obj = {}
    setmetatable(obj, { __index = Square })
    return obj
end
function Square:Draw()
    print("Draw a Square")
end

---@class Rectangle : IShape
local Rectangle = {}
setmetatable(Rectangle, { __index = IShape })
function Rectangle:new()
    local obj = {}
    setmetatable(obj, { __index = Rectangle })
    return obj
end
function Rectangle:Draw()
    print("Draw a Rectangle")
end

---@class UnknownColor : IColor
local UnknownColor = {}
setmetatable(UnknownColor, { __index = IColor })
function UnknownColor:new()
    local obj = {}
    setmetatable(obj, { __index = UnknownColor })
    return obj
end
function UnknownColor:Fill() end

---@class UnknownShape : IShape
local UnknownShape = {}
setmetatable(UnknownShape, { __index = IShape })
function UnknownShape:new()
    local obj = {}
    setmetatable(obj, { __index = UnknownShape })
    return obj
end
function UnknownShape:Draw() end

return {
    IColor = IColor,
    Red = Red,
    Green = Green,
    Blue = Blue,
    IShape = IShape,
    Circle = Circle,
    Square = Square,
    Rectangle = Rectangle,
    UnknownColor = UnknownColor,
    UnknownShape = UnknownShape
}
