pub trait IBuilder {
    fn build(&self) -> Box<dyn Item>;
}

pub trait IPacker {
    fn pack(&self, item: &dyn Item);
}

pub trait Item {
    fn name(&self) -> &str;
    fn price(&self) -> f32;
    fn packer(&self) -> &dyn IPacker;
}

pub enum ItemKind {
    VegetableBurger,
    ChickenBurger,
    CokeCola,
    PepsiCola,
}
