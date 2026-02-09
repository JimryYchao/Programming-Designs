"""
Client.py
"""

from ConcreteFactory import FactoryProducer, ProductKind

# 客户端代码
def draw_shape(ab):
    shape = ab.GetShape()
    color = ab.GetColor()
    shape.Draw()
    color.Fill()

# 示例
def example():
    factory_producer = FactoryProducer()
    
    # 红色圆形
    red_circle_f = factory_producer.GetFactory(ProductKind.RedCircle)
    draw_shape(red_circle_f)
    
    # 蓝色矩形
    blue_rectangle_f = factory_producer.GetFactory(ProductKind.BlueRectangle)
    draw_shape(blue_rectangle_f)

if __name__ == "__main__":
    example()
