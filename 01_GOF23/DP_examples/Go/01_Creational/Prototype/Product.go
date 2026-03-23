package Prototype

import "fmt"

type Color int

const (
	Unknown Color = iota
	Red
	Green
	Blue
	Yellow
)

// 实现 Color 的 toString 方法
func (c Color) String() string {
	switch c {
	case Red:
		return "Red"
	case Green:
		return "Green"
	case Blue:
		return "Blue"
	case Yellow:
		return "Yellow"
	default:
		return "Unknown"
	}
}

type IShape interface {
	Name() string
	Draw()
	Fill(color Color)
	Clone() IShape
}

type ShapeKind = int

const (
	UNKNOWN_SHAPE ShapeKind = iota
	CIRCLE
	SQUARE
	RECTANGLE
)

type Shape struct {
	id   int
	name string
}

func (s *Shape) Name() string { return s.name }

func (s *Shape) Draw() {}

func (s *Shape) Fill(color Color) {}

type Circle struct {
	Shape
}

func NewCircle(id int, name string) *Circle {
	return &Circle{
		Shape: Shape{
			id:   id,
			name: name,
		},
	}
}
func (c *Circle) Draw() {
	fmt.Println("Draw a Circle")
}

func (c *Circle) Fill(color Color) {
	fmt.Println("Fill with", color)
}

func (c *Circle) Clone() IShape {
	return &Circle{
		Shape: Shape{
			id:   c.id,
			name: c.name,
		},
	}
}

type Square struct {
	Shape
}

func NewSquare(id int, name string) *Square {
	return &Square{
		Shape: Shape{
			id:   id,
			name: name,
		},
	}
}

func (s *Square) Draw() {
	fmt.Println("Draw a Square")
}

func (s *Square) Fill(color Color) {
	fmt.Println("Fill with", color)
}

func (s *Square) Clone() IShape {
	return &Square{
		Shape: Shape{
			id:   s.id,
			name: s.name,
		},
	}
}

type Rectangle struct {
	Shape
}

func NewRectangle(id int, name string) *Rectangle {
	return &Rectangle{
		Shape: Shape{
			id:   id,
			name: name,
		},
	}
}

func (r *Rectangle) Draw() {
	fmt.Println("Draw a Rectangle")
}

func (r *Rectangle) Fill(color Color) {
	fmt.Println("Fill with", color)
}

func (r *Rectangle) Clone() IShape {
	return &Rectangle{
		Shape: Shape{
			id:   r.id,
			name: r.name,
		},
	}
}
