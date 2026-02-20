mod component;
mod unshared_flyweight;
mod flyweight_factory;

use crate::component::IShape;
use flyweight_factory::FlyweightFactory;

// 构建圆形
fn build_circles() {
    // 获取 FlyweightFactory 单例
    let factory = FlyweightFactory::get_instance();
    
    // 创建红色圆形
    let red_circle = factory.get_circle("Red", 10.0, 0.0, 0.0);
    red_circle.draw();
    red_circle.fill();
    
    // 创建特殊绿色大圆形
    let green_big_circle = factory.get_special_circle("Green", 100.0, 100.0, 100.0);
    green_big_circle.draw();
    green_big_circle.fill();
    green_big_circle.reset_radius(10.0);
    green_big_circle.move_position(0.0, 0.0);
}

// 构建享元圆形
fn build_flyweight_circle() {
    // 获取 FlyweightFactory 单例
    let factory = FlyweightFactory::get_instance();
    
    // 创建红色圆形（复用之前的 CircleData）
    let red_circle = factory.get_circle("Red", 10.0, 10086.0, 10010.0);
    red_circle.draw();
    red_circle.fill();
}

// 测试 Flyweight 模式
fn main() {
    build_circles();
    build_flyweight_circle();
}
