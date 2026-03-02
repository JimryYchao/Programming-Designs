namespace Behavioral;

using Behavioral.TemplateMethod;
public class TemplateMethodDemo {
    public static void Example() {
        Console.WriteLine("Making coffee:");
        BeverageMaker coffee = new CoffeeMaker();
        coffee.MakeBeverage();
        Console.WriteLine();
        
        Console.WriteLine("Making tea:");
        BeverageMaker tea = new TeaMaker();
        tea.MakeBeverage();
    }
}
