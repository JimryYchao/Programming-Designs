-- 客户端代码
local classes = require("ConcreteClass")

-- 制作咖啡
print("Making coffee:")
local coffee = classes.CoffeeMaker:new()
coffee:makeBeverage()
print()

-- 制作茶
print("Making tea:")
local tea = classes.TeaMaker:new()
tea:makeBeverage()
