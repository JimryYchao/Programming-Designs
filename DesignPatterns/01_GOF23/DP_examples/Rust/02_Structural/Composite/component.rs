// 叶子接口
pub trait ILeaf {
    fn is_leaf(&self) -> bool;
    fn operation(&self);
}

// 组件接口
pub trait IComponent: ILeaf {
    fn add(&mut self, component: Box<dyn IComponent>) -> i32;
    fn remove(&mut self, component: &Box<dyn IComponent>) -> bool;
    fn get_child(&self, index: usize) -> Option<&Box<dyn IComponent>>;
}

// 组合类
pub struct Composite {
    is_leaf: bool,
    pub sub_composites: Vec<Box<dyn IComponent>>,
}

impl Composite {
    pub fn new(is_leaf: bool) -> Self {
        Self {
            is_leaf,
            sub_composites: Vec::new(),
        }
    }
}

impl ILeaf for Composite {
    fn is_leaf(&self) -> bool {
        self.is_leaf
    }

    fn operation(&self) {
        if !self.is_leaf {
            for comp in &self.sub_composites {
                comp.operation();
            }
        }
    }
}

impl IComponent for Composite {
    fn add(&mut self, component: Box<dyn IComponent>) -> i32 {
        if self.is_leaf {
            return -1;
        }

        // 检查是否已存在
        for comp in &self.sub_composites {
            // 这里简化处理，实际应该实现 PartialEq trait
        }

        self.sub_composites.push(component);
        self.sub_composites.len() as i32
    }

    fn remove(&mut self, component: &Box<dyn IComponent>) -> bool {
        if self.is_leaf {
            return false;
        }

        if let Some(index) = self.sub_composites.iter().position(|comp| {
            false
        }) {
            self.sub_composites.remove(index);
            return true;
        }
        false
    }

    fn get_child(&self, index: usize) -> Option<&Box<dyn IComponent>> {
        if index >= self.sub_composites.len() {
            None
        } else {
            Some(&self.sub_composites[index])
        }
    }
}
