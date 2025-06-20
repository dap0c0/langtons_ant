#pragma once
#include "colour.h"
typedef struct LINE line;
typedef struct RECTANGLE rectangle;
typedef struct GRID grid;

grid *create_grid(int w, int h, int cols, int rows, colour *col);
void destroy_grid(grid *g);
