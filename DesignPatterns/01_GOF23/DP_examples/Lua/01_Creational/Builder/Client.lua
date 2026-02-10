-- Client.lua

local Director = require("Director")

local function BuilderDemo()
    -- 素食套餐
    local meal = Director.Construct(Director.VegMealBuilder:GetInstance())
    meal:Remove(Director.ItemKind.VegetableBurger)
    meal:Add(Director.ItemKind.ChickenBurger)

    meal:Build()
    meal:Pack()
    print("Total Cost: " .. meal:GetCost())
end

-- 运行示例
BuilderDemo()
