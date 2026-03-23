# 迭代器接口
from abc import ABC, abstractmethod

class Iterator(ABC):
    @abstractmethod
    def first(self):
        pass
    
    @abstractmethod
    def next(self):
        pass
    
    @abstractmethod
    def is_done(self):
        pass
    
    @abstractmethod
    def current_item(self):
        pass

# 可迭代接口
class Iterable(ABC):
    @abstractmethod
    def get_iterator(self):
        pass

# 聚合接口
class IAggregate(Iterable):
    @abstractmethod
    def count(self):
        pass
    
    @abstractmethod
    def add(self, item):
        pass
    
    @abstractmethod
    def remove(self, item):
        pass
    
    @abstractmethod
    def contains(self, item):
        pass
    
    @abstractmethod
    def clear(self):
        pass
