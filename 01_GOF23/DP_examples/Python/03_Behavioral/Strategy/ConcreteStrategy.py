# 具体策略实现
from Strategy import IStrategy

# 冒泡排序策略
class BubbleSortStrategy(IStrategy):
    def sort(self, array):
        n = len(array)
        for i in range(n - 1):
            for j in range(0, n - i - 1):
                if array[j] > array[j + 1]:
                    array[j], array[j + 1] = array[j + 1], array[j]

# 快速排序策略
class QuickSortStrategy(IStrategy):
    def sort(self, array):
        self.quick_sort(array, 0, len(array) - 1)
    
    def quick_sort(self, array, low, high):
        if low < high:
            pi = self.partition(array, low, high)
            self.quick_sort(array, low, pi - 1)
            self.quick_sort(array, pi + 1, high)
    
    def partition(self, array, low, high):
        pivot = array[high]
        i = low - 1
        for j in range(low, high):
            if array[j] <= pivot:
                i += 1
                array[i], array[j] = array[j], array[i]
        array[i + 1], array[high] = array[high], array[i + 1]
        return i + 1

# 插入排序策略
class InsertionSortStrategy(IStrategy):
    def sort(self, array):
        n = len(array)
        for i in range(1, n):
            key = array[i]
            j = i - 1
            while j >= 0 and array[j] > key:
                array[j + 1] = array[j]
                j -= 1
            array[j + 1] = key

# 选择排序策略
class SelectionSortStrategy(IStrategy):
    def sort(self, array):
        n = len(array)
        for i in range(n - 1):
            min_index = i
            for j in range(i + 1, n):
                if array[j] < array[min_index]:
                    min_index = j
            array[i], array[min_index] = array[min_index], array[i]
