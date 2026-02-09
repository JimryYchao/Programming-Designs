// concrete_factory.rs
// 具体工厂和工厂生产者

use super::abstract_factory::{AbstractFactory, Color, Shape};
use super::abstract_product::{Red, Green, Blue, Circle, Square, Rectangle};

// 具体工厂
pub struct ProductFactory<C, S>
where
    C: Color + Default,
    S: Shape + Default,
{
    _color: std::marker::PhantomData<C>,
    _shape: std::marker::PhantomData<S>,
}

impl<C, S> Default for ProductFactory<C, S>
where
    C: Color + Default,
    S: Shape + Default,
{
    fn default() -> Self {
        Self {
            _color: std::marker::PhantomData,
            _shape: std::marker::PhantomData,
        }
    }
}

impl<C, S> AbstractFactory for ProductFactory<C, S>
where
    C: Color + Default,
    S: Shape + Default,
{
    fn get_color(&self) -> Box<dyn Color> {
        Box::new(C::default())
    }
    
    fn get_shape(&self) -> Box<dyn Shape> {
        Box::new(S::default())
    }
}

// 工厂生产者
pub enum ProductKind {
    RedCircle,
    GreenSquare,
    BlueRectangle,
}

pub struct FactoryProducer {
    factories: std::collections::HashMap<ProductKind, Box<dyn AbstractFactory>>,
}

impl Default for FactoryProducer {
    fn default() -> Self {
        Self {
            factories: std::collections::HashMap::new(),
        }
    }
}

impl FactoryProducer {
    pub fn create_factory(&self, kind: ProductKind) -> Box<dyn AbstractFactory> {
        match kind {
            ProductKind::RedCircle => Box::new(ProductFactory::<Red, Circle>::default()),
            ProductKind::GreenSquare => Box::new(ProductFactory::<Green, Square>::default()),
            ProductKind::BlueRectangle => Box::new(ProductFactory::<Blue, Rectangle>::default()),
        }
    }
    
    pub fn get_factory(&mut self, kind: ProductKind) -> &mut Box<dyn AbstractFactory> {
        self.factories.entry(kind)
            .or_insert_with(|| self.create_factory(kind))
    }
}
