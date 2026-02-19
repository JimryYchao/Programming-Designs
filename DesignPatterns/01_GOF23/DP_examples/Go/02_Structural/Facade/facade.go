package Facade

// 形状类型枚举
type ShapeType int

const (
	CIRCLE ShapeType = iota
	RECTANGLE
	SQUARE
)

// 形状创建者（外观类）
type shapeMaker struct{}

// 单例实例
var ShapeMaker shapeMaker

// 构建形状
func (sm shapeMaker) BuildShape(shapeType ShapeType, args ...int) IShape {
	switch shapeType {
	case CIRCLE:
		if len(args) >= 1 {
			return NewCircle(args[0])
		}
	case RECTANGLE:
		if len(args) >= 2 {
			return NewRectangle(args[0], args[1])
		}
	case SQUARE:
		if len(args) >= 1 {
			return NewSquare(args[0])
		}
	}
	return nil
}
