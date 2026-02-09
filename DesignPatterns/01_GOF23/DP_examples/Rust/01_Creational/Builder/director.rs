// director.rs
// 指挥者

mod builder;
mod product;
mod concrete_builder;

use builder::{IBuilder, Item};

// Meal 产品
pub struct Meal {
    builders: Vec<Box<dyn IBuilder>>,
    items: Vec<Box<dyn Item>>,
}

impl Meal {
    pub fn new(builders: Vec<Box<dyn IBuilder>>) -> Self {
        Self {
            builders,
            items: Vec::new(),
        }
    }
    
    pub fn build(&mut self) {
        for builder in &self.builders {
            self.items.push(builder.build());
        }
    }
    
    pub fn pack(&self) {
        for item in &self.items {
            item.get_packer().pack(item.as_ref());
        }
    }
    
    pub fn get_cost(&self) -> f32 {
        self.items.iter().map(|item| item.get_price()).sum()
    }
}

// 指挥者
pub struct Director<B: concrete_builder::IMealBuilder> {
    _marker: std::marker::PhantomData<B>,
}

impl<B: concrete_builder::IMealBuilder + Default> Director<B> {
    pub fn construct() -> Meal {
        let builder = B::default();
        Meal::new(builder.get_builders())
    }
}
