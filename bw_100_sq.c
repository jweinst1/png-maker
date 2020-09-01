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

int  main(int argc, char const* argv[])
{
    draw_ly(10, COLOR_WHITE);
    draw_lx(10, COLOR_WHITE);
    draw_ly(50, 127);
    draw_lx(30, 127);
    fprintf(stdout, "Writing png to %s\n", CANVAS_FILE);
    return write_png_gray(CANVAS_FILE, 100, 100, 8, CANVAS, "bw100");
}

#undef CANVAS_SIZE

