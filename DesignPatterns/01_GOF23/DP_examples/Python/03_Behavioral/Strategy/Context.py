# 上下文类
class Context:
    def __init__(self, strategy):
        self.strategy = strategy
    
    def set_strategy(self, strategy):
        self.strategy = strategy
    
    def sort(self, array):
        self.strategy.sort(array)
