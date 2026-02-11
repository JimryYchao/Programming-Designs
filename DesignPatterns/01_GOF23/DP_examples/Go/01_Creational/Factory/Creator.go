package Factory

// ICreator 创建者接口
type ICreator interface {
	GetShape() IShape
}

// unknownShapeCreator 未知形状创建者
type unknownShapeCreator struct{}

func (c unknownShapeCreator) GetShape() IShape {
	return &UnknownShape{}
}

// circleCreator 圆形创建者
type circleCreator struct{}

func (c circleCreator) GetShape() IShape {
	return &Circle{}
}

// squareCreator 正方形创建者
type squareCreator struct{}

func (c squareCreator) GetShape() IShape {
	return &Square{}
}

// rectangleCreator 矩形创建者
type rectangleCreator struct{}

func (c rectangleCreator) GetShape() IShape {
	return &Rectangle{}
}

// bigCircleCreator 大圆形创建者
type bigCircleCreator struct {
	circleCreator
}

func (c bigCircleCreator) setRadius() {
	println("Set Radius to 10")
}

func (c bigCircleCreator) GetShape() IShape {
	c.setRadius()
	return c.circleCreator.GetShape()
}

func newCreator(kind ShapeKind) ICreator {
	var creator ICreator
	switch kind {
	case CIRCLE:
		creator = circleCreator{}
	case SQUARE:
		creator = squareCreator{}
	case RECTANGLE:
		creator = rectangleCreator{}
	case BIG_CIRCLE:
		creator = bigCircleCreator{}
	default:
		creator = unknownShapeCreator{}
	}
	return creator
}
