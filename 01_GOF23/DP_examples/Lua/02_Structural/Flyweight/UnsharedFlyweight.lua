-- 加载 Flyweight 模块
require("Flyweight")

-- 非共享具体享元类 - 圆形增强
---@class CircleAddition : IShape
---@field shape Circle
CircleAddition = IShape:new()
---@param shape Circle
function CircleAddition:new(shape)
    local o = IShape.new(self)
    o.shape = shape
    return o
end
function CircleAddition:draw()
    self.shape:draw()
end
function CircleAddition:fill()
    self.shape:fill()
end

-- 移动位置
function CircleAddition:movePosition(x, y)
    print(string.format("Move Circle to (%.2f, %.2f)", x, y))
end

-- 重置半径
function CircleAddition:resetRadius(radius)
    print(string.format("Reset Radius to %.2f", radius))
end
