-- Director.lua
-- 指挥者

local Builder = require("ConcreteBuilder")
local Product = require("Product")

--- 构造套餐
---@param mealBuilder IMealBuilder
---@return MealBuilder
local function Construct(mealBuilder)
    local builders = mealBuilder:GetBuilders()
    return Builder.NewMealBuilder(builders)
end
return {
    Construct = Construct,
    VegMealBuilder = Builder.VegMealBuilder,
    BurgerBuilder = Builder.BurgerBuilder,  
    ItemKind = Product.ItemKind
}
