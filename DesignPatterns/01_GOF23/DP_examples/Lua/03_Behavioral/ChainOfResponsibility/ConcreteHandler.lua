-- 加载基础处理器
require("Handler")

-- ConsoleLogger 控制台日志处理器
--- @class ConsoleLogger : LoggerHandler
--- @field level number
--- @field nextLogger LoggerHandler
ConsoleLogger = {}
ConsoleLogger.__index = ConsoleLogger
setmetatable(ConsoleLogger, LoggerHandler)

-- 创建控制台日志处理器
function ConsoleLogger.new(level)
    local self = LoggerHandler.new(level)
    setmetatable(self, ConsoleLogger)
    return self
end
function ConsoleLogger:write(message)
    print("Standard Console: " .. message)
end

-- ErrorLogger 错误日志处理器
--- @class ErrorLogger : LoggerHandler
--- @field level number
--- @field nextLogger LoggerHandler
ErrorLogger = {}
ErrorLogger.__index = ErrorLogger
setmetatable(ErrorLogger, LoggerHandler)
function ErrorLogger.new(level)
    local self = LoggerHandler.new(level)
    setmetatable(self, ErrorLogger)
    return self
end
function ErrorLogger:write(message)
    print("Error Console: " .. message)
end

-- WarningLogger 警告日志处理器
--- @class WarningLogger : LoggerHandler
--- @field level number
--- @field nextLogger LoggerHandler
WarningLogger = {}
WarningLogger.__index = WarningLogger
setmetatable(WarningLogger, LoggerHandler)
function WarningLogger.new(level)
    local self = LoggerHandler.new(level)
    setmetatable(self, WarningLogger)
    return self
end
function WarningLogger:write(message)
    print("Warning Console: " .. message)
end