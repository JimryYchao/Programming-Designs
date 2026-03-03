-- 访问者接口
local IComputerPartVisitor = {}

function IComputerPartVisitor:new(o)
    o = o or {}
    setmetatable(o, self)
    self.__index = self
    return o
end

function IComputerPartVisitor:visitComputer(computer)
    error("Subclass must implement visitComputer method")
end

function IComputerPartVisitor:visitMouse(mouse)
    error("Subclass must implement visitMouse method")
end

function IComputerPartVisitor:visitKeyboard(keyboard)
    error("Subclass must implement visitKeyboard method")
end

function IComputerPartVisitor:visitMonitor(monitor)
    error("Subclass must implement visitMonitor method")
end

return IComputerPartVisitor
