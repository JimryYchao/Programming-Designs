use super::builder::{IPacker, Item};

// 包装器
pub struct Wrapper;

impl Wrapper {
    pub const INSTANCE: Wrapper = Wrapper;
}

impl IPacker for Wrapper {
    fn pack(&self, item: &dyn Item) {
        println!("Wrapper a {}", item.name());
    }
}

pub struct Bottle;

impl Bottle {
    pub const INSTANCE: Bottle = Bottle;
}

impl IPacker for Bottle {
    fn pack(&self, item: &dyn Item) {
        println!("Bottle a {}", item.name());
    }
}

// Item 实现
pub trait Burger: Item {}
pub trait ColdDrink: Item {}

pub struct VegetableBurger;

impl VegetableBurger {
    pub const INSTANCE: VegetableBurger = VegetableBurger;
}

impl Default for VegetableBurger {
    fn default() -> Self {
        Self::INSTANCE
    }
}

impl Item for VegetableBurger {
    fn name(&self) -> &str {
        "VegetableBurger"
    }
    
    fn price(&self) -> f32 {
        8.5
    }
    
    fn packer(&self) -> &dyn IPacker {
        &Wrapper::INSTANCE
    }
}

impl Burger for VegetableBurger {}

pub struct ChickenBurger;

impl ChickenBurger {
    pub const INSTANCE: ChickenBurger = ChickenBurger;
}

impl Default for ChickenBurger {
    fn default() -> Self {
        Self::INSTANCE
    }
}

impl Item for ChickenBurger {
    fn name(&self) -> &str {
        "ChickenBurger"
    }
    
    fn price(&self) -> f32 {
        15.0
    }
    
    fn packer(&self) -> &dyn IPacker {
        &Wrapper::INSTANCE
    }
}

impl Burger for ChickenBurger {}

pub struct CokeCola;

impl CokeCola {
    pub const INSTANCE: CokeCola = CokeCola;
}

impl Default for CokeCola {
    fn default() -> Self {
        Self::INSTANCE
    }
}

impl Item for CokeCola {
    fn name(&self) -> &str {
        "CokeCola"
    }
    
    fn price(&self) -> f32 {
        3.5
    }
    
    fn packer(&self) -> &dyn IPacker {
        &Bottle::INSTANCE
    }
}

impl ColdDrink for CokeCola {}

pub struct PepsiCola;

impl PepsiCola {
    pub const INSTANCE: PepsiCola = PepsiCola;
}

impl Default for PepsiCola {
    fn default() -> Self {
        Self::INSTANCE
    }
}

impl Item for PepsiCola {
    fn name(&self) -> &str {
        "PepsiCola"
    }
    
    fn price(&self) -> f32 {
        3.0
    }
    
    fn packer(&self) -> &dyn IPacker {
        &Bottle::INSTANCE
    }
}

impl ColdDrink for PepsiCola {}
