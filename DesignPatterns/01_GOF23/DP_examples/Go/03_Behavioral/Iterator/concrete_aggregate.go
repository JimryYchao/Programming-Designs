package Iterator

import "reflect"

const defaultCapacity = 4

// ConcreteAggregate 具体聚合类
type ConcreteAggregate[T any] struct {
	array    []T
	capacity int
}

// NewConcreteAggregate 创建具体聚合对象
func NewConcreteAggregate[T any](capacity int) *ConcreteAggregate[T] {
	if capacity < defaultCapacity {
		capacity = defaultCapacity
	}
	return &ConcreteAggregate[T]{
		array:    make([]T, 0, capacity),
		capacity: capacity,
	}
}

// Count 返回元素数量
func (c *ConcreteAggregate[T]) Count() int {
	return len(c.array)
}

// Add 添加元素
func (c *ConcreteAggregate[T]) Add(item T) {
	c.array = append(c.array, item)
}

// Remove 移除元素
func (c *ConcreteAggregate[T]) Remove(item T) bool {
	for i, v := range c.array {
		if reflect.DeepEqual(v, item) {
			c.array = append(c.array[:i], c.array[i+1:]...)
			return true
		}
	}
	return false
}

// Contains 检查元素是否存在
func (c *ConcreteAggregate[T]) Contains(item T) bool {
	for _, v := range c.array {
		if reflect.DeepEqual(v, item) {
			return true
		}
	}
	return false
}

// Clear 清空元素
func (c *ConcreteAggregate[T]) Clear() {
	c.array = make([]T, 0, c.capacity)
}

// AggregateIterator 具体迭代器实现
type AggregateIterator[T any] struct {
	aggregate *ConcreteAggregate[T]
	index     int
}

// NewAggregateIterator 创建迭代器
func NewAggregateIterator[T any](aggregate *ConcreteAggregate[T]) *AggregateIterator[T] {
	return &AggregateIterator[T]{
		aggregate: aggregate,
		index:     -1,
	}
}

// First 移动到第一个元素
func (i *AggregateIterator[T]) First() {
	if len(i.aggregate.array) > 0 {
		i.index = 0
	}
}

// Next 移动到下一个元素
func (i *AggregateIterator[T]) Next() {
	if i.index < len(i.aggregate.array) {
		i.index++
	}
}

// IsDone 检查是否迭代完成
func (i *AggregateIterator[T]) IsDone() bool {
	return i.index >= len(i.aggregate.array)
}

// CurrentItem 获取当前元素
func (i *AggregateIterator[T]) CurrentItem() T {
	if i.index >= 0 && i.index < len(i.aggregate.array) {
		return i.aggregate.array[i.index]
	}
	var zero T
	return zero
}

// GetIterator 获取迭代器
func (c *ConcreteAggregate[T]) GetIterator() Iterator[T] {
	return NewAggregateIterator(c)
}
