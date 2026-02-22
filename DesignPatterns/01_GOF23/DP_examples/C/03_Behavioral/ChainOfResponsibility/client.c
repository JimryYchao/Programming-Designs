#include "concrete_handler.h"

int main()
{
    // 创建处理器实例
    LoggerHandler logger;
    logger_handler_init(&logger, DEFAULT);

    ConsoleLogger console_logger;
    WarningLogger warning_logger;
    ErrorLogger error_logger;

    // 初始化处理器
    console_logger_init(&console_logger, DEFAULT);
    warning_logger_init(&warning_logger, WARNING);
    error_logger_init(&error_logger, ERROR);

    // 创建责任链
    set_handler_chain(&logger, &console_logger.base);
    set_handler_chain(&logger, &warning_logger.base);
    set_handler_chain(&logger, &error_logger.base);

    // 测试不同级别的日志
    logger.log(&logger, DEFAULT, "This is a default log");
    logger.log(&logger, WARNING, "This is a warning log");
    logger.log(&logger, ERROR, "This is an error log");
}

// gcc -o client client.c handler.c concrete_handler.c