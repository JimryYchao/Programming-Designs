# 管理者类
class Caretaker:
    def __init__(self):
        self.memento_map = {}
    
    def save_memento(self, version, m):
        self.memento_map[version] = m
    
    def get_memento(self, version):
        return self.memento_map.get(version)
