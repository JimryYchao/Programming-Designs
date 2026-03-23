local IComputerPartVisitor = require("Visitor")

-- 具体访问者：ComputerPartDisplayVisitor
local ComputerPartDisplayVisitor = IComputerPartVisitor:new()

function ComputerPartDisplayVisitor:new(o)
    o = o or IComputerPartVisitor:new(o)
    setmetatable(o, self)
    self.__index = self
    return o
end

function ComputerPartDisplayVisitor:visitComputer(computer)
    print("Displaying Computer")
end

function ComputerPartDisplayVisitor:visitMouse(mouse)
    print("Displaying Mouse")
    mouse:operation()
end

function ComputerPartDisplayVisitor:visitKeyboard(keyboard)
    print("Displaying Keyboard")
    keyboard:operation()
end

function ComputerPartDisplayVisitor:visitMonitor(monitor)
    print("Displaying Monitor")
    monitor:operation()
end

return ComputerPartDisplayVisitor
