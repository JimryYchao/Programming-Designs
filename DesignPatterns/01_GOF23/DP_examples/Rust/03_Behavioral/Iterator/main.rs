mod iterator;
mod concrete_aggregate;

use concrete_aggregate::ConcreteAggregate;
use iterator::{IAggregate, Iterable, Iterator as MyIterator};

// 迭代器引擎
struct IteratorEngine;

impl IteratorEngine {
    fn execute<T: std::fmt::Debug + PartialEq + Clone>(aggregate: &ConcreteAggregate<T>, action: impl Fn(&T)) {
        let mut iterator = aggregate.get_iterator();
        iterator.first();
        while !iterator.is_done() {
            if let Some(item) = iterator.current_item() {
                action(&item);
            }
            iterator.next();
        }
    }
}

fn main() {
    // 创建聚合对象
    let mut aggregate: ConcreteAggregate<i32> = ConcreteAggregate::new(4);
    
    // 添加元素
    aggregate.add(1);
    aggregate.add(2);
    aggregate.add(3);
    aggregate.add(4);
    // 校验扩容
    aggregate.add(5);
    aggregate.add(6);
    
    // 执行迭代
    println!("Iterating over aggregate:");
    IteratorEngine::execute(&aggregate, |a| println!("Print : number >> {:?}", a));
    
    // 测试其他方法
    println!("Count: {}", aggregate.count());
    println!("Contains 3: {}", aggregate.contains(&3));
    println!("Remove 3: {}", aggregate.remove(&3));
    println!("Contains 3 after removal: {}", aggregate.contains(&3));
    
    // 再次迭代
    println!("Iterating after removal:");
    IteratorEngine::execute(&aggregate, |a| println!("Print : number >> {:?}", a));
    
    // 清空
    aggregate.clear();
    println!("Count after clear: {}", aggregate.count());
}
