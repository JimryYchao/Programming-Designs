require("Implementor")

---@class Shape
---@field draw DrawAPI
Shape = {}
---@param draw DrawAPI
---@return Shape
function Shape:new(draw)
    local o = { draw = draw }
    setmetatable(o, self)
    self.__index = self
    return o
end
---@param color Color
function Shape:Draw(color)
    self.draw:Draw()
    self.draw:Fill(color)
end

---@class ShapeAdvance : Shape
---@field onDrawCompleted fun()
ShapeAdvance = Shape:new()
function ShapeAdvance:new(draw, onDrawCompleted)
    local o = Shape:new(draw)
    o.onDrawCompleted = onDrawCompleted
    setmetatable(o, self)
    self.__index = self
    return o
end
---@param color Color
function ShapeAdvance:Draw(color)
    Shape.Draw(self, color)
    if self.onDrawCompleted then
        self.onDrawCompleted()
    end
end
