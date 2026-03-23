// 客户端实现
#include <stdio.h>
#include "command.h"
#include "receiver.h"
#include "invoker.h"

Invoker* build_commands() {
    // Invoker
    Invoker* invoker = create_invoker();
    if (!invoker) {
        return NULL;
    }
    
    // Receiver
    Stock book_stock = create_stock("book", 10);
    Stock pencil_stock = create_stock("pencil", 15);
    Stock pen_stock = create_stock("pen", 18);
    BuyStock* buy_book = create_buy_stock(book_stock);
    BuyStock* buy_pencil = create_buy_stock(pencil_stock);
    SellStock* sell_pen = create_sell_stock(pen_stock);
    
    // Command
    ICommand* c = (ICommand*)create_concrete_command(buy_book, buy_stock_action);
    ICommand* c2 = (ICommand*)create_concrete_command(buy_pencil, buy_stock_action);
    ICommand* c3 = (ICommand*)create_concrete_command(sell_pen, sell_stock_action);
    
    invoker_store_command(invoker, c);
    invoker_store_command(invoker, c2);
    invoker_store_command(invoker, c3);
    invoker_remove_command(invoker, c);
    
    return invoker;
}

int main() {
    // 构建命令
    Invoker* invoker = build_commands();
    if (!invoker) {
        printf("Failed to build commands\n");
        return 1;
    }
    
    invoker_invoke(invoker);
    destroy_invoker(invoker);
}

// gcc -o client client.c command.c receiver.c invoker.c