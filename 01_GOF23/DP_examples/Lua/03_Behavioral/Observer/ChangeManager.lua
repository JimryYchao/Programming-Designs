local ObserverModule = require("Observer")
local IChangeManager = ObserverModule.IChangeManager

-- 简单变更管理器
local SimpleChangeManager = {}
SimpleChangeManager.__index = SimpleChangeManager
setmetatable(SimpleChangeManager, IChangeManager)

function SimpleChangeManager:new(subject)
    local o = IChangeManager:new()
    setmetatable(o, self)
    o.subject = subject
    o.observers = {}
    return o
end

function SimpleChangeManager:Register(subject, observer)
    for _, obs in ipairs(self.observers) do
        if obs == observer then
            return
        end
    end
    table.insert(self.observers, observer)
end

function SimpleChangeManager:Unregister(subject, observer)
    for i, obs in ipairs(self.observers) do
        if obs == observer then
            table.remove(self.observers, i)
            break
        end
    end
end

function SimpleChangeManager:Notify()
    for _, observer in ipairs(self.observers) do
        observer:Update(self.subject)
    end
end

function SimpleChangeManager:ClearObserver()
    self.observers = {}
end

-- 多主题变更管理器
local DCGChangeManager = {}
DCGChangeManager.__index = DCGChangeManager
setmetatable(DCGChangeManager, IChangeManager)

local dcgInstance = nil

function DCGChangeManager:getInstance()
    if not dcgInstance then
        dcgInstance = DCGChangeManager:new()
    end
    return dcgInstance
end

function DCGChangeManager:new()
    local o = IChangeManager:new()
    setmetatable(o, self)
    o.subjectObservers = {}
    return o
end

function DCGChangeManager:Register(subject, observer)
    if not self.subjectObservers[subject] then
        self.subjectObservers[subject] = {}
    end
    
    for _, obs in ipairs(self.subjectObservers[subject]) do
        if obs == observer then
            return
        end
    end
    
    table.insert(self.subjectObservers[subject], observer)
end

function DCGChangeManager:Unregister(subject, observer)
    if self.subjectObservers[subject] then
        for i, obs in ipairs(self.subjectObservers[subject]) do
            if obs == observer then
                table.remove(self.subjectObservers[subject], i)
                break
            end
        end
    end
end

function DCGChangeManager:Notify()
    for subject, observers in pairs(self.subjectObservers) do
        for _, observer in ipairs(observers) do
            observer:Update(subject)
        end
    end
end

-- 日志管理器
local LoggerManager = {}
LoggerManager.__index = LoggerManager
setmetatable(LoggerManager, IChangeManager)

local loggerInstance = nil

function LoggerManager:getInstance()
    if not loggerInstance then
        loggerInstance = LoggerManager:new()
    end
    return loggerInstance
end

function LoggerManager:new()
    local o = IChangeManager:new()
    setmetatable(o, self)
    return o
end

function LoggerManager:Register(subject, observer)
    observer:Update(subject)
end

function LoggerManager:Unregister(subject, observer)
    -- 未实现
end

function LoggerManager:Notify()
    -- 未实现
end

return { SimpleChangeManager = SimpleChangeManager, DCGChangeManager = DCGChangeManager, LoggerManager = LoggerManager }
