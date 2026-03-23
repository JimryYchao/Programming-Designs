from Flyweight import Circle
from UnsharedFlyweight import CircleAddition, CircleFactory

# 享元工厂
class FlyweightFactory:
    _instance = None
    
    def __new__(cls):
        if cls._instance is None:
            cls._instance = super(FlyweightFactory, cls).__new__(cls)
            cls._instance.shape_dic = {}
            cls._instance.circle_factory = CircleFactory()
        return cls._instance
    
    def get_circle(self, color: str, radius: float, x: float, y: float) -> Circle:
        circle = None
        
        if color in self.shape_dic:
            if radius in self.shape_dic[color]:
                data = self.shape_dic[color][radius]
                return self.circle_factory.get_circle_by_data(data, x, y)
            else:
                circle = self.circle_factory.get_circle(color, radius, x, y)
                self.shape_dic[color][radius] = circle.data
        else:
            self.shape_dic[color] = {}
            circle = self.circle_factory.get_circle(color, radius, x, y)
            self.shape_dic[color][radius] = circle.data
        
        print(f"Create a New Circle Filled with {color}")
        return circle
    
    def get_special_circle(self, color: str, radius: float, x: float, y: float) -> CircleAddition:
        circle = self.get_circle(color, radius, x, y)
        return self.circle_factory.get_spacial_circle(circle)
