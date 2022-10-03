#include <stdlib.h>
#include <string.h>
#include "file_parser.h"


#pragma pack(push) /* 将当前pack设置压栈保存 */
#pragma pack(1)    /* 必须在结构体定义之前使用 */

typedef struct BMPFileHeader { /* bmfh */
	unsigned short bfType;
	unsigned long  bfSize;
	unsigned short bfReserved1;
	unsigned short bfReserved2;
	unsigned long  bfOffBits;
} BMPFileHeader;

typedef struct BMPInfoHeader { /* bmih */
	unsigned long  biSize;
	unsigned long  biWidth;
	unsigned long  biHeight;
	unsigned short biPlanes;
	unsigned short biBitCount;
	unsigned long  biCompression;
	unsigned long  biSizeImage;
	unsigned long  biXPelsPerMeter;
	unsigned long  biYPelsPerMeter;
	unsigned long  biClrUsed;
	unsigned long  biClrImportant;
} BMPInfoHeader;

#pragma pack(pop) /* 恢复先前的pack设置 */


static int BMPFormatCheck(unsigned char *fileHead)
{
	if (fileHead[0] != 0x42 || fileHead[1] != 0x4d)
		return 0;
	else
		return 1;
}

static int ConvertOneLineData(unsigned char *pSrc, unsigned char *pDst,
									int width, int srcBpp, int dstBpp)
{
	unsigned int dwRed;
	unsigned int dwGreen;
	unsigned int dwBlue;
	unsigned int dwColor;

	unsigned short *pwDstDatas16bpp = (unsigned short *)pDst;
	unsigned int   *pwDstDatas32bpp = (unsigned int *)pDst;

	int i;
	int pos = 0;

	if (srcBpp != 24)
	{
		return -1;
	}

	if (dstBpp == 24)
	{
		memcpy(pDst, pSrc, width*3);
	}
	else
	{
		for (i = 0; i < width; i++)
		{
			dwBlue  = pSrc[pos++];
			dwGreen = pSrc[pos++];
			dwRed   = pSrc[pos++];
			if (dstBpp == 32)
			{
				dwColor = (dwRed << 16) | (dwGreen << 8) | dwBlue;
				*pwDstDatas32bpp = dwColor;
				pwDstDatas32bpp++;
			}
			else if (dstBpp == 16)
			{
				/* 565 */
				dwRed   = dwRed >> 3;
				dwGreen = dwGreen >> 2;
				dwBlue  = dwBlue >> 3;
				dwColor = (dwRed << 11) | (dwGreen << 5) | (dwBlue);
				*pwDstDatas16bpp = dwColor;
				pwDstDatas16bpp++;
			}
		}
	}

	return 0;
}

static int BMPGetPixelData(unsigned char *fileHead, PixelData *pixelData)
{
	/* 从BMP文件数据中获取用于显示的pixel数据 */
	/*
		typedef struct PixelData {
			int width;
			int height;
			int bpp;
			int line_bytes;
			unsigned char *pixel_data;
		} PixelData;
	*/

	int y;
	int heigh, width, bpp;
	int lineWidthReal, lineWidthAlign;
	unsigned char *pSrc, *pDst;
	BMPFileHeader *fh;
	BMPInfoHeader *ih;

	fh = (BMPFileHeader *)fileHead;
	ih = (BMPInfoHeader *)(fileHead + sizeof(*fh));

	heigh = ih->biHeight;
	width = ih->biWidth;
	bpp   = ih->biBitCount;

	if (bpp != 24) {
		/* do not support */
		return -1;
	}

	//pixelData->bpp 	  = bpp;	//由调用者传入
	pixelData->height = heigh;
	pixelData->width  = width;	
	pixelData->line_bytes = width * bpp / 8;
	pixelData->pixel_data = (unsigned char *)malloc(heigh * width * bpp / 8);
	if (pixelData->pixel_data == NULL) {
		return -1;
	}

	lineWidthReal = pixelData->line_bytes;
	lineWidthAlign = (lineWidthReal + 3) & (~0x3);

	pSrc = fileHead + fh->bfOffBits;
	pSrc += (heigh - 1) * lineWidthAlign;	//坐标转换
	pDst = pixelData->pixel_data;

	for (y = 0; y < heigh; y++) {
		ConvertOneLineData(pSrc, pDst, width, bpp, pixelData->bpp);
		pSrc -= lineWidthAlign;
		pDst += pixelData->line_bytes;
	}

	return 0;
}

static int BMPFreePixelData(struct PixelData *pixelData)
{
	free(pixelData->pixel_data);
	return 0;
}

struct PicFileParser BMPFileParser = {
	.name = "bmp",
	.isSupport = BMPFormatCheck,
	.GetPixelData = BMPGetPixelData,
	.FreePixelData = BMPFreePixelData,
};


