package Composite

import "slices"

// 叶子接口
type ILeaf interface {
	IsLeaf() bool
	Operation()
}

// 组件接口
type IComponent interface {
	ILeaf
	Add(component IComponent) int
	Remove(component IComponent) bool
	GetChild(index int) IComponent
}

// 组合类
type Composite struct {
	isLeaf        bool
	subComposites []IComponent
}

// 创建组合实例
func NewComposite(isLeaf bool) *Composite {
	return &Composite{
		isLeaf:        isLeaf,
		subComposites: make([]IComponent, 0),
	}
}
func (c *Composite) IsLeaf() bool {
	return c.isLeaf
}
func (c *Composite) Add(component IComponent) int {
	if c.isLeaf || component == nil {
		return -1
	}
	// 检查是否已存在
	if !slices.Contains(c.subComposites, component) {
		c.subComposites = append(c.subComposites, component)
		return len(c.subComposites)
	}
	return -1
}

func (c *Composite) Remove(component IComponent) bool {
	if c.isLeaf {
		return false
	}
	for i, comp := range c.subComposites {
		if comp == component {
			c.subComposites = append(c.subComposites[:i], c.subComposites[i+1:]...)
			return true
		}
	}
	return false
}

func (c *Composite) GetChild(index int) IComponent {
	if index < 0 || index >= len(c.subComposites) {
		return nil
	}
	return c.subComposites[index]
}

// 执行操作
func (c *Composite) Operation() {
	if !c.isLeaf {
		for _, comp := range c.subComposites {
			comp.Operation()
		}
	}
}
