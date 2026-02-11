-- 导入产品模块
require("Product")

-- 创建者接口
---@class ICreator
ICreator = {
    ---@return IShape
    getShape = function(self)
        error("Subclass must implement getShape method")
    end
}

-- 创建创建者对象的函数
---@return ICreator
function ICreator:new()
    local o = {}
    setmetatable(o, {__index = self})
    -- self.__index = self
    return o
end

-- 未知形状创建者
---@class UnknownShapeCreator : ICreator
UnknownShapeCreator = ICreator:new()
---@return IShape
function UnknownShapeCreator:getShape()
    return UnknownShape:new()
end

-- 圆形创建者
---@class CircleCreator : ICreator
CircleCreator = ICreator:new()
---@return IShape
function CircleCreator:getShape()
    return Circle:new()
end

-- 正方形创建者
---@class SquareCreator : ICreator
SquareCreator = ICreator:new()
---@return IShape
function SquareCreator:getShape()
    return Square:new()
end

-- 矩形创建者
---@class RectangleCreator : ICreator
RectangleCreator = ICreator:new()
---@return IShape
function RectangleCreator:getShape()
    return Rectangle:new()
end

-- 大圆形创建者
---@class BigCircleCreator : CircleCreator
BigCircleCreator = CircleCreator:new()
function BigCircleCreator:setRadius()
    print("Set Radius to 10")
end
function BigCircleCreator:getShape()
    self:setRadius()
    return CircleCreator.getShape(self)
end