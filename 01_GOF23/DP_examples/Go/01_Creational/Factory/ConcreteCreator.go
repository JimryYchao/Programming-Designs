package Factory

// ShapeFactory 形状工厂
type shapeFactory struct {
	factories map[ShapeKind]ICreator
}

var ShapeFactory shapeFactory = shapeFactory{
	factories: make(map[ShapeKind]ICreator),
}

func (f shapeFactory) GetShape(kind ShapeKind) IShape {
	creator := f.getFactory(kind)
	return creator.GetShape()
}

// GetFactory 根据类型获取创建者
func (f shapeFactory) getFactory(kind ShapeKind) ICreator {
	if _, ok := f.factories[kind]; !ok {
		f.factories[kind] = newCreator(kind)
	}
	return f.factories[kind]
}
