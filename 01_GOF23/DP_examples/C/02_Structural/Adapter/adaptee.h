#pragma once

#include <stdio.h>

// 媒体类型枚举
typedef enum {
    MP3,
    AIFF,
    MIDI,
    Wave,
    MP4,
    MOV,
    AVI,
    M4V
} MediaType;

typedef struct IAdvancedMediaPlayer {
    void (*playMedia)(struct IAdvancedMediaPlayer* self, const char* fileName, MediaType type);
} IAdvancedMediaPlayer;

// 音频播放器（被适配的类）
typedef struct {
    IAdvancedMediaPlayer base;
} AudioPlayer;

void audio_player_init(AudioPlayer* self);

// 视频播放器（被适配的类）
typedef struct {
    IAdvancedMediaPlayer base;
} VideoPlayer;

void video_player_init(VideoPlayer* self);
