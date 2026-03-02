package template_method

import (
	"fmt"
	"testing"
)

func TestTemplateMethodPattern(t *testing.T) {
	// 制作咖啡
	fmt.Println("Making coffee:")
	coffee := NewCoffeeMaker()
	coffee.MakeBeverage()

	fmt.Println("")

	// 制作茶
	fmt.Println("Making tea:")
	tea := NewTeaMaker()
	tea.MakeBeverage()
}
