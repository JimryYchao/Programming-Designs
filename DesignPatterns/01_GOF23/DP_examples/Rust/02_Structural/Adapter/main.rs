mod adaptee;
mod adapter;
mod target;

use adapter::PlayerAdapter;
use adaptee::MediaType;
use target::IPlayer;

fn main() {
    // 创建适配器实例
    let player = PlayerAdapter::new();

    // 播放背景音乐
    player.play("BGMusic.wave", MediaType::Wave);

    // 播放 CG 视频
    player.play("CG.mp4", MediaType::MP4);
}
