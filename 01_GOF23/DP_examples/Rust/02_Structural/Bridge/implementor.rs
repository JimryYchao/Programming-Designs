// 颜色枚举
#[derive(Debug, Clone, Copy)]
pub enum Color {
    Unknown,
    Red,
    Green,
    Blue,
}

// 颜色转字符串
impl Color {
    pub fn to_string(&self) -> &'static str {
        match self {
            Color::Red => "red",
            Color::Green => "green",
            Color::Blue => "blue",
            _ => "unknown",
        }
    }
}

// 实现接口
pub trait DrawAPI {
    fn draw(&self);
    fn fill(&self, color: Color){
        println!("Fill with {}", color.to_string());
    }
}

// 圆形实现
pub struct Circle;

impl DrawAPI for Circle {
    fn draw(&self) {
        println!("Draw a Circle");
    }
}

// 正方形实现
pub struct Square;

impl DrawAPI for Square {
    fn draw(&self) {
        println!("Draw a Square");
    }
}

// 矩形实现
pub struct Rectangle;

impl DrawAPI for Rectangle {
    fn draw(&self) {
        println!("Draw a Rectangle");
    }
}

// 大圆形实现
pub struct BigCircle;

impl DrawAPI for BigCircle {
    fn draw(&self) {
        println!("Draw a Big Circle");
    }
}
