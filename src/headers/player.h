#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#define PLAYER_WIDTH 120
#define PLAYER_HEIGHT 132

typedef struct {
    int x, y, speed;
    SDL_Texture *texture;
    SDL_Rect rect; 
    int grounded;
} Player;

void playerInit(Player *player, SDL_Renderer *renderer, int floorHeight) ;
void move(const Uint8 *state, Player *player);
void jump(Player *player);