use crate::LoggerHandler;

pub struct ConsoleLogger {
    level: i32,
    next_logger: Option<Box<dyn LoggerHandler>>,
}

impl ConsoleLogger {
    pub fn new(level: i32) -> Self {
        ConsoleLogger {
            level,
            next_logger: None,
        }
    }
}

impl LoggerHandler for ConsoleLogger {
    fn set_next_logger(&mut self, logger: Box<dyn LoggerHandler>) {
        self.next_logger = Some(logger);
    }
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
    fn write(&self, message: &str) {
        println!("Console: {}", message);
    }
}

pub struct WarningLogger {
    level: i32,
    next_logger: Option<Box<dyn LoggerHandler>>,
}
impl WarningLogger {
    pub fn new(level: i32) -> Self {
        WarningLogger {
            level,
            next_logger: None,
        }
    }
}

impl LoggerHandler for WarningLogger {
    fn set_next_logger(&mut self, logger: Box<dyn LoggerHandler>) {
        self.next_logger = Some(logger);
    }
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
    fn write(&self, message: &str) {
        println!("Warning: {}", message);
    }
}

pub struct ErrorLogger {
    level: i32,
    next_logger: Option<Box<dyn LoggerHandler>>,
}

impl ErrorLogger {
    pub fn new(level: i32) -> Self {
        ErrorLogger {
            level,
            next_logger: None,
        }
    }
}

impl LoggerHandler for ErrorLogger {
    fn set_next_logger(&mut self, logger: Box<dyn LoggerHandler>) {
        self.next_logger = Some(logger);
    }
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
    fn write(&self, message: &str) {
        println!("Error: {}", message);
    }
}
