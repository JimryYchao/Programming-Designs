from Facade import build_shape, ShapeType

# 测试 Facade 模式
def test_facade_pattern():
    # 创建圆形
    circle = build_shape(ShapeType.CIRCLE, 10)
    if circle:
        circle.draw()

    # 创建矩形
    rectangle = build_shape(ShapeType.RECTANGLE, 10, 20)
    if rectangle:
        rectangle.draw()

    # 创建正方形
    square = build_shape(ShapeType.SQUARE, 10)
    if square:
        square.draw()

if __name__ == "__main__":
    test_facade_pattern()
