from Element import Computer
from ConcreteVisitor import ComputerPartDisplayVisitor

def __main__():
    computer = Computer()
    visitor = ComputerPartDisplayVisitor()
    computer.accept(visitor)


if __name__ == "__main__":
    __main__()
   