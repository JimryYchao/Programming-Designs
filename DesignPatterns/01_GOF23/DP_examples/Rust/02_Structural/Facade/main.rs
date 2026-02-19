mod component;
mod facade;

use facade::{build_shape, ShapeType};



fn main() {
    // 获取 ShapeMaker 单例
    // let shape_maker = ShapeMaker::get_instance();

    // 创建圆形
    if let Some(circle) = build_shape(ShapeType::Circle, &[10]) {
        circle.draw();
    }

    // 创建矩形
    if let Some(rectangle) = build_shape(ShapeType::Rectangle, &[10, 20]) {
        rectangle.draw();
    }

    // 创建正方形
    if let Some(square) = build_shape(ShapeType::Square, &[10]) {
        square.draw();
    }
}
