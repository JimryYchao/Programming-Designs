#ifndef HANDLER_H
#define HANDLER_H

#include <stdio.h>

// 日志级别常量
#define DEFAULT 1
#define WARNING 2
#define ERROR 3

// 前向声明
struct LoggerHandler;

// 日志处理器结构体
typedef struct LoggerHandler {
    int level;
    struct LoggerHandler* next_logger;
    void (*write)(struct LoggerHandler*, const char*);
    void (*log)(struct LoggerHandler*, int, const char*);
} LoggerHandler;

// 初始化日志处理器
void logger_handler_init(LoggerHandler* handler, int level);

// 设置上级处理器
LoggerHandler* set_handler_chain(LoggerHandler* handler, LoggerHandler* logger);

#endif // HANDLER_H
