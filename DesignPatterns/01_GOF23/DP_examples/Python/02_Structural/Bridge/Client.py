from Implementor import Circle, Square, Color
from Abstraction import Shape, ShapeAdvance

# 测试 Bridge 模式
def test_bridge_pattern():
    # 创建圆形形状
    circle = Shape(Circle())
    circle.Draw(Color.GREEN)

    def on_draw_completed():
        print("Drew Completely")
    
    square = ShapeAdvance(Square(), on_draw_completed)
    square.Draw(Color.BLUE)

if __name__ == "__main__":
    test_bridge_pattern()
