# 备忘录类
class Memento:
    def __init__(self, version):
        self.states = {}
        self.version = version
    
    def get_state(self, identifier):
        return self.states.get(identifier)
    
    def set_state(self, identifier, state):
        self.states[identifier] = state
