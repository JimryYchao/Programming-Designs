// 日志级别常量
pub const DEFAULT: i32 = 1;
pub const WARNING: i32 = 2;
pub const ERROR: i32 = 3;

// 日志处理器 trait
pub trait LoggerHandler {
    // 设置下一个处理器
    fn set_next_logger(&mut self, logger: Box<dyn LoggerHandler>);
    // 记录日志
    fn log(&self, level: i32, message: &str);
    // 写入日志（由具体实现）
    fn write(&self, message: &str);
}

// 基础日志处理器实现
pub struct BaseLoggerHandler {
    level: i32,
    next_logger: Option<Box<dyn LoggerHandler>>,
}

impl BaseLoggerHandler {
    // 创建基础日志处理器
    pub fn new(level: i32) -> Self {
        BaseLoggerHandler {
            level,
            next_logger: None,
        }
    }
}

impl LoggerHandler for BaseLoggerHandler {
    // 设置下一个处理器
    fn set_next_logger(&mut self, logger: Box<dyn LoggerHandler>) {
        self.next_logger = Some(logger);
    }

    // 记录日志
    fn log(&self, level: i32, message: &str) {
        if level == self.level {
            self.write(message);
        } else if let Some(ref next) = self.next_logger {
            next.log(level, message);
        } else {
            // 默认处理
            println!("Default Console: {}", message);
        }
    }

    // 写入日志（默认实现，由子类重写）
    fn write(&self, _message: &str) {
        // 由具体实现重写
    }
}
