from Product import ShapeKind, Circle, Square, Rectangle

class ShapeCache:
    _instance = None
    _shape_map = {}
    # def __new__(cls):
    #     if cls._instance is None:
    #         cls._instance = super().__new__(cls)
    #         cls._instance._shape_map = {}
    #     return cls._instance

    def GetInstance():
        if ShapeCache._instance is None:
            ShapeCache._instance = ShapeCache()
            ShapeCache._instance._shape_map = {}
            ShapeCache._instance.register_prototype(ShapeKind.Circle, Circle())
            ShapeCache._instance.register_prototype(ShapeKind.Square, Square())
            ShapeCache._instance.register_prototype(ShapeKind.Rectangle, Rectangle())
        return ShapeCache._instance

    def register_prototype(self, key, shape):
        self._shape_map[key] = shape

    def remove_prototype(self, key):
        if key in self._shape_map:
            del self._shape_map[key]
            return True
        return False

    def get_shape(self, key):
        if key in self._shape_map:
            return self._shape_map[key].clone()
        return None
