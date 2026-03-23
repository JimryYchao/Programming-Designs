-- 接收者实现

local function create_stock(name, quantity)
    return {
        name = name,
        quantity = quantity
    }
end

local IReceiver = {
    action = function(self)
        error("Subclass must implement action method")
    end
}

function IReceiver:new(o)
    o = o or {}
    setmetatable(o, self)
    self.__index = self
    return o
end

local BuyStock = IReceiver:new()

function BuyStock:new(stock)
    local o = IReceiver:new()
    setmetatable(o, self)
    self.__index = self
    o.stock = stock
    return o
end

function BuyStock:buy_stocks()
    print("Buy " .. self.stock.quantity .. " Stocks which name is " .. self.stock.name)
end

function BuyStock:action()
    self:buy_stocks()
end

local SellStock = IReceiver:new()

function SellStock:new(stock)
    local o = IReceiver:new()
    setmetatable(o, self)
    self.__index = self
    o.stock = stock
    return o
end

function SellStock:sell_stocks()
    print("Sell " .. self.stock.quantity .. " Stocks which name is " .. self.stock.name)
end

function SellStock:action()
    self:sell_stocks()
end

return {
    create_stock = create_stock,
    IReceiver = IReceiver,
    BuyStock = BuyStock,
    SellStock = SellStock
}
