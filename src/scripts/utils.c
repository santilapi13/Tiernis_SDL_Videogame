#include "../headers/utils.h"

void processEvents(SDL_Window *window, int *done, GameState *game) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                *done = 1;
            break;
            case SDL_KEYDOWN: {
                if (event.key.keysym.sym == SDLK_ESCAPE) {
                    *done = 1;
                    break;
                }
            }
            break;
        
        }
    }

    move(SDL_GetKeyboardState(NULL), &game->player);
}

void doRender(SDL_Renderer *renderer, GameState *game) {
    SDL_SetRenderDrawColor(renderer, 100, 100, 100, 255);
    SDL_RenderClear(renderer);

    SDL_RenderCopy(renderer, game->player.texture, NULL, &game->player.rect);  

    SDL_RenderPresent(renderer);
}

void initializeSDL(SDL_Window **window, SDL_Renderer **renderer) {
    SDL_Init(SDL_INIT_VIDEO);
    *window = SDL_CreateWindow("Jueguito :)",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH, 
        SCREEN_HEIGHT,
        0
    );

    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void loadGame(GameState *game, SDL_Renderer *renderer) {
    playerInit(&game->player, renderer, SCREEN_WIDTH/2, SCREEN_HEIGHT/2);
}

void finishSDL(SDL_Window **window, SDL_Renderer **renderer, GameState *game) {
    SDL_DestroyTexture(game->player.texture);
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_Quit();
}