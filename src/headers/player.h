#include <SDL2/SDL.h>

typedef struct {
    int x, y, speed;
    SDL_Texture *texture;
} Player;

void playerInit(Player *player, SDL_Renderer *renderer);
void move(const Uint8 *state, Player *player);