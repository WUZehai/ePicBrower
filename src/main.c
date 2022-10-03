
#include <stdio.h>
#include "disp_manager.h"


int main(int argc, char **argv)
{
	int ret;
	struct Displayer *player;

	ret = displayer_init();
	player = displayer_select("fb");
	ret = player->DevInit(player);
	ret = player->ClearScreen(player, 0xffff);




	player->DevDeinit(player);

	return 0;
}


