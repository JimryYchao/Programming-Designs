local IteratorModule = require("Iterator")
local Iterator = IteratorModule.Iterator
local IAggregate = IteratorModule.IAggregate

local defaultCapacity = 4

-- 具体聚合类
local ConcreteAggregate = {}
ConcreteAggregate.__index = ConcreteAggregate
setmetatable(ConcreteAggregate, IAggregate)

function ConcreteAggregate:new(capacity)
    local o = IAggregate:new()
    setmetatable(o, self)
    o.capacity = capacity or defaultCapacity
    if o.capacity < defaultCapacity then
        o.capacity = defaultCapacity
    end
    o.array = {}
    return o
end

function ConcreteAggregate:Count()
    return #self.array
end

function ConcreteAggregate:Add(item)
    table.insert(self.array, item)
end

function ConcreteAggregate:Remove(item)
    for i, v in ipairs(self.array) do
        if v == item then
            table.remove(self.array, i)
            return true
        end
    end
    return false
end

function ConcreteAggregate:Contains(item)
    for _, v in ipairs(self.array) do
        if v == item then
            return true
        end
    end
    return false
end

function ConcreteAggregate:Clear()
    self.array = {}
end

-- 具体迭代器实现
local AggregateIterator = {}
AggregateIterator.__index = AggregateIterator
setmetatable(AggregateIterator, Iterator)

function AggregateIterator:new(aggregate)
    local o = Iterator:new()
    setmetatable(o, self)
    o.aggregate = aggregate
    o.index = 0
    return o
end

function AggregateIterator:First()
    if #self.aggregate.array > 0 then
        self.index = 1
    end
end

function AggregateIterator:Next()
    if self.index <= #self.aggregate.array then
        self.index = self.index + 1
    end
end

function AggregateIterator:IsDone()
    return self.index > #self.aggregate.array
end

function AggregateIterator:CurrentItem()
    if self.index >= 1 and self.index <= #self.aggregate.array then
        return self.aggregate.array[self.index]
    end
    return nil
end

function ConcreteAggregate:GetIterator()
    return AggregateIterator:new(self)
end

return ConcreteAggregate
