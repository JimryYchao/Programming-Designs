-- 饮料制作抽象类
local BeverageMaker = {}

function BeverageMaker:new(o)
    o = o or {}
    setmetatable(o, self)
    self.__index = self
    return o
end

-- 模板方法：制作饮料的流程
function BeverageMaker:makeBeverage()
    self:boilWater()
    self:brew()
    self:pourInCup()
    if self:customerWantsCondiments() then
        self:addCondiments()
    end
end

-- 具体方法：烧水
function BeverageMaker:boilWater()
    print("Boiling water")
end

-- 具体方法：倒入杯子
function BeverageMaker:pourInCup()
    print("Pouring into cup")
end

-- 抽象方法：冲泡
function BeverageMaker:brew()
    -- 子类实现
end

-- 抽象方法：添加调料
function BeverageMaker:addCondiments()
    -- 子类实现
end

-- 钩子方法：顾客是否需要调料
function BeverageMaker:customerWantsCondiments()
    return true
end

return BeverageMaker
