#include "concrete_strategy.h"

// 冒泡排序实现
static void bubble_sort(IStrategy* self, int* array, int length) {
    for (int i = 0; i < length - 1; i++) {
        for (int j = 0; j < length - i - 1; j++) {
            if (array[j] > array[j + 1]) {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

// 快速排序辅助函数
static int partition(int* array, int low, int high) {
    int pivot = array[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (array[j] <= pivot) {
            i++;
            int temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }
    }
    int temp = array[i + 1];
    array[i + 1] = array[high];
    array[high] = temp;
    return i + 1;
}

static void quick_sort_recursive(int* array, int low, int high) {
    if (low < high) {
        int pi = partition(array, low, high);
        quick_sort_recursive(array, low, pi - 1);
        quick_sort_recursive(array, pi + 1, high);
    }
}

// 快速排序实现
static void quick_sort(IStrategy* self, int* array, int length) {
    quick_sort_recursive(array, 0, length - 1);
}

// 插入排序实现
static void insertion_sort(IStrategy* self, int* array, int length) {
    for (int i = 1; i < length; i++) {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }
}

// 选择排序实现
static void selection_sort(IStrategy* self, int* array, int length) {
    for (int i = 0; i < length - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < length; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        int temp = array[minIndex];
        array[minIndex] = array[i];
        array[i] = temp;
    }
}

// 初始化冒泡排序策略
void BubbleSortStrategy_init(BubbleSortStrategy* self) {
    IStrategy_init(&self->base);
    self->base.sort = bubble_sort;
}

// 初始化快速排序策略
void QuickSortStrategy_init(QuickSortStrategy* self) {
    IStrategy_init(&self->base);
    self->base.sort = quick_sort;
}

// 初始化插入排序策略
void InsertionSortStrategy_init(InsertionSortStrategy* self) {
    IStrategy_init(&self->base);
    self->base.sort = insertion_sort;
}

// 初始化选择排序策略
void SelectionSortStrategy_init(SelectionSortStrategy* self) {
    IStrategy_init(&self->base);
    self->base.sort = selection_sort;
}
