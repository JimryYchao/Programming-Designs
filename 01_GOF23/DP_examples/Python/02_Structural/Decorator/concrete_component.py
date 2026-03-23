from component import IShape, Color


def _colorToString(color : Color):
    color_name = "unknown"
    if color == Color.red:
        color_name = "red"
    elif color == Color.green:
        color_name = "green"
    elif color == Color.blue:
        color_name = "blue"
    return color_name


class Circle(IShape):
    def draw(self):
        print("Draw a Circle.")
    
    def fill(self, color: Color):
        print(f"Fill with {_colorToString(color)}.")

class Rectangle(IShape):
    def draw(self):
        print("Draw a Rectangle.")
    
    def fill(self, color):
        print(f"Fill with {_colorToString(color)}.")
