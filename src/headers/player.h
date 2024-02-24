#include <SDL2/SDL.h>

typedef struct {
    int x, y, speed;
} Player;

void playerInit(Player *player);
void move(const Uint8 *state, Player *player);