package Factory_test

import (
	. "Factory"
	"testing"
)

func TestFactoryDemo(t *testing.T) {
	defer func() {
		if r := recover(); r != nil {
			t.Errorf("TestFactoryDemo panicked: %v", r)
		}
	}()

	// 测试圆形
	circle := ShapeFactory.GetShape(CIRCLE)
	circle.Draw()
	circle.Fill()

	// 测试大圆形
	bigCircle := ShapeFactory.GetShape(BIG_CIRCLE)
	bigCircle.Draw()
	bigCircle.Fill()

	// 测试正方形
	square := ShapeFactory.GetShape(SQUARE)
	square.Draw()
	square.Fill()
}
