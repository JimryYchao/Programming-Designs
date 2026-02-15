#pragma once

#include "Target.hpp"

// 适配器类
class PlayerAdapter : public IPlayer {
private:
    Player player;
    AudioPlayer audioPlayer;
    VideoPlayer videoPlayer;
public:
    void play(const std::string& fileName, MediaType type) override {
        // 调用原始播放器
        player.play(fileName, type);
        // 调用音频播放器
        audioPlayer.playMedia(fileName, type);
        // 调用视频播放器
        videoPlayer.playMedia(fileName, type);
    }
};
