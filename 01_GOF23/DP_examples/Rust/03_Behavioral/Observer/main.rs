mod observer;
mod account_data;
mod change_manager;
mod subject;

use std::io;
use crate::subject::{ConcreteSubject, Subject};


fn main() {
    let subject = ConcreteSubject::get_instance();
    
    loop {
        println!("Whether or not registered? Input Y/N");
        let mut yn = String::new();
        io::stdin().read_line(&mut yn).expect("Failed to read line");
        let yn = yn.trim();
        
        if yn == "Y" {
            let name = loop {
                println!("Please input your Account name");
                let mut name = String::new();
                io::stdin().read_line(&mut name).expect("Failed to read line");
                let name = name.trim();
                if !name.is_empty() {
                    break name.to_string();
                } else {
                    println!("Input name ERROR");
                }
            };
            
            let password = loop {
                println!("Please input your password");
                let mut password = String::new();
                io::stdin().read_line(&mut password).expect("Failed to read line");
                let password = password.trim();
                if !password.is_empty() {
                    break password.to_string();
                } else {
                    println!("Input password ERROR");
                }
            };
            
            subject.lock().unwrap().register_account(&name, &password);
            subject.lock().unwrap().notify();
        } else if yn == "N" {
            let name = loop {
                println!("Please input your Account name");
                let mut name = String::new();
                io::stdin().read_line(&mut name).expect("Failed to read line");
                let name = name.trim();
                if !name.is_empty() {
                    break name.to_string();
                } else {
                    println!("Input name ERROR");
                }
            };
            
            let password = loop {
                println!("Please input your password");
                let mut password = String::new();
                io::stdin().read_line(&mut password).expect("Failed to read line");
                let password = password.trim();
                if !password.is_empty() {
                    break password.to_string();
                } else {
                    println!("Input password ERROR");
                }
            };
            
            subject.lock().unwrap().login_account(&name, &password);
            subject.lock().unwrap().notify();
            break;
        } else {
            println!("Input ERROR");
        }
    }
}
