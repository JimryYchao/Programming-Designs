from abc import ABC, abstractmethod

# 叶子接口
class ILeaf(ABC):
    @abstractmethod
    def is_leaf(self):
        pass
    
    @abstractmethod
    def operation(self):
        pass

# 组件接口
class IComponent(ILeaf):
    @abstractmethod
    def add(self, component):
        pass
    
    @abstractmethod
    def remove(self, component):
        pass
    
    @abstractmethod
    def get_child(self, index):
        pass

# 组合类
class Composite(IComponent):
    def __init__(self, is_leaf):
        self._is_leaf = is_leaf
        self._sub_composites = []
    
    def is_leaf(self):
        return self._is_leaf
    
    def operation(self):
        if not self._is_leaf:
            for comp in self._sub_composites:
                comp.operation()
    
    def add(self, component):
        if self._is_leaf or component is None:
            return -1
        # 检查是否已存在
        if component in self._sub_composites:
            return -1
        self._sub_composites.append(component)
        return len(self._sub_composites)
    
    def remove(self, component):
        if self._is_leaf:
            return False
        if component in self._sub_composites:
            self._sub_composites.remove(component)
            return True
        return False
    
    def get_child(self, index):
        if index < 0 or index >= len(self._sub_composites):
            return None
        return self._sub_composites[index]

     
