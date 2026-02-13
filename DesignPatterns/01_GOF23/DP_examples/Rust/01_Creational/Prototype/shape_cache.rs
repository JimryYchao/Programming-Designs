use std::collections::HashMap;
use std::sync::{Mutex, OnceLock};

use crate::product::{Circle, IShape, Rectangle, ShapeKind, Square};

// 形状缓存
pub struct ShapeCache {
    shape_map: HashMap<ShapeKind, Box<dyn IShape>>,
}

impl ShapeCache {
    // 创建新实例
    fn new() -> Self {
        let mut cache = Self {
            shape_map: HashMap::new(),
        };
        cache.load_cache();
        cache
    }

    // 加载缓存
    fn load_cache(&mut self) {
        self.register_prototype(ShapeKind::Circle, Box::new(Circle::new()));
        self.register_prototype(ShapeKind::Square, Box::new(Square::new()));
        self.register_prototype(ShapeKind::Rectangle, Box::new(Rectangle::new()));
    }

    // 注册原型
    pub fn register_prototype(&mut self, key: ShapeKind, shape: Box<dyn IShape>) {
        self.shape_map.insert(key, shape);
    }

    // 移除原型
    pub fn remove_prototype(&mut self, key: ShapeKind) {
        self.shape_map.remove(&key);
    }

    // 获取形状
    pub fn get_shape(&self, key: ShapeKind) -> Option<Box<dyn IShape>> {
        self.shape_map
            .get(&key)
            .map(|shape| IShape::clone(&**shape))
    }
}

// 单例实例
static SHAPE_CACHE: OnceLock<Mutex<ShapeCache>> = OnceLock::new();

pub fn get_shape_cache() -> impl std::ops::DerefMut<Target = ShapeCache> {
    let mutex = SHAPE_CACHE.get_or_init(|| Mutex::new(ShapeCache::new()));
    mutex.lock().unwrap()
}
