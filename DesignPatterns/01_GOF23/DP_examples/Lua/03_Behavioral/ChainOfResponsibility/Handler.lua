-- 日志级别常量
DEFAULT = 1
WARNING = 2
ERROR = 3

-- LoggerHandler 日志处理器基类
--- @class LoggerHandler
--- @field level number
--- @field nextLogger LoggerHandler
LoggerHandler = {}
LoggerHandler.__index = LoggerHandler

-- 创建日志处理器
function LoggerHandler.new(level)
    local self = setmetatable({}, LoggerHandler)
    self.level = level
    self.nextLogger = nil
    return self
end

--- 设置上级处理器
--- @param logger LoggerHandler
--- @return LoggerHandler
function LoggerHandler:setSupHandler(logger)
    logger.nextLogger = self
    return logger
end

--- 默认写入
--- @param message string
local function defaultWrite(message)
    print("Default Console: " .. message)
end

--- 记录日志
--- @param level number
--- @param message string
function LoggerHandler:log(level, message)
    if level == self.level then
        self:write(message)
        return
    end
    if self.nextLogger then
        self.nextLogger:log(level, message)
    else
        defaultWrite(message)
    end
end

--- 写入日志（需要子类实现）
--- @param message string
function LoggerHandler:write(message)
    -- 由子类实现
end
