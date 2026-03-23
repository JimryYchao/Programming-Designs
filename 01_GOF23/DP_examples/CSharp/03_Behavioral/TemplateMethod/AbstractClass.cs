using System;

namespace Behavioral.TemplateMethod;

public abstract class BeverageMaker {
    // 模板方法：制作饮料的流程
    public void MakeBeverage() {
        BoilWater();
        Brew();
        PourInCup();
        AddCondiments();
        
        // 钩子方法
        CustomerWantsCondiments();
    }
    
    // 具体方法：烧水（相同步骤）
    private void BoilWater() {
        Console.WriteLine("Boiling water");
    }
    
    // 具体方法：倒入杯子（相同步骤）
    private void PourInCup() {
        Console.WriteLine("Pouring into cup");
    }
    
    // 抽象方法：冲泡（不同饮料不同实现）
    protected abstract void Brew();
    
    // 抽象方法：添加调料（不同饮料不同实现）
    protected abstract void AddCondiments();
    
    // 钩子方法：顾客是否需要调料
    protected virtual bool CustomerWantsCondiments() {
        return true;
    }
}
