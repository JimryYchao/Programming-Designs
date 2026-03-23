use super::product::{IShape, ShapeKind, Circle, Square, Rectangle, UnknownShape};

pub trait ICreator {
    fn get_shape(&self) -> Box<dyn IShape>;
}

pub struct CircleCreator;

impl CircleCreator {
    pub const INSTANCE: CircleCreator = CircleCreator;
}
impl ICreator for CircleCreator {
    fn get_shape(&self) -> Box<dyn IShape> {
        Box::new(Circle)
    }
}

pub struct SquareCreator;

impl SquareCreator {
    pub const INSTANCE: SquareCreator = SquareCreator;
}
impl ICreator for SquareCreator {
    fn get_shape(&self) -> Box<dyn IShape> {
        Box::new(Square)
    }
}

pub struct RectangleCreator;

impl RectangleCreator {
    pub const INSTANCE: RectangleCreator = RectangleCreator;
}
impl ICreator for RectangleCreator {
    fn get_shape(&self) -> Box<dyn IShape> {
        Box::new(Rectangle)
    }
}

pub struct UnknownShapeCreator;

impl UnknownShapeCreator {
    pub const INSTANCE: UnknownShapeCreator = UnknownShapeCreator;
}
impl ICreator for UnknownShapeCreator {
    fn get_shape(&self) -> Box<dyn IShape> {
        Box::new(UnknownShape)
    }
}

pub struct BigCircleCreator;

impl BigCircleCreator {
    pub const INSTANCE: BigCircleCreator = BigCircleCreator;
    
    fn set_radius(&self) {
        println!("Set radius to 10");
    }
}
impl ICreator for BigCircleCreator {
    fn get_shape(&self) -> Box<dyn IShape> {
        self.set_radius();
        return CircleCreator::INSTANCE.get_shape()
    }
}