mod concrete_builder;
mod creator;
mod product;

use concrete_builder::ShapeFactory;
use product::ShapeKind;

fn example(){
    let circle = ShapeFactory::get_shape(ShapeKind::Circle);
    circle.draw();
    circle.fill();

    let square = ShapeFactory::get_shape(ShapeKind::Square);
    square.draw();
    square.fill();
   
    let rectangle = ShapeFactory::get_shape(ShapeKind::Rectangle);
    rectangle.draw();
    rectangle.fill();
}

fn main() {
    example();
}