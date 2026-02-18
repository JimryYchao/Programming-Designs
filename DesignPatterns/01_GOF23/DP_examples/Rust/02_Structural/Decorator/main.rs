mod component;
mod concrete_component;
mod decorator;

use crate::component::{Color, IShape};
use crate::concrete_component::{Circle, Rectangle};
use crate::decorator::{Decorator, ShapeDecorator};

fn main() {
    // 创建红色圆形
    let red_circle = Decorator::new(Circle::new());
    red_circle.draw();
    red_circle.fill(Color::Red);
    
    // 创建绿色矩形
    let green_rectangle = ShapeDecorator::new(Rectangle::new());
    green_rectangle.draw();
    green_rectangle.fill(Color::Green);
}
