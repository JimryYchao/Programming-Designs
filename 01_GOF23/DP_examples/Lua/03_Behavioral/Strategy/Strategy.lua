-- 策略接口
local IStrategy = {}

function IStrategy:new(o)
    o = o or {}
    setmetatable(o, self)
    self.__index = self
    return o
end

function IStrategy:sort(array)
    -- 子类实现
end

return IStrategy
