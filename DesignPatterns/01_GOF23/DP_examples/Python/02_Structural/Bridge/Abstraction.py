from Implementor import DrawAPI, Color

class Shape:
    def __init__(self, draw):
        self.draw = draw
    
    def Draw(self, color):
        self.draw.draw()
        self.draw.fill(color)

# 修正抽象类
class ShapeAdvance(Shape):
    def __init__(self, draw, on_draw_completed):
        super().__init__(draw)
        self.on_draw_completed = on_draw_completed
    
    def Draw(self, color):
        super().Draw(color)
        if self.on_draw_completed:
            self.on_draw_completed()
