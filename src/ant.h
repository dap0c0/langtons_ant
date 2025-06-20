#pragma once
#include <stdint.h>
#include <stdbool.h>

typedef enum DIRECTION {
    UP,
    RIGHT,
    DOWN,
    LEFT,
    NUM_DIRECTIONS
} direction;

typedef struct COORDINATES {
    int x, y;
} coordinates;

typedef struct ANT ant;
ant *create_ant(int x, int y, uint8_t direction);
void destroy_ant(ant *n);
coordinates turn(ant *n, bool left);

