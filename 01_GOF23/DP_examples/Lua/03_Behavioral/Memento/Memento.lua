-- 备忘录类
local Memento = {}
Memento.__index = Memento

function Memento:new(version)
    local o = {}
    setmetatable(o, self)
    o.states = {}
    o.Version = version
    return o
end

function Memento:GetState(identifier)
    return self.states[identifier]
end

function Memento:SetState(identifier, state)
    self.states[identifier] = state
end

return Memento
