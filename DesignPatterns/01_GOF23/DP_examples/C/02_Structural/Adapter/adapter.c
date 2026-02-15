#include "adapter.h"

// 适配器的 play 方法实现
static void player_adapter_play(IPlayer* self, const char* fileName, MediaType type) {
    // 转换为 PlayerAdapter 指针
    PlayerAdapter* adapter = (PlayerAdapter*)self;
    // 调用原始播放器
    adapter->player.base.play(&adapter->player.base, fileName, type);
    // 调用音频播放器
    adapter->audioPlayer.base.playMedia(&adapter->audioPlayer.base, fileName, type);
    // 调用视频播放器
    adapter->videoPlayer.base.playMedia(&adapter->videoPlayer.base, fileName, type);
}

static void PlayerAdapter_play(PlayerAdapter* self, const char* fileName, MediaType type) {
    self->player.base.play(&self->player.base, fileName, type);
    // 调用视频播放器
    self->videoPlayer.base.playMedia(&self->videoPlayer.base, fileName, type);
    // 调用音频播放器
    self->audioPlayer.base.playMedia(&self->audioPlayer.base, fileName, type);
}


void player_adapter_init(PlayerAdapter* self) {
    // 初始化各个播放器
    player_init(&self->player);
    audio_player_init(&self->audioPlayer);
    video_player_init(&self->videoPlayer);
    // 初始化适配方法
    self->play = PlayerAdapter_play;
}
