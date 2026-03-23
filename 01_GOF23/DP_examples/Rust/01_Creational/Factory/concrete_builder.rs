use std::collections::HashMap;
use super::creator::{CircleCreator, SquareCreator, RectangleCreator, UnknownShapeCreator, BigCircleCreator, ICreator};
use super::product::{IShape, ShapeKind};

pub struct Creator;

impl Creator {
    pub fn get_creator(shape_kind: &ShapeKind) -> &'static dyn ICreator {
        match shape_kind {
            ShapeKind::Circle => &CircleCreator::INSTANCE,
            ShapeKind::Square => &SquareCreator::INSTANCE,
            ShapeKind::Rectangle => &RectangleCreator::INSTANCE,
            ShapeKind::BigCircle => &BigCircleCreator::INSTANCE,
            ShapeKind::Unknown => &UnknownShapeCreator::INSTANCE,
        }
    }
}

pub struct ShapeFactory {
    dic: HashMap<ShapeKind, &'static dyn ICreator>,
}

impl ShapeFactory {
    pub fn get_instance() -> &'static mut ShapeFactory {
        static mut INSTANCE: Option<ShapeFactory> = None;
        unsafe {
            if INSTANCE.is_none() {
                INSTANCE = Some(ShapeFactory { dic: HashMap::new() });
            }
            INSTANCE.as_mut().unwrap()
        }
    }

    fn _get_shape(&mut self, shape_kind: ShapeKind) -> Box<dyn IShape> {
        if let Some(creator) = self.dic.get(&shape_kind) {
            return creator.get_shape();
        } else {
            let creator: &'static dyn ICreator = Creator::get_creator(&shape_kind);
            self.dic.insert(shape_kind, creator);
            creator.get_shape()
        }
    }

    pub fn get_shape(shape_kind: ShapeKind) -> Box<dyn IShape> {
        Self::get_instance()._get_shape(shape_kind)
    }
}

