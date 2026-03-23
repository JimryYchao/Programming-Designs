from Iterator import IAggregate, Iterator

DEFAULT_CAPACITY = 4

# 具体聚合类
class ConcreteAggregate(IAggregate):
    def __init__(self, capacity=DEFAULT_CAPACITY):
        self.capacity = max(capacity, DEFAULT_CAPACITY)
        self.array = []
    
    def count(self):
        return len(self.array)
    
    def add(self, item):
        self.array.append(item)
    
    def remove(self, item):
        if item in self.array:
            self.array.remove(item)
            return True
        return False
    
    def contains(self, item):
        return item in self.array
    
    def clear(self):
        self.array = []
    
    def get_iterator(self):
        return AggregateIterator(self)

# 具体迭代器实现
class AggregateIterator(Iterator):
    def __init__(self, aggregate):
        self.aggregate = aggregate
        self.index = -1
    
    def first(self):
        if self.aggregate.count() > 0:
            self.index = 0
    
    def next(self):
        if self.index < self.aggregate.count():
            self.index += 1
    
    def is_done(self):
        return self.index >= self.aggregate.count()
    
    def current_item(self):
        if 0 <= self.index < self.aggregate.count():
            return self.aggregate.array[self.index]
        raise IndexError("Iterator out of range")
