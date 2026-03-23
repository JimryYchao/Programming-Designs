package Iterator_test

import (
	. "Iterator"
	"fmt"
	"testing"
)

// IteratorEngine 迭代器引擎
type IteratorEngine[T any] struct{}

// Execute 执行迭代
func (e *IteratorEngine[T]) Execute(aggregate IAggregate[T], action func(T)) {
	iterator := aggregate.GetIterator()
	iterator.First()
	for !iterator.IsDone() {
		item := iterator.CurrentItem()
		action(item)
		iterator.Next()
	}
}

func TestIteratorPattern(t *testing.T) {
	// 创建聚合对象
	aggregate := NewConcreteAggregate[int](4)

	// 添加元素
	aggregate.Add(1)
	aggregate.Add(2)
	aggregate.Add(3)
	aggregate.Add(4)
	// 校验扩容
	aggregate.Add(5)
	aggregate.Add(6)

	// 执行迭代
	fmt.Println("Iterating over aggregate:")
	engine := &IteratorEngine[int]{}
	engine.Execute(aggregate, func(a int) {
		fmt.Printf("Print : number >> %d\n", a)
	})

	// 测试其他方法
	fmt.Printf("Count: %d\n", aggregate.Count())
	fmt.Printf("Contains 3: %v\n", aggregate.Contains(3))
	fmt.Printf("Remove 3: %v\n", aggregate.Remove(3))
	fmt.Printf("Contains 3 after removal: %v\n", aggregate.Contains(3))

	// 再次迭代
	fmt.Println("Iterating after removal:")
	engine.Execute(aggregate, func(a int) {
		fmt.Printf("Print : number >> %d\n", a)
	})

	// 清空
	aggregate.Clear()
	fmt.Printf("Count after clear: %d\n", aggregate.Count())
}
