#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <string.h>
#include "../scripts/utils.c"
#define PLAYER_WIDTH 120
#define PLAYER_HEIGHT 132
#define TRANSFORMATIONS_QUANTITY 1
#define IDLE_ACTION 0
#define ATTACK_ACTION 1
#define WALK_ACTION 2
#define JUMP_ACTION 3
#define ACTIONS_QUANTITY 4
#define MAX_FRAMES 13
#define TIME_PER_FRAME 100

typedef struct {
    int x, y, speed;
    float velocityY, velocityX;
    int direction;
    unsigned int actionIndex;
    unsigned int actionsMaxFrames[ACTIONS_QUANTITY];
    unsigned int frameIndex;
    SDL_Texture *textures[ACTIONS_QUANTITY][MAX_FRAMES]; 
    SDL_Rect rect; 
    int grounded;
    float attackCooldown;
    Uint32 lastFrameTime;
} Player;

void playerInit(Player *player, SDL_Renderer *renderer, int floorHeight);
void updatePlayerAnimation(Player *player, int action);
void move(const Uint8 *state, Player *player);
void attack(Player *player);
void jump(Player *player);
void destroyPlayerTextures(SDL_Texture *textures[ACTIONS_QUANTITY][MAX_FRAMES]);