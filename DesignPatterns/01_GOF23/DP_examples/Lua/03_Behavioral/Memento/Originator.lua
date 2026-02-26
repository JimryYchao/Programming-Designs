local Memento = require("Memento")

-- 发起人类
local Originator = {}
Originator.__index = Originator

function Originator:new(s1, s2, s3)
    local o = {}
    setmetatable(o, self)
    o.state1 = s1
    o.state2 = s2
    o.state3 = s3
    return o
end

function Originator:ConsoleState()
    print("State_1: " .. self.state1)
    print("State_2: " .. self.state2)
    print("State_3: " .. self.state3)
end

function Originator:CreateMemento(version)
    local memento = Memento:new(version)
    memento:SetState("state1", self.state1)
    memento:SetState("state2", self.state2)
    memento:SetState("state3", self.state3)
    return memento
end

function Originator:SetMemento(m)
    self.state1 = m:GetState("state1")
    self.state2 = m:GetState("state2")
    self.state3 = m:GetState("state3")
end

return Originator
