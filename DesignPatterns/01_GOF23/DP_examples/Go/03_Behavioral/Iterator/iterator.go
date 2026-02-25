package Iterator

// Iterator 迭代器接口
type Iterator[T any] interface {
	First()
	Next()
	IsDone() bool
	CurrentItem() T
}

// Iterable 可迭代接口
type Iterable[T any] interface {
	GetIterator() Iterator[T]
}

// IAggregate 聚合接口
type IAggregate[T any] interface {
	Iterable[T]
	Count() int
	Add(item T)
	Remove(item T) bool
	Contains(item T) bool
	Clear()
}
