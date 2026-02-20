package Flyweight

import "fmt"

// 非共享具体享元类 - 圆形增强

type CircleAddition struct {
	Shape IShape
}

// 绘制
func (ca *CircleAddition) Draw() {
	ca.Shape.Draw()
}

// 填充
func (ca *CircleAddition) Fill() {
	ca.Shape.Fill()
}

// 移动位置
func (ca *CircleAddition) MovePosition(x, y float64) {
	fmt.Printf("Move Circle to (%.f, %.f)\n", x, y)
}

// 重置半径
func (ca *CircleAddition) ResetRadius(radius float64) {
	fmt.Printf("Reset Radius to %.f\n", radius)
}
