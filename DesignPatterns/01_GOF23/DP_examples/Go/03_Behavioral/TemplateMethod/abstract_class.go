package template_method

import "fmt"

// BeverageMaker 饮料制作抽象类
type BeverageMaker interface {
	MakeBeverage()
	Brew()
	AddCondiments()
	CustomerWantsCondiments() bool
}

// AbstractBeverageMaker 抽象实现
type AbstractBeverageMaker struct {
	BeverageMaker
}

// MakeBeverage 模板方法：制作饮料的流程
func (ab *AbstractBeverageMaker) MakeBeverage() {
	ab.boilWater()
	ab.Brew()
	ab.pourInCup()
	if ab.CustomerWantsCondiments() {
		ab.AddCondiments()
	}
}

// boilWater 具体方法：烧水
func (ab *AbstractBeverageMaker) boilWater() {
	fmt.Println("Boiling water")
}

// pourInCup 具体方法：倒入杯子
func (ab *AbstractBeverageMaker) pourInCup() {
	fmt.Println("Pouring into cup")
}

// CustomerWantsCondiments 钩子方法：顾客是否需要调料
func (ab *AbstractBeverageMaker) CustomerWantsCondiments() bool {
	return true
}
