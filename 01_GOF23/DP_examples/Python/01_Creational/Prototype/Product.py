from abc import ABC, abstractmethod

class Color:
    Unknown = 0
    Red = 1
    Green = 2
    Blue = 3
    Yellow = 4

    @staticmethod
    def to_string(color):
        color_map = {
            Color.Red: "Red",
            Color.Green: "Green",
            Color.Blue: "Blue",
            Color.Yellow: "Yellow"
        }
        return color_map.get(color, "Unknown")

class IShape(ABC):
    @abstractmethod
    def name(self):
        pass

    @abstractmethod
    def draw(self):
        pass

    @abstractmethod
    def fill(self, color):
        pass

    @abstractmethod
    def clone(self):
        pass

class Shape(IShape):
    def __init__(self, id=0, name=""):
        self._id = id
        self._name = name

    def name(self):
        return self._name

    def draw(self):
        pass

    def fill(self, color):
        pass

    def clone(self):
        pass

class ShapeKind:
    Unknown = 0
    Circle = 1
    Square = 2
    Rectangle = 3

class Circle(Shape):
    def __init__(self, id=ShapeKind.Circle, name="Circle"):
        super().__init__(id, name)

    def draw(self):
        print("Draw a Circle")

    def fill(self, color):
        print(f"Fill with {Color.to_string(color)}")

    def clone(self):
        return Circle(self._id, self._name)

class Square(Shape):
    def __init__(self, id=ShapeKind.Square, name="Square"):
        super().__init__(id, name)

    def draw(self):
        print("Draw a Square")

    def fill(self, color):
        print(f"Fill with {Color.to_string(color)}")

    def clone(self):
        return Square(self._id, self._name)

class Rectangle(Shape):
    def __init__(self, id=ShapeKind.Rectangle, name="Rectangle"):
        super().__init__(id, name)

    def draw(self):
        print("Draw a Rectangle")

    def fill(self, color):
        print(f"Fill with {Color.to_string(color)}")

    def clone(self):
        return Rectangle(self._id, self._name)
