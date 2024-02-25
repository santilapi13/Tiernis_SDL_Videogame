#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#define PLAYER_WIDTH 64
#define PLAYER_HEIGHT 100

typedef struct {
    int x, y, speed;
    SDL_Texture *texture;
    SDL_Rect rect;
} Player;

void playerInit(Player *player, SDL_Renderer *renderer, int x, int y) ;
void move(const Uint8 *state, Player *player);