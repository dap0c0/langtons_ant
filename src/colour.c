#include <stdint.h>
#include "colour.h"

typedef struct COLOUR {
    uint8_t r, g, b, o;
} colour;

colour WHITE = {255, 255, 255, 255};
colour BLACK = {0, 0, 0, 255};

