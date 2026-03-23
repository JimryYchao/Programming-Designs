#pragma once

#include "target.h"

// 适配器类
typedef struct PlayerAdapter {
    // 被适配者
    AudioPlayer audioPlayer;
    VideoPlayer videoPlayer;
    Player player;
    // 适配方法
    void (*play)(struct PlayerAdapter *self, const char *fileName, MediaType type);
} PlayerAdapter;

void player_adapter_init(PlayerAdapter* self);

