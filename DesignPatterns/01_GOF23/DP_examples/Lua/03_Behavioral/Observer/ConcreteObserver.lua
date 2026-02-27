local ObserverModule = require("Observer")
local IObserver = ObserverModule.IObserver

-- 登录观察者
local LoginObserver = {}
LoginObserver.__index = LoginObserver
setmetatable(LoginObserver, IObserver)

local loginObserverInstance = nil

function LoginObserver:getInstance()
    if not loginObserverInstance then
        loginObserverInstance = LoginObserver:new()
    end
    return loginObserverInstance
end

function LoginObserver:new()
    local o = IObserver:new()
    setmetatable(o, self)
    return o
end

function LoginObserver:Update(subject)
    local AccountData = require("AccountData")
    if subject.GetState then
        AccountData.getInstance():LoginAccount(subject:GetState(0), subject:GetState(1))
    end
end

-- 注册观察者
local RegisterObserver = {}
RegisterObserver.__index = RegisterObserver
setmetatable(RegisterObserver, IObserver)

local registerObserverInstance = nil

function RegisterObserver:getInstance()
    if not registerObserverInstance then
        registerObserverInstance = RegisterObserver:new()
    end
    return registerObserverInstance
end

function RegisterObserver:new()
    local o = IObserver:new()
    setmetatable(o, self)
    return o
end

function RegisterObserver:Update(subject)
    local AccountData = require("AccountData")
    if subject.GetState then
        AccountData.getInstance():RegisterAccount(subject:GetState(0), subject:GetState(1))
    end
end

-- 登录成功观察者
local LoginSuccessful = {}
LoginSuccessful.__index = LoginSuccessful
setmetatable(LoginSuccessful, IObserver)

local loginSuccessfulInstance = nil

function LoginSuccessful:getInstance()
    if not loginSuccessfulInstance then
        loginSuccessfulInstance = LoginSuccessful:new()
    end
    return loginSuccessfulInstance
end

function LoginSuccessful:new()
    local o = IObserver:new()
    setmetatable(o, self)
    return o
end

function LoginSuccessful:Update(subject)
    print("Login Successful")
end

-- 登录失败观察者
local LoginFailed = {}
LoginFailed.__index = LoginFailed
setmetatable(LoginFailed, IObserver)

local loginFailedInstance = nil

function LoginFailed:getInstance()
    if not loginFailedInstance then
        loginFailedInstance = LoginFailed:new()
    end
    return loginFailedInstance
end

function LoginFailed:new()
    local o = IObserver:new()
    setmetatable(o, self)
    return o
end

function LoginFailed:Update(subject)
    print("Login Failed")
end

-- 注册成功观察者
local RegisterSuccessful = {}
RegisterSuccessful.__index = RegisterSuccessful
setmetatable(RegisterSuccessful, IObserver)

local registerSuccessfulInstance = nil

function RegisterSuccessful:getInstance()
    if not registerSuccessfulInstance then
        registerSuccessfulInstance = RegisterSuccessful:new()
    end
    return registerSuccessfulInstance
end

function RegisterSuccessful:new()
    local o = IObserver:new()
    setmetatable(o, self)
    return o
end

function RegisterSuccessful:Update(subject)
    print("Register-Account Successful")
end

-- 注册失败观察者
local RegisterFailed = {}
RegisterFailed.__index = RegisterFailed
setmetatable(RegisterFailed, IObserver)

local registerFailedInstance = nil

function RegisterFailed:getInstance()
    if not registerFailedInstance then
        registerFailedInstance = RegisterFailed:new()
    end
    return registerFailedInstance
end

function RegisterFailed:new()
    local o = IObserver:new()
    setmetatable(o, self)
    return o
end

function RegisterFailed:Update(subject)
    print("Register-Account Failed")
end

-- 导出函数
return {
    getLoginObserver = function() return LoginObserver:getInstance() end,
    getRegisterObserver = function() return RegisterObserver:getInstance() end,
    getLoginSuccessfulObserver = function() return LoginSuccessful:getInstance() end,
    getLoginFailedObserver = function() return LoginFailed:getInstance() end,
    getRegisterSuccessfulObserver = function() return RegisterSuccessful:getInstance() end,
    getRegisterFailedObserver = function() return RegisterFailed:getInstance() end
}
