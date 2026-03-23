namespace Behavioral.TemplateMethod;

public class CoffeeMaker : BeverageMaker {
    protected override void Brew() {
        Console.WriteLine("Brewing coffee grounds");
    }
    
    protected override void AddCondiments() {
        Console.WriteLine("Adding sugar and milk");
    }
    
    // 重写钩子方法，默认需要调料
    protected override bool CustomerWantsCondiments() {
        Console.WriteLine("Customer wants sugar and milk");
        return true;
    }
}

public class TeaMaker : BeverageMaker {
    protected override void Brew() {
        Console.WriteLine("Steeping the tea bag");
    }
    
    protected override void AddCondiments() {
        Console.WriteLine("Adding lemon");
    }
    
    // 重写钩子方法，默认需要调料
    protected override bool CustomerWantsCondiments() {
        Console.WriteLine("Customer wants lemon");
        return true;
    }
}
