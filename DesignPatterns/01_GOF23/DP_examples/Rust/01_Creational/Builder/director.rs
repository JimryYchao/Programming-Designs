use super::concrete_builder::{IMealBuilder, MealBuilder};

// 指挥者
pub struct Director<B: IMealBuilder> {
    _marker: std::marker::PhantomData<B>,
}

impl<B: IMealBuilder + Default> Director<B> {
    pub fn construct() -> MealBuilder {
        let builder = B::default();
        MealBuilder::new(builder.get_builders())
    }
}
