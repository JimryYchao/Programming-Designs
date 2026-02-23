// 客户端实现
#include "Command.hpp"
#include "Receiver.hpp"
#include "Invoker.hpp"

Invoker* buildCommands() {
    Invoker* invoker = new Invoker();
    ICommand* c = new ConcreteCommand(new BuyStock(Stock("book", 10)));
    
    // 关联 Invoker 并控制执行/撤销操作
    invoker->storeCommand(c);
    invoker->storeCommand(new ConcreteCommand(new BuyStock(Stock("pencil", 15))));
    invoker->storeCommand(new ConcreteCommand(new SellStock(Stock("pen", 18))));
    invoker->removeCommand(c);
    
    return invoker;
}

int main() {
    Invoker* invoker = buildCommands();
    invoker->invoke();
    delete invoker;
}
