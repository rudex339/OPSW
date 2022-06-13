#include "character.h"
#include <math.h>
//
landing::landing() {
	LINE* NEW;
	NEW = new LINE; NEW->p.x = 0; NEW->p.y = 183; NEW->prev = NULL;  NEW->p2.x = 562; NEW->p2.y = 183; land = NEW;
	NEW->next = new LINE; NEW->next->p.x = 562; NEW->next->p.y = 183; NEW->next->p2.x = 610; NEW->next->p2.y = 166; NEW->next->prev = NEW;
	NEW = NEW->next;
	NEW->next = new LINE; NEW->next->p.x = 609; NEW->next->p.y = 166; NEW->next->p2.x = 767; NEW->next->p2.y = 135; NEW->next->prev = NEW;
	NEW = NEW->next;
	NEW->next = new LINE; NEW->next->p.x = 765; NEW->next->p.y = 135; NEW->next->p2.x = 822; NEW->next->p2.y = 129; NEW->next->prev = NEW;
	NEW = NEW->next;
	NEW->next = new LINE; NEW->next->p.x = 820; NEW->next->p.y = 129; NEW->next->p2.x = 855; NEW->next->p2.y = 187; NEW->next->prev = NEW;
	NEW = NEW->next;
	NEW->next = new LINE; NEW->next->p.x = 853; NEW->next->p.y = 187; NEW->next->p2.x = 980; NEW->next->p2.y = 189; NEW->next->prev = NEW;
	NEW = NEW->next;
	NEW->next = new LINE; NEW->next->p.x = 978; NEW->next->p.y = 158; NEW->next->p2.x = 1026; NEW->next->p2.y = 151; NEW->next->prev = NEW;
	NEW = NEW->next;
	NEW->next = new LINE; NEW->next->p.x = 1024; NEW->next->p.y = 151; NEW->next->p2.x = 1081; NEW->next->p2.y = 152; NEW->next->prev = NEW;
	NEW = NEW->next;
	NEW->next = new LINE; NEW->next->p.x = 1079; NEW->next->p.y = 152; NEW->next->p2.x = 1125; NEW->next->p2.y = 186; NEW->next->prev = NEW;
	NEW = NEW->next;
	NEW->next = new LINE; NEW->next->p.x = 1123; NEW->next->p.y = 186; NEW->next->p2.x = 1290; NEW->next->p2.y = 194; NEW->next->prev = NEW;
	NEW = NEW->next;
	NEW->next = new LINE; NEW->next->p.x = 1288; NEW->next->p.y = 194; NEW->next->p2.x = 1420; NEW->next->p2.y = 180; NEW->next->prev = NEW;
	NEW = NEW->next;
	NEW->next = new LINE; NEW->next->p.x = 1418; NEW->next->p.y = 180; NEW->next->p2.x = 1605; NEW->next->p2.y = 168; NEW->next->prev = NEW;
	NEW = NEW->next;
	NEW->next = NULL;

	//NEW->next = new LINE; NEW->next->p.x = 980; NEW->next->p.y = 189; NEW->next->p2.x = 980; NEW->next->p2.y = 158; NEW->next->prev = NEW;
	//NEW->next->situation = 1; NEW = NEW->next;
}
int landing::crash_check(int x, int y, int wid, int hei,int px,int py) {
	while (1) {
		if (px >= land->p2.x) {
			if (land->next != NULL)
				land = land->next;
		}
		else if (px < land->p.x) {
			if (land->prev != NULL)
				land = land->prev;
		}
		else break;
	}
	float u, v;
	float x1, y1, x2, y2, x3, y3, x4, y4;
	x1 = x+wid;
	y1 = y;
	x2 = x+wid;
	y2 = y + hei;
	x3 = land->p.x;
	y3 = land->p.y;
	x4 = land->p2.x;
	y4 = land->p2.y;
	u = ((x4 - x3) * (y1 - y3) - (x1 - x3) * (y4 - y3)) / ((x2 - x1) * (y4 - y3) - (x4 - x3) * (y2 - y1));
	if (u < 0)
		u = -u;
	v = ((x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3)) / ((x2 - x1) * (y4 - y3) - (x4 - x3) * (y2 - y1));
	if (v < 0)
		v = -u;
	if (u > 0 && u < 1 && v>0 && v < 1) {
		return (y3 + v * (y4 - y3)) - y2;
	}
	x1 = x;

	x2 = x;

	u = ((x4 - x3) * (y1 - y3) - (y4 - y3) * (x1 - x3)) / ((x2 - x1) * (y4 - y3) - (x4 - x3) * (y2 - y1));
	if (u < 0)
		u = -u;
	v = ((x2 - x1) * (y1 - y3) - (y2 - y1) * (x1 - x3)) / ((x2 - x1) * (y4 - y3) - (x4 - x3) * (y2 - y1));
	if (v < 0)
		v = -u;
	if (u > 0 && u < 1 && v>0 && v < 1) {
		return (y3 + v * (y4 - y3)) - y2;
	}
	return 0;
}
int landing::check_hei(int x, int y) {
	while (1) {
		if (x >= land->p2.x) {
			if (land->next != NULL)
				land = land->next;
			else break;
		}
		else if (x < land->p.x) {
			if (land->prev != NULL)
				land = land->prev;
			else break;
		}

		else break;
	}
	return round((float)((land->p.y - land->p2.y) / (land->p.x - land->p2.x)) * (float)(x - land->p.x) + land->p.y-y);
}
void landing::print_line(HDC hdc, RECT rt) {
	MoveToEx(hdc, land->p.x-rt.left, land->p.y, NULL);
	LineTo(hdc, land->p2.x-rt.left, land->p2.y);
}
//
character::character() {
		hp = 0;
		damage = 0;
		direct = 0;
		speed = 0;
		position.x = 0; position.y = 0;
		floating = 0;

		move_int = 0;
	}
void character::character_insert(int in_hp, int in_damage, int in_direct, int in_speed, int x, int y) {
		hp = in_hp;
		damage = in_damage;
		direct = in_direct;
		speed = in_speed;
		position.x = x; position.y = y;
		floating = 0;
		move_int = 1;
	}
POINT character::return_position() {
		return this->position;
	}
void character::move_c(int moving) {
		if (moving != 0) {
			if (direct != moving)
				direct = moving;
			position.x += moving * 5;
		}
	}
void character::move_y(int moving) {
		if (moving != 0) {
			position.y += moving;
		}
	}
int character::return_direct() {
		return this->direct;
	}
int character::MOVE_check(int check) {
		if (check == 0)
			return this->move_int;
		else {
			if (move_int)move_int = 0;
			else move_int = 1;
		}
	}
int character::change_float(int mod) {
	if (mod==1) {
		return floating;
	}
	else if (mod == 2)
		floating = 2;
	else {
		if (floating == 0)
			floating = 1;
		else
			floating = 0;

		
	}
	return 0;
}
//
player::player() {
	M = 0;
	jump = 0;
	character_insert(1,1,1,1,10,10);
	this->sprite.Load(TEXT("sprite/player.png"));
	this->sprite.SetTransparentColor(RGB(0, 0, 255));
	FRAME* NEW;
	this->down = new FRAME * [5];
	{
		NEW = new FRAME;
		NEW->x = 150; NEW->y = 1602; NEW->wid = 20; NEW->hei = 24;//서있는 다리
		NEW->next = NEW; this->down[0] = NEW; NEW->left = 6; NEW->up = 6;

		NEW = new FRAME;
		NEW->x = 176; NEW->y = 1600; NEW->wid = 22; NEW->hei = 26;//달리는 다리
		this->down[1] = NEW; NEW->left = 10; NEW->up = 6;
		NEW->next = new FRAME; NEW->next->left = 11; NEW->next->up = 5;
		NEW->next->x = 204; NEW->next->y = 1603; NEW->next->wid = 27; NEW->next->hei = 23; NEW = NEW->next;
		NEW->next = new FRAME; NEW->next->left = 9; NEW->next->up = 6;
		NEW->next->x = 236; NEW->next->y = 1600; NEW->next->wid = 17; NEW->next->hei = 26; NEW = NEW->next;
		NEW->next = new FRAME; NEW->next->left = 8; NEW->next->up = 5;
		NEW->next->x = 259; NEW->next->y = 1601; NEW->next->wid = 21; NEW->next->hei = 25; NEW = NEW->next;
		NEW->next = new FRAME; NEW->next->left = 12; NEW->next->up = 5;
		NEW->next->x = 285; NEW->next->y = 1601; NEW->next->wid = 30; NEW->next->hei = 25; NEW = NEW->next;
		NEW->next = new FRAME; NEW->next->left = 8; NEW->next->up = 6;
		NEW->next->x = 320; NEW->next->y = 1600; NEW->next->wid = 18; NEW->next->hei = 26; NEW->next->next = this->down[1];

		NEW = new FRAME;//제자리 점프 다리
		NEW->x = 456; NEW->y = 1595; NEW->wid = 22; NEW->hei = 31;
		this->down[2] = NEW; NEW->left = 7; NEW->up = 7;
		NEW->next = new FRAME; NEW->next->left = 8; NEW->next->up = 7;
		NEW->next->x = 482; NEW->next->y = 1595; NEW->next->wid = 22; NEW->next->hei = 31; NEW = NEW->next;
		NEW->next = new FRAME; NEW->next->left = 8; NEW->next->up = 7;
		NEW->next->x = 508; NEW->next->y = 1595; NEW->next->wid = 22; NEW->next->hei = 30; NEW = NEW->next;
		NEW->next = new FRAME; NEW->next->left = 8; NEW->next->up = 7;
		NEW->next->x = 534; NEW->next->y = 1595; NEW->next->wid = 23; NEW->next->hei = 29; NEW = NEW->next;
		NEW->next = new FRAME; NEW->next->left = 8; NEW->next->up = 7;
		NEW->next->x = 561; NEW->next->y = 1595; NEW->next->wid = 24; NEW->next->hei = 26; NEW = NEW->next;
		NEW->next = new FRAME; NEW->next->left = 8; NEW->next->up = 7;
		NEW->next->x = 589; NEW->next->y = 1595; NEW->next->wid = 24; NEW->next->hei = 23; NEW = NEW->next;
		NEW->next = new FRAME; NEW->next->left = 8; NEW->next->up = 7;
		NEW->next->x = 561; NEW->next->y = 1595; NEW->next->wid = 24; NEW->next->hei = 26; NEW = NEW->next;
		NEW->next = new FRAME; NEW->next->left = 8; NEW->next->up = 7;
		NEW->next->x = 534; NEW->next->y = 1595; NEW->next->wid = 23; NEW->next->hei = 29; NEW = NEW->next;
		NEW->next = new FRAME; NEW->next->left = 8; NEW->next->up = 7;
		NEW->next->x = 508; NEW->next->y = 1595; NEW->next->wid = 22; NEW->next->hei = 30; NEW = NEW->next;
		NEW->next = new FRAME; NEW->next->left = 7;  NEW->next->up = 7;
		NEW->next->x = 482; NEW->next->y = 1595; NEW->next->wid = 22; NEW->next->hei = 31; NEW->next->next = NEW->next;//땅에 닿을때까지 반복

		NEW = new FRAME;//이동 점프 다리
		NEW->x = 619; NEW->y = 1603; NEW->wid = 28; NEW->hei = 23;
		this->down[3] = NEW; NEW->left = 8; NEW->up = 3;
		NEW->next = new FRAME; NEW->next->left = 11; NEW->next->up = 4;
		NEW->next->x = 651; NEW->next->y = 1603; NEW->next->wid = 29; NEW->next->hei = 21; NEW = NEW->next;
		NEW->next = new FRAME; NEW->next->left = 12; NEW->next->up = 3;
		NEW->next->x = 683; NEW->next->y = 1603; NEW->next->wid = 33; NEW->next->hei = 19; NEW = NEW->next;
		NEW->next = new FRAME; NEW->next->left = 12; NEW->next->up = 3;
		NEW->next->x = 720; NEW->next->y = 1603; NEW->next->wid = 30; NEW->next->hei = 17; NEW = NEW->next;
		NEW->next = new FRAME; NEW->next->left = 12; NEW->next->up = 3;
		NEW->next->x = 754;	 NEW->next->y = 1603; NEW->next->wid = 30; NEW->next->hei = 17;  NEW->next->next = NEW->next;//땅에 닿을때까지 반복

		NEW = new FRAME;//정지 다리
		NEW->x = 343; NEW->y = 1602; NEW->wid = 22; NEW->hei = 24;
		this->down[4] = NEW; NEW->left = 7; NEW->up = 6;
		NEW->next = new FRAME; NEW->next->left = 9; NEW->next->up = 6;
		NEW->next->x = 369; NEW->next->y = 1602; NEW->next->wid = 25; NEW->next->hei = 24; NEW = NEW->next;
		NEW->next = new FRAME; NEW->next->left = 9; NEW->next->up = 6;
		NEW->next->x = 398; NEW->next->y = 1602; NEW->next->wid = 25; NEW->next->hei = 24; NEW = NEW->next;
		NEW->next = new FRAME; NEW->next->left = 7; NEW->next->up = 6;
		NEW->next->x = 427; NEW->next->y = 1602; NEW->next->wid = 23; NEW->next->hei = 24; NEW->next->next = this->down[0];//끝나면 서있는 다리로
	}
	p_down = down[0];
	this->up = new FRAME * [11];
	{
		NEW = new FRAME;
		NEW->x = 84; NEW->y = 4; NEW->wid = 28; NEW->hei = 26;//멈춘 상체
		this->up[0] = NEW; NEW->left = 7; NEW->up = 20;
		NEW->next = new FRAME; NEW->next->left = 7; NEW->next->up = 20;
		NEW->next->x = 116; NEW->next->y = 4; NEW->next->wid = 28; NEW->next->hei = 26; NEW = NEW->next;
		NEW->next = new FRAME; NEW->next->left = 7; NEW->next->up = 20;
		NEW->next->x = 149; NEW->next->y = 4; NEW->next->wid = 28; NEW->next->hei = 26; NEW = NEW->next;
		NEW->next = new FRAME; NEW->next->left = 7; NEW->next->up = 20;
		NEW->next->x = 181; NEW->next->y = 4; NEW->next->wid = 28; NEW->next->hei = 26; NEW->next = this->up[0];

		NEW = new FRAME;//달리는 상체
		NEW->x = 215; NEW->y = 4; NEW->wid = 27; NEW->hei = 26;
		up[1] = NEW; NEW->left = 6; NEW->up = 20;
		NEW->next = new FRAME; NEW->next->left = 6; NEW->next->up = 20;
		NEW->next->x = 245; NEW->next->y = 4; NEW->next->wid = 27; NEW->next->hei = 26; NEW = NEW->next;
		NEW->next = new FRAME; NEW->next->left = 6; NEW->next->up = 19;
		NEW->next->x = 276; NEW->next->y = 4; NEW->next->wid = 27; NEW->next->hei = 26; NEW = NEW->next;
		NEW->next = new FRAME; NEW->next->left = 6; NEW->next->up = 19;
		NEW->next->x = 310; NEW->next->y = 4; NEW->next->wid = 27; NEW->next->hei = 26; NEW = NEW->next;
		NEW->next = new FRAME; NEW->next->left = 6; NEW->next->up = 20;
		NEW->next->x = 341; NEW->next->y = 4; NEW->next->wid = 27; NEW->next->hei = 26; NEW = NEW->next;
		NEW->next = new FRAME; NEW->next->left = 7; NEW->next->up = 20;
		NEW->next->x = 372; NEW->next->y = 4; NEW->next->wid = 28; NEW->next->hei = 26; NEW = NEW->next;
		NEW->next = new FRAME; NEW->next->left = 7; NEW->next->up = 20;
		NEW->next->x = 404; NEW->next->y = 4; NEW->next->wid = 28; NEW->next->hei = 26; NEW = NEW->next;
		NEW->next = new FRAME; NEW->next->left = 7; NEW->next->up = 20;
		NEW->next->x = 436; NEW->next->y = 4; NEW->next->wid = 28; NEW->next->hei = 26; NEW = NEW->next;
		NEW->next = new FRAME; NEW->next->left = 7; NEW->next->up = 20;
		NEW->next->x = 468; NEW->next->y = 4; NEW->next->wid = 29; NEW->next->hei = 26; NEW = NEW->next;
		NEW->next = new FRAME; NEW->next->left = 6; NEW->next->up = 20;
		NEW->next->x = 501; NEW->next->y = 4; NEW->next->wid = 28; NEW->next->hei = 26; NEW = NEW->next;
		NEW->next = new FRAME; NEW->next->left = 5; NEW->next->up = 20;
		NEW->next->x = 533; NEW->next->y = 4; NEW->next->wid = 26; NEW->next->hei = 26; NEW = NEW->next;
		NEW->next = new FRAME; NEW->next->left = 7; NEW->next->up = 20;
		NEW->next->x = 563; NEW->next->y = 4; NEW->next->wid = 27; NEW->next->hei = 27; NEW = NEW->next;
		NEW->next = new FRAME; NEW->next->left = 7; NEW->next->up = 19;
		NEW->next->x = 595; NEW->next->y = 4; NEW->next->wid = 28; NEW->next->hei = 26; NEW = NEW->next;
		NEW->next = new FRAME; NEW->next->left = 6; NEW->next->up = 20;
		NEW->next->x = 628; NEW->next->y = 4; NEW->next->wid = 28; NEW->next->hei = 26; NEW = NEW->next;
		NEW->next = new FRAME; NEW->next->left = 7; NEW->next->up = 19;
		NEW->next->x = 661; NEW->next->y = 4; NEW->next->wid = 28; NEW->next->hei = 26; NEW = NEW->next;
		NEW->next = new FRAME; NEW->next->left = 7; NEW->next->up = 20;
		NEW->next->x = 693; NEW->next->y = 4; NEW->next->wid = 28; NEW->next->hei = 26; NEW = NEW->next;
		NEW->next = new FRAME; NEW->next->left = 6; NEW->next->up = 20;
		NEW->next->x = 726; NEW->next->y = 4; NEW->next->wid = 28; NEW->next->hei = 26; NEW = NEW->next;
		NEW->next = new FRAME; NEW->next->left = 6; NEW->next->up = 20;
		NEW->next->x = 758; NEW->next->y = 4; NEW->next->wid = 27; NEW->next->hei = 27; NEW->next->next =up[1];

	}
	p_up = up[0];
}
void player::move(WPARAM wParam, int mode) {
	if (mode == 0) {
		switch (wParam) {
		case VK_UP:



			break;
		case VK_DOWN:



			break;
		case VK_LEFT:
			if (MOVE_check(0)) { p_down = down[1];
			MOVE_check(1);
			}
			if (change_float(1) == 0)
			M = -1;

			break;
		case VK_RIGHT:
			if (MOVE_check(0)) {
				p_down = down[1];
				MOVE_check(1);
			}
			if (change_float(1) == 0)
			M = 1;

			break;
		case 'c':
		case 'C':
			if (change_float(1) == 0)
			jump = -10;
			break;
		}
	}
	else if (mode == 1) {
		switch (wParam) {
		case VK_UP:



			break;
		case VK_DOWN:



			break;
		case VK_LEFT:
			M = 0;
			MOVE_check(1);
			if (change_float(1) == 0)
			p_down = down[4];

			break;
		case VK_RIGHT:
			M = 0;
			MOVE_check(1);
			if (change_float(1) == 0)
			p_down = down[4];

			break;
		}
	}
}
void player::print_player(HDC hdc,RECT *rt) {
	HDC chardc;
	int hei, wed, x, y;
	HBITMAP hbit;
	
	y = return_position().y - p_up->up;
	hei = p_up->up + p_down->hei - p_down->up;
	if (p_up->left >= p_down->left) {
		wed = p_up->left;
		x = return_position().x - p_up->left;
	}
	else {
		wed = p_down->left;
		x = return_position().x - p_down->left;
	}
	if ((p_up->wid - p_up->left) >= (p_down->wid - p_down->left)) {
		wed += (p_up->wid - p_up->left);
	}
	else {
		wed += (p_down->wid - p_down->left);
	}
	hbit = CreateCompatibleBitmap(hdc, 900, 600);
	chardc = CreateCompatibleDC(hdc);
	SelectObject(chardc, hbit);
	if (return_direct() == -1)
		StretchBlt(chardc, x + wed-1- rt->left, y, return_direct() * wed, hei, hdc, x- rt->left, y, wed, hei, SRCCOPY);
	else if (return_direct() == 1)
		StretchBlt(chardc, x- rt->left, y, return_direct() * wed, hei, hdc, x - rt->left, y, wed, hei, SRCCOPY);
	sprite.AlphaBlend(chardc, return_position().x - p_down->left - rt->left, return_position().y - p_down->up, p_down->wid, p_down->hei,
		p_down->x, p_down->y, p_down->wid, p_down->hei);
	sprite.AlphaBlend(chardc, return_position().x - p_up->left - rt->left, return_position().y - p_up->up, p_up->wid, p_up->hei,
		p_up->x, p_up->y, p_up->wid, p_up->hei);
	TCHAR a[10];
	wsprintf(a, TEXT("%d"), M);
	TextOut(chardc, return_position().x - rt->left, return_position().y, a, lstrlen(a));
	if (return_direct() == -1)
		StretchBlt(hdc, x + p_down->left + p_up->left- rt->left, y, return_direct() * wed, hei, chardc, x- rt->left, y, wed, hei, SRCCOPY);
	else if (return_direct() == 1)
		StretchBlt(hdc, x- rt->left, y, return_direct() * wed, hei, chardc, x- rt->left, y, wed, hei, SRCCOPY);

	
	
	DeleteObject(hbit);
	DeleteDC(chardc);
}
void player::Animation(landing* ground) {
	p_up = p_up->next;
	p_down = p_down->next;
	move_c(M);
	if (ground->check_hei(return_position().x - p_down->left+ p_down->wid, return_position().y - p_down->up+25) > 10&& 
		ground->check_hei(return_position().x - p_down->left, return_position().y - p_down->up + 25) > 10) {
		if (change_float(1) == 0) {
			change_float(0);
		}
	}
	else  {
		if (change_float(1) == 2) {
			jump = 10;
			if (M != 0)
				p_down = down[1];
			else p_down = down[4];

			change_float(0);
		}
	}
	if (change_float(1) != 0) {
		if(jump<10)
		jump += 2;
	}
	move_y(jump);
	move_y(ground->crash_check(return_position().x-p_down->left, return_position().y - p_down->up,p_down->wid, p_down->hei, return_position().x, return_position().y));
	
	if (change_float(1) == 1) {
		change_float(2);
		if (M != 0)
			p_down = down[3];
		else p_down = down[2];
	}
}
POINT player::return_playerp() {
	return return_position();
}