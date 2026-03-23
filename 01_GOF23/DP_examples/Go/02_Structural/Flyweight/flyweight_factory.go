package Flyweight

import "fmt"

// 享元工厂
type FlyweightFactory struct {
	shapeDic      map[string]map[float64]*CircleData
	circleFactory CircleFactory
}

// 单例实例
var instance *FlyweightFactory

// 获取单例实例
func GetFlyweightFactory() *FlyweightFactory {
	if instance == nil {
		instance = &FlyweightFactory{
			shapeDic:      make(map[string]map[float64]*CircleData),
			circleFactory: CircleFactory{},
		}
	}
	return instance
}

// 获取圆形
func (ff *FlyweightFactory) GetCircle(color string, radius, x, y float64) *Circle {
	var circle *Circle

	if dic, ok := ff.shapeDic[color]; ok {
		if data, ok := dic[radius]; ok {
			return ff.circleFactory.GetCircleByData(data, x, y)
		} else {
			circle = ff.circleFactory.GetCircle(color, radius, x, y)
			dic[radius] = circle.CircleData
		}
	} else {
		dic := make(map[float64]*CircleData)
		circle = ff.circleFactory.GetCircle(color, radius, x, y)
		dic[radius] = circle.CircleData
		ff.shapeDic[color] = dic
	}
	fmt.Println("Create a New Circle Filled with " + color)
	return circle
}

// 获取特殊圆形
func (ff *FlyweightFactory) GetSpecialCircle(color string, radius, x, y float64) *CircleAddition {
	return ff.circleFactory.GetSpacialCircle(ff.GetCircle(color, radius, x, y))
}
