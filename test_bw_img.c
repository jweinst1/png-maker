#include "write_pngs.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * An 8 x 8 pixel array
 */
static const unsigned char
BW_PIXELS[] = {
   0, 0, 0, 0, 255, 255, 255, 255,
   0, 0, 0, 0, 255, 255, 255, 255,
   0, 0, 0, 0, 255, 255, 255, 255,
   0, 0, 0, 0, 255, 255, 255, 255,
   0, 0, 0, 0, 255, 255, 255, 255,
   0, 0, 0, 0, 255, 255, 255, 255,
   0, 0, 0, 0, 255, 255, 255, 255,
   0, 0, 0, 0, 255, 255, 255, 255
};

static const size_t BW_SIZE = sizeof(BW_PIXELS);
static const char* BW_NAME = "bwtest.png";
static const unsigned BW_DEPTH = 8;

int main(void)
{
     return write_png_gray(BW_NAME, 8, 8, BW_DEPTH, BW_PIXELS, "bw");
}
