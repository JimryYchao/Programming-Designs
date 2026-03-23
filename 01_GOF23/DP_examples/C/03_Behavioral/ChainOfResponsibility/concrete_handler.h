#ifndef CONCRETE_HANDLER_H
#define CONCRETE_HANDLER_H

#include "handler.h"

// 控制台日志处理器
typedef struct ConsoleLogger {
    LoggerHandler base;
} ConsoleLogger;

// 错误日志处理器
typedef struct ErrorLogger {
    LoggerHandler base;
} ErrorLogger;

// 警告日志处理器
typedef struct WarningLogger {
    LoggerHandler base;
} WarningLogger;

// 初始化控制台日志处理器
void console_logger_init(ConsoleLogger* logger, int level);

// 初始化错误日志处理器
void error_logger_init(ErrorLogger* logger, int level);

// 初始化警告日志处理器
void warning_logger_init(WarningLogger* logger, int level);

#endif // CONCRETE_HANDLER_H
