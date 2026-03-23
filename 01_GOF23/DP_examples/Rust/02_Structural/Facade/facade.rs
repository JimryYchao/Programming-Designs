use crate::component::{Circle, IShape, Rectangle, Square};

// 形状类型枚举
#[derive(Debug, Clone, Copy)]
pub enum ShapeType {
    Circle,
    Rectangle,
    Square,
}

pub fn build_shape(shape_type: ShapeType, args: &[i32]) -> Option<Box<dyn IShape>> {
    match shape_type {
        ShapeType::Circle => {
            if args.len() >= 1 {
                Some(Box::new(Circle::new(args[0])))
            } else {
                None
            }
        }
        ShapeType::Rectangle => {
            if args.len() >= 2 {
                Some(Box::new(Rectangle::new(args[0], args[1])))
            } else {
                None
            }
        }
        ShapeType::Square => {
            if args.len() >= 1 {
                Some(Box::new(Square::new(args[0])))
            } else {
                None
            }
        }
    }
}
