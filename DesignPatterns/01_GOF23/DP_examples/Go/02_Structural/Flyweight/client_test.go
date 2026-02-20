package Flyweight_test

import (
	. "Flyweight"
	"testing"
)

// 构建圆形
func BuildCircles() {
	// 获取 FlyweightFactory 单例
	factory := GetFlyweightFactory()

	// 创建红色圆形
	redCircle := factory.GetCircle("Red", 10, 0, 0)
	redCircle.Draw()
	redCircle.Fill()

	// 创建特殊绿色大圆形
	greenBigCircle := factory.GetSpecialCircle("Green", 100, 100, 100)
	greenBigCircle.Draw()
	greenBigCircle.Fill()
	greenBigCircle.ResetRadius(10)
	greenBigCircle.MovePosition(0, 0)
}

// 构建享元圆形
func BuildFlyweightCircle() {
	// 获取 FlyweightFactory 单例
	factory := GetFlyweightFactory()

	// 创建红色圆形（复用之前的 CircleData）
	redCircle := factory.GetCircle("Red", 10, 10086, 10010)
	redCircle.Draw()
	redCircle.Fill()
}

// 测试 Flyweight 模式
func TestFlyweightPattern(t *testing.T) {
	BuildCircles()
	BuildFlyweightCircle()
}
