local ConcreteAggregate = require("ConcreteAggregate")

-- 迭代器引擎
local IteratorEngine = {}

function IteratorEngine:Execute(aggregate, action)
    local iterator = aggregate:GetIterator()
    iterator:First()
    while not iterator:IsDone() do
        local item = iterator:CurrentItem()
        if item then
            action(item)
        end
        iterator:Next()
    end
end

-- 测试代码
local function main()
    -- 创建聚合对象
    local aggregate = ConcreteAggregate:new(4)
    
    -- 添加元素
    aggregate:Add(1)
    aggregate:Add(2)
    aggregate:Add(3)
    aggregate:Add(4)
    -- 校验扩容
    aggregate:Add(5)
    aggregate:Add(6)
    
    -- 执行迭代
    print("Iterating over aggregate:")
    local engine = IteratorEngine
    engine:Execute(aggregate, function(a)
        print("Print : number >> " .. a)
    end)
    
    -- 测试其他方法
    print("Count: " .. aggregate:Count())
    print("Contains 3: " .. tostring(aggregate:Contains(3)))
    print("Remove 3: " .. tostring(aggregate:Remove(3)))
    print("Contains 3 after removal: " .. tostring(aggregate:Contains(3)))
    
    -- 再次迭代
    print("Iterating after removal:")
    engine:Execute(aggregate, function(a)
        print("Print : number >> " .. a)
    end)
    
    -- 清空
    aggregate:Clear()
    print("Count after clear: " .. aggregate:Count())
end

-- 运行测试
main()
