#include "screen.h"
#define beachx 1607
#define beachy 223
#define skyx 2374
#define skyy 272
screen::screen() {
	background.Load(TEXT("sprite/object.png"));
	back_start.x = 8; back_start.y = 8;
	map_rt.left = 1; map_rt.top = 1196; map_rt.right = 300; map_rt.bottom = 200;
}
void screen::print_screen(HDC hdc, player* p,RECT rt_main) {
	HDC memdc;
	HBITMAP map;
	RECT rt;
	memdc = CreateCompatibleDC(hdc);
	map = CreateCompatibleBitmap(hdc,rt_main.right,rt_main.bottom);
	(HBITMAP)SelectObject(memdc, map);
	background.Draw(memdc, 0, 0, rt_main.right, rt_main.bottom, 8, 69, 300, 200);
	background.Draw(memdc, 0, 0, rt_main.right, rt_main.bottom, map_rt.left, map_rt.top, 300, 200);

	p->print_player(memdc,&map_rt);
	
	StretchBlt(hdc, rt_main.left, rt_main.top, rt_main.right, rt_main.bottom, memdc, 0,0, rt_main.right, rt_main.bottom, SRCCOPY);
	
	DeleteDC(memdc);
}