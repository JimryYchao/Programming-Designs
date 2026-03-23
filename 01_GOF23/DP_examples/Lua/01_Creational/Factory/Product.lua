-- 产品类型枚举

---@enum ShapeKind
ShapeKind = {
    UNKNOWN_SHAPE = 0,
    CIRCLE = 1,
    SQUARE = 2,
    RECTANGLE = 3,
    BIG_CIRCLE = 4
}

-- 产品接口
---@class IShape
IShape = {
    draw = function(self)
        error("Subclass must implement draw method")
    end,
    fill = function(self)
        error("Subclass must implement fill method")
    end
}

-- 创建产品对象的函数
---@return IShape
function IShape:new()
    local o = {}
    setmetatable(o, {__index = self})
    return o
end

-- 圆形产品
---@class Circle : IShape
Circle = IShape:new()
function Circle:draw()
    print("Draw a Circle")
end
function Circle:fill()
    print("Fill red")
end

-- 正方形产品
---@class Square : IShape
Square = IShape:new()
function Square:draw()
    print("Draw a Square")
end
function Square:fill()
    print("Fill Green")
end

-- 矩形产品
---@class Rectangle : IShape
Rectangle = IShape:new()
function Rectangle:draw()
    print("Draw a Rectangle")
end
function Rectangle:fill()
    print("Fill Blue")
end

-- 未知形状产品
---@class UnknownShape : IShape
UnknownShape = IShape:new()
function UnknownShape:draw()
    -- 空实现
end
function UnknownShape:fill()
    -- 空实现
end
