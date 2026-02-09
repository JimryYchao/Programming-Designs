// builder.rs
// 建造者接口

pub trait IBuilder {
    fn build(&self) -> Box<dyn Item>;
}

pub trait IPacker {
    fn pack(&self, item: &dyn Item);
}

pub trait Item {
    fn get_name(&self) -> &str;
    fn get_price(&self) -> f32;
    fn get_packer(&self) -> &dyn IPacker;
}
