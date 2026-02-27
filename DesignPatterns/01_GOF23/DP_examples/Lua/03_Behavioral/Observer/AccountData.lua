local ObserverModule = require("Observer")
local ISubject = ObserverModule.ISubject
local ChangeManagerModule = require("ChangeManager")
local LoggerManager = ChangeManagerModule.LoggerManager

-- 账户数据
local AccountData = {}
AccountData.__index = AccountData
setmetatable(AccountData, ISubject)

local accountInstance = nil

function AccountData:getInstance()
    if not accountInstance then
        accountInstance = AccountData:new()
    end
    return accountInstance
end

function AccountData:new()
    local o = ISubject:new()
    setmetatable(o, self)
    o.accounts = {}
    o.changer = LoggerManager:getInstance()
    return o
end

function AccountData:LoginAccount(account, password)
    if self.accounts[account] then
        if self.accounts[account] == password then
            self:Attach(require("ConcreteObserver").getLoginSuccessfulObserver())
            return
        end
    end
    self:Attach(require("ConcreteObserver").getLoginFailedObserver())
end

function AccountData:RegisterAccount(account, password)
    if not self.accounts[account] then
        self.accounts[account] = password
        self:Attach(require("ConcreteObserver").getRegisterSuccessfulObserver())
    else
        self:Attach(require("ConcreteObserver").getRegisterFailedObserver())
    end
end

function AccountData:Attach(observer)
    self.changer:Register(self, observer)
end

function AccountData:Detach(observer)
    self.changer:Unregister(self, observer)
end

function AccountData:Notify()
    self.changer:Notify()
end

return AccountData
