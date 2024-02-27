#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../scripts/player.c"
#include "../scripts/physics.c"
#define SCREEN_WIDTH 1920
#define SCREEN_HEIGHT 1080

typedef struct {
    SDL_Texture *texture;
    SDL_Rect rect;
} Background;

typedef struct {
    Player player;
    SDL_Rect floor;
    Background background;
} GameState;

void initializeSDL(SDL_Window **window, SDL_Renderer **renderer);
void loadGame(GameState *game, SDL_Renderer *renderer);
void backgroundLoad(Background *background, SDL_Renderer *renderer);
void processEvents(SDL_Window *window, int *done, GameState *game);
void collisionDetect(GameState *game);
void doRender(SDL_Renderer *renderer, GameState *game);
void finishSDL(SDL_Window **window, SDL_Renderer **renderer, GameState *game);