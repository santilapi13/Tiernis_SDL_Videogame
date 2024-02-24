#include <stdio.h>
#include "src/scripts/utils.c"

int main(int argc, char *argv[]) {
    SDL_Window *window;
    SDL_Renderer *renderer;
    int done = 0;

    initializeSDL(&window, &renderer);

    GameState game;
    playerInit(&(game.player));

    while (!done) {
        processEvents(window, &done, &game);
        doRender(renderer, &game);
        SDL_Delay(30);
    }

    finishSDL(&window, &renderer);

    return 0;
}