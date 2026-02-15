#pragma once
#include <iostream>
#include <string>
#include "Adaptee.hpp"

// 目标接口
class IPlayer {
public:
    virtual ~IPlayer() = default;
    virtual void play(const std::string& fileName, MediaType type) = 0;
};

// mp3 默认播放类
class Player : public IPlayer {
public:
    void play(const std::string& fileName, MediaType type) override {
        if (type == MediaType::MP3) {
            std::cout << "PlayAudio mp3 : " << fileName << std::endl;
        }
    }
};