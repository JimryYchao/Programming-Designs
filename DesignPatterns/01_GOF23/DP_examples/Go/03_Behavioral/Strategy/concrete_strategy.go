package strategy

// BubbleSortStrategy 冒泡排序策略
type BubbleSortStrategy struct{}

// NewBubbleSortStrategy 创建冒泡排序策略实例
func NewBubbleSortStrategy() *BubbleSortStrategy {
	return &BubbleSortStrategy{}
}

// Sort 实现排序方法
func (s *BubbleSortStrategy) Sort(array []int) {
	n := len(array)
	for i := 0; i < n-1; i++ {
		for j := 0; j < n-i-1; j++ {
			if array[j] > array[j+1] {
				array[j], array[j+1] = array[j+1], array[j]
			}
		}
	}
}

// QuickSortStrategy 快速排序策略
type QuickSortStrategy struct{}

// NewQuickSortStrategy 创建快速排序策略实例
func NewQuickSortStrategy() *QuickSortStrategy {
	return &QuickSortStrategy{}
}

// Sort 实现排序方法
func (s *QuickSortStrategy) Sort(array []int) {
	quickSort(array, 0, len(array)-1)
}

func quickSort(array []int, low, high int) {
	if low < high {
		pi := partition(array, low, high)
		quickSort(array, low, pi-1)
		quickSort(array, pi+1, high)
	}
}

func partition(array []int, low, high int) int {
	pivot := array[high]
	i := low - 1
	for j := low; j < high; j++ {
		if array[j] <= pivot {
			i++
			array[i], array[j] = array[j], array[i]
		}
	}
	array[i+1], array[high] = array[high], array[i+1]
	return i + 1
}

// InsertionSortStrategy 插入排序策略
type InsertionSortStrategy struct{}

// NewInsertionSortStrategy 创建插入排序策略实例
func NewInsertionSortStrategy() *InsertionSortStrategy {
	return &InsertionSortStrategy{}
}

// Sort 实现排序方法
func (s *InsertionSortStrategy) Sort(array []int) {
	n := len(array)
	for i := 1; i < n; i++ {
		key := array[i]
		j := i - 1
		for j >= 0 && array[j] > key {
			array[j+1] = array[j]
			j--
		}
		array[j+1] = key
	}
}

// SelectionSortStrategy 选择排序策略
type SelectionSortStrategy struct{}

// NewSelectionSortStrategy 创建选择排序策略实例
func NewSelectionSortStrategy() *SelectionSortStrategy {
	return &SelectionSortStrategy{}
}

// Sort 实现排序方法
func (s *SelectionSortStrategy) Sort(array []int) {
	n := len(array)
	for i := 0; i < n-1; i++ {
		minIndex := i
		for j := i + 1; j < n; j++ {
			if array[j] < array[minIndex] {
				minIndex = j
			}
		}
		array[i], array[minIndex] = array[minIndex], array[i]
	}
}
