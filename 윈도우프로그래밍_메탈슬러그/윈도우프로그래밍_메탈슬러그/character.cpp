#include "character.h"

character::character() {
	hp = 0;
	damage = 0;
	direct = 0;
	speed = 0;
	position.x=0; position.y = 0;
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
	if(direct!=moving)
	direct = moving;
	position.x += moving;
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

player::player() {
	character_insert(1,1,1,1,10,150);
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
		this->down[2] = NEW;
		NEW->next = new FRAME;
		NEW->next->x = 482; NEW->next->y = 1595; NEW->next->wid = 22; NEW->next->hei = 31; NEW = NEW->next;
		NEW->next = new FRAME;
		NEW->next->x = 508; NEW->next->y = 1595; NEW->next->wid = 22; NEW->next->hei = 30; NEW = NEW->next;
		NEW->next = new FRAME;
		NEW->next->x = 534; NEW->next->y = 1595; NEW->next->wid = 23; NEW->next->hei = 29; NEW = NEW->next;
		NEW->next = new FRAME;
		NEW->next->x = 561; NEW->next->y = 1595; NEW->next->wid = 24; NEW->next->hei = 26; NEW = NEW->next;
		NEW->next = new FRAME;
		NEW->next->x = 589; NEW->next->y = 1595; NEW->next->wid = 24; NEW->next->hei = 23; NEW = NEW->next;
		NEW->next = new FRAME;
		NEW->next->x = 561; NEW->next->y = 1595; NEW->next->wid = 24; NEW->next->hei = 26; NEW = NEW->next;
		NEW->next = new FRAME;
		NEW->next->x = 534; NEW->next->y = 1595; NEW->next->wid = 23; NEW->next->hei = 29; NEW = NEW->next;
		NEW->next = new FRAME;
		NEW->next->x = 508; NEW->next->y = 1595; NEW->next->wid = 22; NEW->next->hei = 30; NEW = NEW->next;
		NEW->next = new FRAME;
		NEW->next->x = 482; NEW->next->y = 1595; NEW->next->wid = 22; NEW->next->hei = 31; NEW->next->next = down[2];//땅에 닿을때까지 반복

		NEW = new FRAME;//이동 점프 다리
		NEW->x = 619; NEW->y = 1613; NEW->wid = 28; NEW->hei = 23;
		this->down[3] = NEW;
		NEW->next = new FRAME;
		NEW->next->x = 651; NEW->next->y = 1603; NEW->next->wid = 29; NEW->next->hei = 21; NEW = NEW->next;
		NEW->next = new FRAME;
		NEW->next->x = 683; NEW->next->y = 1603; NEW->next->wid = 33; NEW->next->hei = 19; NEW = NEW->next;
		NEW->next = new FRAME;
		NEW->next->x = 720; NEW->next->y = 1603; NEW->next->wid = 30; NEW->next->hei = 17; NEW = NEW->next;
		NEW->next = new FRAME;
		NEW->next->x = 754;	 NEW->next->y = 1603; NEW->next->wid = 30; NEW->next->hei = 17;  NEW->next->next = down[3];//땅에 닿을때까지 반복

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
			move_c(-1);

			break;
		case VK_RIGHT:
			if (MOVE_check(0)) {
				p_down = down[1];
				MOVE_check(1);
			}
			move_c(1);

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
			MOVE_check(1);
			p_down = down[4];

			break;
		case VK_RIGHT:
			MOVE_check(1);
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

	if (return_direct() == -1)
		StretchBlt(hdc, x + p_down->left + p_up->left- rt->left, y, return_direct() * wed, hei, chardc, x- rt->left, y, wed, hei, SRCCOPY);
	else if (return_direct() == 1)
		StretchBlt(hdc, x- rt->left, y, return_direct() * wed, hei, chardc, x- rt->left, y, wed, hei, SRCCOPY);

	p_up = p_up->next;
	p_down = p_down->next;
	if (rt->left + rt->right / 2 < return_position().x)
		rt->left += (return_position().x- rt->right / 2- rt->left);
	DeleteObject(hbit);
	DeleteDC(chardc);
}