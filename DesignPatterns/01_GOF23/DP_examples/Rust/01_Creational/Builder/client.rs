// client.rs
// 客户端代码

mod builder;
mod product;
mod concrete_builder;
mod director;

use director::{Director, Meal};
use concrete_builder::VegMealBuilder;

fn example() {
    // 素食套餐
    let mut meal: Meal = Director::<VegMealBuilder>::construct();
    
    meal.build();
    meal.pack();
    println!("Total Cost: {}", meal.get_cost());
}

fn main() {
    example();
}
