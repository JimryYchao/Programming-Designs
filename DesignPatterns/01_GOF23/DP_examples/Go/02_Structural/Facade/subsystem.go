package Facade

import "fmt"

// 形状接口
type IShape interface {
	Draw()
}

// 圆形实现
type Circle struct {
	radius int
}

// 创建圆形
func NewCircle(radius int) *Circle {
	return &Circle{
		radius: radius,
	}
}

// 绘制圆形
func (c *Circle) Draw() {
	fmt.Printf("Draw a circle with radius %d\n", c.radius)
}

// 矩形实现
type Rectangle struct {
	width  int
	height int
}

// 创建矩形
func NewRectangle(width, height int) *Rectangle {
	return &Rectangle{
		width:  width,
		height: height,
	}
}

// 绘制矩形
func (r *Rectangle) Draw() {
	fmt.Printf("Draw a rectangle with width %d and height %d\n", r.width, r.height)
}

// 正方形实现
type Square struct {
	side int
}

// 创建正方形
func NewSquare(side int) *Square {
	return &Square{
		side: side,
	}
}

// 绘制正方形
func (s *Square) Draw() {
	fmt.Printf("Draw a square with side %d\n", s.side)
}
