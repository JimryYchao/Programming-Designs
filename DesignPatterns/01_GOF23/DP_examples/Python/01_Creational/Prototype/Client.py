from ShapeCache import ShapeCache
from Product import Color, ShapeKind

# 测试代码
if __name__ == "__main__":
    # 加载形状缓存
    cache = ShapeCache.GetInstance()

    # 克隆不同形状
    circle = cache.get_shape(ShapeKind.Circle)
    if circle:
        circle.draw()
        circle.fill(Color.Red)

    square = cache.get_shape(ShapeKind.Square)
    if square:
        square.draw()
        square.fill(Color.Green)

    cache.remove_prototype(ShapeKind.Rectangle)
    rectangle = cache.get_shape(ShapeKind.Rectangle)
    if rectangle is not None:
        print("Rectangle should be nil after removal")
