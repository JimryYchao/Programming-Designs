# 命令调用者


class Invoker:
    def __init__(self):
        self.commands = []
    
    def store_command(self, command):
        self.commands.append(command)
    
    def remove_command(self, command):
        if not self.commands:
            return False
        if command in self.commands:
            self.commands.remove(command)
            return True
        return False
    
    @property
    def count(self):
        return len(self.commands)
    
    def invoke(self):
        for command in self.commands:
            command.execute()
