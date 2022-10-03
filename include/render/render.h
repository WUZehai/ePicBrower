
#ifndef __RENDER_H
#define __RENDER_H

#include <file_parser.h>

int PicZoom(PixelData *ptOriginPic, PixelData *ptZoomPic);
int PicMerge(int iX, int iY, PixelData *ptSmallPic, PixelData *ptBigPic);


#endif

