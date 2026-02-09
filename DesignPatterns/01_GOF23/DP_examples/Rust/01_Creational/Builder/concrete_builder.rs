// concrete_builder.rs
// 具体建造者

use super::builder::IBuilder;
use super::product::{VegetableBurger, ChickenBurger, CokeCola, PepsiCola};

// 汉堡建造者
pub struct BurgerBuilder<T: Default + super::builder::Item + 'static> {
    _marker: std::marker::PhantomData<T>,
}

impl<T: Default + super::builder::Item + 'static> Default for BurgerBuilder<T> {
    fn default() -> Self {
        Self {
            _marker: std::marker::PhantomData,
        }
    }
}

impl<T: Default + super::builder::Item + 'static> IBuilder for BurgerBuilder<T> {
    fn build(&self) -> Box<dyn super::builder::Item> {
        Box::new(T::default())
    }
}

// 冷饮建造者
pub struct ColdDrinkBuilder<T: Default + super::builder::Item + 'static> {
    _marker: std::marker::PhantomData<T>,
}

impl<T: Default + super::builder::Item + 'static> Default for ColdDrinkBuilder<T> {
    fn default() -> Self {
        Self {
            _marker: std::marker::PhantomData,
        }
    }
}

impl<T: Default + super::builder::Item + 'static> IBuilder for ColdDrinkBuilder<T> {
    fn build(&self) -> Box<dyn super::builder::Item> {
        Box::new(T::default())
    }
}

// 套餐建造者接口
pub trait IMealBuilder {
    fn get_builders(&self) -> Vec<Box<dyn IBuilder>>;
}

// 鸡肉套餐建造者
pub struct ChickenMealBuilder;

impl IMealBuilder for ChickenMealBuilder {
    fn get_builders(&self) -> Vec<Box<dyn IBuilder>> {
        vec![
            Box::new(BurgerBuilder::<ChickenBurger>::default()),
            Box::new(ColdDrinkBuilder::<PepsiCola>::default()),
        ]
    }
}

// 素食套餐建造者
pub struct VegMealBuilder;

impl IMealBuilder for VegMealBuilder {
    fn get_builders(&self) -> Vec<Box<dyn IBuilder>> {
        vec![
            Box::new(BurgerBuilder::<VegetableBurger>::default()),
            Box::new(ColdDrinkBuilder::<CokeCola>::default()),
        ]
    }
}
