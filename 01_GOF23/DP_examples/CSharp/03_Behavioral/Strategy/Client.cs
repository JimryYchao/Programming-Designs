namespace Behavioral;

using Behavioral.Strategy;

public class StrategyDemo
{
    private static void PrintArray(int[] array) {
        foreach (int item in array) {
            Console.Write(item + " ");
        }
        Console.WriteLine();
    }
    public static void Example()
    {
        
        Console.WriteLine("Original array: ");
        int[] array = { 64, 34, 25, 12, 22, 11, 90 };
        PrintArray(array);
        
        // 使用冒泡排序
        Console.WriteLine("\nUsing Bubble Sort:");
        int[] bubbleSortArray = (int[])array.Clone();
        Context.GetInstance(BubbleSortStrategy.strategy).Sort(bubbleSortArray);
        PrintArray(bubbleSortArray);
        
        // 使用快速排序
        Console.WriteLine("\nUsing Quick Sort:");
        int[] quickSortArray = (int[])array.Clone();
        Context.GetInstance(QuickSortStrategy.strategy).Sort(quickSortArray);
        PrintArray(quickSortArray);
        
        // 使用插入排序
        Console.WriteLine("\nUsing Insertion Sort:");
        int[] insertionSortArray = (int[])array.Clone();
        Context.GetInstance(InsertionSortStrategy.strategy).Sort(insertionSortArray);
        PrintArray(insertionSortArray);
        
        // 使用选择排序
        Console.WriteLine("\nUsing Selection Sort:");
        int[] selectionSortArray = (int[])array.Clone();
        Context.GetInstance(SelectionSortStrategy.strategy).Sort(selectionSortArray);
        PrintArray(selectionSortArray);
    }
}