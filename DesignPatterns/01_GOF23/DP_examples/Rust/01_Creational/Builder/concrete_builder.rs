use super::builder::{IBuilder, Item, ItemKind};
use super::product::{Burger, ColdDrink, VegetableBurger, ChickenBurger, CokeCola, PepsiCola};

// 汉堡建造者
pub struct BurgerBuilder<T: Burger + Default + 'static> {
    _marker: std::marker::PhantomData<T>,
}

impl<T: Burger + Default + 'static> BurgerBuilder<T> {
    pub const INSTANCE: BurgerBuilder<T> = BurgerBuilder {
        _marker: std::marker::PhantomData,
    };
}

impl<T: Burger + Default + 'static> Default for BurgerBuilder<T> {
    fn default() -> Self {
        Self::INSTANCE
    }
}

impl<T: Burger + Default + 'static> IBuilder for BurgerBuilder<T> {
    fn build(&self) -> Box<dyn Item> {
        Box::new(T::default())
    }
}

// 冷饮建造者
pub struct ColdDrinkBuilder<T: ColdDrink + Default + 'static> {
    _marker: std::marker::PhantomData<T>,
}

impl<T: ColdDrink + Default + 'static> ColdDrinkBuilder<T> {
    pub const INSTANCE: ColdDrinkBuilder<T> = ColdDrinkBuilder {
        _marker: std::marker::PhantomData,
    };
}

impl<T: ColdDrink + Default + 'static> Default for ColdDrinkBuilder<T> {
    fn default() -> Self {
        Self::INSTANCE
    }
}

impl<T: ColdDrink + Default + 'static> IBuilder for ColdDrinkBuilder<T> {
    fn build(&self) -> Box<dyn Item> {
        Box::new(T::default())
    }
}

// 套餐建造者接口
pub trait IMealBuilder {
    fn get_builders(&self) -> Vec<Box<dyn IBuilder>>;
}

// 鸡肉套餐建造者
pub struct ChickenMealBuilder;

impl ChickenMealBuilder {
    pub const INSTANCE: ChickenMealBuilder = ChickenMealBuilder;
}

impl IMealBuilder for ChickenMealBuilder {
    fn get_builders(&self) -> Vec<Box<dyn IBuilder>> {
        vec![
            Box::new(BurgerBuilder::<ChickenBurger>::INSTANCE),
            Box::new(ColdDrinkBuilder::<PepsiCola>::INSTANCE),
        ]
    }
}

impl Default for ChickenMealBuilder {
    fn default() -> Self {
        Self::INSTANCE
    }
}

// 素食套餐建造者
pub struct VegMealBuilder;

impl VegMealBuilder {
    pub const INSTANCE: VegMealBuilder = VegMealBuilder;
}

impl IMealBuilder for VegMealBuilder {
    fn get_builders(&self) -> Vec<Box<dyn IBuilder>> {
        vec![
            Box::new(BurgerBuilder::<VegetableBurger>::INSTANCE),
            Box::new(ColdDrinkBuilder::<CokeCola>::INSTANCE),
        ]
    }
}

impl Default for VegMealBuilder {
    fn default() -> Self {
        Self::INSTANCE
    }
}

// Meal Product
pub struct MealBuilder {
    builders: Vec<Box<dyn IBuilder>>,
    items: Vec<Box<dyn Item>>,
}

impl MealBuilder {
    pub fn new(builders: Vec<Box<dyn IBuilder>>) -> Self {
        Self {
            builders: builders,
            items: Vec::new(),
        }
    }
    
    pub fn add(&mut self, kind: ItemKind) {
        let builder: Box<dyn IBuilder> = match kind {
            ItemKind::VegetableBurger => Box::new(BurgerBuilder::<VegetableBurger>::INSTANCE),
            ItemKind::ChickenBurger => Box::new(BurgerBuilder::<ChickenBurger>::INSTANCE),
            ItemKind::CokeCola => Box::new(ColdDrinkBuilder::<CokeCola>::INSTANCE),
            ItemKind::PepsiCola => Box::new(ColdDrinkBuilder::<PepsiCola>::INSTANCE),
        };
        self.builders.push(builder);
    }
    
    pub fn remove(&mut self, kind: ItemKind) {
        let builder_to_remove: Box<dyn IBuilder> = match kind {
            ItemKind::VegetableBurger => Box::new(BurgerBuilder::<VegetableBurger>::INSTANCE),
            ItemKind::ChickenBurger => Box::new(BurgerBuilder::<ChickenBurger>::INSTANCE),
            ItemKind::CokeCola => Box::new(ColdDrinkBuilder::<CokeCola>::INSTANCE),
            ItemKind::PepsiCola => Box::new(ColdDrinkBuilder::<PepsiCola>::INSTANCE),
        };
        
        self.builders.retain(|b| !std::ptr::eq(b.as_ref() as *const dyn IBuilder, builder_to_remove.as_ref() as *const dyn IBuilder));
    }
    
    pub fn build(&mut self) {
        self.items.clear();
        for builder in &self.builders {
            self.items.push(builder.build());
        }
    }
    
    pub fn pack(&self) {
        for item in &self.items {
            item.packer().pack(item.as_ref());
        }
    }
    
    pub fn get_cost(&self) -> f32 {
        self.items.iter().map(|item| item.price()).sum()
    }
}
