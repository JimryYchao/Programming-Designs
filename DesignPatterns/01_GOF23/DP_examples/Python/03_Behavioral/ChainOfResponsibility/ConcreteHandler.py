from Handler import LoggerHandler

# ConsoleLogger 控制台日志处理器
class ConsoleLogger(LoggerHandler):
    def __init__(self, level):
        super().__init__(level)
    
    def write(self, message):
        print(f"Standard Console: {message}")

# ErrorLogger 错误日志处理器
class ErrorLogger(LoggerHandler):
    def __init__(self, level):
        super().__init__(level)
    
    def write(self, message):
        print(f"Error Console: {message}")

# WarningLogger 警告日志处理器
class WarningLogger(LoggerHandler):
    def __init__(self, level):
        super().__init__(level)
    
    def write(self, message):
        print(f"Warning Console: {message}")
