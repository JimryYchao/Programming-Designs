package Flyweight

import "fmt"

// 形状接口
type IShape interface {
	Draw()
	Fill()
}

// 圆形数据
type CircleData struct {
	Color  string
	Radius float64
}

// 圆形实现
type Circle struct {
	*CircleData
	X float64
	Y float64
}

// 绘制圆形
func (c *Circle) Draw() {
	fmt.Printf("Draw a Circle with radius %.f at (%.f, %.f)\n", c.Radius, c.X, c.Y)
}

// 填充圆形
func (c *Circle) Fill() {
	fmt.Println("Fill with " + c.Color)
}

// 圆形工厂
type CircleFactory struct{}

// 获取圆形
func (cf *CircleFactory) GetCircle(color string, radius, x, y float64) *Circle {
	return &Circle{
		CircleData: &CircleData{Color: color, Radius: radius},
		X:          x,
		Y:          y,
	}
}

// 通过数据获取圆形
func (cf *CircleFactory) GetCircleByData(data *CircleData, x, y float64) *Circle {
	return &Circle{
		CircleData: data,
		X:          x,
		Y:          y,
	}
}

// 获取特殊圆形
func (cf *CircleFactory) GetSpacialCircle(circle *Circle) *CircleAddition {
	return &CircleAddition{Shape: circle}
}
