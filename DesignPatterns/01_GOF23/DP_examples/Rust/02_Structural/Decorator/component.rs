#[derive(Debug)]
pub enum Color {
    Unknown,
    Red,
    Green,
    Blue,
}

pub trait IShape {
    fn draw(&self);
    fn fill(&self, color: Color);
}
