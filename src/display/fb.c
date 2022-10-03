#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <fcntl.h>

#include "disp_manager.h"
#include "fb.h"

static int fb_putPixel(struct Displayer *player, int x, int y, unsigned int color)
{
	int red, green, blue;
	struct FbDispPriv *fbPriv = (struct FbDispPriv *)player->priv;
	struct fb_var_screeninfo *pVarInfo = &fbPriv->varInfo;

	/** 计算该坐标在buff中的地址 */
	char *pen = fbPriv->memBase + (pVarInfo->xres * y + x) * pVarInfo->bits_per_pixel / 8;
	short *pen16 = (short *)pen;
	int *pen32 = (int *)pen;
	
	red = (color >> 16) & 0xff;
	green = (color >> 8) & 0xff;
	blue = color & 0xff;

	switch (pVarInfo->bits_per_pixel) {
		case 8:
			*pen = ((red >> 3) << 10) | ((green >> 3) << 5) | (blue >> 3);
			break;
		case 16:
			*pen16 = ((red >> 3) << 11) | ((green >> 2) << 5) | (blue >> 3);
			break;
		default:
		case 32:
			*pen32 = color;
			break;
	}

	return 0;
}

static int fb_clearScreen(struct Displayer *player, unsigned int color)
{
	int x, y;
	struct FbDispPriv *fbPriv = (struct FbDispPriv *)player->priv;

	for (y = 0; y < player->yRes; y++) {
		for (x = 0; x < player->xRes; x++) {
			player->PutPixel(player, x, y, color);
		}
	}

	return 0;
}

static int fb_dev_init(struct Displayer *player)
{
	struct FbDispPriv *fbPriv = NULL;
	struct fb_var_screeninfo *pVarInfo = NULL;

	fbPriv = malloc(sizeof(struct FbDispPriv));
	if (fbPriv == NULL) {
		printf("fb_dev_init calloc for priv failed!\n");
		return -1;
	} else {
		memset(fbPriv, 0, sizeof(*fbPriv));
		player->priv = fbPriv;
	}

	fbPriv->fd = open("/dev/fb0", O_RDWR);
	if (fbPriv->fd < 0) {
		return -1;
	}

	ioctl(fbPriv->fd, FBIOGET_VSCREENINFO, &fbPriv->varInfo);
	pVarInfo = &fbPriv->varInfo;

	player->xRes = pVarInfo->xres;
	player->yRes = pVarInfo->yres;
	player->bpp  = pVarInfo->bits_per_pixel;

	fbPriv->buffLen = pVarInfo->xres * pVarInfo->yres * pVarInfo->bits_per_pixel / 8;
	fbPriv->memBase = (unsigned char *)mmap(NULL, fbPriv->buffLen, PROT_READ | PROT_WRITE, MAP_SHARED, fbPriv->fd, 0);
	if (fbPriv->memBase < 0) {
		return -2;
	}

	memset(fbPriv->memBase, 0xffffff, fbPriv->buffLen);//0xffffff:white
	fbPriv->init = 1;

	return 0;
}

static void fb_dev_exit(struct Displayer *player)
{
	int buffLen;
	struct FbDispPriv *fbPriv = (struct FbDispPriv *)player->priv;
	struct fb_var_screeninfo *pVarInfo = &fbPriv->varInfo;

	fbPriv->init = 0;
	munmap(fbPriv->memBase, fbPriv->buffLen);
	close(fbPriv->fd);
	free(fbPriv);
}

static struct Displayer disp_fb = {
	.name 		 = "fb",
	.PutPixel 	 = fb_putPixel,
	.ClearScreen = fb_clearScreen,
	.DevInit 	 = fb_dev_init,
	.DevDeinit 	 = fb_dev_exit,
};

int fb_disp_init(void)
{
	return displayer_register(&disp_fb);
}

