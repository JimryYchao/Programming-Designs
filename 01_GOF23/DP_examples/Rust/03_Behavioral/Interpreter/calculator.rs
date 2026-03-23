// 计算器类，用于构建和解析表达式
use crate::arithmetic_expr::ArithmeticExpr;
use crate::terminal_expression::NumberExpr;
use crate::nonterminal_expression::{AdditionExpr, SubtractionExpr, MultiplicationExpr, DivisionExpr};

pub struct Calculator;

impl Calculator {
    pub fn calculate(expression: &str) -> f64 {
        let end_expre = Self::create_expression_tree(expression, 0, expression.len() - 1);
        end_expre.interpret()
    }

    fn find_split(expression: &str, start: usize, end: usize) -> Option<usize> {
        let mut tag = None;
        let mut adjusted_start = start;
        let mut adjusted_end = end;

        if expression.chars().nth(start) == Some('(') && expression.chars().nth(end) == Some(')') {
            adjusted_start += 1;
            adjusted_end -= 1;
        }

        let mut is_in_bracket = 0;
        let mut more_grade = 0;

        for i in adjusted_start..=adjusted_end {
            match expression.chars().nth(i) {
                Some('(') => is_in_bracket += 1,
                Some(')') => is_in_bracket -= 1,
                _ => {}
            }

            if is_in_bracket == 0 {
                match expression.chars().nth(i) {
                    Some('+') | Some('-') => {
                        more_grade = 1;
                        tag = Some(i);
                    }
                    Some('*') | Some('/') if more_grade == 0 => {
                        tag = Some(i);
                    }
                    _ => {}
                }
            }
        }

        tag
    }

    fn create_expression_tree(expression: &str, start: usize, end: usize) -> Box<dyn ArithmeticExpr> {
        let substr = &expression[start..=end];

        // 尝试解析为数字
        if let Ok(num) = substr.parse::<f64>() {
            return Box::new(NumberExpr::new(num));
        }

        // 查找分割点
        if let Some(tag) = Self::find_split(expression, start, end) {
            let left = Self::create_expression_tree(expression, start, tag - 1);
            let right = Self::create_expression_tree(expression, tag + 1, end);

            match expression.chars().nth(tag) {
                Some('+') => Box::new(AdditionExpr::new(left, right)),
                Some('-') => Box::new(SubtractionExpr::new(left, right)),
                Some('*') => Box::new(MultiplicationExpr::new(left, right)),
                Some('/') => Box::new(DivisionExpr::new(left, right)),
                _ => panic!("Unknown operator"),
            }
        } else {
            // 处理括号内的数字
            let s: String = substr.chars().filter(|&c| c != '(' && c != ')').collect();
            if let Ok(num) = s.parse::<f64>() {
                Box::new(NumberExpr::new(num))
            } else {
                panic!("Invalid expression");
            }
        }
    }
}