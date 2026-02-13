package Prototype_test

import (
	. "Prototype"
	"testing"
)

func TestPrototypePattern(t *testing.T) {
	// 获取形状缓存实例
	cache := ShapeCache_GetInstance()

	// 克隆不同形状
	circle := cache.GetShape(CIRCLE)
	if circle == nil {
		t.Errorf("Failed to get circle shape")
	}
	circle.Draw()
	circle.Fill(Red)

	square := cache.GetShape(SQUARE)
	if square == nil {
		t.Errorf("Failed to get square shape")
	}
	square.Draw()
	square.Fill(Green)

	cache.RemovePrototype(CIRCLE)

	circle = cache.GetShape(CIRCLE)
	if circle != nil {
		t.Errorf("Failed to remove circle prototype")
	}
}
