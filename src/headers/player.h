#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string.h>
#include "../scripts/utils.c"
#define PLAYER_WIDTH 120
#define PLAYER_HEIGHT 132
#define TRANSFORMATIONS_QUANTITY 1
#define ACTIONS_QUANTITY 2
#define MAX_FRAMES 13

typedef struct {
    int x, y, speed;
    float velocityY, velocityX;
    unsigned int actionIndex;
    unsigned int frameIndex;
    SDL_Texture *textures[ACTIONS_QUANTITY][MAX_FRAMES];  // rows: 0=idle, 1=attack
    SDL_Rect rect; 
    int grounded;
} Player;

void playerInit(Player *player, SDL_Renderer *renderer, int floorHeight) ;
void move(const Uint8 *state, Player *player);
void jump(Player *player);
void destroyPlayerTextures(SDL_Texture *textures[ACTIONS_QUANTITY][MAX_FRAMES]);