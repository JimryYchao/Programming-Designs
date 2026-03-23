// 客户端代码，用于测试解释器模式
package Interpreter_test

import (
	. "Interpreter"
	"fmt"
	"testing"
)

func TestInterpreter(t *testing.T) {
	fmt.Println(Calculate("1+2+3"))
	fmt.Println(Calculate("2*(1+2)"))
	fmt.Println(Calculate("2+(1+2*5)"))
	fmt.Println(Calculate("2*(1+2*6)"))
	fmt.Println(Calculate("(68*(115+20)+10)"))
}
