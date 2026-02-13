use std::fmt;

// 颜色枚举
#[derive(Debug, Clone, Copy)]
pub enum Color {
    Unknown,
    Red,
    Green,
    Blue,
    Yellow,
}

impl fmt::Display for Color {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        match self {
            Color::Red => write!(f, "Red"),
            Color::Green => write!(f, "Green"),
            Color::Blue => write!(f, "Blue"),
            Color::Yellow => write!(f, "Yellow"),
            _ => write!(f, "Unknown"),
        }
    }
}

// 形状接口
pub trait IShape: Send + Sync {
    fn name(&self) -> &str;
    fn draw(&self);
    fn fill(&self, color: Color);
    fn clone(&self) -> Box<dyn IShape>;
}

// 形状基类
#[derive(Debug, Clone)]
struct Shape {
    id: i32,
    name: String,
}

impl Shape {
    fn new(id: i32, name: &str) -> Self {
        Self {
            id,
            name: name.to_string(),
        }
    }
}

// 形状类型枚举
#[derive(Debug, Clone, Copy, Eq, Hash, PartialEq)]
pub enum ShapeKind {
    Unknown,
    Circle,
    Square,
    Rectangle,
}

// 圆形
#[derive(Debug, Clone)]
pub struct Circle {
    shape: Shape,
}

impl Circle {
    pub fn new() -> Self {
        Self {
            shape: Shape::new(ShapeKind::Circle as i32, "Circle"),
        }
    }
}

impl IShape for Circle {
    fn name(&self) -> &str {
        &self.shape.name
    }

    fn draw(&self) {
        println!("Draw a Circle");
    }

    fn fill(&self, color: Color) {
        println!("Fill with {}", color);
    }

    fn clone(&self) -> Box<dyn IShape> {
        Box::new(Clone::clone(self))
    }
}

// 正方形
#[derive(Debug, Clone)]
pub struct Square {
    shape: Shape,
}

impl Square {
    pub fn new() -> Self {
        Self {
            shape: Shape::new(ShapeKind::Square as i32, "Square"),
        }
    }
}

impl IShape for Square {
    fn name(&self) -> &str {
        &self.shape.name
    }

    fn draw(&self) {
        println!("Draw a Square");
    }

    fn fill(&self, color: Color) {
        println!("Fill with {}", color);
    }

    fn clone(&self) -> Box<dyn IShape> {
        Box::new(Clone::clone(self))
    }
}

// 矩形
#[derive(Debug, Clone)]
pub struct Rectangle {
    shape: Shape,
}

impl Rectangle {
    pub fn new() -> Self {
        Self {
            shape: Shape::new(ShapeKind::Rectangle as i32, "Rectangle"),
        }
    }
}

impl IShape for Rectangle {
    fn name(&self) -> &str {
        &self.shape.name
    }

    fn draw(&self) {
        println!("Draw a Rectangle");
    }

    fn fill(&self, color: Color) {
        println!("Fill with {}", color);
    }

    fn clone(&self) -> Box<dyn IShape> {
        Box::new(Clone::clone(self))
    }
}
