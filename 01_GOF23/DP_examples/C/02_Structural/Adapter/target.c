#include "target.h"

// Player 实现
static void player_play(IPlayer* self, const char* fileName, MediaType type) {
    if (type == MP3) {
        printf("PlayAudio mp3 : %s\n", fileName);
    }
}

void player_init(Player* self) {
    self->base.play = player_play;
}