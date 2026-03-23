// 饮料制作抽象类
pub trait BeverageMaker {
    // 模板方法：制作饮料的流程
    fn make_beverage(&self) {
        self.boil_water();
        self.brew();
        self.pour_in_cup();
        if self.customer_wants_condiments() {
            self.add_condiments();
        }
    }
    
    // 具体方法：烧水
    fn boil_water(&self) {
        println!("Boiling water");
    }
    
    // 具体方法：倒入杯子
    fn pour_in_cup(&self) {
        println!("Pouring into cup");
    }
    
    // 抽象方法：冲泡
    fn brew(&self);
    
    // 抽象方法：添加调料
    fn add_condiments(&self);
    
    // 钩子方法：顾客是否需要调料
    fn customer_wants_condiments(&self) -> bool {
        true
    }
}
