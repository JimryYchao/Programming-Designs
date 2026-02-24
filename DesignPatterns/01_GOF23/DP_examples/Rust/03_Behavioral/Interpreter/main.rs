// 客户端代码，用于测试解释器模式
mod arithmetic_expr;
mod terminal_expression;
mod nonterminal_expression;
mod calculator;

use calculator::Calculator;

fn main() {
    println!("{}", Calculator::calculate("1+2+3"));
    println!("{}", Calculator::calculate("2*(1+2)"));
    println!("{}", Calculator::calculate("2+(1+2*5)"));
    println!("{}", Calculator::calculate("2*(1+2*6)"));
    println!("{}", Calculator::calculate("(68*(115+20)+10)"));
}