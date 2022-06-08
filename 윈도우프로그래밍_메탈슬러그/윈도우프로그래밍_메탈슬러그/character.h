#pragma once
#include <Windows.h>
#include <atlImage.h>
class character {
private:
	int hp, damage, direct,speed,floating;
	POINT position;
	
public:
	character();
	void character_insert(int in_hp, int in_damage, int in_direct, int in_speed, int x, int y);
	POINT return_position();
	void move_c(int moving);
	int return_direct();
};
struct FRAME {
	int x, y, wid, hei,up,left;
	FRAME* next;
};
class player : private character {
private:
	CImage sprite;
	FRAME** up,*p_up;
	FRAME** down,*p_down;
public:
	player();
	player(RECT rt);
	void move(WPARAM wParam,int mode);
	void print_player(HDC hdc,RECT rt);
	void Animation();
};