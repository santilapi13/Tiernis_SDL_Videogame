#include <stdio.h>
#include "src/scripts/gameManagement.c"

int main(int argc, char *argv[]) {
    SDL_Window *window;
    SDL_Renderer *renderer;
    int done = 0;
    GameState game;
    initializeSDL(&window, &renderer);
    loadGame(&game, renderer);

    while (!done) {
        projectilesMove(game.projectiles);
        processEvents(window, &done, &game);
        gravityAffect(&game);
        collisionDetect(&game);
        refreshCooldowns(&game);
        doRender(renderer, &game);
        SDL_Delay(10);
    }

    finishSDL(&window, &renderer, &game);

    return 0;
}