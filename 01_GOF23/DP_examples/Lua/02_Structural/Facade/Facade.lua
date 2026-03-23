-- 加载 Subsystem 模块
require("Subsystem")

-- 形状类型枚举
---@enum ShapeType
ShapeType = {
    CIRCLE = 0,
    RECTANGLE = 1,
    SQUARE = 2
}

-- 形状创建者（外观类）
---@param shapeType ShapeType
---@param ... number[]
---@return IShape
function BuildShape(shapeType, ...)
    local args = {...}
    if shapeType == ShapeType.CIRCLE then
        if #args >= 1 then
            return Circle:new(args[1])
        end
    elseif shapeType == ShapeType.RECTANGLE then
        if #args >= 2 then
            return Rectangle:new(args[1], args[2])
        end
    elseif shapeType == ShapeType.SQUARE then
        if #args >= 1 then
            return Square:new(args[1])
        end
    end
    return nil
end
