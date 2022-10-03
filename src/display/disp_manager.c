#include <stdio.h>
#include <string.h>
#include "disp_manager.h"
#include "fb.h"

static struct Displayer *g_playersHead = NULL;
static struct Displayer *g_defPlayer = NULL;

int displayer_register(struct Displayer *player)
{
	if (player == NULL) {
		return -1;
	}

	if (g_playersHead == NULL) {
		g_playersHead = player;
	} else {
		player->next = g_playersHead;
		g_playersHead = player;
	}

	return 0;
}

struct Displayer * displayer_select(char *name)
{
	g_defPlayer = g_playersHead;

	while (g_defPlayer) {
		if (strcmp(name, g_defPlayer->name) == 0) {
			break;
		}
		g_defPlayer = g_defPlayer->next;
	}

	return g_defPlayer;
}

int displayer_init(void)
{
	return fb_disp_init();
}


