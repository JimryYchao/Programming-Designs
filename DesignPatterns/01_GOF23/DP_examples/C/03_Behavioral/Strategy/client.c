#include <stdio.h>
#include <stdlib.h>
#include "context.h"
#include "concrete_strategy.h"

// 打印数组
void print_array(int* array, int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// 复制数组
void copy_array(int* dest, int* src, int length) {
    for (int i = 0; i < length; i++) {
        dest[i] = src[i];
    }
}

int main() {
    int array[] = {64, 34, 25, 12, 22, 11, 90};
    int length = sizeof(array) / sizeof(array[0]);
    
    printf("Original array:\n");
    print_array(array, length);
    
    // 创建策略实例
    BubbleSortStrategy bubbleSortStrategy;
    BubbleSortStrategy_init(&bubbleSortStrategy);
    
    QuickSortStrategy quickSortStrategy;
    QuickSortStrategy_init(&quickSortStrategy);
    
    InsertionSortStrategy insertionSortStrategy;
    InsertionSortStrategy_init(&insertionSortStrategy);
    
    SelectionSortStrategy selectionSortStrategy;
    SelectionSortStrategy_init(&selectionSortStrategy);
    
    // 创建上下文
    Context context;
    
    // 冒泡排序
    printf("\nUsing Bubble Sort:\n");
    int bubbleSortArray[length];
    copy_array(bubbleSortArray, array, length);
    Context_init(&context, (IStrategy*)&bubbleSortStrategy);
    Context_sort(&context, bubbleSortArray, length);
    print_array(bubbleSortArray, length);
    
    // 快速排序
    printf("\nUsing Quick Sort:\n");
    int quickSortArray[length];
    copy_array(quickSortArray, array, length);
    Context_setStrategy(&context, (IStrategy*)&quickSortStrategy);
    Context_sort(&context, quickSortArray, length);
    print_array(quickSortArray, length);
    
    // 插入排序
    printf("\nUsing Insertion Sort:\n");
    int insertionSortArray[length];
    copy_array(insertionSortArray, array, length);
    Context_setStrategy(&context, (IStrategy*)&insertionSortStrategy);
    Context_sort(&context, insertionSortArray, length);
    print_array(insertionSortArray, length);
    
    // 选择排序
    printf("\nUsing Selection Sort:\n");
    int selectionSortArray[length];
    copy_array(selectionSortArray, array, length);
    Context_setStrategy(&context, (IStrategy*)&selectionSortStrategy);
    Context_sort(&context, selectionSortArray, length);
    print_array(selectionSortArray, length);
    
}

// gcc -o client client.c context.c concrete_strategy.c strategy.c
