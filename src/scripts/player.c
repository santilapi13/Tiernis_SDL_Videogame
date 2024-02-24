#include "../headers/player.h"

void playerInit(Player *player) {
    player->x = 220;
    player->y = 140;
    player->speed = 10;
}

void move(const Uint8 *state, Player *player) {
    if (state[SDL_SCANCODE_LEFT] || state[SDL_SCANCODE_A])
        player->x -= player->speed;
    
    if (state[SDL_SCANCODE_RIGHT] || state[SDL_SCANCODE_D])
        player->x += player->speed;

    if (state[SDL_SCANCODE_UP] || state[SDL_SCANCODE_W])
        player->y -= player->speed;

    if (state[SDL_SCANCODE_DOWN] || state[SDL_SCANCODE_S])
        player->y += player->speed;
}