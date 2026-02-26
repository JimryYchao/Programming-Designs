from memento import Memento

# 发起人类
class Originator:
    def __init__(self, s1, s2, s3):
        self.state1 = s1
        self.state2 = s2
        self.state3 = s3
    
    def console_state(self):
        print(f"State_1: {self.state1}")
        print(f"State_2: {self.state2}")
        print(f"State_3: {self.state3}")
    
    def create_memento(self, version):
        memento = Memento(version)
        memento.set_state("state1", self.state1)
        memento.set_state("state2", self.state2)
        memento.set_state("state3", self.state3)
        return memento
    
    def set_memento(self, m):
        self.state1 = m.get_state("state1")
        self.state2 = m.get_state("state2")
        self.state3 = m.get_state("state3")
