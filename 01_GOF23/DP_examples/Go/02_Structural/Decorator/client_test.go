package Decorator_test

import (
	. "Decorator"
	"testing"
)

func TestDecoratorPattern(t *testing.T) {
	// 创建红色圆形
	redCircle := NewShapeDecorator(NewCircle())
	redCircle.Draw()
	redCircle.Fill(RED)

	// 创建绿色矩形
	greenRectangle := NewShapeDecorator(NewRectangle())
	greenRectangle.Draw()
	greenRectangle.Fill(GREEN)
}
