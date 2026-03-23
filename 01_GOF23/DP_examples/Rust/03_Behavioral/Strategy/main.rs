// 主文件
mod strategy;
mod concrete_strategy;
mod context;

use concrete_strategy::{BubbleSortStrategy, QuickSortStrategy, InsertionSortStrategy, SelectionSortStrategy};
use context::Context;

// 打印数组
fn print_array(array: &[i32]) {
    for item in array {
        print!("{} ", item);
    }
    println!();
}

fn main() {
    let mut array = [64, 34, 25, 12, 22, 11, 90];
    
    println!("Original array:");
    print_array(&array);
    
    // 冒泡排序
    println!("\nUsing Bubble Sort:");
    let mut bubble_sort_array = array.clone();
    let mut context = Context::new(Box::new(BubbleSortStrategy));
    context.sort(&mut bubble_sort_array);
    print_array(&bubble_sort_array);
    
    // 快速排序
    println!("\nUsing Quick Sort:");
    let mut quick_sort_array = array.clone();
    context.set_strategy(Box::new(QuickSortStrategy));
    context.sort(&mut quick_sort_array);
    print_array(&quick_sort_array);
    
    // 插入排序
    println!("\nUsing Insertion Sort:");
    let mut insertion_sort_array = array.clone();
    context.set_strategy(Box::new(InsertionSortStrategy));
    context.sort(&mut insertion_sort_array);
    print_array(&insertion_sort_array);
    
    // 选择排序
    println!("\nUsing Selection Sort:");
    let mut selection_sort_array = array.clone();
    context.set_strategy(Box::new(SelectionSortStrategy));
    context.sort(&mut selection_sort_array);
    print_array(&selection_sort_array);
}
