
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>

#include "disp_manager.h"
#include "file_parser.h"
#include "render.h"

extern struct PicFileParser BMPFileParser;	//bmp.c

int main(int argc, char **argv)
{
	int bmpFd, ret;
	struct stat bmpStat;
	struct Displayer *player;
	struct PixelData pixelData;
	struct PixelData fbPixelData;
	unsigned char *pBmpData;

	if (argc <= 1) {
		printf("usage:%s filename\n", argv[0]);
		return -1;
	}

	ret = displayer_init();
	player = displayer_select("fb");
	ret = player->DevInit(player);
	ret = player->ClearScreen(player, 0xffff);

	/* get a .bmp file */
	bmpFd = open(argv[1], O_RDWR);
	fstat(bmpFd, &bmpStat);
	pBmpData = (unsigned char *)mmap(NULL, bmpStat.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, bmpFd, 0);
	if (pBmpData <= 0) {
		player->DevDeinit(player);
		close(bmpFd);
		return -1;
	}

	ret = BMPFileParser.isSupport(pBmpData);
	if (ret == 0) {
		printf("file format check failed!\n");
		player->DevDeinit(player);
		close(bmpFd);
		return -1;
	}
	
	pixelData.bpp = player->bpp;
	ret = BMPFileParser.GetPixelData(pBmpData, &pixelData);
	if (ret != 0) {
		printf("GetPixelData failed!\n");
		return -1;
	}

	
	fbPixelData.bpp = player->bpp;
	fbPixelData.height = player->yRes;
	fbPixelData.width = player->xRes;
	fbPixelData.line_bytes = player->xRes * fbPixelData.bpp / 8;
	fbPixelData.pixel_data = player->pixelData;

	PicMerge(0, 0, &pixelData, &fbPixelData);

	
	player->DevDeinit(player);

	return 0;
}


