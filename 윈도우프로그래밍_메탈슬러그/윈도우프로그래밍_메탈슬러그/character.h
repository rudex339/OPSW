#pragma once
#include <Windows.h>
#include <atlImage.h>
struct LINE {
	POINT p, p2;
	LINE* next, * prev;
};
class landing {
private:
	LINE* land;

public:
	landing();
	int crash_check(int x, int y, int wid, int hei, int px, int py);
	int check_hei(int x, int y);
	void print_line(HDC hdc, RECT rt);
};

class character {
private:
	int hp, damage, direct,speed,move_int, floating;
	POINT position;
	
public:
	character();
	void character_insert(int in_hp, int in_damage, int in_direct, int in_speed, int x, int y);
	POINT return_position();
	void move_c(int moving);
	void move_y(int moving);
	int change_float(int mod);
	int return_direct();
	int MOVE_check(int check);
};

struct FRAME {
	int x, y, wid, hei,up,left;
	FRAME* next;
};
class player : private character {
private:
	int M,jump;
	CImage sprite;
	FRAME** up,*p_up;
	FRAME** down,*p_down;
public:
	player();
	player(RECT rt);
	void move(WPARAM wParam,int mode);
	void print_player(HDC hdc,RECT *rt);
	void Animation(landing* ground);
	POINT return_playerp();
};