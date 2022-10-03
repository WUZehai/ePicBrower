
#include <file_parser.h>
#include <string.h>

int PicMerge(int iX, int iY, PixelData *ptSmallPic, PixelData *ptBigPic)
{
	int i;
	unsigned char *pucSrc;
	unsigned char *pucDst;
	
	if ((ptSmallPic->width > ptBigPic->width)  ||
		(ptSmallPic->height > ptBigPic->height) ||
		(ptSmallPic->bpp != ptBigPic->bpp))
	{
		return -1;
	}

	pucSrc = ptSmallPic->pixel_data;
	pucDst = ptBigPic->pixel_data + iY * ptBigPic->line_bytes + iX * ptBigPic->bpp / 8;
	for (i = 0; i < ptSmallPic->height; i++)
	{
		memcpy(pucDst, pucSrc, ptSmallPic->line_bytes);
		pucSrc += ptSmallPic->line_bytes;
		pucDst += ptBigPic->line_bytes;
	}

	return 0;
}

