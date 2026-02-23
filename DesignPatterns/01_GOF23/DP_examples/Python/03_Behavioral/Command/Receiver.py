# 接收者实现


class Stock:
    def __init__(self, name, quantity):
        self.name = name
        self.quantity = quantity


class IReceiver:
    def action(self):
        pass


class BuyStock(IReceiver):
    def __init__(self, stock):
        self.stock = stock
    
    def buy_stocks(self):
        print(f"Buy {self.stock.quantity} Stocks which name is {self.stock.name}")
    
    def action(self):
        self.buy_stocks()


class SellStock(IReceiver):
    def __init__(self, stock):
        self.stock = stock
    
    def sell_stocks(self):
        print(f"Sell {self.stock.quantity} Stocks which name is {self.stock.name}")
    
    def action(self):
        self.sell_stocks()
