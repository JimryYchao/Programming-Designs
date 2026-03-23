package Prototype

type ShapeCache struct {
	shapeMap map[ShapeKind]IShape
}

var instance *ShapeCache

func ShapeCache_GetInstance() *ShapeCache {
	if instance == nil {
		instance = &ShapeCache{
			shapeMap: make(map[ShapeKind]IShape),
		}
		instance.loadCache()
	}
	return instance
}

func (sc *ShapeCache) loadCache() {
	sc.RegisterPrototype(CIRCLE, NewCircle(CIRCLE, "Circle"))
	sc.RegisterPrototype(SQUARE, NewSquare(SQUARE, "Square"))
	sc.RegisterPrototype(RECTANGLE, NewRectangle(RECTANGLE, "Rectangle"))
}

func (sc *ShapeCache) RegisterPrototype(key ShapeKind, shape IShape) {
	if _, ok := sc.shapeMap[key]; !ok {
		sc.shapeMap[key] = shape
	}
}

func (sc *ShapeCache) RemovePrototype(key ShapeKind) {
	_, ok := sc.shapeMap[key]
	if ok {
		delete(sc.shapeMap, key)
	}
}

func (sc *ShapeCache) GetShape(key ShapeKind) IShape {

	if shape, ok := sc.shapeMap[key]; ok {
		return shape.Clone()
	}
	return nil
}
