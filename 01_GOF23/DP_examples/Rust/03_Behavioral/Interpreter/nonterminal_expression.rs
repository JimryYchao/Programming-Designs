// 非终结符表达式 - 处理运算符
use crate::arithmetic_expr::ArithmeticExpr;

pub struct OperationExpr {
    exp1: Box<dyn ArithmeticExpr>,
    exp2: Box<dyn ArithmeticExpr>,
}

// 加法表达式
pub struct AdditionExpr {
    operation: OperationExpr,
}

impl AdditionExpr {
    pub fn new(exp1: Box<dyn ArithmeticExpr>, exp2: Box<dyn ArithmeticExpr>) -> Self {
        AdditionExpr {
            operation: OperationExpr { exp1, exp2 },
        }
    }
}

impl ArithmeticExpr for AdditionExpr {
    fn interpret(&self) -> f64 {
        self.operation.exp1.interpret() + self.operation.exp2.interpret()
    }
}

// 减法表达式
pub struct SubtractionExpr {
    operation: OperationExpr,
}

impl SubtractionExpr {
    pub fn new(exp1: Box<dyn ArithmeticExpr>, exp2: Box<dyn ArithmeticExpr>) -> Self {
        SubtractionExpr {
            operation: OperationExpr { exp1, exp2 },
        }
    }
}

impl ArithmeticExpr for SubtractionExpr {
    fn interpret(&self) -> f64 {
        self.operation.exp1.interpret() - self.operation.exp2.interpret()
    }
}

// 乘法表达式
pub struct MultiplicationExpr {
    operation: OperationExpr,
}

impl MultiplicationExpr {
    pub fn new(exp1: Box<dyn ArithmeticExpr>, exp2: Box<dyn ArithmeticExpr>) -> Self {
        MultiplicationExpr {
            operation: OperationExpr { exp1, exp2 },
        }
    }
}

impl ArithmeticExpr for MultiplicationExpr {
    fn interpret(&self) -> f64 {
        self.operation.exp1.interpret() * self.operation.exp2.interpret()
    }
}

// 除法表达式
pub struct DivisionExpr {
    operation: OperationExpr,
}

impl DivisionExpr {
    pub fn new(exp1: Box<dyn ArithmeticExpr>, exp2: Box<dyn ArithmeticExpr>) -> Self {
        DivisionExpr {
            operation: OperationExpr { exp1, exp2 },
        }
    }
}

impl ArithmeticExpr for DivisionExpr {
    fn interpret(&self) -> f64 {
        self.operation.exp1.interpret() / self.operation.exp2.interpret()
    }
}