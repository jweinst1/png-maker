#include "write_pngs.h"
#include <stdio.h>
#include <stdlib.h>


#define CANVAS_X 100
#define CANVAS_Y 100
#define CANVAS_SIZE (CANVAS_X * CANVAS_Y)
#define COLOR_BLACK 0
#define COLOR_WHITE 255
#define CANVAS_FILE "bw_100.png"

static unsigned char CANVAS[CANVAS_SIZE] = {COLOR_WHITE};

static void draw_ly(size_t y, unsigned char gc)
{
   size_t i = y * CANVAS_Y;
   size_t end = i + CANVAS_X;
   while (i < end) {
      CANVAS[i++] = gc;
   }
}

int  main(int argc, char const* argv[])
{
    draw_ly(8, 0);
    draw_ly(16, 100);
    draw_ly(30, 0);
    draw_ly(60, 50);
    fprintf(stdout, "Writing png to %s\n", CANVAS_FILE);
    return write_png_gray(CANVAS_FILE, 100, 100, 8, CANVAS, "bw100");
}

#undef CANVAS_SIZE

