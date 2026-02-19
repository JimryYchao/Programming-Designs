// 形状接口
pub trait IShape {
    fn draw(&self);
}

// 圆形实现
pub struct Circle {
    radius: i32,
}

impl Circle {
    pub fn new(radius: i32) -> Self {
        Self {
            radius,
        }
    }
}

impl IShape for Circle {
    fn draw(&self) {
        println!("Draw a circle with radius {}", self.radius);
    }
}

// 矩形实现
pub struct Rectangle {
    width: i32,
    height: i32,
}

impl Rectangle {
    pub fn new(width: i32, height: i32) -> Self {
        Self {
            width,
            height,
        }
    }
}

impl IShape for Rectangle {
    fn draw(&self) {
        println!("Draw a rectangle with width {} and height {}", self.width, self.height);
    }
}

// 正方形实现
pub struct Square {
    side: i32,
}

impl Square {
    pub fn new(side: i32) -> Self {
        Self {
            side,
        }
    }
}

impl IShape for Square {
    fn draw(&self) {
        println!("Draw a square with side {}", self.side);
    }
}
