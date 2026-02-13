-- 加载产品模块
require("Product")

-- 形状缓存
---@class ShapeCache
ShapeCache = {
    shapeMap = {}
}
---@param Cache ShapeCache
local function loadCache(Cache)
    Cache:RegisterPrototype(ShapeKind.Circle, Circle:new())
    Cache:RegisterPrototype(ShapeKind.Square, Square:new())
    Cache:RegisterPrototype(ShapeKind.Rectangle, Rectangle:new())
end

local instance = nil
function ShapeCache.GetInstance()
    if instance == nil then
        instance = {}
        setmetatable(instance, { __index = ShapeCache })
        loadCache(instance)
    end
    return instance
end

---@param key ShapeKind
---@param shape Shape
function ShapeCache:RegisterPrototype(key, shape)
    if (self.shapeMap[key] == nil) then
        self.shapeMap[key] = shape
    end
end

---@param key ShapeKind
function ShapeCache:RemovePrototype(key)
    self.shapeMap[key] = nil
end

---@param key ShapeKind
---@return Shape|nil
function ShapeCache:GetShape(key)
    local shape = self.shapeMap[key]
    if shape then
        return shape:clone()
    end
    return nil
end
