// 主文件
mod abstract_class;
mod concrete_class;

use crate::abstract_class::BeverageMaker;
use concrete_class::{CoffeeMaker, TeaMaker};

fn main() {
    // 制作咖啡
    println!("Making coffee:");
    let coffee = CoffeeMaker;
    coffee.make_beverage();
    println!();
    
    // 制作茶
    println!("Making tea:");
    let tea = TeaMaker;
    tea.make_beverage();
}
