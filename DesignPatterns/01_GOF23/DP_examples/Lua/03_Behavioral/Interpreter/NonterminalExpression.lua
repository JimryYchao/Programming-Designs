-- 非终结符表达式 - 处理运算符
require("AbstractExpression")

OperationExpr = ArithmeticExpr:new()

function OperationExpr:new(exp1, exp2)
    local o = ArithmeticExpr:new()
    o.exp1 = exp1
    o.exp2 = exp2
    setmetatable(o, self)
    self.__index = self
    return o
end

-- 加法表达式
AdditionExpr = OperationExpr:new()

function AdditionExpr:new(exp1, exp2)
    local o = OperationExpr:new(exp1, exp2)
    setmetatable(o, self)
    self.__index = self
    return o
end

function AdditionExpr:interpret()
    return self.exp1:interpret() + self.exp2:interpret()
end

-- 减法表达式
SubtractionExpr = OperationExpr:new()

function SubtractionExpr:new(exp1, exp2)
    local o = OperationExpr:new(exp1, exp2)
    setmetatable(o, self)
    self.__index = self
    return o
end

function SubtractionExpr:interpret()
    return self.exp1:interpret() - self.exp2:interpret()
end

-- 乘法表达式
MultiplicationExpr = OperationExpr:new()

function MultiplicationExpr:new(exp1, exp2)
    local o = OperationExpr:new(exp1, exp2)
    setmetatable(o, self)
    self.__index = self
    return o
end

function MultiplicationExpr:interpret()
    return self.exp1:interpret() * self.exp2:interpret()
end

-- 除法表达式
DivisionExpr = OperationExpr:new()

function DivisionExpr:new(exp1, exp2)
    local o = OperationExpr:new(exp1, exp2)
    setmetatable(o, self)
    self.__index = self
    return o
end

function DivisionExpr:interpret()
    return self.exp1:interpret() / self.exp2:interpret()
end