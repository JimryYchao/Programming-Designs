mod context;
mod concrete_state;

use std::io::{self, Read, Write};
use std::net::{TcpListener, TcpStream};
use std::thread;
use context::TCPConnection;

fn main() {
    // 创建服务器端
    let listener = TcpListener::bind("127.0.0.1:7777").expect("Failed to start server");
    println!("Server is Builded");

    // 创建客户端TCPConnection
    let mut client = TCPConnection::new();

    // 启动服务器接受连接的线程
    thread::spawn(move || {
        for stream in listener.incoming() {
            match stream {
                Ok(stream) => {
                    println!("Server accepted connection");
                    handle_server_connection(stream);
                }
                Err(e) => {
                    println!("Accept error: {}", e);
                }
            }
        }
    });

    // 主循环
    loop {
        // 1. 建立连接
        if !client.is_connected() {
            client.connect();
            println!("Input Buffer: ");
            let mut message = String::new();
            io::stdin().read_line(&mut message).expect("Failed to read line");
            let message = message.trim();
            if message.is_empty() {
                continue;
            }

            // 2. 客户端发送消息
            client.send_message(message.as_bytes());

            // 3. 等待服务器处理
            thread::sleep(std::time::Duration::from_millis(100));

            // 4. 客户端接收状态
            if let Some(buffer) = client.receive() {
                // 5. 客户端打印状态
                if !buffer.is_empty() {
                    println!("Client received: {}", String::from_utf8_lossy(&buffer));
                    client.close();
                    println!("Test Finished, and input anyKey to exit");
                    let mut _input = String::new();
                    io::stdin().read_line(&mut _input).expect("Failed to read line");
                    return;
                }
            }
        }
    }
}

// 处理服务器端连接
fn handle_server_connection(mut stream: TcpStream) {
    // 接收客户端消息
    let mut buffer = [0; 1024];
    match stream.read(&mut buffer) {
        Ok(len) if len > 0 => {
            println!("Server received: {}", String::from_utf8_lossy(&buffer[..len]));

            // 发送响应
            let response = "Successful";
            stream.write(response.as_bytes()).expect("Failed to send response");
            println!("Server sent response: {}", response);
        }
        Err(e) => {
            println!("Server read error: {}", e);
        }
        _ => {}
    }
}
