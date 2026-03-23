-- 常规单例
Singleton = {}
Singleton.__index = Singleton

local instance = nil

function Singleton.getInstance()
    if instance == nil then
        instance = setmetatable({}, Singleton)
    end
    return instance
end

function Singleton:showMessage()
    print("Singleton instance")
end

-- 继承单例基类
Singleton_Inherit = {}
Singleton_Inherit.__index = Singleton_Inherit
function Singleton_Inherit:log() end

MonoSingleton = setmetatable({}, { __index = Singleton_Inherit })
MonoSingleton.__index = MonoSingleton
local monoInstance = nil
function MonoSingleton.getInstance()
    if monoInstance == nil then
        monoInstance = setmetatable({}, MonoSingleton)
    end
    return monoInstance
end
function MonoSingleton:log()
    print("MonoSingleton is created")
end

GameSingleton = setmetatable({}, { __index = Singleton_Inherit })
GameSingleton.__index = GameSingleton
local gameInstance = nil
function GameSingleton.getInstance()
    if gameInstance == nil then
        gameInstance = setmetatable({}, GameSingleton)
    end
    return gameInstance
end
function GameSingleton:log()
    print("GameSingleton is created")
end