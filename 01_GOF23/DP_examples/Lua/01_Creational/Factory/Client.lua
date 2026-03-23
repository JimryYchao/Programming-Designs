require("ConcreteCreator")

-- 工厂模式演示
function example()
    -- 测试圆形
    local circle = ShapeFactory:GetShape(ShapeKind.CIRCLE)
    circle:draw()
    circle:fill()
    
    -- 测试大圆形
    local bigCircle = ShapeFactory:GetShape(ShapeKind.BIG_CIRCLE)
    bigCircle:draw()
    bigCircle:fill()
    
    -- 测试正方形
    local square = ShapeFactory:GetShape(ShapeKind.SQUARE)
    square:draw()
    square:fill()
end

-- 运行示例
example()
