from ConcreteBuilder import IMealBuilder, MealBuilder

class Director:
    def __init__(self, builder: IMealBuilder):
        self.builder = builder
    
    def Construct(self):
        return MealBuilder(self.builder.GetBuilders())
