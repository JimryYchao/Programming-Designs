local ObserverModule = require("Observer")
local ISubject = ObserverModule.ISubject
local ChangeManagerModule = require("ChangeManager")
local SimpleChangeManager = ChangeManagerModule.SimpleChangeManager

-- 具体主题
local Subject = {}
Subject.__index = Subject
setmetatable(Subject, ISubject)

local subjectInstance = nil

function Subject:getInstance()
    if not subjectInstance then
        subjectInstance = Subject:new()
    end
    return subjectInstance
end

function Subject:new()
    local o = ISubject:new()
    setmetatable(o, self)
    o.name = ""
    o.password = ""
    o.changeMgr = SimpleChangeManager:new(o)
    return o
end

function Subject:RegisterAccount(name, password)
    self.name = name
    self.password = password
    self:Attach(require("ConcreteObserver").getRegisterObserver())
end

function Subject:LoginAccount(name, password)
    self.name = name
    self.password = password
    self:Attach(require("ConcreteObserver").getLoginObserver())
end

function Subject:GetState(state)
    if state == 0 then
        return self.name
    elseif state == 1 then
        return self.password
    else
        return ""
    end
end

function Subject:Attach(observer)
    self.changeMgr:Register(self, observer)
end

function Subject:Detach(observer)
    self.changeMgr:Unregister(self, observer)
end

function Subject:Notify()
    self.changeMgr:Notify()
    self.changeMgr:ClearObserver()
end

return Subject
