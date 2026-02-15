#pragma once
#include <iostream>
#include <string>

// 媒体类型枚举
enum class MediaType {
    MP3,
    AIFF,
    MIDI,
    Wave,
    MP4,
    MOV,
    AVI,
    M4V
};

// 被适配的接口
class IAdvancedMediaPlayer {
public:
    virtual ~IAdvancedMediaPlayer() = default;
    virtual void playMedia(const std::string& fileName, MediaType type) = 0;
};

// 音频播放器（被适配的类）
class AudioPlayer : public IAdvancedMediaPlayer {
public:
    void playMedia(const std::string& fileName, MediaType type) override {
        switch (type) {
            case MediaType::AIFF:
                std::cout << "PlayAudio AIFF : " << fileName << std::endl;
                break;
            case MediaType::MIDI:
                std::cout << "PlayAudio MIDI : " << fileName << std::endl;
                break;
            case MediaType::Wave:
                std::cout << "PlayAudio wave : " << fileName << std::endl;
                break;
            default:
                break;
        }
    }
};

// 视频播放器（被适配的类）
class VideoPlayer : public IAdvancedMediaPlayer {
public:
    void playMedia(const std::string& fileName, MediaType type) override {
        switch (type) {
            case MediaType::MP4:
                std::cout << "PlayVideo mp4 : " << fileName << std::endl;
                break;
            case MediaType::MOV:
                std::cout << "PlayVideo mov : " << fileName << std::endl;
                break;
            case MediaType::AVI:
                std::cout << "PlayVideo avi : " << fileName << std::endl;
                break;
            case MediaType::M4V:
                std::cout << "PlayVideo m4v : " << fileName << std::endl;
                break;
            default:
                break;
        }
    }
};
