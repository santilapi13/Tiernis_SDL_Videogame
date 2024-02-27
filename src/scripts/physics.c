#include "../headers/physics.h"

void groundCollision(int floorTop, int objectHeight, int *grounded, int *objectYPos, int *objectRectY) {
    int objectBottom = *objectRectY + objectHeight;

    // Fix its position
    if (objectBottom <= floorTop) {
        *grounded = 1;
        *objectYPos = floorTop - objectHeight/2;
        *objectRectY = *objectYPos - objectHeight/2;
        return;
    }

    *grounded = 0;
}