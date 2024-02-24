#include <SDL2/SDL.h>

void processEvents(SDL_Window *window, int *done, SDL_Rect *rect);
void doRender(SDL_Renderer *renderer, SDL_Rect *rect);
void initializeSDL(SDL_Window **window, SDL_Renderer **renderer);
void finishSDL(SDL_Window **window, SDL_Renderer **renderer);
void move(int direction, SDL_Rect *rect);