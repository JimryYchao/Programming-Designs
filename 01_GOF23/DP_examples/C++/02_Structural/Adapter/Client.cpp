#include "Adapter.hpp"

int main() {
    // 创建适配器实例
    PlayerAdapter player;
    
    // 播放背景音乐
    player.play("BGMusic.wave", MediaType::Wave);

    // 播放 CG 视频
    player.play("CG.mp4", MediaType::MP4);
}


