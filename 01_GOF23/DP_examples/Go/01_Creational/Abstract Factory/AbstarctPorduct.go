package AbstractFactory

type (
	IShape interface {
		any
		Draw()
	}
	circle       struct{}
	rectangle    struct{}
	square       struct{}
	unknownShape struct{}
)

func (c circle) Draw() {
	println("Draw a Circle")
}
func (r rectangle) Draw() {
	println("Draw a Rectangle")
}
func (s square) Draw() {
	println("Draw a Square")
}
func (u unknownShape) Draw() {}

type (
	IColor interface {
		Fill()
	}
	red          struct{}
	green        struct{}
	blue         struct{}
	unknownColor struct{}
)

func (r red) Fill() {
	println("Fill Red")
}
func (g green) Fill() {
	println("Fill Green")
}
func (b blue) Fill() {
	println("Fill Blue")
}
func (u unknownColor) Fill() {}
