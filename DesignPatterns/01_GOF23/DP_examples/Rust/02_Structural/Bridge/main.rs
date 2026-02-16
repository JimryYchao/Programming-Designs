mod implementor;
mod abstraction;

use crate::implementor::{Circle, Square, Color};
use crate::abstraction::{Shape, ShapeAdvance};

fn main() {
    let circle = Shape::new(Circle);
    circle.Draw(Color::Green);

    let on_draw_completed = || {
        println!("Drew Completely");
    };
    let square = ShapeAdvance::new(Square, Some(Box::new(on_draw_completed)));
    square.Draw(Color::Blue);
}
