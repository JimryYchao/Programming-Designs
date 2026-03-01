#ifndef CONCRETE_STRATEGY_HPP
#define CONCRETE_STRATEGY_HPP

#include "Strategy.hpp"

// 冒泡排序策略
class BubbleSortStrategy : public IStrategy {
public:
    void sort(int* array, int length) override {
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
};

// 快速排序策略
class QuickSortStrategy : public IStrategy {
private:
    int partition(int* array, int low, int high) {
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
    
    void quickSort(int* array, int low, int high) {
        if (low < high) {
            int pi = partition(array, low, high);
            quickSort(array, low, pi - 1);
            quickSort(array, pi + 1, high);
        }
    }
public:
    void sort(int* array, int length) override {
        quickSort(array, 0, length - 1);
    }
};

// 插入排序策略
class InsertionSortStrategy : public IStrategy {
public:
    void sort(int* array, int length) override {
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
};

// 选择排序策略
class SelectionSortStrategy : public IStrategy {
public:
    void sort(int* array, int length) override {
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
};

#endif // CONCRETE_STRATEGY_HPP
