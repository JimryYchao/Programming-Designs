use crate::implementor::{Color, DrawAPI};

// 抽象类
pub struct Shape<T: DrawAPI> {
    draw: T,
}

impl<T: DrawAPI> Shape<T> {
    pub fn new(draw: T) -> Self {
        Self { draw }
    }

    pub fn Draw(&self, color: Color) {
        self.draw.draw();
        self.draw.fill(color);
    }
}

// 修正抽象类
pub struct ShapeAdvance<T: DrawAPI> {
    shape: Shape<T>,
    on_draw_completed: Option<Box<dyn Fn()>>,
}

impl<T: DrawAPI> ShapeAdvance<T> {
    pub fn new(draw: T, on_draw_completed: Option<Box<dyn Fn()>>) -> Self {
        Self {
            shape: Shape::new(draw),
            on_draw_completed,
        }
    }

    pub fn Draw(&self, color: Color) {
        self.shape.Draw(color);
        if let Some(callback) = &self.on_draw_completed {
            callback();
        }
    }
}
