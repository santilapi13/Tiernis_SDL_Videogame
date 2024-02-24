#include "utils.h"
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

void processEvents(SDL_Window *window, int *done, SDL_Rect *rect) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
            case SDL_QUIT:
                *done = 1;
            break;
            case SDL_KEYDOWN: {
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        *done = 1;
                    break;
                    case SDLK_UP:
                        move(UP, rect);
                    break;
                }
            }
            break;
        
        }
    }
}

void doRender(SDL_Renderer *renderer, SDL_Rect *rect) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, rect);

    SDL_RenderPresent(renderer);
}

void initializeSDL(SDL_Window **window, SDL_Renderer **renderer) {
    SDL_Init(SDL_INIT_VIDEO);
    *window = SDL_CreateWindow("Jueguito :)",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        640, 
        480,
        0
    );

    *renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED);
}

void finishSDL(SDL_Window **window, SDL_Renderer **renderer) {
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_Quit();
}

void move(int direction, SDL_Rect *rect) {
    switch (direction) {
        case UP:
            
        break;
        case DOWN:
            printf("Moving down\n");
        break;
        case LEFT:
            printf("Moving left\n");
        break;
        case RIGHT:
            printf("Moving right\n");
        break;
    }
}