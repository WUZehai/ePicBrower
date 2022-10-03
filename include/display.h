#ifndef __DISPLAY_H
#define __DISPLAY_H

#include <linux/fb.h>

#define DISPLAY_DEV_FILE	"/dev/fb0"

typedef struct DispInfo {
	int fd;
	int buff_len;
	char *mem_base;
	struct fb_var_screeninfo var_info;
} DispInfo, *pDispInfo;

void display_put_pixel(int x, int y, int color);
int display_show_line(int yLine, int xStart, int len, unsigned char *data);


int display_device_init(void);
void display_device_exit(void);


#endif


