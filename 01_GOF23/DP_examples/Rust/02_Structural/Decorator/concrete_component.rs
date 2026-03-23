use crate::component::{Color, IShape};

pub struct Circle;

impl Circle {
    pub fn new() -> Self {
        Circle
    }
}

impl IShape for Circle {
    fn draw(&self) {
        println!("Draw a Circle.");
    }
    
    fn fill(&self, color: Color) {
        match color {
            Color::Red => println!("Fill with red."),
            Color::Green => println!("Fill with green."),
            Color::Blue => println!("Fill with blue."),
            _ => println!("Fill with unknown."),
        }
    }
}

pub struct Rectangle;

impl Rectangle {
    pub fn new() -> Self {
        Rectangle
    }
}

impl IShape for Rectangle {
    fn draw(&self) {
        println!("Draw a Rectangle.");
    }
    
    fn fill(&self, color: Color) {
        match color {
            Color::Red => println!("Fill with red."),
            Color::Green => println!("Fill with green."),
            Color::Blue => println!("Fill with blue."),
            _ => println!("Fill with unknown."),
        }
    }
}
