// 具体策略实现
use crate::strategy::IStrategy;

// 冒泡排序策略
pub struct BubbleSortStrategy;

impl IStrategy for BubbleSortStrategy {
    fn sort(&self, array: &mut [i32]) {
        let n = array.len();
        for i in 0..n-1 {
            for j in 0..n-i-1 {
                if array[j] > array[j+1] {
                    array.swap(j, j+1);
                }
            }
        }
    }
}

// 快速排序策略
pub struct QuickSortStrategy;

impl IStrategy for QuickSortStrategy {
    fn sort(&self, array: &mut [i32]) {
        if array.len() > 1 {
            quick_sort(array, 0, array.len() - 1);
        }
    }
}

fn quick_sort(array: &mut [i32], low: usize, high: usize) {
    if low < high {
        let pi = partition(array, low, high);
        if pi > 0 {
            quick_sort(array, low, pi - 1);
        }
        quick_sort(array, pi + 1, high);
    }
}

fn partition(array: &mut [i32], low: usize, high: usize) -> usize {
    let pivot = array[high];
    let mut i = low as i32 - 1;
    
    for j in low..high {
        if array[j] <= pivot {
            i += 1;
            array.swap(i as usize, j);
        }
    }
    
    array.swap((i + 1) as usize, high);
    (i + 1) as usize
}

// 插入排序策略
pub struct InsertionSortStrategy;

impl IStrategy for InsertionSortStrategy {
    fn sort(&self, array: &mut [i32]) {
        let n = array.len();
        for i in 1..n {
            let key = array[i];
            let mut j = i as i32 - 1;
            
            while j >= 0 && array[j as usize] > key {
                array[(j + 1) as usize] = array[j as usize];
                j -= 1;
            }
            
            array[(j + 1) as usize] = key;
        }
    }
}

// 选择排序策略
pub struct SelectionSortStrategy;

impl IStrategy for SelectionSortStrategy {
    fn sort(&self, array: &mut [i32]) {
        let n = array.len();
        for i in 0..n-1 {
            let mut min_index = i;
            for j in i+1..n {
                if array[j] < array[min_index] {
                    min_index = j;
                }
            }
            if min_index != i {
                array.swap(i, min_index);
            }
        }
    }
}
