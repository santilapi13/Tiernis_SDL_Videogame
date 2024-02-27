#include "../headers/physics.h"
#define GRAVITY_ACCELERATION 0.34
void groundCollision(int floorTop, int objectHeight, int *grounded, float *velocityY, int *objectYPos, int *objectRectY) {
    int objectBottom = *objectRectY + objectHeight;

    // Fix its position
    if (objectBottom >= floorTop) {
        *velocityY = 0;
        *grounded = 1;
        *objectYPos = floorTop - objectHeight/2;
        *objectRectY = *objectYPos - objectHeight/2;
        return;
    }

    *grounded = 0;
}

void inflictGravity(int grounded, int objectHeight, float *velocityY, int *y, int *rectY) {
    if (!grounded) {
        *y += *velocityY;
        *rectY = *y - objectHeight/2;
        *velocityY += GRAVITY_ACCELERATION;
    }
}