#ifndef HANDLER_HPP
#define HANDLER_HPP

#include <iostream>
// 日志级别常量
const int DEFAULT = 1;
const int WARNING = 2;
const int ERROR = 3;

// LoggerHandler 日志处理器基类
class LoggerHandler
{
protected:
    int level;
    LoggerHandler* nextLogger;
    static void defaultWrite(const std::string &message)
    {
        std::cout << "Default Console: " << message << std::endl;
    }

public:
    LoggerHandler(int level) : level(level), nextLogger(nullptr) {}
    virtual ~LoggerHandler() {
        if (nextLogger)
            delete nextLogger;
        printf("LoggerHandler destructor\n");
    };

    LoggerHandler* setSupHandler(LoggerHandler* logger)
    {
        logger->nextLogger = this;
        return logger;
    }
    void log(int level, const std::string &message)
    {
        if (level == this->level)
        {
            write(message);
            return;
        }
        if (nextLogger)
        {
            nextLogger->log(level, message);
        }
        else
        {
            LoggerHandler::defaultWrite(message);
        }
    }
    virtual void write(const std::string &message) {}
};

#endif // HANDLER_HPP
