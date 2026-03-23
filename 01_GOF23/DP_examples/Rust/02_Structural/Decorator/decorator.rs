use crate::component::{Color, IShape};

pub struct Decorator<T: IShape> {
    shape: T,
}

impl<T: IShape> Decorator<T> {
    pub fn new(shape: T) -> Self {
        Decorator { shape }
    }
}

impl<T: IShape> IShape for Decorator<T> {
    fn draw(&self) {
        self.shape.draw();
    }
    
    fn fill(&self, color: Color) {
        self.shape.fill(color);
    }
}

pub struct ShapeDecorator<T: IShape> {
    decorator: Decorator<T>,
}

impl<T: IShape> ShapeDecorator<T> {
    pub fn new(shape: T) -> Self {
        ShapeDecorator {
            decorator: Decorator::new(shape),
        }
    }
    
    fn before_draw(&self) {
        println!("Before Draw() >> Do...");
    }
    
    fn after_draw(&self) {
        println!("When Draw Complete >> Do...");
    }
    
    fn before_fill(&self) {
        println!("Before Fill() >> Do...");
    }
    
    fn after_fill(&self) {
        println!("When Fill Complete >> Do...");
    }
}

impl<T: IShape> IShape for ShapeDecorator<T> {
    fn draw(&self) {
        self.before_draw();
        self.decorator.draw();
        self.after_draw();
    }
    
    fn fill(&self, color: Color) {
        self.before_fill();
        self.decorator.fill(color);
        self.after_fill();
    }
}
