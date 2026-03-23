use crate::adaptee::MediaType;

// 目标接口
pub trait IPlayer {
    fn play(&self, file_name: &str, typ: MediaType);
}

// 具体目标类
pub struct Player;

impl IPlayer for Player {
    fn play(&self, file_name: &str, typ: MediaType) {
        if typ == MediaType::MP3 {
            println!("PlayAudio mp3 : {}", file_name);
        }
    }
}