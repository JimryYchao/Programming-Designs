require("Singleton")

-- 测试非线程安全单例
local s1 = Singleton.getInstance()
local s2 = Singleton.getInstance()
if s1 == s2 then
    s1:showMessage()
end

-- 测试继承单例
local ms = MonoSingleton.getInstance()
local gs = GameSingleton.getInstance()
if ms ~= gs then
    ms:log()
    gs:log()
end