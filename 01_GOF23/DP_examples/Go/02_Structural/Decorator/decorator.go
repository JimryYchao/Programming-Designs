package Decorator

import "fmt"

type Decorator struct {
	shape IShape
}

func NewDecorator(shape IShape) *Decorator {
	return &Decorator{shape: shape}
}

func (d *Decorator) Draw() {
	if d.shape != nil {
		d.shape.Draw()
	}
}

func (d *Decorator) Fill(color Color) {
	if d.shape != nil {
		d.shape.Fill(color)
	}
}

type ShapeDecorator struct {
	*Decorator
}

func NewShapeDecorator(shape IShape) *ShapeDecorator {
	return &ShapeDecorator{
		Decorator: NewDecorator(shape),
	}
}

func (sd *ShapeDecorator) beforeDraw() {
	fmt.Println("Before Draw() >> Do...")
}

func (sd *ShapeDecorator) afterDraw() {
	fmt.Println("When Draw Complete >> Do...")
}

func (sd *ShapeDecorator) beforeFill() {
	fmt.Println("Before Fill() >> Do...")
}

func (sd *ShapeDecorator) afterFill() {
	fmt.Println("When Fill Complete >> Do...")
}

func (sd *ShapeDecorator) Draw() {
	sd.beforeDraw()
	sd.Decorator.Draw()
	sd.afterDraw()
}

func (sd *ShapeDecorator) Fill(color Color) {
	sd.beforeFill()
	sd.Decorator.Fill(color)
	sd.afterFill()
}
