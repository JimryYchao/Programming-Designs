package Facade_test

import (
	. "Facade"
	"testing"
)

// 测试 Facade 模式
func TestFacadePattern(t *testing.T) {
	// 创建圆形
	circle := ShapeMaker.BuildShape(CIRCLE, 10)
	if circle != nil {
		circle.Draw()
	}

	// 创建矩形
	rectangle := ShapeMaker.BuildShape(RECTANGLE, 10, 20)
	if rectangle != nil {
		rectangle.Draw()
	}

	// 创建正方形
	square := ShapeMaker.BuildShape(SQUARE, 10)
	if square != nil {
		square.Draw()
	}
}
