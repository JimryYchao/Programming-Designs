// 接收者实现
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "receiver.h"

// 创建股票
Stock create_stock(const char* name, int quantity) {
    Stock stock;
    stock.name = strdup(name);
    stock.quantity = quantity;
    return stock;
}

// 创建购买股票的接收者
BuyStock* create_buy_stock(Stock stock) {
    BuyStock* buy_stock = (BuyStock*)malloc(sizeof(BuyStock));
    if (buy_stock) {
        buy_stock->stock = stock;
    }
    return buy_stock;
}

// 购买股票
static void buy_stocks(BuyStock* stock) {
    printf("Buy %d Stocks which name is %s\n", stock->stock.quantity, stock->stock.name);
}

// 购买股票的 action 方法
void buy_stock_action(void* receiver) {
    BuyStock* stock = (BuyStock*)receiver;
    buy_stocks(stock);
}

// 创建卖出股票的接收者
SellStock* create_sell_stock(Stock stock) {
    SellStock* sell_stock = (SellStock*)malloc(sizeof(SellStock));
    if (sell_stock) {
        sell_stock->stock = stock;
    }
    return sell_stock;
}

// 卖出股票
static void sell_stocks(SellStock* stock) {
    printf("Sell %d Stocks which name is %s\n", stock->stock.quantity, stock->stock.name);
}

// 卖出股票的 action 方法
void sell_stock_action(void* receiver) {
    SellStock* stock = (SellStock*)receiver;
    sell_stocks(stock);
}

// 释放购买股票的接收者
void destroy_buy_stock(BuyStock* stock) {
    if (stock) {
        free(stock->stock.name);
        free(stock);
    }
}

// 释放卖出股票的接收者
void destroy_sell_stock(SellStock* stock) {
    if (stock) {
        free(stock->stock.name);
        free(stock);
    }
}
