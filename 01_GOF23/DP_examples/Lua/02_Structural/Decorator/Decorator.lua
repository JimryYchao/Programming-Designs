require("Component")

-- 装饰器基类
---@class Decorator : IShape
---@field shapeComponent IShape
Decorator = IShape:new()
function Decorator:new(o, shape)
    o = o or IShape:new()
    setmetatable(o, self)
    self.__index = self
    o.shapeComponent = shape
    return o
end
function Decorator:Draw()
    if self.shapeComponent then
        self.shapeComponent:Draw()
    end
end
function Decorator:Fill(color)
    if self.shapeComponent then
        self.shapeComponent:Fill(color)
    end
end

---- 具体装饰器
---@class ShapeDecorator : Decorator
ShapeDecorator = Decorator:new()
function ShapeDecorator:new(o, shape)
    o = o or Decorator:new(nil, shape)
    setmetatable(o, self)
    self.__index = self
    return o
end

---@param self ShapeDecorator
local function BeforeDraw(self)
    print("Before Draw() >> Do...")
end

---@param self ShapeDecorator
local function AfterDraw(self)
    print("When Draw Complete >> Do...")
end

---@param self ShapeDecorator
local function BeforeFill(self)
    print("Before Fill() >> Do...")
end

---@param self ShapeDecorator
local function AfterFill(self)
    print("When Fill Complete >> Do...")
end

function ShapeDecorator:Draw()
    BeforeDraw(self)
    Decorator.Draw(self)
    AfterDraw(self)
end

function ShapeDecorator:Fill(color)
    BeforeFill(self)
    Decorator.Fill(self, color)
    AfterFill(self)
end
