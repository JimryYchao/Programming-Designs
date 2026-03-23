// 策略接口
pub trait IStrategy {
    fn sort(&self, array: &mut [i32]);
}
