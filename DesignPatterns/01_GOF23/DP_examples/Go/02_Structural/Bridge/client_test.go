package Bridge_test

import (
	. "Bridge"
	"fmt"
	"testing"
)

func TestBridgeDemo(t *testing.T) {
	circle := NewShape(&Circle{})
	circle.Draw(Green)

	square := NewShapeAdvance(&Square{}, func() {
		fmt.Println("Drew Completely")
	})
	square.Draw(Blue)
}
