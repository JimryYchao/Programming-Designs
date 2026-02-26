local Originator = require("Originator")
local Caretaker = require("Caretaker")

-- 测试代码
local function main()
    -- 创建发起人
    local o = Originator:new("Hello", "World", "!")
    
    -- 创建管理者
    local caretaker = Caretaker:new()
    
    -- 保存第一版
    caretaker:SaveMemento(1, o:CreateMemento(1))
    
    -- 修改状态
    o = Originator:new("X", "Y", "Z")
    o:ConsoleState()
    
    -- 恢复第一版
    local memento = caretaker:GetMemento(1)
    o:SetMemento(memento)
    o:ConsoleState()
end

-- 运行测试
main()
