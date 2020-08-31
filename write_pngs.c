#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <png.h>
#include "write_pngs.h"

extern int write_png_rgb(const char* filename, 
	            int width, 
	            int height, 
	            unsigned char *buffer, 
	            char* title)
{
	int yrow;
	int code = 1;
	FILE *fp = NULL;
	png_structp png_ptr = NULL;
	png_infop info_ptr = NULL;
	png_bytep row = NULL;

	if(width == 0 || height == 0) {
		fprintf(stderr, "PNG Error: Found a zero dimension. width:%d, height%d\n", width, height);
		code = 0;
		goto finalise;
	}
	
	// Open file for writing (binary mode)
	fp = fopen(filename, "wb");
	if (fp == NULL) {
		fprintf(stderr, "PNG ERROR: Could not open file %s for writing\n", filename);
		code = 0;
		goto finalise;
	}

	// Initialize write structure
	png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (png_ptr == NULL) {
		fprintf(stderr, "PNG ERROR: Could not allocate PNG write struct\n");
		code = 0;
		goto finalise;
	}

	// Initialize info structure
	info_ptr = png_create_info_struct(png_ptr);
	if (info_ptr == NULL) {
		fprintf(stderr, "PNG ERROR: Could not allocate PNG info struct\n");
		code = 0;
		goto finalise;
	}

	// Setup Exception handling
	if (setjmp(png_jmpbuf(png_ptr))) {
		fprintf(stderr, "PNG Error: Creating the PNG output failed.\n");
		code = 0;
		goto finalise;
	}

	png_init_io(png_ptr, fp);

	// Write header (8 bit colour depth)
	png_set_IHDR(png_ptr, info_ptr, width, height,
			8, PNG_COLOR_TYPE_RGB, PNG_INTERLACE_NONE,
			PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);

	// Sets the title
	if (title != NULL) {
		png_text title_text;
		title_text.compression = PNG_TEXT_COMPRESSION_NONE;
		title_text.key = "Title";
		title_text.text = title;
		png_set_text(png_ptr, info_ptr, &title_text, 1);
	}

	png_write_info(png_ptr, info_ptr);

	row = (png_bytep) buffer;

	// Write image data
	for (yrow=0 ; yrow<height ; yrow++) {
		png_write_row(png_ptr, row);
		// Advance the row ptr by 24-bit alignment
		row += (width * 3);
	}

	// End write operation
	png_write_end(png_ptr, NULL);

	finalise:
	if (fp != NULL) fclose(fp);
	if (info_ptr != NULL) png_free_data(png_ptr, info_ptr, PNG_FREE_ALL, -1);
	if (png_ptr != NULL) png_destroy_write_struct(&png_ptr, (png_infopp)NULL);

	return code;
}

extern int write_png_gray(const char* filename,
                    int width,
                    int height,
                    unsigned bit_depth,
                    unsigned char *buffer,
                    char* title)
{

	int yrow;
	int code = 1;
	FILE *fp = NULL;
	png_structp png_ptr = NULL;
	png_infop info_ptr = NULL;
	png_bytep row = NULL;

	if(width == 0 || height == 0) {
		fprintf(stderr, "PNG Error: Found a zero dimension. width:%d, height%d\n", width, height);
		code = 0;
		goto finalise;
	}
	
	// Open file for writing (binary mode)
	fp = fopen(filename, "wb");
	if (fp == NULL) {
		fprintf(stderr, "PNG ERROR: Could not open file %s for writing\n", filename);
		code = 0;
		goto finalise;
	}

	// Initialize write structure
	png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (png_ptr == NULL) {
		fprintf(stderr, "PNG ERROR: Could not allocate PNG write struct\n");
		code = 0;
		goto finalise;
	}

	// Initialize info structure
	info_ptr = png_create_info_struct(png_ptr);
	if (info_ptr == NULL) {
		fprintf(stderr, "PNG ERROR: Could not allocate PNG info struct\n");
		code = 0;
		goto finalise;
	}

	// Setup Exception handling
	if (setjmp(png_jmpbuf(png_ptr))) {
		fprintf(stderr, "PNG Error: Creating the PNG output failed.\n");
		code = 0;
		goto finalise;
	}

	png_init_io(png_ptr, fp);

	png_set_IHDR(png_ptr, info_ptr, width, height,
			bit_depth, PNG_COLOR_TYPE_GRAY, PNG_INTERLACE_NONE,
			PNG_COMPRESSION_TYPE_BASE, PNG_FILTER_TYPE_BASE);

	// Sets the title
	if (title != NULL) {
		png_text title_text;
		title_text.compression = PNG_TEXT_COMPRESSION_NONE;
		title_text.key = "Title";
		title_text.text = title;
		png_set_text(png_ptr, info_ptr, &title_text, 1);
	}

	png_write_info(png_ptr, info_ptr);

	row = (png_bytep) buffer;

	// Write image data
	for (yrow=0 ; yrow<height ; yrow++) {
		png_write_row(png_ptr, row);
		// Advance the row ptr by 24-bit alignment
		row += (width * 3);
	}

	// End write operation
	png_write_end(png_ptr, NULL);

	finalise:
	if (fp != NULL) fclose(fp);
	if (info_ptr != NULL) png_free_data(png_ptr, info_ptr, PNG_FREE_ALL, -1);
	if (png_ptr != NULL) png_destroy_write_struct(&png_ptr, (png_infopp)NULL);

	return code;
}
