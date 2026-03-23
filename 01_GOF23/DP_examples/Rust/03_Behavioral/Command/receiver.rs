// 接收者实现

// 接收者接口
pub trait IReceiver {
    fn action(&self);
}

// 股票结构体
pub struct Stock {
    pub name: String,
    pub quantity: i32,
}

impl Stock {
    pub fn new(name: &str, quantity: i32) -> Self {
        Stock {
            name: name.to_string(),
            quantity,
        }
    }
}

// 购买股票的接收者
pub struct BuyStock {
    stock: Stock,
}

impl BuyStock {
    pub fn new(stock: Stock) -> Self {
        BuyStock {
            stock,
        }
    }
    
    fn buy_stocks(&self) {
        println!("Buy {} Stocks which name is {}", self.stock.quantity, self.stock.name);
    }
}

impl IReceiver for BuyStock {
    fn action(&self) {
        self.buy_stocks();
    }
}

// 卖出股票的接收者
pub struct SellStock {
    stock: Stock,
}

impl SellStock {
    pub fn new(stock: Stock) -> Self {
        SellStock {
            stock,
        }
    }
    
    fn sell_stocks(&self) {
        println!("Sell {} Stocks which name is {}", self.stock.quantity, self.stock.name);
    }
}

impl IReceiver for SellStock {
    fn action(&self) {
        self.sell_stocks();
    }
}
