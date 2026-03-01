-- 客户端代码
local Context = require("Context")
local strategies = require("ConcreteStrategy")

function printArray(array)
    for i, item in ipairs(array) do
        io.write(item, " ")
    end
    print()
end

function main()
    local array = { 64, 34, 25, 12, 22, 11, 90 }
    print("Original array:")
    printArray(array)



    -- 冒泡排序
    print("\nUsing Bubble Sort:")
    local bubbleSortArray = { table.unpack(array) }
    local context = Context:new(strategies.BubbleSortStrategy)
    context:sort(bubbleSortArray)
    printArray(bubbleSortArray)

    -- 快速排序
    print("\nUsing Quick Sort:")
    local quickSortArray = { table.unpack(array) }
    context:setStrategy(strategies.QuickSortStrategy)
    context:sort(quickSortArray)
    printArray(quickSortArray)

    -- 插入排序
    print("\nUsing Insertion Sort:")
    local insertionSortArray = { table.unpack(array) }
    context:setStrategy(strategies.InsertionSortStrategy)
    context:sort(insertionSortArray)
    printArray(insertionSortArray)

    -- 选择排序
    print("\nUsing Selection Sort:")
    local selectionSortArray = { table.unpack(array) }
    context:setStrategy(strategies.SelectionSortStrategy)
    context:sort(selectionSortArray)
    printArray(selectionSortArray)
end

main()
