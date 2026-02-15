#pragma once

#include <stdio.h>
#include "adaptee.h"

typedef struct IPlayer {
    void (*play)(struct IPlayer *self, const char *fileName, MediaType type);
} IPlayer;

typedef struct {
    IPlayer base;
} Player;

void player_init(Player *self);