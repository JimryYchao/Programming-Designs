// 媒体类型枚举
#[derive(Debug, Clone, Copy, PartialEq)]
pub enum MediaType {
    MP3,
    AIFF,
    MIDI,
    Wave,
    MP4,
    MOV,
    AVI,
    M4V,
}

// 被适配的接口
pub trait IAdvancedMediaPlayer {
    fn play_media(&self, file_name: &str, typ: MediaType);
}

// 音频播放器（被适配的类）
pub struct AudioPlayer;

impl IAdvancedMediaPlayer for AudioPlayer {
    fn play_media(&self, file_name: &str, typ: MediaType) {
        match typ {
            MediaType::AIFF => println!("PlayAudio AIFF : {}", file_name),
            MediaType::MIDI => println!("PlayAudio MIDI : {}", file_name),
            MediaType::Wave => println!("PlayAudio wave : {}", file_name),
            _ => (),
        }
    }
}

// 视频播放器（被适配的类）
pub struct VideoPlayer;

impl IAdvancedMediaPlayer for VideoPlayer {
    fn play_media(&self, file_name: &str, typ: MediaType) {
        match typ {
            MediaType::MP4 => println!("PlayVideo mp4 : {}", file_name),
            MediaType::MOV => println!("PlayVideo mov : {}", file_name),
            MediaType::AVI => println!("PlayVideo avi : {}", file_name),
            MediaType::M4V => println!("PlayVideo m4v : {}", file_name),
            _ => (),
        }
    }
}
