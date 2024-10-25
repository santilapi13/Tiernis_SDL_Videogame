#include "../headers/projectile.h"

void renderProjectiles(SDL_Renderer *renderer, ProjectileList projectiles[]) {
    int i;
    ProjectileNode *aux;
    // CAMBIAR CUANDO SE CARGUEN MAS TEXTURAS
    for (i = 0 ; i < 1 ; i++) {
        aux = projectiles[i].listHead;
        while (aux != NULL) {
            SDL_RenderCopyEx(renderer, projectiles[i].texture, NULL, &(aux->rect), 0, NULL, (aux->direction == -1) ? SDL_FLIP_HORIZONTAL : SDL_FLIP_NONE);
            aux = aux->next;
        }
    }
}

void projectilesInit(ProjectileList L[], SDL_Renderer *renderer) {
    int i;
    for (i = 0 ; i < PROJECTILE_TYPES_AMOUNT ; i++) {
        L[i].listHead = NULL;
        L[i].height = 50;
        L[i].width = 50;
    }

    SDL_Surface *surface = IMG_Load("assets/player/player_bullet.png");
    if (surface == NULL) {
        printf("Error loading projectile surface\n\n");
        exit(1);
    }

    L[PLAYER_BULLETS_INDEX].texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
}

void createProjectile(Vector2 position, Vector2F speed, int direction, ProjectileList *L) {
    ProjectileNode *newNode = (ProjectileNode*) malloc(sizeof(ProjectileNode));
    newNode->position = position;
    newNode->speed = speed;
    newNode->direction = direction;
    newNode->next = L->listHead; 
    newNode->rect = (SDL_Rect) {(int) position.x - L->width/2, (int) position.y - L->height/2, L->width, L->height};

    L->listHead = newNode;
}

void projectilesMove(ProjectileList L[]) {
    int i;
    ProjectileNode *aux;

    for (i = 0 ; i < PROJECTILE_TYPES_AMOUNT ; i++) {
        aux = L[i].listHead;
        while (aux != NULL) {
            aux->position.x += aux->speed.x;
            aux->position.y += aux->speed.y;
            aux->rect.x = aux->position.x - L[i].width/2;
            aux->rect.y = aux->position.y - L[i].height/2;

            aux = aux->next;
        }
    }
}