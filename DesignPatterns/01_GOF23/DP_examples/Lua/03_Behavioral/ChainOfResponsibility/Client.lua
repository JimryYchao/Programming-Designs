-- 加载处理器
require("ConcreteHandler")

-- 测试责任链模式
function testChainOfResponsibility()
    -- 创建责任链
    local logger = ConsoleLogger.new(DEFAULT):setSupHandler(WarningLogger.new(WARNING)):setSupHandler(ErrorLogger.new(ERROR))
    
    -- 测试不同级别的日志
    logger:log(DEFAULT, "This is a default log")
    logger:log(WARNING, "This is a warning log")
    logger:log(ERROR, "This is an error log")
end

-- 执行测试
testChainOfResponsibility()

--- lua Client.lua