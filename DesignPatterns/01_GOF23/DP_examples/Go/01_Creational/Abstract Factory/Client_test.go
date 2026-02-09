package AbstractFactory_test

import (
	. "AbstractFactory"
	"testing"
)

func TestAbstractFactory(t *testing.T) {
	factory := FactoryProducer.GetFactory(RedCircle)

	if shape := factory.GetShape(); shape != nil {
		shape.Draw()
	}
	if color := factory.GetColor(); color != nil {
		color.Fill()
	}
}
