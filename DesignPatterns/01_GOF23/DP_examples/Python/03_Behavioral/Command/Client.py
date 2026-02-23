# 客户端实现
from Command import ConcreteCommand
from Receiver import Stock, BuyStock, SellStock
from Invoker import Invoker


def build_commands():
    # 创建命令调用者
    invoker = Invoker()
    
    # 创建一个具体的命令对象并设定它的接收者
    c = ConcreteCommand(BuyStock(Stock("book", 10)))
    
    # 关联 Invoker 并控制执行/撤销操作
    invoker.store_command(c)
    invoker.store_command(ConcreteCommand(BuyStock(Stock("pencil", 15))))
    invoker.store_command(ConcreteCommand(SellStock(Stock("pen", 18))))
    invoker.remove_command(c)
    
    return invoker


def test_command_pattern():
    # 构建命令
    invoker = build_commands()
    
    # 执行命令
    invoker.invoke()


if __name__ == "__main__":
    test_command_pattern()
