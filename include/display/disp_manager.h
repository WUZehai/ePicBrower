
#ifndef _DISP_MANAGER_H
#define _DISP_MANAGER_H

typedef struct Displayer {
	char *name;
	int xRes;	//x方向有多少个像素
	int yRes;	//y方向有多少个像素
	int bpp;	//bit per pixel
	
	int (*PutPixel)(struct Displayer *player, int x, int y, unsigned int color);
	int (*ClearScreen)(struct Displayer *player, unsigned int color);
	
	int (*DevInit)(struct Displayer *player);
	void (*DevDeinit)(struct Displayer *player);
	
	void *priv;
	
	struct Displayer *next;
}Displayer, *pDisplayer;


int displayer_register(struct Displayer *player);
struct Displayer * displayer_select(char *name);
int displayer_init(void);


#endif //_DISP_MANAGER_H



