pub trait AbstractFactory {
    fn get_color(&self) -> Box<dyn IColor>;
    fn get_shape(&self) -> Box<dyn IShape>;
}
pub trait IColor {
    fn fill(&self);
}

pub trait IShape {
    fn draw(&self);
}
