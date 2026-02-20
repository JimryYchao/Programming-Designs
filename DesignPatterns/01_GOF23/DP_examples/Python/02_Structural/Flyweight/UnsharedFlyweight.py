from Flyweight import IShape, CircleData, Circle

# 非共享具体享元类 - 圆形增强
class CircleAddition(IShape):
    def __init__(self, circle: Circle):
        self.shape = circle
    
    def draw(self):
        self.shape.draw()
    
    def fill(self):
        self.shape.fill()
    
    def move_position(self, x: float, y: float):
        print(f"Move Circle to ({x:.2f}, {y:.2f})")
    
    def reset_radius(self, radius: float):
        print(f"Reset Radius to {radius:.2f}")

# 圆形工厂
class CircleFactory:
    _instance = None
    def __new__(cls):
        if cls._instance is None:
            cls._instance = super(CircleFactory, cls).__new__(cls)
        return cls._instance    

    def get_circle(self, color: str, radius: float, x: float, y: float) -> Circle:
        data = CircleData(color, radius)
        return Circle(data, x, y)
    
    def get_circle_by_data(self, data: CircleData, x: float, y: float) -> Circle:
        return Circle(data, x, y)
    
    def get_spacial_circle(self, circle: Circle) -> CircleAddition:
        return CircleAddition(circle)
