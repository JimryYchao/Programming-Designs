package Command

import "fmt"

type Stock struct {
	Name     string
	Quantity int
}
type IReceiver interface {
	Action()
}

type BuyStock struct {
	stock Stock
}

func NewBuyStock(stock Stock) *BuyStock {
	return &BuyStock{
		stock: stock,
	}
}

func (b *BuyStock) BuyStocks() {
	fmt.Printf("Buy %d Stocks which name is %s\n", b.stock.Quantity, b.stock.Name)
}

func (b *BuyStock) Action() {
	b.BuyStocks()
}

type SellStock struct {
	stock Stock
}

func NewSellStock(stock Stock) *SellStock {
	return &SellStock{
		stock: stock,
	}
}

func (s *SellStock) SellStocks() {
	fmt.Printf("Sell %d Stocks which name is %s\n", s.stock.Quantity, s.stock.Name)
}

func (s *SellStock) Action() {
	s.SellStocks()
}
