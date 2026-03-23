#include "ConcreteHandler.hpp"

int main()
{
    // 创建责任链
    LoggerHandler *logger = new ConsoleLogger(DEFAULT);
    logger = logger->setSupHandler(new WarningLogger(WARNING))->setSupHandler(new ErrorLogger(ERROR));

    // 测试不同级别的日志
    logger->log(DEFAULT, "This is a default log");
    logger->log(WARNING, "This is a warning log");
    logger->log(ERROR, "This is an error log");
    delete logger;
}
