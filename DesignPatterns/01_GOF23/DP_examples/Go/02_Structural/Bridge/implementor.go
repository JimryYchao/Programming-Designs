package Bridge

import "fmt"

// 颜色枚举
type Color int

const (
	Unknown Color = iota
	Red
	Green
	Blue
)

func (c Color) String() string {
	switch c {
	case Red:
		return "red"
	case Green:
		return "green"
	case Blue:
		return "blue"
	default:
		return "unknown"
	}
}

// 实现接口
type DrawAPI interface {
	Draw()
	Fill(color Color)
}

type drawAPI_Impl struct{}

func (d *drawAPI_Impl) Draw() {}
func (d *drawAPI_Impl) Fill(color Color) {
	fmt.Println("Fill with", color)
}

// 圆形实现
type Circle struct {
	drawAPI_Impl
}

func (c *Circle) Draw() {
	fmt.Println("Draw a Circle")
}

// 正方形实现
type Square struct {
	drawAPI_Impl
}

func (s *Square) Draw() {
	fmt.Println("Draw a Square")
}

// 矩形实现
type Rectangle struct{}

func (r *Rectangle) Draw() {
	fmt.Println("Draw a Rectangle")
}

// 大圆形实现
type BigCircle struct {
	Circle
}

func (bc *BigCircle) Draw() {
	fmt.Println("Draw a Big Circle")
}
