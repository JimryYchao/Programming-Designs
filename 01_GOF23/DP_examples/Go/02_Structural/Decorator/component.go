package Decorator

import "fmt"

type Color int

const (
	UNKNOWN Color = iota
	RED
	GREEN
	BLUE
)

func (c Color) String() string {
	switch c {
	case UNKNOWN:
		return "unknown"
	case RED:
		return "red"
	case GREEN:
		return "green"
	case BLUE:
		return "blue"
	default:
		return "unknown"
	}
}

type IShape interface {
	Draw()
	Fill(color Color)
}

type Circle struct{}

func NewCircle() *Circle {
	return &Circle{}
}

func (c *Circle) Draw() {
	fmt.Println("Draw a Circle.")
}

func (c *Circle) Fill(color Color) {
	fmt.Printf("Fill with %s.\n", color)
}

type Rectangle struct{}

func NewRectangle() *Rectangle {
	return &Rectangle{}
}

func (r *Rectangle) Draw() {
	fmt.Println("Draw a Rectangle.")
}

func (r *Rectangle) Fill(color Color) {
	fmt.Printf("Fill with %s.\n", color)
}
