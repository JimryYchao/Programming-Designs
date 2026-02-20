use crate::component::{Circle, CircleData};
use crate::unshared_flyweight::{CircleAddition, CircleFactory};
use std::collections::HashMap;
use std::sync::{OnceLock, RwLock};

// 享元工厂
pub struct FlyweightFactory {
    shape_dic: RwLock<HashMap<String, HashMap<String, CircleData>>>,
    circle_factory: CircleFactory,
}

impl FlyweightFactory {
    // 获取单例实例
    pub fn get_instance() -> &'static Self {
        static INSTANCE: OnceLock<FlyweightFactory> = OnceLock::new();
        INSTANCE.get_or_init(|| Self {
            shape_dic: RwLock::new(HashMap::new()),
            circle_factory: CircleFactory::new(),
        })
    }
    
    // 获取圆形
    pub fn get_circle(&self, color: &str, radius: f32, x: f32, y: f32) -> Circle {
        let radius_key = radius.to_string();
        let mut shape_dic = self.shape_dic.write().unwrap();
        // 查找颜色
        if let Some(radius_map) = shape_dic.get_mut(color) {
            // 查找半径
            if let Some(data) = radius_map.get(&radius_key) {
                // 复用已有的 CircleData
                return self.circle_factory.get_circle_by_data(data, x, y);
            } else {
                // 创建新的圆形
                let circle = self.circle_factory.get_circle(color, radius, x, y);
                // 存储 CircleData
                radius_map.insert(radius_key, circle.get_data().clone());
                println!("Create a New Circle Filled with {}", color);
                return circle;
            }
        } else {
            // 创建新的颜色条目
            let mut radius_map = HashMap::new();
            // 创建新的圆形
            let circle = self.circle_factory.get_circle(color, radius, x, y);
            // 存储 CircleData
            radius_map.insert(radius_key, circle.get_data().clone());
            shape_dic.insert(color.to_string(), radius_map);
            println!("Create a New Circle Filled with {}", color);
            return circle;
        }
    }
    
    // 获取特殊圆形
    pub fn get_special_circle(&self, color: &str, radius: f32, x: f32, y: f32) -> CircleAddition {
        let circle = self.get_circle(color, radius, x, y);
        self.circle_factory.get_spacial_circle(circle)
    }
}
