# 客户端代码
from Context import Context
from ConcreteStrategy import BubbleSortStrategy, QuickSortStrategy, InsertionSortStrategy, SelectionSortStrategy

def print_array(array):
    for item in array:
        print(item, end=" ")
    print()

def main():
    array = [64, 34, 25, 12, 22, 11, 90]
    
    print("Original array:")
    print_array(array)
    
    # 冒泡排序
    print("\nUsing Bubble Sort:")
    bubble_sort_array = array.copy()
    context = Context(BubbleSortStrategy())
    context.sort(bubble_sort_array)
    print_array(bubble_sort_array)
    
    # 快速排序
    print("\nUsing Quick Sort:")
    quick_sort_array = array.copy()
    context.set_strategy(QuickSortStrategy())
    context.sort(quick_sort_array)
    print_array(quick_sort_array)
    
    # 插入排序
    print("\nUsing Insertion Sort:")
    insertion_sort_array = array.copy()
    context.set_strategy(InsertionSortStrategy())
    context.sort(insertion_sort_array)
    print_array(insertion_sort_array)
    
    # 选择排序
    print("\nUsing Selection Sort:")
    selection_sort_array = array.copy()
    context.set_strategy(SelectionSortStrategy())
    context.sort(selection_sort_array)
    print_array(selection_sort_array)

if __name__ == "__main__":
    main()
