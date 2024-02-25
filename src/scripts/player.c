#include "../headers/player.h"

void playerInit(Player *player, SDL_Renderer *renderer, int floorHeight) {
    player->speed = 5;
    player->rect = (SDL_Rect) {player->x - PLAYER_WIDTH/2, player->y - PLAYER_HEIGHT/2, PLAYER_WIDTH, PLAYER_HEIGHT};
    player->x = player->rect.w;
    player->y = floorHeight - player->rect.h/2;
    player->grounded = 1;

    SDL_Surface *surface = IMG_Load("assets/player/player_t0/player_idle_t0/player_idle_t0_01.png");
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

    if (!player->grounded && (state[SDL_SCANCODE_UP] || state[SDL_SCANCODE_W]))
        jump(player);

    player->rect.x = player->x - PLAYER_WIDTH/2;
    player->rect.y = player->y - PLAYER_HEIGHT/2;
}

void jump(Player *player) {
    // TODO: Implementar logica del salto
    player->y -= 10;
    player->grounded = 0;
}