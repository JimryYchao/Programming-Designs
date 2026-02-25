use crate::iterator::{IAggregate, Iterable, Iterator};

const DEFAULT_CAPACITY: usize = 4;

// 具体聚合类
pub struct ConcreteAggregate<T> {
    array: Vec<T>,
    capacity: usize,
}

impl<T: PartialEq + Clone> ConcreteAggregate<T> {
    pub fn new(capacity: usize) -> Self {
        let capacity = if capacity < DEFAULT_CAPACITY { DEFAULT_CAPACITY } else { capacity };
        Self {
            array: Vec::with_capacity(capacity),
            capacity,
        }
    }
}

impl<T: PartialEq + Clone> IAggregate<T> for ConcreteAggregate<T> {
    fn count(&self) -> usize {
        self.array.len()
    }

    fn add(&mut self, item: T) {
        self.array.push(item);
    }

    fn remove(&mut self, item: &T) -> bool {
        if let Some(index) = self.array.iter().position(|x| x == item) {
            self.array.remove(index);
            true
        } else {
            false
        }
    }

    fn contains(&self, item: &T) -> bool {
        self.array.contains(item)
    }

    fn clear(&mut self) {
        self.array.clear();
    }
}

impl<T: PartialEq + Clone> Iterable<T> for ConcreteAggregate<T> {
    fn get_iterator(&self) -> Box<dyn Iterator<T> + '_> {
        Box::new(AggregateIterator::new(self))
    }
}

// 具体迭代器实现
pub struct AggregateIterator<'a, T> {
    aggregate: &'a ConcreteAggregate<T>,
    index: isize,
}

impl<'a, T: PartialEq + Clone> AggregateIterator<'a, T> {
    fn new(aggregate: &'a ConcreteAggregate<T>) -> Self {
        Self {
            aggregate,
            index: -1,
        }
    }
}

impl<'a, T: PartialEq + Clone> Iterator<T> for AggregateIterator<'a, T> {
    fn first(&mut self) {
        if self.aggregate.count() > 0 {
            self.index = 0;
        }
    }

    fn next(&mut self) {
        if self.index < self.aggregate.count() as isize {
            self.index += 1;
        }
    }

    fn is_done(&self) -> bool {
        self.index >= self.aggregate.count() as isize
    }

    fn current_item(&self) -> Option<T> {
        if self.index >= 0 && (self.index as usize) < self.aggregate.count() {
            Some(self.aggregate.array[self.index as usize].clone())
        } else {
            None
        }
    }
}
