#include <SDL2/SDL.h>
#include "../scripts/player.c"

typedef struct {
    Player player;
} GameState;

void processEvents(SDL_Window *window, int *done, GameState *game);
void doRender(SDL_Renderer *renderer, GameState *game);
void initializeSDL(SDL_Window **window, SDL_Renderer **renderer);
void finishSDL(SDL_Window **window, SDL_Renderer **renderer);