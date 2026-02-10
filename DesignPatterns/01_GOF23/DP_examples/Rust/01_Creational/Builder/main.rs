mod builder;
mod product;
mod concrete_builder;
mod director;

use director::Director;
use concrete_builder::VegMealBuilder;
use builder::ItemKind;

fn example() {
    let mut meal = Director::<VegMealBuilder>::construct();
    
    meal.add(ItemKind::ChickenBurger);
    meal.remove(ItemKind::VegetableBurger);
    
    meal.build();
    meal.pack();
    println!("Total Cost: {:.2}", meal.get_cost());
}

fn main() {
    example();
}
