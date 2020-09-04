#include "write_pngs.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#if CHAR_BIT != 8
#  error "CHAR_BIT is not usable on this platform"
#endif

#define PIC_SIZE_DIM 1080
#define PIC_SIZE_BW ((PIC_SIZE_DIM * PIC_SIZE_DIM) / CHAR_BIT) 
static unsigned char PIC_BITS[PIC_SIZE_BW] = {0};

static void __write_bits_pic(void)
{
     size_t i = 1000;
     for(;i < 140000;++i) {
        PIC_BITS[i] = ((i + 76) >> 5) & 0xff;
     }
}


int main(void) {
   __write_bits_pic();
   printf("Writing picture of %d bytes and %d bits\n", PIC_SIZE_BW, PIC_SIZE_BW * CHAR_BIT);
   return !write_png_bwsq("bwpixs.png",
                    PIC_SIZE_DIM,
                    PIC_BITS,
                    "bwpixs");
}
