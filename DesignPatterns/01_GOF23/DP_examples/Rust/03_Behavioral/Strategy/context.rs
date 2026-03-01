// 上下文类
use crate::strategy::IStrategy;

pub struct Context {
    strategy: Box<dyn IStrategy>,
}

impl Context {
    pub fn new(strategy: Box<dyn IStrategy>) -> Self {
        Self {
            strategy,
        }
    }
    
    pub fn set_strategy(&mut self, strategy: Box<dyn IStrategy>) {
        self.strategy = strategy;
    }
    
    pub fn sort(&self, array: &mut [i32]) {
        self.strategy.sort(array);
    }
}
