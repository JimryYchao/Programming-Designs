#include "concrete_handler.h"

// 控制台日志处理器的 write 方法
static void console_write(LoggerHandler* handler, const char* message) {
    printf("Standard Console: %s\n", message);
}

// 错误日志处理器的 write 方法
static void error_write(LoggerHandler* handler, const char* message) {
    printf("Error Console: %s\n", message);
}

// 警告日志处理器的 write 方法
static void warning_write(LoggerHandler* handler, const char* message) {
    printf("Warning Console: %s\n", message);
}

// 初始化控制台日志处理器
void console_logger_init(ConsoleLogger* logger, int level) {
    logger_handler_init(&logger->base, level);
    logger->base.write = console_write;
}

// 初始化错误日志处理器
void error_logger_init(ErrorLogger* logger, int level) {
    logger_handler_init(&logger->base, level);
    logger->base.write = error_write;
}

// 初始化警告日志处理器
void warning_logger_init(WarningLogger* logger, int level) {
    logger_handler_init(&logger->base, level);
    logger->base.write = warning_write;
}
