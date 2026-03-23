mod product;
mod shape_cache;

use product::{Color, ShapeKind};
use shape_cache::{get_shape_cache};

fn main() {
    // 克隆不同形状
    let mut cache = get_shape_cache();
    if let Some(circle) = cache.get_shape(ShapeKind::Circle) {
        circle.draw();
        circle.fill(Color::Red);
    }

    if let Some(square) = cache.get_shape(ShapeKind::Square) {
        square.draw();
        square.fill(Color::Green);
    }

    cache.remove_prototype(ShapeKind::Rectangle);
    if let Some(_) = cache.get_shape(ShapeKind::Rectangle) {
        println!("Rectangle should not exist after removal");
    }

    cache.register_prototype(ShapeKind::Rectangle, Box::new(product::Rectangle::new()));
    if let Some(rectangle) = cache.get_shape(ShapeKind::Rectangle) {
        println!("Rectangle prototype registered successfully");
        rectangle.draw();
        rectangle.fill(Color::Blue);
    }
}
