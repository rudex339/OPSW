#include "screen.h"

screen::screen() {
	background.Load(TEXT("object.png"));
	map_rt.left = 8; map_rt.top = 8; map_rt.right = 2374; map_rt.bottom = 272;
	screen_x = 8; screen_y = 8; wid = 300; hei = 200;
}