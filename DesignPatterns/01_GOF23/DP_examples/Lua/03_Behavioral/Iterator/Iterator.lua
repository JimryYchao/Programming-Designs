-- 迭代器接口
local Iterator = {}
Iterator.__index = Iterator

function Iterator:new()
    local o = {}
    setmetatable(o, self)
    return o
end

function Iterator:First()
    error("Subclass must implement First method")
end

function Iterator:Next()
    error("Subclass must implement Next method")
end

function Iterator:IsDone()
    error("Subclass must implement IsDone method")
end

function Iterator:CurrentItem()
    error("Subclass must implement CurrentItem method")
end

-- 可迭代接口
local Iterable = {}
Iterable.__index = Iterable

function Iterable:new()
    local o = {}
    setmetatable(o, self)
    return o
end

function Iterable:GetIterator()
    error("Subclass must implement GetIterator method")
end

-- 聚合接口
local IAggregate = {}
IAggregate.__index = IAggregate
setmetatable(IAggregate, Iterable)

function IAggregate:new()
    local o = Iterable:new()
    setmetatable(o, self)
    return o
end

function IAggregate:Count()
    error("Subclass must implement Count method")
end

function IAggregate:Add(item)
    error("Subclass must implement Add method")
end

function IAggregate:Remove(item)
    error("Subclass must implement Remove method")
end

function IAggregate:Contains(item)
    error("Subclass must implement Contains method")
end

function IAggregate:Clear()
    error("Subclass must implement Clear method")
end

return { Iterator = Iterator, Iterable = Iterable, IAggregate = IAggregate }
