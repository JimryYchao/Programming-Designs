-- 命令模式的 Lua 实现

-- 命令接口
local ICommand = {
    execute = function(self)
        error("Subclass must implement execute method")
    end
}

-- 创建命令对象的元表
function ICommand:new(o)
    o = o or {}
    setmetatable(o, self)
    self.__index = self
    return o
end

-- 具体命令实现
local ConcreteCommand = ICommand:new()

function ConcreteCommand:new(receiver)
    local o = ICommand:new()
    setmetatable(o, self)
    self.__index = self
    o.receiver = receiver
    return o
end

function ConcreteCommand:execute()
    if self.receiver then
        self.receiver:action()
    end
end

-- 导出模块
return {
    ICommand = ICommand,
    ConcreteCommand = ConcreteCommand
}
