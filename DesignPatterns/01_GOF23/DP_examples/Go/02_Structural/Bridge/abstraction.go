package Bridge

// 抽象类
type Shape struct {
	draw DrawAPI
}

func NewShape(draw DrawAPI) *Shape {
	return &Shape{draw: draw}
}
func (s *Shape) Draw(color Color) {
	s.draw.Draw()
	s.draw.Fill(color)
}

type ShapeAdvance struct {
	Shape
	onDrawCompleted func()
}

func NewShapeAdvance(draw DrawAPI, onDrawCompleted func()) *ShapeAdvance {
	return &ShapeAdvance{
		Shape:           *NewShape(draw),
		onDrawCompleted: onDrawCompleted,
	}
}
func (sa *ShapeAdvance) Draw(color Color) {
	sa.Shape.Draw(color)
	if sa.onDrawCompleted != nil {
		sa.onDrawCompleted()
	}
}
