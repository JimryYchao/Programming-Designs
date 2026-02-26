// Memento 模式

// 备忘录
pub struct Memento {
    states: std::collections::HashMap<String, String>,
    version: i32,
}

impl Memento {
    pub fn new(version: i32) -> Self {
        Self {
            states: std::collections::HashMap::new(),
            version,
        }
    }
    
    pub fn get_state(&self, identifier: &str) -> Option<&String> {
        self.states.get(identifier)
    }
    
    pub fn set_state(&mut self, identifier: &str, state: &str) {
        self.states.insert(identifier.to_string(), state.to_string());
    }
    
    pub fn get_version(&self) -> i32 {
        self.version
    }
}

// 发起人
pub struct Originator {
    state_1: String,
    state_2: String,
    state_3: String,
}

impl Originator {
    pub fn new(s1: &str, s2: &str, s3: &str) -> Self {
        Self {
            state_1: s1.to_string(),
            state_2: s2.to_string(),
            state_3: s3.to_string(),
        }
    }
    
    pub fn console_state(&self) {
        println!("State_1: {}", self.state_1);
        println!("State_2: {}", self.state_2);
        println!("State_3: {}", self.state_3);
    }
    
    pub fn create_memento(&self, version: i32) -> Memento {
        let mut memento = Memento::new(version);
        memento.set_state("state_1", &self.state_1);
        memento.set_state("state_2", &self.state_2);
        memento.set_state("state_3", &self.state_3);
        memento
    }
    
    pub fn set_memento(&mut self, m: &Memento) {
        if let Some(state) = m.get_state("state_1") {
            self.state_1 = state.clone();
        }
        if let Some(state) = m.get_state("state_2") {
            self.state_2 = state.clone();
        }
        if let Some(state) = m.get_state("state_3") {
            self.state_3 = state.clone();
        }
    }
    
    pub fn set_state_1(&mut self, state: &str) {
        self.state_1 = state.to_string();
    }
    
    pub fn set_state_2(&mut self, state: &str) {
        self.state_2 = state.to_string();
    }
    
    pub fn set_state_3(&mut self, state: &str) {
        self.state_3 = state.to_string();
    }
}

// caretaker
pub struct Caretaker {
    mementos: std::collections::HashMap<i32, Memento>,
}

impl Caretaker {
    pub fn new() -> Self {
        Self {
            mementos: std::collections::HashMap::new(),
        }
    }
    
    pub fn save_memento(&mut self, version: i32, m: Memento) {
        self.mementos.insert(version, m);
    }
    
    pub fn get_memento(&self, version: i32) -> Option<&Memento> {
        self.mementos.get(&version)
    }
}
