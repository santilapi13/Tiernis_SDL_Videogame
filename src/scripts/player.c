#include "../headers/player.h"

void playerInit(Player *player, SDL_Renderer *renderer, int floorHeight) {
    player->speed = 5;
    player->x = PLAYER_WIDTH;
    //player->y = floorHeight - PLAYER_HEIGHT/2;
    player->y = PLAYER_HEIGHT/2;
    player->rect = (SDL_Rect) {player->x - PLAYER_WIDTH/2, player->y - PLAYER_HEIGHT/2, PLAYER_WIDTH, PLAYER_HEIGHT};
    player->grounded = 0;
    player->velocityY = 0;
    player->actionIndex = 0;
    player->frameIndex = 0;

    for (int transformation = 0; transformation < TRANSFORMATIONS_QUANTITY; transformation++) {
        for (int action = 0; action < ACTIONS_QUANTITY; action++) {
            char actionName[10];
            char directoryPath[100];
            char filePath[100];
            char path[100];
            switch (action) {
                case 0:
                    strcpy(actionName, "idle");
                    break;
                case 1:
                    strcpy(actionName, "attack");
                    break;
            }

            sprintf(directoryPath, "assets/player/player_t%d/player_%s_t%d", transformation, actionName, transformation);
            int framesQuantity = filesInDirectory(directoryPath);

            for (int frame = 0; frame < framesQuantity; frame++) {
                sprintf(filePath, "/player_%s_t%d_%02d.png", actionName, transformation, frame+1);
                strcpy(path, directoryPath);
                strcat(path, filePath);
                printf("Loading image from file %s\n", path);
                SDL_Surface *surface = IMG_Load(path);
                if (surface == NULL) {
                    printf("Error loading player surface\n\n");
                    exit(1);
                }
                player->textures[action][frame] = SDL_CreateTextureFromSurface(renderer, surface);
                SDL_FreeSurface(surface);
                printf("Texture created successfully\n\n");
            }
        }
    }
}

void move(const Uint8 *state, Player *player) {
    if (state[SDL_SCANCODE_LEFT] || state[SDL_SCANCODE_A])
        player->x -= player->speed;
    
    if (state[SDL_SCANCODE_RIGHT] || state[SDL_SCANCODE_D])
        player->x += player->speed;

    if (player->grounded && (state[SDL_SCANCODE_UP] || state[SDL_SCANCODE_W]))
        jump(player);

    player->rect.x = player->x - PLAYER_WIDTH/2;
    player->rect.y = player->y - PLAYER_HEIGHT/2;
}

void jump(Player *player) {
    player->velocityY = -12;
    player->y -= 5;
    player->grounded = 0;
}

void destroyPlayerTextures(SDL_Texture *textures[ACTIONS_QUANTITY][MAX_FRAMES]) {
    for (int action = 0; action < ACTIONS_QUANTITY; action++) {
        for (int frame = 0; frame < MAX_FRAMES; frame++) {
            SDL_DestroyTexture(textures[action][frame]);
        }
    }
}