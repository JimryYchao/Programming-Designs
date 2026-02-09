// abstract_factory.rs
// 抽象工厂

pub trait AbstractFactory {
    fn get_color(&self) -> Box<dyn Color>;
    fn get_shape(&self) -> Box<dyn Shape>;
}

pub trait Color {
    fn fill(&self);
}

pub trait Shape {
    fn draw(&self);
}
