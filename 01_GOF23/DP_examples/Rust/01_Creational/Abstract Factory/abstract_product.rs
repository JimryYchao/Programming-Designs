use super::abstract_factory::{IColor, IShape};

// 具体产品 - 颜色
#[derive(Default)]
pub struct Red;
impl IColor for Red {
    fn fill(&self) {
        println!("Fill Red");
    }
}

#[derive(Default)]
pub struct Green;
impl IColor for Green {
    fn fill(&self) {
        println!("Fill Green");
    }
}

#[derive(Default)]
pub struct Blue;
impl IColor for Blue {
    fn fill(&self) {
        println!("Fill Blue");
    }
}

// 具体产品 - 形状
#[derive(Default)]
pub struct Circle;
impl IShape for Circle {
    fn draw(&self) {
        println!("Draw a Circle");
    }
}

#[derive(Default)]
pub struct Square;
impl IShape for Square {
    fn draw(&self) {
        println!("Draw a Square");
    }
}

#[derive(Default)]
pub struct Rectangle;
impl IShape for Rectangle {
    fn draw(&self) {
        println!("Draw a Rectangle");
    }
}
