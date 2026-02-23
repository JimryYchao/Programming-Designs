package Command

// ICommand 命令接口
type ICommand interface {
	Execute()
}

// ConcreteCommand 具体命令实现
type ConcreteCommand struct {
	receiver IReceiver
}

// NewConcreteCommand 创建具体命令
func NewConcreteCommand(receiver IReceiver) *ConcreteCommand {
	return &ConcreteCommand{
		receiver: receiver,
	}
}

// Execute 执行命令
func (c *ConcreteCommand) Execute() {
	if c.receiver != nil {
		c.receiver.Action()
	}
}
