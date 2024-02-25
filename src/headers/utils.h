#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "../scripts/player.c"
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

typedef struct {
    Player player;
} GameState;

void processEvents(SDL_Window *window, int *done, GameState *game);
void doRender(SDL_Renderer *renderer, GameState *game);
void initializeSDL(SDL_Window **window, SDL_Renderer **renderer);
void loadGame(GameState *game, SDL_Renderer *renderer);
void finishSDL(SDL_Window **window, SDL_Renderer **renderer, GameState *game);