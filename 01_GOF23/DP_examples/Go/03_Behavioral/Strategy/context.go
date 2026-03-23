package strategy

// Context 上下文类
type Context struct {
	strategy IStrategy
}

// NewContext 创建上下文实例
func NewContext(strategy IStrategy) *Context {
	return &Context{
		strategy: strategy,
	}
}

// SetStrategy 设置策略
func (c *Context) SetStrategy(strategy IStrategy) {
	c.strategy = strategy
}

// Sort 执行排序操作
func (c *Context) Sort(array []int) {
	c.strategy.Sort(array)
}
