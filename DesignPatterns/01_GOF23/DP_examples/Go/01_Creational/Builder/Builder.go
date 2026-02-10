package Builder

type IBuilder interface {
	Build() Item
}

type IPacker interface {
	Pack(item Item)
}

type Item interface {
	Name() string
	Price() float64
	Packer() IPacker
}

type IMealBuilder interface {
	GetBuilders() []IBuilder
}
