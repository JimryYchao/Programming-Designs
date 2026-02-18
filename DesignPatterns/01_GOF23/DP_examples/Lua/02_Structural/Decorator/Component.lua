-- 颜色枚举
Color = {
    unknown = 0,
    red = 1,
    green = 2,
    blue = 3
}

-- 组件接口
---@class IShape
---@field Draw fun()
---@field Fill fun(color: Color)
IShape = {}

---@param o table
---@return IShape
function IShape:new(o)
    o = o or {}
    setmetatable(o, self)
    self.__index = self
    return o
end


function IShape:Draw()
    error("Subclass must implement Draw method")
end

---@param color Color
function IShape:Fill(color)
    error("Subclass must implement Fill method")
end
