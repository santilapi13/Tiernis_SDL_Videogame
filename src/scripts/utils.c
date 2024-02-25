#include "../headers/utils.h"

void initializeSDL(SDL_Window **window, SDL_Renderer **renderer) {
    SDL_Init(SDL_INIT_VIDEO);
    *window = SDL_CreateWindow("Jueguito :)",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        SCREEN_WIDTH, 
        SCREEN_HEIGHT,
        SDL_WINDOW_FULLSCREEN_DESKTOP
    );

    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}

void loadGame(GameState *game, SDL_Renderer *renderer) {
    game->floor = (SDL_Rect) {0, SCREEN_HEIGHT - SCREEN_HEIGHT/15, SCREEN_WIDTH, SCREEN_HEIGHT/15};
    backgroundLoad(&game->background, renderer);
    playerInit(&game->player, renderer, game->floor.y);
}

void backgroundLoad(Background *background, SDL_Renderer *renderer) {
    SDL_Surface *surface = IMG_Load("assets/background/background_01.png");
    if (surface == NULL) {
        printf("Error loading background surface\n\n");
        exit(1);
    }

    background->texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    background->rect = (SDL_Rect) {0, 0, 7681, SCREEN_HEIGHT};
}

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

void collisionDetect(GameState *game) { // TODO: Implement collision detection
}

void doRender(SDL_Renderer *renderer, GameState *game) {
    SDL_RenderCopy(renderer, game->background.texture, NULL, &game->background.rect);

    SDL_RenderCopy(renderer, game->player.texture, NULL, &game->player.rect);
    //SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    //SDL_RenderFillRect(renderer, &game->floor);

    SDL_RenderPresent(renderer);
}

void finishSDL(SDL_Window **window, SDL_Renderer **renderer, GameState *game) {
    SDL_DestroyTexture(game->player.texture);
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_Quit();
}