#ifndef __FB_H_
#define __FB_H_

#include <linux/fb.h>

typedef struct FbDispPriv {
	int fd;
	int init;
	int buffLen;
	unsigned char *memBase;
	struct fb_var_screeninfo varInfo;
} FbDispPriv;
	

int fb_disp_init(void);

#endif
