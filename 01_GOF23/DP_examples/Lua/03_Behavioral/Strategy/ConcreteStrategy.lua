-- 具体策略实现
local IStrategy = require("Strategy")

-- 冒泡排序策略
local BubbleSortStrategy = IStrategy:new()

function BubbleSortStrategy:sort(array)
    local n = #array
    for i = 1, n - 1 do
        for j = 1, n - i do
            if array[j] > array[j + 1] then
                array[j], array[j + 1] = array[j + 1], array[j]
            end
        end
    end
end

-- 快速排序策略
local QuickSortStrategy = IStrategy:new()

function QuickSortStrategy:sort(array)
    self:quickSort(array, 1, #array)
end

function QuickSortStrategy:quickSort(array, low, high)
    if low < high then
        local pi = self:partition(array, low, high)
        self:quickSort(array, low, pi - 1)
        self:quickSort(array, pi + 1, high)
    end
end

function QuickSortStrategy:partition(array, low, high)
    local pivot = array[high]
    local i = low - 1
    for j = low, high - 1 do
        if array[j] <= pivot then
            i = i + 1
            array[i], array[j] = array[j], array[i]
        end
    end
    array[i + 1], array[high] = array[high], array[i + 1]
    return i + 1
end

-- 插入排序策略
local InsertionSortStrategy = IStrategy:new()

function InsertionSortStrategy:sort(array)
    local n = #array
    for i = 2, n do
        local key = array[i]
        local j = i - 1
        while j >= 1 and array[j] > key do
            array[j + 1] = array[j]
            j = j - 1
        end
        array[j + 1] = key
    end
end

-- 选择排序策略
local SelectionSortStrategy = IStrategy:new()

function SelectionSortStrategy:sort(array)
    local n = #array
    for i = 1, n - 1 do
        local minIndex = i
        for j = i + 1, n do
            if array[j] < array[minIndex] then
                minIndex = j
            end
        end
        array[i], array[minIndex] = array[minIndex], array[i]
    end
end

return {
    BubbleSortStrategy = BubbleSortStrategy,
    QuickSortStrategy = QuickSortStrategy,
    InsertionSortStrategy = InsertionSortStrategy,
    SelectionSortStrategy = SelectionSortStrategy
}
