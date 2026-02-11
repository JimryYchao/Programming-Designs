
local creators = require("Creator")
-- 形状工厂
---@class ShapeFactory
ShapeFactory = {}

---@type table<ShapeKind, ICreator>
local factories = {}
-- 根据类型获取创建者
---@param kind ShapeKind
---@return ICreator
local function getFactory(kind)
    if not factories[kind] then
        if kind == ShapeKind.CIRCLE then
           factories[kind] = CircleCreator:new()
        elseif kind == ShapeKind.SQUARE then
           factories[kind] = SquareCreator:new()
        elseif kind == ShapeKind.RECTANGLE then
           factories[kind] = RectangleCreator:new()
        elseif kind == ShapeKind.BIG_CIRCLE then
           factories[kind] = BigCircleCreator:new()
        else
           factories[kind] = UnknownShapeCreator:new()
        end
    end
    return factories[kind]
end

---@param kind ShapeKind
---@return IShape
function ShapeFactory:GetShape(kind)
    local creator = getFactory(kind)
    return creator:getShape()
end


