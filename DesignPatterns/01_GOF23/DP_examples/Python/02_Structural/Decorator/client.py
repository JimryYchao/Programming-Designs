from component import Color
from concrete_component import Circle, Rectangle
from decorator import ShapeDecorator, Decorator

# 创建红色圆形
red_circle = Decorator(Circle())
red_circle.draw()
red_circle.fill(Color.red)

# 创建绿色矩形
green_rectangle = ShapeDecorator(Rectangle())
green_rectangle.draw()
green_rectangle.fill(Color.green)
