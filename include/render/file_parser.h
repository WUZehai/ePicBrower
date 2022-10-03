#ifndef __FILE_PARSER_H
#define __FILE_PARSER_H

typedef struct PixelData {
	int width;
	int height;
	int bpp;
	int line_bytes;
	unsigned char *pixel_data;
} PixelData;

typedef struct PicFileParser {
	char *name;
	int (*isSupport)(unsigned char *fileHead);
	int (*GetPixelData)(unsigned char *fileHead, PixelData *pixelData);
	int (*FreePixelData)(struct PixelData *pixelData);
} PicFileParser;


#endif

