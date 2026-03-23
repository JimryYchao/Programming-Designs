-- 加载 Facade 模块
require("Facade")

-- 测试 Facade 模式
function testFacadePattern()
    -- 创建圆形
    local circle = BuildShape(ShapeType.CIRCLE, 10)
    if circle then
        circle:draw()
    end
    -- 创建矩形
    local rectangle = BuildShape(ShapeType.RECTANGLE, 10, 20)
    if rectangle then
        rectangle:draw()
    end
    -- 创建正方形
    local square = BuildShape(ShapeType.SQUARE, 10)
    if square then
        square:draw()
    end
end

-- 执行测试
testFacadePattern()

--- lua Client.lua