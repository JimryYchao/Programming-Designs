-- 具体饮料实现
local BeverageMaker = require("AbstractClass")

-- 咖啡制作类
local CoffeeMaker = BeverageMaker:new()

function CoffeeMaker:brew()
    print("Brewing coffee grounds")
end

function CoffeeMaker:addCondiments()
    print("Adding sugar and milk")
end

function CoffeeMaker:customerWantsCondiments()
    print("Customer wants sugar and milk")
    return true
end

-- 茶制作类
local TeaMaker = BeverageMaker:new()

function TeaMaker:brew()
    print("Steeping the tea bag")
end

function TeaMaker:addCondiments()
    print("Adding lemon")
end

function TeaMaker:customerWantsCondiments()
    print("Customer wants lemon")
    return true
end

return {
    CoffeeMaker = CoffeeMaker,
    TeaMaker = TeaMaker
}
