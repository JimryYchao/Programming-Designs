from FlyweightFactory import FlyweightFactory

# 构建圆形
def build_circles():
    # 获取 FlyweightFactory 单例
    factory = FlyweightFactory()
    
    # 创建红色圆形
    red_circle = factory.get_circle("Red", 10, 0, 0)
    red_circle.draw()
    red_circle.fill()
    
    # 创建特殊绿色大圆形
    green_big_circle = factory.get_special_circle("Green", 100, 100, 100)
    green_big_circle.draw()
    green_big_circle.fill()
    green_big_circle.reset_radius(10)
    green_big_circle.move_position(0, 0)

# 构建享元圆形
def build_flyweight_circle():
    # 获取 FlyweightFactory 单例
    factory = FlyweightFactory()
    
    # 创建红色圆形（复用之前的 CircleData）
    red_circle = factory.get_circle("Red", 10, 10086, 10010)
    red_circle.draw()
    red_circle.fill()

# 测试 Flyweight 模式
def test_flyweight_pattern():
    build_circles()
    build_flyweight_circle()

if __name__ == "__main__":
    test_flyweight_pattern()
