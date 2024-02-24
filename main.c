#include <stdio.h>
#include "src/scripts/utils.c"

int main(int argc, char *argv[]) {
    SDL_Window *window;
    SDL_Renderer *renderer;
    int done = 0;
    GameState game;

    initializeSDL(&window, &renderer);
    playerInit(&game.player, renderer);

    while (!done) {
        processEvents(window, &done, &game);
        doRender(renderer, &game);
        SDL_Delay(10);
    }

    finishSDL(&window, &renderer, &game);

    return 0;
}