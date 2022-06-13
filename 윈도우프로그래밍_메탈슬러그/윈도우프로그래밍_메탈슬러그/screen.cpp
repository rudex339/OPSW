#include "screen.h"
#define beachx 1607
#define beachy 223
#define skyx 2374
#define skyy 272
screen::screen() {
	background.Load(TEXT("sprite/object.png"));
	back_start.x = 8; back_start.y = 69;
	map_rt.left = 1; map_rt.top = 1196; map_rt.right = 300; map_rt.bottom = 200;
}

void screen::print_screen(HDC hdc,RECT* rt_main) {
	memdc = CreateCompatibleDC(hdc);
	map = CreateCompatibleBitmap(hdc,300,200);
	(HBITMAP)SelectObject(memdc, map);
	background.Draw(memdc, 0, 0, 300, 200, back_start.x, back_start.y, 300, 200);
	background.Draw(memdc, 0, 0, 300, 200, map_rt.left, map_rt.top, 300, 200);

	p.print_player(memdc,&map_rt);

	back_start.x = 8 + (p.return_playerp().x / 3);
	if (map_rt.left + map_rt.right >= beachx) {
		map_rt.left = beachx - map_rt.right;
	}
	else if (map_rt.left + map_rt.right / 2 < p.return_playerp().x) {
		map_rt.left += (p.return_playerp().x - map_rt.right / 2 - map_rt.left);
		
	}
	StretchBlt(hdc, 0, 0, rt_main->right, rt_main->bottom, memdc, 0,0, 300, 200, SRCCOPY);
	
	DeleteDC(memdc);
}

void screen::animation() {
	p.Animation(&ground);
}

void screen::player_contral(WPARAM wparam,int mode) {
	p.move(wparam, mode);
}
