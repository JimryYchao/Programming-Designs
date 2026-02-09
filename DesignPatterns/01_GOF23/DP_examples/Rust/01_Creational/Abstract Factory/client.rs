// client.rs
// 客户端代码

mod abstract_factory;
mod abstract_product;
mod concrete_factory;

use abstract_factory::{AbstractFactory, Color, Shape};
use concrete_factory::{FactoryProducer, ProductKind};

// 客户端代码
fn draw_shape(ab: &dyn AbstractFactory) {
    let shape = ab.get_shape();
    let color = ab.get_color();
    shape.draw();
    color.fill();
}

// 示例
fn example() {
    let mut factory_producer = FactoryProducer::default();
    
    // 红色圆形
    let red_circle_f = factory_producer.get_factory(ProductKind::RedCircle);
    draw_shape(red_circle_f);
    
    // 蓝色矩形
    let blue_rectangle_f = factory_producer.get_factory(ProductKind::BlueRectangle);
    draw_shape(blue_rectangle_f);
}

fn main() {
    example();
}
