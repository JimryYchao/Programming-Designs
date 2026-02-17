-- 加载 ConcreteComposite 模块
require("ConcreteComposite")

-- 构建团队
function BuildATeam()
    -- 创建老板
    local boss = Employee:new(false)
    boss:init("Tom", "man", 45, 50000)

    -- 创建主管
    local chargeA = Employee:new(false)
    chargeA:init("Lily", "woman", 25, 12000)

    local chargeB = Employee:new(false)
    chargeB:init("Jerry", "man", 27, 11000)

    -- 创建基础员工
    local baseA = Employee:new(true)
    baseA:init("Lee", "woman", 21, 8000)

    local baseB = Employee:new(true)
    baseB:init("Ychao", "man", 21, 7500)

    local baseC = Employee:new(true)
    baseC:init("Tomas", "man", 22, 7000)

    local baseD = Employee:new(true)
    baseD:init("Jimmy", "man", 23, 8200)

    -- 构建层级关系
    boss:add(chargeA)
    boss:add(chargeB)
    chargeA:add(baseA)
    chargeA:add(baseB)
    chargeB:add(baseC)
    chargeB:add(baseD)

    return boss
end

-- 测试 Composite 模式
local function testCompositePattern()
    local tree = BuildATeam()
    tree:operation()
end

-- 执行测试
testCompositePattern()
