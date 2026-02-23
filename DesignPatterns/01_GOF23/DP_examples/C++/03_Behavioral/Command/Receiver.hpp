// 接收者实现
#ifndef RECEIVER_HPP
#define RECEIVER_HPP

#include <iostream>
#include <string>
#include "Command.hpp"

struct Stock {
    std::string name;
    int quantity;
    
    Stock(const std::string& name, int quantity) : name(name), quantity(quantity) {}
};

class BuyStock : public IReceiver {
private:
    Stock stock;
public:
    BuyStock(const Stock& stock) : stock(stock) {}
    void buyStocks() {
        std::cout << "Buy " << stock.quantity << " Stocks which name is " << stock.name << std::endl;
    }
    void action() override {
        buyStocks();
    }
};

class SellStock : public IReceiver {
private:
    Stock stock;
public:
    SellStock(const Stock& stock) : stock(stock) {}
    void sellStocks() {
        std::cout << "Sell " << stock.quantity << " Stocks which name is " << stock.name << std::endl;
    }
    void action() override {
        sellStocks();
    }
};

#endif // RECEIVER_HPP
