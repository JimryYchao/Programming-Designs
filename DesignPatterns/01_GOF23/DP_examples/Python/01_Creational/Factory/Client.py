from ConcreteCreator import ShapeFactory
from Product import ShapeKind

# 工厂模式演示
def example():
    # 测试圆形
    circle = ShapeFactory.get_shape(ShapeKind.Circle)
    circle.draw()
    circle.fill()
    
    # 测试大圆形
    big_circle = ShapeFactory.get_shape(ShapeKind.BigCircle)
    big_circle.draw()
    big_circle.fill()
    
    # 测试正方形
    square = ShapeFactory.get_shape(ShapeKind.Square)
    square.draw()
    square.fill()

if __name__ == "__main__":
    example()
