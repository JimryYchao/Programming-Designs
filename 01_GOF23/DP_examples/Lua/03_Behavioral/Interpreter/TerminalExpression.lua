-- 终结符表达式 - 处理数字
require("AbstractExpression")

NumberExpr = ArithmeticExpr:new()

function NumberExpr:new(num)
    local o = ArithmeticExpr:new()
    o.num = num
    setmetatable(o, self)
    self.__index = self
    return o
end

function NumberExpr:interpret()
    return self.num
end