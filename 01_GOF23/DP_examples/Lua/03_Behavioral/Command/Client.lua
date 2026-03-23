-- 客户端实现
local Command = require("Command")
local Receiver = require("Receiver")
local Invoker = require("Invoker")

local function build_commands()
    -- 创建命令调用者
    local invoker = Invoker.create_invoker()
    
    -- 创建股票
    local book_stock = Receiver.create_stock("book", 10)
    local pencil_stock = Receiver.create_stock("pencil", 15)
    local pen_stock = Receiver.create_stock("pen", 18)
    
    -- 创建接收者
    local buy_book = Receiver.BuyStock:new(book_stock)
    local buy_pencil = Receiver.BuyStock:new(pencil_stock)
    local sell_pen = Receiver.SellStock:new(pen_stock)
    
    -- 创建命令
    local c = Command.ConcreteCommand:new(buy_book)
    local c2 = Command.ConcreteCommand:new(buy_pencil)
    local c3 = Command.ConcreteCommand:new(sell_pen)
    
    -- 存储命令
    invoker:store_command(c)
    invoker:store_command(c2)
    invoker:store_command(c3)
    
    -- 移除命令
    invoker:remove_command(c)
    
    return invoker
end

local function test_command_pattern()
    -- 构建命令
    local invoker = build_commands()
    
    -- 执行命令
    invoker:invoke()
end

-- 运行测试
test_command_pattern()

--- lua Client.lua