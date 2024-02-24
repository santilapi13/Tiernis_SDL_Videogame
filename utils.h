#include <SDL2/SDL.h>

void processEvents(SDL_Window *window, int *done);
void doRender(SDL_Renderer *renderer);
void initializeSDL(SDL_Window **window, SDL_Renderer **renderer);
void finishSDL(SDL_Window **window, SDL_Renderer **renderer);