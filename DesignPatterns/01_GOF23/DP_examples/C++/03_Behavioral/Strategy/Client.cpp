#include <iostream>
#include "Context.hpp"
#include "ConcreteStrategy.hpp"

// 打印数组
void printArray(int* array, int length) {
    for (int i = 0; i < length; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}

// 复制数组
void copyArray(int* dest, int* src, int length) {
    for (int i = 0; i < length; i++) {
        dest[i] = src[i];
    }
}

int main() {
    int array[] = {64, 34, 25, 12, 22, 11, 90};
    int length = sizeof(array) / sizeof(array[0]);
    
    std::cout << "Original array:" << std::endl;
    printArray(array, length);
    
    // 创建策略实例
    BubbleSortStrategy bubbleSortStrategy;
    QuickSortStrategy quickSortStrategy;
    InsertionSortStrategy insertionSortStrategy;
    SelectionSortStrategy selectionSortStrategy;
    
    // 冒泡排序
    std::cout << "\nUsing Bubble Sort:" << std::endl;
    int bubbleSortArray[length];
    copyArray(bubbleSortArray, array, length);
    Context context(&bubbleSortStrategy);
    context.sort(bubbleSortArray, length);
    printArray(bubbleSortArray, length);
    
    // 快速排序
    std::cout << "\nUsing Quick Sort:" << std::endl;
    int quickSortArray[length];
    copyArray(quickSortArray, array, length);
    context.setStrategy(&quickSortStrategy);
    context.sort(quickSortArray, length);
    printArray(quickSortArray, length);
    
    // 插入排序
    std::cout << "\nUsing Insertion Sort:" << std::endl;
    int insertionSortArray[length];
    copyArray(insertionSortArray, array, length);
    context.setStrategy(&insertionSortStrategy);
    context.sort(insertionSortArray, length);
    printArray(insertionSortArray, length);
    
    // 选择排序
    std::cout << "\nUsing Selection Sort:" << std::endl;
    int selectionSortArray[length];
    copyArray(selectionSortArray, array, length);
    context.setStrategy(&selectionSortStrategy);
    context.sort(selectionSortArray, length);
    printArray(selectionSortArray, length);
    
    return 0;
}
