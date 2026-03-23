-- 管理者类
local Caretaker = {}
Caretaker.__index = Caretaker

function Caretaker:new()
    local o = {}
    setmetatable(o, self)
    o.mementoMap = {}
    return o
end

function Caretaker:SaveMemento(version, m)
    self.mementoMap[version] = m
end

function Caretaker:GetMemento(version)
    return self.mementoMap[version]
end

return Caretaker
