use std::io::{Read, Write};
use std::net::TcpStream;
use std::sync::Arc;
use std::thread::sleep;
use std::time::Duration;

use crate::context::{TCPConnection, TCPState};

// 具体状态：TCP已建立
#[derive(Default)]
pub struct TCPEstablished;

impl TCPEstablished {
    pub fn new() -> Self {
        Self::default()
    }
}

impl TCPState for TCPEstablished {
    fn connect(&self, _connection: &mut TCPConnection) {
        // 空实现
    }

    fn receive(&self, _connection: &mut TCPConnection) -> Option<Vec<u8>> {
        None
    }

    fn close(&self, connection: &mut TCPConnection) {
        if let Some(mut connector) = connection.connector.take() {
            drop(connector); // 自动关闭连接
        }
        self.change_state(connection, Arc::new(TCPUnconnected::new()));
    }

    fn send_message(&self, connection: &mut TCPConnection, buffer: &[u8]) {
        if let Some(connector) = connection.get_connector() {
            if connector.write(buffer).is_err() {
                self.change_state(connection, Arc::new(TCPUnconnected::new()));
                return;
            }
        } else {
            self.change_state(connection, Arc::new(TCPUnconnected::new()));
            return;
        }
        self.change_state(connection, Arc::new(TCPListen::new()));
    }

    fn change_state(&self, connection: &mut TCPConnection, state: Arc<dyn TCPState>) {
        println!("Switch state to >> {:?}", std::any::type_name::<dyn TCPState>());
        connection.change_state(state);
    }
}

// 具体状态：TCP监听
#[derive(Default)]
pub struct TCPListen;

impl TCPListen {
    pub fn new() -> Self {
        Self::default()
    }
}

impl TCPState for TCPListen {
    fn connect(&self, _connection: &mut TCPConnection) {
        // 空实现
    }

    fn receive(&self, connection: &mut TCPConnection) -> Option<Vec<u8>> {
        if let Some(connector) = connection.get_connector() {
            let mut buffer = [0; 1024];
            match connector.read(&mut buffer) {
                Ok(len) if len > 0 => {
                    let result = buffer[..len].to_vec();
                    self.change_state(connection, Arc::new(TCPEstablished::new()));
                    Some(result)
                }
                _ => {
                    connection.clear_connector();
                    self.change_state(connection, Arc::new(TCPUnconnected::new()));
                    None
                }
            }
        } else {
            self.change_state(connection, Arc::new(TCPUnconnected::new()));
            None
        }
    }

    fn close(&self, _connection: &mut TCPConnection) {
        // 空实现
    }

    fn send_message(&self, _connection: &mut TCPConnection, _buffer: &[u8]) {
        // 空实现
    }

    fn change_state(&self, connection: &mut TCPConnection, state: Arc<dyn TCPState>) {
        println!("Switch state to >> {:?}", std::any::type_name::<dyn TCPState>());
        connection.change_state(state);
    }
}

// 具体状态：TCP未连接
#[derive(Default)]
pub struct TCPUnconnected;

impl TCPUnconnected {
    pub fn new() -> Self {
        Self::default()
    }
}

impl TCPState for TCPUnconnected {
    fn connect(&self, connection: &mut TCPConnection) {
        let addr = format!("{}:{}", connection.get_ip_address(), connection.get_port());
        loop {
            match TcpStream::connect(&addr) {
                Ok(connector) => {
                    connection.set_connector(connector);
                    println!("Connect to >>> {}", addr);
                    self.change_state(connection, Arc::new(TCPEstablished::new()));
                    break;
                }
                Err(e) => {
                    println!("Cannot connect to >>> {}: {}", addr, e);
                    sleep(Duration::from_secs(1));
                    continue;
                }
            }
        }
    }

    fn receive(&self, _connection: &mut TCPConnection) -> Option<Vec<u8>> {
        None
    }

    fn close(&self, _connection: &mut TCPConnection) {
        // 空实现
    }

    fn send_message(&self, _connection: &mut TCPConnection, _buffer: &[u8]) {
        // 空实现
    }

    fn change_state(&self, connection: &mut TCPConnection, state: Arc<dyn TCPState>) {
        println!("Switch state to >> {:?}", std::any::type_name::<dyn TCPState>());
        connection.change_state(state);
    }
}