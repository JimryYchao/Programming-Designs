local Subject = require("ConcreteSubject")

-- 测试代码
local function main()
    -- 测试注册
    local subject = Subject.getInstance()
    subject:RegisterAccount("test", "123456")
    subject:Notify()
    
    -- 测试重复注册
    subject:RegisterAccount("test", "123456")
    subject:Notify()
    
    -- 测试登录
    subject:LoginAccount("test", "123456")
    subject:Notify()
    
    -- 测试登录失败
    subject:LoginAccount("test", "wrong")
    subject:Notify()
end

-- 运行测试
main()

--- lua Client.lua