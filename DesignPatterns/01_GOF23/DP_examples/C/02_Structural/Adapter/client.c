#include "adapter.h"

int main() {
    // 创建并初始化适配器实例
    PlayerAdapter adapter;
    player_adapter_init(&adapter);
    // 播放背景音乐
    adapter.play(&adapter, "BGMusic.wave", Wave);
    // 播放 CG 视频
    adapter.play(&adapter, "CG.mp4", MP4);
}

// gcc -o client client.c adapter.c target.c adaptee.c