#pragma once
#include "character.h"
class screen {
private:
	CImage background;
	POINT back_start;
	RECT map_rt;
	int screen_x, screen_y,hei,wid;
public:
	screen();
	void print_screen(HDC hdc,player* p,RECT rt);
};