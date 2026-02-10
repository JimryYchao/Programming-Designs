use super::abstract_factory::{AbstractFactory, IColor, IShape};
use super::abstract_product::{Red, Green, Blue, Circle, Square, Rectangle};

// 具体工厂
pub struct ProductFactory<C, S>
where
    C: IColor + Default + 'static, 
    S: IShape + Default + 'static,
{
    _color: std::marker::PhantomData<C>,
    _shape: std::marker::PhantomData<S>,
}

impl<C, S> Default for ProductFactory<C, S>
where
    C: IColor + Default + 'static,
    S: IShape + Default + 'static,
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
    C: IColor + Default + 'static,
    S: IShape + Default + 'static,
{
    fn get_color(&self) -> Box<dyn IColor> {
        Box::new(C::default())
    }
    
    fn get_shape(&self) -> Box<dyn IShape> {
        Box::new(S::default())
    }
}

// 工厂生产者
#[derive(Eq, Hash, PartialEq, Clone)]
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
    pub fn CreateFactory(&self, kind: &ProductKind) -> Box<dyn AbstractFactory> {
        match kind {
            ProductKind::RedCircle => Box::new(ProductFactory::<Red, Circle>::default()),
            ProductKind::GreenSquare => Box::new(ProductFactory::<Green, Square>::default()),
            ProductKind::BlueRectangle => Box::new(ProductFactory::<Blue, Rectangle>::default()),
        }
    }
    
    pub fn GetFactory(&mut self, kind: ProductKind) -> &dyn AbstractFactory {
        // 检查是否存在该工厂
        if !self.factories.contains_key(&kind) {
            // 如果不存在，则创建新工厂
            self.factories.insert(kind.clone(), self.CreateFactory(&kind));
        }
        return self.factories.get(&kind).unwrap().as_ref();
    }
}
