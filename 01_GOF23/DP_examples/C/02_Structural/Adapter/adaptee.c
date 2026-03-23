#include "adaptee.h"

// AudioPlayer 实现
static void audio_player_play_media(IAdvancedMediaPlayer* self, const char* fileName, MediaType type) {
    switch (type) {
        case AIFF:
            printf("PlayAudio AIFF : %s\n", fileName);
            break;
        case MIDI:
            printf("PlayAudio MIDI : %s\n", fileName);
            break;
        case Wave:
            printf("PlayAudio wave : %s\n", fileName);
            break;
        default:
            break;
    }
}

void audio_player_init(AudioPlayer* self) {
    self->base.playMedia = audio_player_play_media;
}

// VideoPlayer 实现
static void video_player_play_media(IAdvancedMediaPlayer* self, const char* fileName, MediaType type) {
    switch (type) {
        case MP4:
            printf("PlayVideo mp4 : %s\n", fileName);
            break;
        case MOV:
            printf("PlayVideo mov : %s\n", fileName);
            break;
        case AVI:
            printf("PlayVideo avi : %s\n", fileName);
            break;
        case M4V:
            printf("PlayVideo m4v : %s\n", fileName);
            break;
        default:
            break;
    }
}

void video_player_init(VideoPlayer* self) {
    self->base.playMedia = video_player_play_media;
}
