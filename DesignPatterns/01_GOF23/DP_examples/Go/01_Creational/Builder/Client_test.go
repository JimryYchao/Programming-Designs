package Builder_test

import (
	. "Builder"
	"fmt"
	"testing"
)

func TestBuilderDemo(t *testing.T) {
	director := Director[VegMealBuilder]{}
	meal := director.Construct()
	meal.Add(CHICKEN_BURGER)
	meal.Remove(VEGETABLE_BURGER)
	meal.Build()
	meal.Pack()
	fmt.Printf("Total Cost: %.2f\n", meal.GetCost())
}
