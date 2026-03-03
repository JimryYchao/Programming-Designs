-- 元素接口
local IComputerPart = {}

function IComputerPart:new(o)
    o = o or {}
    setmetatable(o, self)
    self.__index = self
    return o
end

function IComputerPart:accept(visitor)
    error("Subclass must implement accept method")
end

-- 具体元素：Keyboard
local Keyboard = IComputerPart:new()

function Keyboard:new(o)
    o = o or IComputerPart:new(o)
    setmetatable(o, self)
    self.__index = self
    return o
end

function Keyboard:accept(visitor)
    visitor:visitKeyboard(self)
end

function Keyboard:operation()
    print("Using Keyboard")
end

-- 具体元素：Monitor
local Monitor = IComputerPart:new()

function Monitor:new(o)
    o = o or IComputerPart:new(o)
    setmetatable(o, self)
    self.__index = self
    return o
end

function Monitor:accept(visitor)
    visitor:visitMonitor(self)
end

function Monitor:operation()
    print("Using Monitor")
end

-- 具体元素：Mouse
local Mouse = IComputerPart:new()

function Mouse:new(o)
    o = o or IComputerPart:new(o)
    setmetatable(o, self)
    self.__index = self
    return o
end

function Mouse:accept(visitor)
    visitor:visitMouse(self)
end

function Mouse:operation()
    print("Using Mouse")
end

-- 具体元素：Computer (ObjectStructure)
local Computer = IComputerPart:new()

function Computer:new(o)
    o = o or IComputerPart:new(o)
    o.parts = {
        Keyboard:new(),
        Mouse:new(),
        Monitor:new()
    }
    setmetatable(o, self)
    self.__index = self
    return o
end

function Computer:accept(visitor)
    for _, part in ipairs(self.parts) do
        part:accept(visitor)
    end
    visitor:visitComputer(self)
end

return {"IComputerPart", IComputerPart, "Keyboard", Keyboard, "Monitor", Monitor, "Mouse", Mouse, "Computer", Computer}
