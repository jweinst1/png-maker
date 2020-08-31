#ifndef WRITE_PNGS_H
#define WRITE_PNGS_H

#ifdef __cplusplus
extern "C" {
#endif

extern int write_png_rgb(const char* filename, 
	            int width, 
	            int height, 
	            const unsigned char *buffer, 
	            char* title);

extern int write_png_gray(const char* filename,
                    int width,
                    int height,
                    unsigned bit_depth,
                    const unsigned char *buffer,
                    char* title);

#ifdef __cplusplus
}
#endif

#endif 
