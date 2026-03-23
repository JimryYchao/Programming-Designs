-- 命令调用者

-- 创建命令调用者
local function create_invoker()
    return {
        commands = {},
        
        -- 存储命令
        store_command = function(self, command)
            table.insert(self.commands, command)
        end,
        
        -- 移除命令
        remove_command = function(self, command)
            if #self.commands == 0 then
                return false
            end
            for i, cmd in ipairs(self.commands) do
                if cmd == command then
                    table.remove(self.commands, i)
                    return true
                end
            end
            return false
        end,
        
        -- 获取命令数量
        count = function(self)
            return #self.commands
        end,
        
        -- 执行所有命令
        invoke = function(self)
            for _, command in ipairs(self.commands) do
                command:execute()
            end
        end
    }
end

-- 导出模块
return {
    create_invoker = create_invoker
}
