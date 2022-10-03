#include <file_parser.h>
#include <stdlib.h>
#include <string.h>


int PicZoom(PixelData *ptOriginPic, PixelData *ptZoomPic)
{
    unsigned long dwDstWidth = ptZoomPic->width;
    unsigned long* pdwSrcXTable = malloc(sizeof(unsigned long) * dwDstWidth);
	unsigned long x;
	unsigned long y;
	unsigned long dwSrcY;
	unsigned char *pucDest;
	unsigned char *pucSrc;
	unsigned long dwPixelBytes = ptOriginPic->bpp/8;

	if (ptOriginPic->bpp != ptZoomPic->bpp)
	{
		return -1;
	}
	
    for (x = 0; x < dwDstWidth; x++)//生成表 pdwSrcXTable
    {
        pdwSrcXTable[x]=(x*ptOriginPic->width/ptZoomPic->width);
    }

    for (y = 0; y < ptZoomPic->height; y++)
    {			
        dwSrcY = (y * ptOriginPic->height / ptZoomPic->height);

		pucDest = ptZoomPic->pixel_data + y*ptZoomPic->line_bytes;
		pucSrc  = ptOriginPic->pixel_data + dwSrcY*ptOriginPic->line_bytes;
		
        for (x = 0; x <dwDstWidth; x++)
        {
            /* 原图座标: pdwSrcXTable[x]，srcy
             * 缩放座标: x, y
			 */
			 memcpy(pucDest+x*dwPixelBytes, pucSrc+pdwSrcXTable[x]*dwPixelBytes, dwPixelBytes);
        }
    }

    free(pdwSrcXTable);
	return 0;
}

