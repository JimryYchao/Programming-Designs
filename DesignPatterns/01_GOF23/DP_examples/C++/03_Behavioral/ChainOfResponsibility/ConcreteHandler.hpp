#ifndef CONCRETE_HANDLER_HPP
#define CONCRETE_HANDLER_HPP

#include "Handler.hpp"

// ConsoleLogger 控制台日志处理器
class ConsoleLogger : public LoggerHandler {
public:
    ConsoleLogger(int level) : LoggerHandler(level) {}
    void write(const std::string& message) override {
        std::cout << "Standard Console: " << message << std::endl;
    }
};

// ErrorLogger 错误日志处理器
class ErrorLogger : public LoggerHandler {
public:
    ErrorLogger(int level) : LoggerHandler(level) {}
    void write(const std::string& message) override {
        std::cout << "Error Console: " << message << std::endl;
    }
};

// WarningLogger 警告日志处理器
class WarningLogger : public LoggerHandler {
public:
    WarningLogger(int level) : LoggerHandler(level) {}
    void write(const std::string& message) override {
        std::cout << "Warning Console: " << message << std::endl;
    }
};

#endif // CONCRETE_HANDLER_HPP
