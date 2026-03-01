package strategy

import (
	"fmt"
	"testing"
)

func TestStrategyPattern(t *testing.T) {
	array := []int{64, 34, 25, 12, 22, 11, 90}
	
	fmt.Println("Original array:")
	printArray(array)
	
	// 冒泡排序
	fmt.Println("\nUsing Bubble Sort:")
	bubbleSortArray := make([]int, len(array))
	copy(bubbleSortArray, array)
	context := NewContext(NewBubbleSortStrategy())
	context.Sort(bubbleSortArray)
	printArray(bubbleSortArray)
	
	// 快速排序
	fmt.Println("\nUsing Quick Sort:")
	quickSortArray := make([]int, len(array))
	copy(quickSortArray, array)
	context.SetStrategy(NewQuickSortStrategy())
	context.Sort(quickSortArray)
	printArray(quickSortArray)
	
	// 插入排序
	fmt.Println("\nUsing Insertion Sort:")
	insertionSortArray := make([]int, len(array))
	copy(insertionSortArray, array)
	context.SetStrategy(NewInsertionSortStrategy())
	context.Sort(insertionSortArray)
	printArray(insertionSortArray)
	
	// 选择排序
	fmt.Println("\nUsing Selection Sort:")
	selectionSortArray := make([]int, len(array))
	copy(selectionSortArray, array)
	context.SetStrategy(NewSelectionSortStrategy())
	context.Sort(selectionSortArray)
	printArray(selectionSortArray)
}

func printArray(array []int) {
	for _, item := range array {
		fmt.Printf("%d ", item)
	}
	fmt.Println()
}
