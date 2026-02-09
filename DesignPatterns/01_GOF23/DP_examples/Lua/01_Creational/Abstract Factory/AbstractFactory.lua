-- AbstractFactory.lua
-- 抽象工厂

---@class AbstractFactory
local AbstractFactory = {
    getColor = function(self)
        error("子类必须实现 getColor 方法")
    end,
    getShape = function(self)
        error("子类必须实现 getShape 方法")
    end
}

return {
    AbstractFactory
}
