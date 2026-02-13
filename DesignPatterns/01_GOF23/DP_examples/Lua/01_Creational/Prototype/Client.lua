-- 加载形状缓存模块
require("ShapeCache")

-- 获取形状缓存实例
local cache = ShapeCache.GetInstance()

-- 克隆不同形状
local circle = cache:GetShape(ShapeKind.Circle)
if circle then
    circle:draw()
    circle:fill(Color.Red)
end

local square = cache:GetShape(ShapeKind.Square)
if square then
    square:draw()
    square:fill(Color.Green)
end

cache:RemovePrototype(ShapeKind.Rectangle)
local rectangle = cache:GetShape(ShapeKind.Rectangle)
if rectangle ~= nil then
    error("Rectangle should be nil after removal")
end
