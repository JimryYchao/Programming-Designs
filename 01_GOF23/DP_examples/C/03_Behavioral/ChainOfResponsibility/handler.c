#include "handler.h"

// 初始化日志处理器
static void default_write(LoggerHandler *handler, const char *message)
{
    printf("Default Console: %s\n", message);
}

static void log_message(LoggerHandler *handler, int level, const char *message)
{
    if (level == handler->level)
    {
        if (handler->write)
            handler->write(handler, message);
        return;
    }
    if (handler->next_logger)
        log_message(handler->next_logger, level, message);
}

void logger_handler_init(LoggerHandler *handler, int level)
{
    handler->level = level;
    handler->next_logger = NULL;
    handler->log = log_message;
    handler->write = default_write;
}

// 设置上级处理器
LoggerHandler *set_handler_chain(LoggerHandler *handler, LoggerHandler *logger)
{
    if (logger == NULL || handler == NULL)
        return handler;
    LoggerHandler *current = handler;
    while (current->next_logger != NULL)
        current = current->next_logger;
    current->next_logger = logger;
    return logger;
}
