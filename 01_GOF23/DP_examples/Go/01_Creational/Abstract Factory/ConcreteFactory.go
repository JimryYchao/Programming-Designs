package AbstractFactory

type ProductKind int

const (
	RedCircle     ProductKind = iota
	GreenSquare   ProductKind = iota
	BlueRectangle ProductKind = iota
)

type factoryProducer struct{}

var dicFactory = make(map[ProductKind]AbstractFactory, 5)
var FactoryProducer = factoryProducer{}

func (factoryProducer) createFactory(shapeType ProductKind) AbstractFactory {
	switch shapeType {
	case RedCircle:
		return productFactory[red, circle]{}
	case GreenSquare:
		return productFactory[green, square]{}
	case BlueRectangle:
		return productFactory[blue, rectangle]{}
	default:
		return productFactory[unknownColor, unknownShape]{}
	}
}
func (factoryProducer) GetFactory(shapeType ProductKind) AbstractFactory {
	if _, ok := dicFactory[shapeType]; !ok {
		dicFactory[shapeType] = FactoryProducer.createFactory(shapeType)
	}
	return dicFactory[shapeType]
}
