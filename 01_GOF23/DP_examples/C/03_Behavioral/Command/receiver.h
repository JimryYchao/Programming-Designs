// 接收者接口和实现
#ifndef RECEIVER_H
#define RECEIVER_H

typedef struct Stock {
    char* name;
    int quantity;
} Stock;

typedef struct BuyStock {
    Stock stock;
} BuyStock;

typedef struct SellStock {
    Stock stock;
} SellStock;

Stock create_stock(const char* name, int quantity);
BuyStock* create_buy_stock(Stock stock);
void buy_stock_action(void* receiver);
SellStock* create_sell_stock(Stock stock);
void sell_stock_action(void* receiver);
void destroy_buy_stock(BuyStock* stock);
void destroy_sell_stock(SellStock* stock);

#endif // RECEIVER_H
