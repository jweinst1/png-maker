#include "write_pngs.h"
#include <stdio.h>
#include <stdlib.h>


#define CANVAS_X 100
#define CANVAS_Y 100
#define CANVAS_SIZE (CANVAS_X * CANVAS_Y)
#define COLOR_BLACK 0
#define COLOR_WHITE 255
#define CANVAS_FILE "bw_100.png"

static unsigned char CANVAS[CANVAS_SIZE] = {COLOR_BLACK};

#define CANVAS_AT(x, y) (CANVAS[(CANVAS_Y * y) + x])

static void draw_ly(size_t y, unsigned char gc)
{
   size_t i = y * CANVAS_Y;
   size_t end = i + CANVAS_X;
   while (i < end) {
      CANVAS[i++] = gc;
   }
}

static void draw_lx(size_t x, unsigned char gc)
{
   size_t i = x;
   size_t end = CANVAS_Y * CANVAS_X + x;
   while (i < end) {
      CANVAS[i] = gc;
      i += CANVAS_X;
   }
}

static void draw_rg(size_t x1, size_t x2, size_t y1, size_t y2, unsigned char gc)
{
    size_t x;
    size_t y;
    for (x = x1; x < x2 ; x++) {
        for (y = y1; y < y2 ; y++) {
            CANVAS_AT(x, y) = gc;
        }
    } 
}

int  main(int argc, char const* argv[])
{
    draw_ly(10, COLOR_WHITE);
    draw_lx(10, COLOR_WHITE);
    draw_ly(50, 127);
    draw_lx(30, 127);
    draw_rg(10, 30, 10, 30, COLOR_WHITE);
    fprintf(stdout, "Writing png to %s\n", CANVAS_FILE);
    return write_png_gray(CANVAS_FILE, 100, 100, 8, CANVAS, "bw100");
}

#undef CANVAS_SIZE
#undef CANVAS_AT

