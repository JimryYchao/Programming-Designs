mod concrete_handler;
mod handler;

use crate::handler::{DEFAULT, WARNING, ERROR, LoggerHandler, BaseLoggerHandler};
use crate::concrete_handler::{ConsoleLogger, WarningLogger, ErrorLogger};

fn main() {
    // 创建责任链
    let mut logger = BaseLoggerHandler::new(0);   
    let mut console_logger = ConsoleLogger::new(DEFAULT);
    let mut warning_logger = WarningLogger::new(WARNING);
    let error_logger = ErrorLogger::new(ERROR);
    
    // 构建责任链：error -> warning -> console 
    warning_logger.set_next_logger(Box::new(error_logger));
    console_logger.set_next_logger(Box::new(warning_logger));
    logger.set_next_logger(Box::new(console_logger));
    
    // 测试不同级别的日志
    logger.log(DEFAULT, "This is a default log");
    logger.log(WARNING, "This is a warning log");
    logger.log(ERROR, "This is an error log");
}
