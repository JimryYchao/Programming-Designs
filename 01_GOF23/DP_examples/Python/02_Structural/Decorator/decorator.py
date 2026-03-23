from component import IShape, Color

class Decorator(IShape):
    def __init__(self, shape):
        self.shape_component = shape
    
    def draw(self):
        if self.shape_component:
            self.shape_component.draw()
    
    def fill(self, color: Color):
        if self.shape_component:
            self.shape_component.fill(color)

class ShapeDecorator(Decorator):
    def __init__(self, shape : IShape):
        super().__init__(shape)
    
    def _before_draw(self):
        print("Before Draw() >> Do...")
    
    def _after_draw(self):
        print("When Draw Complete >> Do...")
    
    def _before_fill(self):
        print("Before Fill() >> Do...")
    
    def _after_fill(self):
        print("When Fill Complete >> Do...")
    
    def draw(self):
        self._before_draw()
        super().draw()
        self._after_draw()
    
    def fill(self, color: Color):
        self._before_fill()     
        super().fill(color)
        self._after_fill()
