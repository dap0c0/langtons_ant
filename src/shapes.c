#include <assert.h>
#include <stdlib.h>

#include "shapes.h"
#include "colour.h"

typedef struct LINE {
    float x1, x2, y1, y2;
    colour *col;
} line;

typedef struct RECTANGLE {
    float x, y, width, height;
    colour *col;
} rectangle;

typedef struct GRID {
    line *verticals;
    line *horizontals;
} grid;

grid *create_grid(int w, int h, int cols, int rows, colour *col) {
    assert(cols > 0);
    assert(rows > 0);

    grid *toret;
    if ((toret = (grid *)malloc(sizeof(grid))) != NULL) {
        if ((toret->verticals = (line *)malloc(sizeof(line) * cols)) != NULL
            && (toret->horizontals = (line *)malloc(sizeof(line) * rows)) != NULL) {
            for (int i = 0; i < cols; i++) {
                toret->verticals[i].x1 = (int)(w/(float)cols);
                toret->verticals[i].x2 = (int)(w/(float)cols);
                toret->verticals[i].y1 = 0;
                toret->verticals[i].y2 = h;
                toret->verticals[i].col = col;
            }
            for (int i = 0; i < rows; i++) {
                toret->horizontals[i].x1 = 0;
                toret->horizontals[i].x2 = w;
                toret->horizontals[i].y1 = (int)(h/(float)rows);
                toret->horizontals[i].y2 = (int)(h/(float)rows);
                toret->horizontals[i].col = col;
            }
        } else {
            destroy_grid(toret);
        }
    }
    return toret;
}
void destroy_grid(grid *g) {
    if (g != NULL) {
        free(g->verticals);
        free(g->horizontals);
    }
    free(g);
}
