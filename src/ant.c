#include <assert.h>
#include <stdint.h>
#include <stdlib.h>
#include "ant.h"

static void VERIFY_DIRECTION(uint8_t direction);

typedef struct ANT {
    coordinates coords;
    uint8_t direction;
} ant;

ant *create_ant(int x, int y, uint8_t direction) {
    VERIFY_DIRECTION(direction);

    ant *toret;
    if ((toret = (ant *)malloc(sizeof(ant))) != NULL) {
        toret->coords.x = x;
        toret->coords.y = y;
        toret->direction = direction;

    } else {
        destroy_ant(toret);
    }
    return toret;
}

void destroy_ant(ant *n) {
    free(n);
}

coordinates turn(ant *n, bool left) {
    VERIFY_DIRECTION(n->direction);
    int8_t update = left ? -1 : 1;
    n->direction = ((int8_t)n->direction + update) % NUM_DIRECTIONS;

    switch (n->direction) {
        case UP:
            n->coords.y--;
            break;

        case RIGHT:
            n->coords.x++;
            break;

        case DOWN:
            n->coords.y++;
            break;

        case LEFT:
            n->coords.x--;
            break;

        case NUM_DIRECTIONS:
            break;
    }
    VERIFY_DIRECTION(n->direction);
    return n->coords;
}

static void VERIFY_DIRECTION(uint8_t direction) {
    assert(direction >= UP);
    assert(direction < NUM_DIRECTIONS);
}
