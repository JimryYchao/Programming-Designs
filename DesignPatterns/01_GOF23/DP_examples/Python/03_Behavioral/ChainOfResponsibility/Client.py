from Handler import DEFAULT, WARNING, ERROR
from ConcreteHandler import ConsoleLogger, ErrorLogger, WarningLogger

# 测试责任链模式
def test_chain_of_responsibility():
    # 创建责任链
    logger = ConsoleLogger(DEFAULT).set_sup_handler(WarningLogger(WARNING)).set_sup_handler(ErrorLogger(ERROR))
    
    # 测试不同级别的日志
    logger.log(DEFAULT, "This is a default log")
    logger.log(WARNING, "This is a warning log")
    logger.log(ERROR, "This is an error log")

if __name__ == "__main__":
    test_chain_of_responsibility()
