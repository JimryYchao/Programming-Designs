package Command

// Invoker 命令调用者
type Invoker struct {
	commands []ICommand
}

// NewInvoker 创建命令调用者
func NewInvoker() *Invoker {
	return &Invoker{
		commands: make([]ICommand, 0),
	}
}

// StoreCommand 存储命令
func (i *Invoker) StoreCommand(command ICommand) {
	i.commands = append(i.commands, command)
}

// RemoveCommand 移除命令
func (i *Invoker) RemoveCommand(command ICommand) bool {
	if len(i.commands) == 0 {
		return false
	}
	for index, cmd := range i.commands {
		if cmd == command {
			i.commands = append(i.commands[:index], i.commands[index+1:]...)
			return true
		}
	}
	return false
}

// Count 获取命令数量
func (i *Invoker) Count() int {
	return len(i.commands)
}

// Invoke 执行所有命令
func (i *Invoker) Invoke() {
	for _, command := range i.commands {
		command.Execute()
	}
}
