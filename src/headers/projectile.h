#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#define PLAYER_BULLET_FRAMES
#define PROJECTILE_TYPES_AMOUNT 2

#define PLAYER_BULLETS_INDEX 0
#define PLAYER_BULLET_SPEED 10

// Sacar de acá:
typedef struct {
    float x, y;
} Vector2F;

typedef struct {
    int x, y;
} Vector2;

typedef struct ProjectileNode {
    Vector2 position;
    Vector2F speed;
    int direction;
    SDL_Rect rect;
    ProjectileNode *next;
} ProjectileNode;

typedef struct {
    int width, height;
    SDL_Texture *texture;
    ProjectileNode *listHead;
} ProjectileList;

void renderProjectiles(SDL_Renderer *renderer, ProjectileList projectiles[]);
void projectilesInit(ProjectileList L[], SDL_Renderer *renderer);
void createProjectile(Vector2 position, Vector2F speed, int direction, ProjectileList *L);
void projectilesMove(ProjectileList L[]);