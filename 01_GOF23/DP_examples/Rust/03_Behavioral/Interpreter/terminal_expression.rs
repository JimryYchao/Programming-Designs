// 终结符表达式 - 处理数字
use crate::arithmetic_expr::ArithmeticExpr;

pub struct NumberExpr {
    num: f64,
}

impl NumberExpr {
    pub fn new(num: f64) -> Self {
        NumberExpr { num }
    }
}

impl ArithmeticExpr for NumberExpr {
    fn interpret(&self) -> f64 {
        self.num
    }
}