#include "../headers/player.h"

void playerInit(Player *player, SDL_Renderer *renderer, int x, int y) {
    player->x = x;
    player->y = y;
    player->speed = 5;
    player->rect = (SDL_Rect) {player->x - PLAYER_WIDTH/2, player->y - PLAYER_HEIGHT/2, PLAYER_WIDTH, PLAYER_HEIGHT};

    SDL_Surface *surface = IMG_Load("assets/player.png");
    if (surface == NULL) {
        printf("Error loading player surface\n\n");
        exit(1);
    }

    player->texture = SDL_CreateTextureFromSurface(renderer, surface); 
    SDL_FreeSurface(surface);
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

    player->rect.x = player->x - PLAYER_WIDTH/2;
    player->rect.y = player->y - PLAYER_HEIGHT/2;
}