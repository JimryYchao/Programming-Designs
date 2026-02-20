// 形状接口
pub trait IShape {
    fn draw(&self);
    fn fill(&self);
}

// 圆形数据
#[derive(Clone)]
pub struct CircleData {
    pub color: String,
    pub radius: f32,
}

// 圆形实现
pub struct Circle {
    data: CircleData,
    x: f32,
    y: f32,
}

impl Circle {
    pub fn new(data: CircleData, x: f32, y: f32) -> Self {
        Self {
            data,
            x,
            y,
        }
    }
    
    pub fn get_data(&self) -> &CircleData {
        &self.data
    }
}

impl IShape for Circle {
    fn draw(&self) {
        println!("Draw a Circle with radius {} at ({}, {})", self.data.radius, self.x, self.y);
    }
    
    fn fill(&self) {
        println!("Fill with {}", self.data.color);
    }
}
