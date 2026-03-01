-- 上下文类
local Context = {}

function Context:new(strategy)
    local o = {}
    setmetatable(o, self)
    self.__index = self
    o.strategy = strategy
    return o
end

function Context:setStrategy(strategy)
    self.strategy = strategy
end

function Context:sort(array)
    self.strategy:sort(array)
end

return Context
