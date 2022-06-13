#pragma once
#include "character.h"

class screen {
private:
	CImage background;
	POINT back_start;
	RECT map_rt;
	int screen_x, screen_y,hei,wid;

	player p;

	landing ground;

	HDC memdc;
	HDC memdc2;
	HBITMAP map;
public:
	screen();

	void print_screen(HDC hdc,RECT *rt);

	void animation();

	void player_contral(WPARAM wparam, int mode);
};
