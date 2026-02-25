// 迭代器接口
pub trait Iterator<T> {
    fn first(&mut self);
    fn next(&mut self);
    fn is_done(&self) -> bool;
    fn current_item(&self) -> Option<T>;
}

// 可迭代接口
pub trait Iterable<T> {
    fn get_iterator(&self) -> Box<dyn Iterator<T> + '_>;
}

// 聚合接口
pub trait IAggregate<T>: Iterable<T> {
    fn count(&self) -> usize;
    fn add(&mut self, item: T);
    fn remove(&mut self, item: &T) -> bool;
    fn contains(&self, item: &T) -> bool;
    fn clear(&mut self);
}
