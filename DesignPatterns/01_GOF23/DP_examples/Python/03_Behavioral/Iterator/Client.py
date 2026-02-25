from ConcreteAggregate import ConcreteAggregate

# 迭代器引擎
class IteratorEngine:
    @staticmethod
    def execute(aggregate, action):
        iterator = aggregate.get_iterator()
        iterator.first()
        while not iterator.is_done():
            try:
                item = iterator.current_item()
                action(item)
            except IndexError:
                pass
            iterator.next()

# 测试代码
if __name__ == "__main__":
    # 创建聚合对象
    aggregate = ConcreteAggregate(4)
    
    # 添加元素
    aggregate.add(1)
    aggregate.add(2)
    aggregate.add(3)
    aggregate.add(4)
    # 校验扩容
    aggregate.add(5)
    aggregate.add(6)
    
    # 执行迭代
    print("Iterating over aggregate:")
    engine = IteratorEngine()
    engine.execute(aggregate, lambda a: print(f"Print : number >> {a}"))
    
    # 测试其他方法
    print(f"Count: {aggregate.count()}")
    print(f"Contains 3: {aggregate.contains(3)}")
    print(f"Remove 3: {aggregate.remove(3)}")
    print(f"Contains 3 after removal: {aggregate.contains(3)}")
    
    # 再次迭代
    print("Iterating after removal:")
    engine.execute(aggregate, lambda a: print(f"Print : number >> {a}"))
    
    # 清空
    aggregate.clear()
    print(f"Count after clear: {aggregate.count()}")
