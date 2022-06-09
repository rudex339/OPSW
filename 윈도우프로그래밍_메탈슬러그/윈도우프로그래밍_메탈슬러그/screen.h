#pragma once
#include "character.h"
class screen {
private:
	CImage background;
	RECT map_rt;
	int screen_x, screen_y,hei,wid;
public:
	screen();
	void print_screen(player p);
};