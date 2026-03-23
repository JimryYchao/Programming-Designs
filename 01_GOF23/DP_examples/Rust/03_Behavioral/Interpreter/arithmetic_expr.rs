// 抽象表达式接口
pub trait ArithmeticExpr {
    fn interpret(&self) -> f64;
}