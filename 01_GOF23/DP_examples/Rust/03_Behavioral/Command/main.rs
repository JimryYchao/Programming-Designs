// 客户端实现
mod receiver;
mod command;
mod invoker;

use std::sync::Arc;
use crate::receiver::{Stock, BuyStock, SellStock};
use crate::command::{ConcreteCommand, CommandPtr};
use crate::invoker::Invoker;

fn build_commands() -> Invoker {
    // 创建命令调用者
    let mut invoker = Invoker::new();
    
    // 创建股票
    let book_stock = Stock::new("book", 10);
    let pencil_stock = Stock::new("pencil", 15);
    let pen_stock = Stock::new("pen", 18);
    
    // 创建接收者
    let buy_book = BuyStock::new(book_stock);
    let buy_pencil = BuyStock::new(pencil_stock);
    let sell_pen = SellStock::new(pen_stock);
    
    // 创建命令
    let c: CommandPtr = Arc::new(ConcreteCommand::new(Box::new(buy_book)));
    let c2: CommandPtr = Arc::new(ConcreteCommand::new(Box::new(buy_pencil)));
    let c3: CommandPtr = Arc::new(ConcreteCommand::new(Box::new(sell_pen)));
    
    // 存储命令
    invoker.store_command(&c);
    invoker.store_command(&c2);
    invoker.store_command(&c3);
    
    // 移除命令 c
    invoker.remove_command(&c);
    
    invoker
}

fn main() {
    // 构建命令
    let invoker = build_commands();
    
    // 执行命令
    invoker.invoke();
}
