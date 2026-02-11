package Factory

// IShape 产品接口
type IShape interface {
	Draw()
	Fill()
}

// ShapeKind 产品类型枚举
type ShapeKind int

const (
	UNKNOWN_SHAPE ShapeKind = iota
	CIRCLE
	SQUARE
	RECTANGLE
	BIG_CIRCLE
)

// Circle 圆形产品
type Circle struct{}

func (c *Circle) Draw() {
	println("Draw a Circle")
}

func (c *Circle) Fill() {
	println("Fill red")
}

// Square 正方形产品
type Square struct{}

func (s *Square) Draw() {
	println("Draw a Square")
}

func (s *Square) Fill() {
	println("Fill Green")
}

// Rectangle 矩形产品
type Rectangle struct{}

func (r *Rectangle) Draw() {
	println("Draw a Rectangle")
}

func (r *Rectangle) Fill() {
	println("Fill Blue")
}

// UnknownShape 未知形状产品
type UnknownShape struct{}

func (u *UnknownShape) Draw() {}

func (u *UnknownShape) Fill() {}
