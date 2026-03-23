package Builder

import "fmt"

// 包装器
type wrapper struct{}

var wrapper_Instance IPacker = wrapper{}

func (w wrapper) Pack(item Item) {
	fmt.Printf("Wrapper a %s\n", item.Name())
}

type bottle struct{}

var bottle_Instance IPacker = bottle{}

func (b bottle) Pack(item Item) {
	fmt.Printf("Bottle a %s\n", item.Name())
}

// 产品类型
type ItemKind int

const (
	VEGETABLE_BURGER ItemKind = iota
	CHICKEN_BURGER
	COKE_COLA
	PEPSI_COLA
)

type (
	burger interface {
		vegetableBurger | chickenBurger
		Item
	}
	coldDrink interface {
		cokeCola | pepsiCola
		Item
	}
)
type vegetableBurger struct{}

func (v vegetableBurger) Name() string {
	return "VegetableBurger"
}

func (v vegetableBurger) Price() float64 {
	return 8.5
}

func (v vegetableBurger) Packer() IPacker {
	return wrapper_Instance
}

type chickenBurger struct{}

func (c chickenBurger) Name() string {
	return "ChickenBurger"
}

func (c chickenBurger) Price() float64 {
	return 15.0
}

func (c chickenBurger) Packer() IPacker {
	return wrapper_Instance
}

type cokeCola struct{}

func (c cokeCola) Name() string {
	return "CokeCola"
}

func (c cokeCola) Price() float64 {
	return 3.5
}

func (c cokeCola) Packer() IPacker {
	return bottle_Instance
}

type pepsiCola struct{}

func (p pepsiCola) Name() string {
	return "PepsiCola"
}

func (p pepsiCola) Price() float64 {
	return 3.0
}

func (p pepsiCola) Packer() IPacker {
	return bottle_Instance
}
