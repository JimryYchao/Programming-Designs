pub trait IShape {
    fn draw(&self);
    fn fill(&self);
}

#[derive(Eq, Hash, PartialEq, Debug)]
pub enum ShapeKind {
    Unknown,
    Circle,
    Square,
    Rectangle,
    BigCircle,
}

pub struct Circle;

impl IShape for Circle {
    fn draw(&self) {
        println!("Draw a Circle");
    }
    
    fn fill(&self) {
        println!("Fill red");
    }
}

pub struct Square;

impl IShape for Square {
    fn draw(&self) {
        println!("Draw a Square");
    }
    
    fn fill(&self) {
        println!("Fill Green");
    }
}

pub struct Rectangle;

impl IShape for Rectangle {
    fn draw(&self) {
        println!("Draw a Rectangle");
    }
    
    fn fill(&self) {
        println!("Fill Blue");
    }
}

pub struct UnknownShape;

impl IShape for UnknownShape {
    fn draw(&self) {}
    fn fill(&self) {}
}