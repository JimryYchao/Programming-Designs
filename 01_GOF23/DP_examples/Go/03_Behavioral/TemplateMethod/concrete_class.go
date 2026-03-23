package template_method

import "fmt"

// CoffeeMaker 咖啡制作类
type CoffeeMaker struct {
	AbstractBeverageMaker
}

// NewCoffeeMaker 创建咖啡制作实例
func NewCoffeeMaker() *CoffeeMaker {
	coffee := &CoffeeMaker{}
	coffee.BeverageMaker = coffee
	return coffee
}

// Brew 实现冲泡方法
func (cm *CoffeeMaker) Brew() {
	fmt.Println("Brewing coffee grounds")
}

// AddCondiments 实现添加调料方法
func (cm *CoffeeMaker) AddCondiments() {
	fmt.Println("Adding sugar and milk")
}

// CustomerWantsCondiments 重写钩子方法
func (cm *CoffeeMaker) CustomerWantsCondiments() bool {
	fmt.Println("Customer wants sugar and milk")
	return true
}

// TeaMaker 茶制作类
type TeaMaker struct {
	AbstractBeverageMaker
}

// NewTeaMaker 创建茶制作实例
func NewTeaMaker() *TeaMaker {
	tea := &TeaMaker{}
	tea.BeverageMaker = tea
	return tea
}

// Brew 实现冲泡方法
func (tm *TeaMaker) Brew() {
	fmt.Println("Steeping the tea bag")
}

// AddCondiments 实现添加调料方法
func (tm *TeaMaker) AddCondiments() {
	fmt.Println("Adding lemon")
}

// CustomerWantsCondiments 重写钩子方法
func (tm *TeaMaker) CustomerWantsCondiments() bool {
	fmt.Println("Customer wants lemon")
	return true
}
