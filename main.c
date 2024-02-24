#include <stdio.h>
#include "utils.h"
#include "utils.c"

int main(int argc, char *argv[]) {
    SDL_Window *window;
    SDL_Renderer *renderer;
    int done = 0;

    initializeSDL(&window, &renderer);

    while (!done) {
        processEvents(window, &done);
        doRender(renderer);
        SDL_Delay(100);
    }

    finishSDL(&window, &renderer);

    return 0;
}