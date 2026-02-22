# 日志级别常量
DEFAULT = 1
WARNING = 2
ERROR = 3

# LoggerHandler 日志处理器基类
class LoggerHandler:
    def __init__(self, level):
        self.level = level
        self.next_logger = None
    
    def set_sup_handler(self, logger):
        logger.next_logger = self
        return logger
    
    def log(self, level, message):
        if level == self.level:
            self.write(message)
            return
        if self.next_logger:
            self.next_logger.log(level, message)
        else:
            self.default_write(message)
    
    def write(self, message):
        # 由子类实现
        pass
    
    def default_write(self, message):
        print(f"Default Console: {message}")
