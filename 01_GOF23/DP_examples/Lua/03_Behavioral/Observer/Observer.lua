-- 观察者接口
local IObserver = {}
IObserver.__index = IObserver

function IObserver:new()
    local o = {}
    setmetatable(o, self)
    return o
end

function IObserver:Update(subject)
    error("Subclass must implement Update method")
end

-- 主题接口
local ISubject = {}
ISubject.__index = ISubject

function ISubject:new()
    local o = {}
    setmetatable(o, self)
    return o
end

function ISubject:Attach(observer)
    error("Subclass must implement Attach method")
end

function ISubject:Detach(observer)
    error("Subclass must implement Detach method")
end

function ISubject:Notify()
    error("Subclass must implement Notify method")
end

-- 变更管理器接口
local IChangeManager = {}
IChangeManager.__index = IChangeManager

function IChangeManager:new()
    local o = {}
    setmetatable(o, self)
    return o
end

function IChangeManager:Register(subject, observer)
    error("Subclass must implement Register method")
end

function IChangeManager:Unregister(subject, observer)
    error("Subclass must implement Unregister method")
end

function IChangeManager:Notify()
    error("Subclass must implement Notify method")
end

return { IObserver = IObserver, ISubject = ISubject, IChangeManager = IChangeManager }
