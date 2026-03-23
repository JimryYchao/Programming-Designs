-- 加载 FlyweightFactory 模块
require("FlyweightFactory")

-- 构建圆形
function buildCircles()
    -- 创建红色圆形
    local redCircle = FlyweightFactory:getCircle("Red", 10, 0, 0)
    if redCircle then
        redCircle:draw()
        redCircle:fill()
    end
    
    -- 创建特殊绿色大圆形
    local greenBigCircle = FlyweightFactory:getSpecialCircle("Green", 100, 100, 100)
    if greenBigCircle then
        greenBigCircle:draw()
        greenBigCircle:fill()
        greenBigCircle:resetRadius(10)
        greenBigCircle:movePosition(0, 0)
    end
end

-- 构建享元圆形
function buildFlyweightCircle()
    -- 创建红色圆形（复用之前的 CircleData）
    local redCircle = FlyweightFactory:getCircle("Red", 10, 10086, 10010)
    if redCircle then
        redCircle:draw()
        redCircle:fill()
    end
end

-- 测试 Flyweight 模式
function testFlyweightPattern()
    buildCircles()
    buildFlyweightCircle()
end

-- 执行测试
testFlyweightPattern()

--- lua Client.lua