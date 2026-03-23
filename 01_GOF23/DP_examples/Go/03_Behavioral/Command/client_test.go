package Command_test

import (
	. "Command"
	"testing"
)

func buildCommands() *Invoker {
	// 创建命令调用者
	invoker := NewInvoker()

	// 创建一个具体的命令对象并设定它的接收者
	c := NewConcreteCommand(NewBuyStock(Stock{Name: "book", Quantity: 10}))

	// 关联 Invoker 并控制执行/撤销操作
	invoker.StoreCommand(c)
	invoker.StoreCommand(NewConcreteCommand(NewBuyStock(Stock{Name: "pencil", Quantity: 15})))
	invoker.StoreCommand(NewConcreteCommand(NewSellStock(Stock{Name: "pen", Quantity: 18})))
	invoker.RemoveCommand(c)

	return invoker
}

func TestClient(t *testing.T) {
	// 构建命令
	invoker := buildCommands()

	// 执行命令
	invoker.Invoke()
}
