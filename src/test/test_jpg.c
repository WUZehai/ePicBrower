
#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include "jpeglib.h"
#include "display.h"


int main(int argc, char **argv)
{
	int ret;
	FILE *infile;
	unsigned char *buff;
	struct jpeg_decompress_struct cinfo;
	struct jpeg_error_mgr jerr;

	if (argc <= 1) {
		fprintf(stderr, "Usage:./app fileName.\n");
		return -1;
	}

	ret = display_device_init();
	if (ret) {
		fprintf(stderr, "display_device_init failed with %d\n", ret);
		return ret;
	}

	/* 1. Allocate and initialize a JPEG decompression object. */
	cinfo.err = jpeg_std_error(&jerr);
	jpeg_create_decompress(&cinfo);

	/* 2. Specify the source of the compressed data (eg, a file). */
	if ((infile = fopen(argv[1], "rb")) == NULL) {
		fprintf(stderr, "can't open %s\n", argv[1]);
		return -1;
	}

	jpeg_stdio_src(&cinfo, infile);

	/* 3. Call jpeg_read_header() to obtain image info. */
	jpeg_read_header(&cinfo, TRUE);

	/* 4. Set parameters for decompression. */
	cinfo.scale_num = 1;
	cinfo.scale_denom = 1;

	/* 5. jpeg_start_decompress(...); 
	 *  After this call, the final output image dimensions
	 */
	jpeg_start_decompress(&cinfo);

	buff = calloc(1, cinfo.output_width * cinfo.output_components);
	if (buff == NULL) {
		fprintf(stderr, "calloc for buff failed!\n");
		return -1;
	}

	/*6. while (scan lines remain to be read)
     *   jpeg_read_scanlines(...);
	 */
	while (cinfo.output_scanline < cinfo.output_height) {
		jpeg_read_scanlines(&cinfo, &buff, 1);	//read 1 line.
		display_show_line(cinfo.output_scanline, 0, cinfo.output_width, buff);
	}

	free(buff);
	display_device_exit();

	return 0;
}

