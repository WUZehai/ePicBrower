
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <string.h>
#include <linux/fb.h>

#include "display.h"

struct DispInfo g_disp;

/** 功能：描点函数 
 *  x,y: 像素坐标
 *  color: red: 7~0;  green:15~8;  blue:23~16;
 */
void display_put_pixel(int x, int y, int color)
{
	int red, green, blue;

	/** 计算该坐标在buff中的地址 */
	char *pen = g_disp.mem_base + (g_disp.var_info.xres * y + x) * g_disp.var_info.bits_per_pixel / 8;
	short *pen16 = (short *)pen;
	int *pen32 = (int *)pen;
	
	red = (color >> 16) & 0xff;
	green = (color >> 8) & 0xff;
	blue = color & 0xff;

	switch (g_disp.var_info.bits_per_pixel) {
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
}

int display_show_line(int yLine, int xStart, int len, unsigned char *data)
{
	int i, index, color;

	if (yLine >= g_disp.var_info.yres ||
		xStart >= g_disp.var_info.xres) {
		return -1;
	}

	if (xStart + len > g_disp.var_info.xres) {
		len = g_disp.var_info.xres - xStart;
	}

	for (i = xStart; i < xStart + len; i++) {
		index = (i - xStart) * 3;
		color = data[index] << 16 | data[index+1] << 8 | data[index+2];
		display_put_pixel(i, yLine, color);	// y坐标不变
	}

	return 0;
}


int display_device_init(void)
{
	struct fb_var_screeninfo *pVarInfo = &g_disp.var_info;

	g_disp.fd = open(DISPLAY_DEV_FILE, O_RDWR);
	if (g_disp.fd < 0) {
		return -1;
	}

	ioctl(g_disp.fd, FBIOGET_VSCREENINFO, pVarInfo);
	g_disp.buff_len = pVarInfo->xres * pVarInfo->yres * pVarInfo->bits_per_pixel / 8;
	g_disp.mem_base = (char *)mmap(NULL, g_disp.buff_len, PROT_READ | PROT_WRITE, MAP_SHARED, g_disp.fd, 0);
	if (g_disp.mem_base == NULL) {
		return -2;
	}

	memset(g_disp.mem_base, 0xffffff, g_disp.buff_len);//0xffffff:white

	return 0;
}

void display_device_exit(void)
{
	munmap(g_disp.mem_base, g_disp.buff_len);
	close(g_disp.fd);
}

