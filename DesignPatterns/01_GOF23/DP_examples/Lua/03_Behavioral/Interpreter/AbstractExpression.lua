-- 抽象表达式接口
ArithmeticExpr = {}

function ArithmeticExpr:new(o)
    o = o or {}
    setmetatable(o, self)
    self.__index = self
    return o
end

function ArithmeticExpr:interpret()
    error("Subclass must implement interpret method")
end