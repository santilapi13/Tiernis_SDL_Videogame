#include "../headers/gameManagement.h"

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
    game->deltaTime = 0;
    game->lastFrameTime = SDL_GetTicks();
    game->floor = (SDL_Rect) {0, SCREEN_HEIGHT - SCREEN_HEIGHT/15, SCREEN_WIDTH, SCREEN_HEIGHT/15};
    backgroundLoad(&game->background, renderer);
    playerInit(&game->player, renderer, game->floor.y);
    projectilesInit(game->projectiles, renderer);
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
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        *done = 1;
                        break;
                    case SDLK_SPACE:
                        attack(&game->player, &game->projectiles[PLAYER_BULLETS_INDEX]);
                }
            }
            break;
        
        }
    }

    move(SDL_GetKeyboardState(NULL), &game->player);
}

void collisionDetect(GameState *game) { 
    groundCollision(game->floor.y, game->player.rect.h, &game->player.grounded, &game->player.velocityY, &game->player.y, &game->player.rect.y);
}

void gravityAffect(GameState *game) {
    int i;
    ProjectileNode *aux;
    inflictGravity(game->player.grounded, game->player.rect.h, &game->player.velocityY, &game->player.y, &game->player.rect.y);
    /*
    for (i = 0 ; i < PROJECTILE_TYPES_AMOUNT; i++) {
        aux = game->projectiles[i].listHead;
        while (aux != NULL) {
            inflictGravity(0, game->projectiles[i].height, &aux->speed.y, &aux->position.y, &aux->rect.y);
            aux = aux->next;
        }
    }*/
}

void refreshCooldowns(GameState *game) {
    game->deltaTime = SDL_GetTicks() - game->lastFrameTime;
    game->lastFrameTime = SDL_GetTicks();

    if (game->player.attackCooldown != 0) {
        updatePlayerOneTimeAnimation(&(game->player), ATTACK_ACTION);
    }
}

void doRender(SDL_Renderer *renderer, GameState *game) {
    SDL_RenderCopy(renderer, game->background.texture, NULL, &game->background.rect);

    Player player = game->player;
    SDL_RenderCopyEx(renderer, player.textures[player.actionIndex][player.frameIndex], NULL, &game->player.rect, 0, NULL, (player.direction == -1) ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
    renderProjectiles(renderer, game->projectiles);
    //SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    //SDL_RenderFillRect(renderer, &game->floor);

    SDL_RenderPresent(renderer);
}

void finishSDL(SDL_Window **window, SDL_Renderer **renderer, GameState *game) {
    destroyPlayerTextures(game->player.textures);
    SDL_DestroyRenderer(*renderer);
    SDL_DestroyWindow(*window);
    SDL_Quit();
}