use std::net::TcpStream;
use std::sync::Arc;

use crate::concrete_state::TCPUnconnected;

// 状态接口
pub trait TCPState {
    fn connect(&self, connection: &mut TCPConnection);
    fn receive(&self, connection: &mut TCPConnection) -> Option<Vec<u8>>;
    fn close(&self, connection: &mut TCPConnection);
    fn send_message(&self, connection: &mut TCPConnection, buffer: &[u8]);
    fn change_state(&self, connection: &mut TCPConnection, state: Arc<dyn TCPState>);
}

// 上下文结构体
pub struct  TCPConnection {
    tcp_state: Arc<dyn TCPState>,
    pub connector: Option<TcpStream>,
    ip_address: String,
    port: u16,
}

impl TCPConnection {
    pub fn new() -> Self {
        Self {
            tcp_state: Arc::new(TCPUnconnected::new()),
            connector: None,
            ip_address: "127.0.0.1".to_string(),
            port: 7777,
        }
    }

    pub fn connect(&mut self) {
        let state = Arc::clone(&self.tcp_state);
        state.connect(self);
    }

    pub fn receive(&mut self) -> Option<Vec<u8>> {
        let state = Arc::clone(&self.tcp_state);
        state.receive(self)
    }

    pub fn close(&mut self) {
        let state = Arc::clone(&self.tcp_state);
        state.close(self);
    }

    pub fn send_message(&mut self, buffer: &[u8]) {
        let state = Arc::clone(&self.tcp_state);
        state.send_message(self, buffer);
    }

    pub fn is_connected(&self) -> bool {
        self.connector.is_some()
    }

    pub fn get_connector(&mut self) -> Option<&mut TcpStream> {
        self.connector.as_mut()
    }

    pub fn set_connector(&mut self, connector: TcpStream) {
        self.connector = Some(connector);
    }

    pub fn clear_connector(&mut self) {
        self.connector = None;
    }

    pub fn get_ip_address(&self) -> &str {
        &self.ip_address
    }

    pub fn get_port(&self) -> u16 {
        self.port
    }

    pub fn change_state(&mut self, state: Arc<dyn TCPState>) {
        self.tcp_state = state;
    }
}
