use crate::component::{IComponent, ILeaf,Composite};

// 员工类
pub struct Employee {
    composite: Composite,
    name: String,
    sex: String,
    age: i32,
    salary: i32,
}

impl Employee {
    pub fn new(is_base_employee: bool) -> Self {
        Self {
            composite: Composite::new(is_base_employee),
            name: String::new(),
            sex: String::new(),
            age: 0,
            salary: 0,
        }
    }
    
    pub fn init(mut self, name: &str, sex: &str, age: i32, salary: i32) -> Self {
        self.name = name.to_string();
        self.sex = sex.to_string();
        self.age = age;
        self.salary = salary;
        self
    }
}

impl ILeaf for Employee {
    fn is_leaf(&self) -> bool {
        self.composite.is_leaf()
    }
    
    fn operation(&self) {
        print!("[Name:{name}][Age:{age}][Sex:{sex}]:Doing some work, and ", 
            name = self.name, 
            age = self.age, 
            sex = self.sex
        );
        if self.sex == "man" {
            print!("his salary is {}.", self.salary);
        } else {
            print!("her salary is {}.", self.salary);
        }
        if !self.composite.is_leaf() {
            print!(" who has {} Employees work under.", self.composite.sub_composites.len());
        }
        println!();
        self.composite.operation();
    }
}

impl IComponent for Employee {
    fn add(&mut self, component: Box<dyn IComponent>) -> i32 {
        self.composite.add(component)
    }
    
    fn remove(&mut self, component: &Box<dyn IComponent>) -> bool {
        self.composite.remove(component)
    }
    
    fn get_child(&self, index: usize) -> Option<&Box<dyn IComponent>> {
        self.composite.get_child(index)
    }
}
