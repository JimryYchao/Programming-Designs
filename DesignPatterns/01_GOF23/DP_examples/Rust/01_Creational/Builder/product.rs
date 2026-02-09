// product.rs
// 产品和包装实现

use super::builder::{IPacker, Item};

// 包装器
pub struct Wrapper {
    item_name: String,
}

impl Wrapper {
    pub fn new(item_name: &str) -> Self {
        Self {
            item_name: item_name.to_string(),
        }
    }
}

impl IPacker for Wrapper {
    fn pack(&self, item: &dyn Item) {
        println!("Wrapper a {}", item.get_name());
    }
}

pub struct Bottle {
    item_name: String,
}

impl Bottle {
    pub fn new(item_name: &str) -> Self {
        Self {
            item_name: item_name.to_string(),
        }
    }
}

impl IPacker for Bottle {
    fn pack(&self, item: &dyn Item) {
        println!("Bottle a {}", item.get_name());
    }
}

// Item 实现
pub struct VegetableBurger {
    wrapper: Wrapper,
}

impl VegetableBurger {
    pub fn new() -> Self {
        Self {
            wrapper: Wrapper::new("VegetableBurger"),
        }
    }
}

impl Default for VegetableBurger {
    fn default() -> Self {
        Self::new()
    }
}

impl Item for VegetableBurger {
    fn get_name(&self) -> &str {
        "VegetableBurger"
    }
    
    fn get_price(&self) -> f32 {
        8.5
    }
    
    fn get_packer(&self) -> &dyn IPacker {
        &self.wrapper
    }
}

pub struct ChickenBurger {
    wrapper: Wrapper,
}

impl ChickenBurger {
    pub fn new() -> Self {
        Self {
            wrapper: Wrapper::new("ChickenBurger"),
        }
    }
}

impl Default for ChickenBurger {
    fn default() -> Self {
        Self::new()
    }
}

impl Item for ChickenBurger {
    fn get_name(&self) -> &str {
        "ChickenBurger"
    }
    
    fn get_price(&self) -> f32 {
        15.0
    }
    
    fn get_packer(&self) -> &dyn IPacker {
        &self.wrapper
    }
}

pub struct CokeCola {
    bottle: Bottle,
}

impl CokeCola {
    pub fn new() -> Self {
        Self {
            bottle: Bottle::new("CokeCola"),
        }
    }
}

impl Default for CokeCola {
    fn default() -> Self {
        Self::new()
    }
}

impl Item for CokeCola {
    fn get_name(&self) -> &str {
        "CokeCola"
    }
    
    fn get_price(&self) -> f32 {
        3.5
    }
    
    fn get_packer(&self) -> &dyn IPacker {
        &self.bottle
    }
}

pub struct PepsiCola {
    bottle: Bottle,
}

impl PepsiCola {
    pub fn new() -> Self {
        Self {
            bottle: Bottle::new("PepsiCola"),
        }
    }
}

impl Default for PepsiCola {
    fn default() -> Self {
        Self::new()
    }
}

impl Item for PepsiCola {
    fn get_name(&self) -> &str {
        "PepsiCola"
    }
    
    fn get_price(&self) -> f32 {
        3.0
    }
    
    fn get_packer(&self) -> &dyn IPacker {
        &self.bottle
    }
}
