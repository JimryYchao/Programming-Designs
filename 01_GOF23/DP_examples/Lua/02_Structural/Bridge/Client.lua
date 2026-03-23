-- 加载 Abstraction 模块
require("Abstraction")

-- 测试 Bridge 模式
function testBridgePattern()
    local circle = Shape:new(Circle:new())
    circle:Draw(Color.green)

    local square = ShapeAdvance:new(Square:new(), function()
        print("Drew Completely")
    end)
    square:Draw(Color.blue)
end

-- 执行测试
testBridgePattern()
