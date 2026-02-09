package AbstractFactory

type AbstractFactory interface {
	GetShape() IShape
	GetColor() IColor
}

type productFactory[Color IColor, Shape IShape] struct{}

func (p productFactory[Color, Shape]) GetShape() IShape {
	return *new(Shape)
}
func (p productFactory[Color, Shape]) GetColor() IColor {
	return *new(Color)
}
