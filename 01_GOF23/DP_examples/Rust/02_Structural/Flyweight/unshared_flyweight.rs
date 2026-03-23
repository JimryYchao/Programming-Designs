use crate::component::{IShape, Circle, CircleData};

// 非共享具体享元类 - 圆形增强
pub struct CircleAddition {
    shape: Box<dyn IShape>,
}

impl CircleAddition {
    pub fn new(shape: Box<dyn IShape>) -> Self {
        Self {
            shape,
        }
    }
    
    pub fn move_position(&self, x: f32, y: f32) {
        println!("Move Circle to ({}, {})", x, y);
    }
    
    pub fn reset_radius(&self, radius: f32) {
        println!("Reset Radius to {}", radius);
    }
}

impl IShape for CircleAddition {
    fn draw(&self) {
        self.shape.draw();
    }
    
    fn fill(&self) {
        self.shape.fill();
    }
}

// 圆形工厂
pub struct CircleFactory;

impl CircleFactory {
    pub fn new() -> Self {
        Self
    }
    
    pub fn get_circle(&self, color: &str, radius: f32, x: f32, y: f32) -> Circle {
        let data = CircleData {
            color: color.to_string(),
            radius,
        };
        Circle::new(data, x, y)
    }
    
    pub fn get_circle_by_data(&self, data: &CircleData, x: f32, y: f32) -> Circle {
        Circle::new(data.clone(), x, y)
    }
    
    pub fn get_spacial_circle(&self, circle: Circle) -> CircleAddition {
        CircleAddition::new(Box::new(circle))
    }
}
