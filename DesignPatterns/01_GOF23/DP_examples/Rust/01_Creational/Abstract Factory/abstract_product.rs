// abstract_product.rs
// 产品接口和具体实现

use super::abstract_factory::{Color, Shape};

// 具体产品 - 颜色
pub struct Red;
impl Color for Red {
    fn fill(&self) {
        println!("Fill Red");
    }
}

pub struct Green;
impl Color for Green {
    fn fill(&self) {
        println!("Fill Green");
    }
}

pub struct Blue;
impl Color for Blue {
    fn fill(&self) {
        println!("Fill Blue");
    }
}

// 具体产品 - 形状
pub struct Circle;
impl Shape for Circle {
    fn draw(&self) {
        println!("Draw a Circle");
    }
}

pub struct Square;
impl Shape for Square {
    fn draw(&self) {
        println!("Draw a Square");
    }
}

pub struct Rectangle;
impl Shape for Rectangle {
    fn draw(&self) {
        println!("Draw a Rectangle");
    }
}
