#include "character.h"

character::character() {
	hp = 0;
	damage = 0;
	direct = 0;
	speed = 0;
	position.x=0; position.y = 0;
}
void character::character_insert(int in_hp, int in_damage, int in_direct, int in_speed, int x, int y) {
	hp = in_hp;
	damage = in_damage;
	direct = in_direct;
	speed = in_speed;
	position.x = x; position.y = y;
	floating = 0;
}
POINT character::return_position() {
	return this->position;
}
void character::move_c(int moving) {
	if(direct!=moving)
	direct = moving;
	//position.x += moving * 5;
}
int character::return_direct() {
	return this->direct;
}


player::player() {
	character_insert(1,1,1,1,300,300);
	this->sprite.Load(TEXT("sprite/player.png"));
	this->sprite.SetTransparentColor(RGB(0, 0, 255));
	FRAME* NEW;
	this->down = new FRAME * [5];
	{
		NEW = new FRAME;
		NEW->x = 150; NEW->y = 1602; NEW->wid = 20; NEW->hei = 24;//���ִ� �ٸ�
		NEW->next = NEW; this->down[0] = NEW; NEW->left = 6; NEW->up = 6;

		NEW = new FRAME;
		NEW->x = 176; NEW->y = 1600; NEW->wid = 22; NEW->hei = 26;//�޸��� �ٸ�
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

		NEW = new FRAME;//���ڸ� ���� �ٸ�
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
		NEW->next->x = 482; NEW->next->y = 1595; NEW->next->wid = 22; NEW->next->hei = 31; NEW->next = NEW;//���� ���������� �ݺ�

		NEW = new FRAME;//�̵� ���� �ٸ�
		NEW->x = 619; NEW->y = 1613; NEW->wid = 28; NEW->hei = 23;
		this->down[3] = NEW;
		NEW->next = new FRAME;
		NEW->next->x = 651; NEW->next->y = 1603; NEW->next->wid = 29; NEW->next->hei = 21; NEW = NEW->next;
		NEW->next = new FRAME;
		NEW->next->x = 683; NEW->next->y = 1603; NEW->next->wid = 33; NEW->next->hei = 19; NEW = NEW->next;
		NEW->next = new FRAME;
		NEW->next->x = 720; NEW->next->y = 1603; NEW->next->wid = 30; NEW->next->hei = 17; NEW = NEW->next;
		NEW->next = new FRAME;
		NEW->next->x = 754;	 NEW->next->y = 1603; NEW->next->wid = 30; NEW->next->hei = 17; NEW->next = NEW;//���� ���������� �ݺ�

		NEW = new FRAME;//���� �ٸ�
		NEW->x = 343; NEW->y = 1602; NEW->wid = 22; NEW->hei = 24;
		this->down[4] = NEW;
		NEW->next = new FRAME;
		NEW->next->x = 369; NEW->next->y = 1602; NEW->next->wid = 25; NEW->next->hei = 24; NEW = NEW->next;
		NEW->next = new FRAME;
		NEW->next->x = 398; NEW->next->y = 1602; NEW->next->wid = 25; NEW->next->hei = 24; NEW = NEW->next;
		NEW->next = new FRAME;
		NEW->next->x = 427; NEW->next->y = 1602; NEW->next->wid = 23; NEW->next->hei = 24; NEW->next = this->down[0];//������ ���ִ� �ٸ���
	}
	p_down = down[0];
	this->up = new FRAME * [11];
	{
		NEW = new FRAME;
		NEW->x = 84; NEW->y = 4; NEW->wid = 28; NEW->hei = 26;//���� ��ü
		this->up[0] = NEW; NEW->left = 7; NEW->up = 20;
		NEW->next = new FRAME; NEW->next->left = 7; NEW->next->up = 20;
		NEW->next->x = 116; NEW->next->y = 4; NEW->next->wid = 28; NEW->next->hei = 26; NEW = NEW->next;
		NEW->next = new FRAME; NEW->next->left = 7; NEW->next->up = 20;
		NEW->next->x = 149; NEW->next->y = 4; NEW->next->wid = 28; NEW->next->hei = 26; NEW = NEW->next;
		NEW->next = new FRAME; NEW->next->left = 7; NEW->next->up = 20;
		NEW->next->x = 181; NEW->next->y = 4; NEW->next->wid = 28; NEW->next->hei = 26; NEW = this->up[0];

		NEW = new FRAME;//�޸��� ��ü
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
		NEW->next->x = 758; NEW->next->y = 4; NEW->next->wid = 27; NEW->next->hei = 27; NEW = NEW->next;

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
			if (return_direct() != -1)p_down = down[1];
			move_c(-1);

			break;
		case VK_RIGHT:
			if (return_direct() != 1)p_down = down[1];
			move_c(1);

			break;
		}
	}
	else if (mode == 0) {
		switch (wParam) {
		case VK_UP:



			break;
		case VK_DOWN:



			break;
		case VK_LEFT:
			p_down = down[0];

			break;
		case VK_RIGHT:
			p_down = down[0];

			break;
		}
	}
}
void player::print_player(HDC hdc,RECT rt) {
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
	hbit = CreateCompatibleBitmap(hdc, rt.right, rt.bottom);
	chardc = CreateCompatibleDC(hdc);
	SelectObject(chardc, hbit);
	if (return_direct() == -1)
		StretchBlt(chardc, x + p_down->left + player->p_up->left + 3, y, player->direct * wed, hei, memdc, x, y, wed, hei, SRCCOPY);
	else if (player->direct == 1)
		StretchBlt(chardc, x, y, player->direct * wed, hei, memdc, x, y, wed, hei, SRCCOPY);
	player->sprite.AlphaBlend(chardc, player->position.x - player->p_down->left, player->position.y - player->p_down->top, player->p_down->wid, player->p_down->hei,
		player->p_down->cut.x, player->p_down->cut.y, player->p_down->wid, player->p_down->hei);
	player->sprite.AlphaBlend(chardc, player->position.x - player->p_up->left, player->position.y - player->p_up->top, player->p_up->wid, player->p_up->hei,
		player->p_up->cut.x, player->p_up->cut.y, player->p_up->wid, player->p_up->hei);

	if (player->direct == -1)
		StretchBlt(memdc, x + player->p_down->left + player->p_up->left - 3, y, player->direct * wed, hei, chardc, x, y, wed, hei, SRCCOPY);
	else if (player->direct == 1)
		StretchBlt(memdc, x, y, player->direct * wed, hei, chardc, x, y, wed, hei, SRCCOPY);

	player->p_up = player->p_up->next;
	player->p_down = player->p_down->next;
	DeleteObject(hbit);
	DeleteDC(chardc);
}