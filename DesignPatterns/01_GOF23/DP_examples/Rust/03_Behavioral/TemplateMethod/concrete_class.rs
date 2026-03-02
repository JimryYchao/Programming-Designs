// 具体饮料实现
use crate::abstract_class::BeverageMaker;

// 咖啡制作类
pub struct CoffeeMaker;

impl BeverageMaker for CoffeeMaker {
    // 实现冲泡方法
    fn brew(&self) {
        println!("Brewing coffee grounds");
    }
    
    // 实现添加调料方法
    fn add_condiments(&self) {
        println!("Adding sugar and milk");
    }
    
    // 重写钩子方法
    fn customer_wants_condiments(&self) -> bool {
        println!("Customer wants sugar and milk");
        true
    }
}

// 茶制作类
pub struct TeaMaker;

impl BeverageMaker for TeaMaker {
    // 实现冲泡方法
    fn brew(&self) {
        println!("Steeping the tea bag");
    }
    
    // 实现添加调料方法
    fn add_condiments(&self) {
        println!("Adding lemon");
    }
    
    // 重写钩子方法
    fn customer_wants_condiments(&self) -> bool {
        println!("Customer wants lemon");
        true
    }
}
