#include <windows.h>
#include <math.h>
#include <string.h>
#include <random>
#include "screen.h"
using namespace std;

#define PI  3.14

random_device rd;
HINSTANCE g_hInst;
LPCTSTR lpszClass = L"Window Class Name";
LPCTSTR lpszWindowName = L"Window Programming Lab";
LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM lParam);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdParam, int nCmdShow) {

	HWND hWnd;

	MSG Message;

	WNDCLASSEX WndClass;

	g_hInst = hInstance;

	WndClass.cbSize = sizeof(WndClass);

	WndClass.style = CS_HREDRAW | CS_VREDRAW;

	WndClass.lpfnWndProc = (WNDPROC)WndProc;

	WndClass.cbClsExtra = 0;

	WndClass.cbWndExtra = 0;

	WndClass.hInstance = hInstance;

	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);

	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);

	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);

	WndClass.lpszMenuName = NULL;

	WndClass.lpszClassName = lpszClass;

	WndClass.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	RegisterClassEx(&WndClass);

	WndClass.lpszMenuName = NULL;

	hWnd = CreateWindow(lpszClass, lpszWindowName, WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU, 0, 0, 900, 600, NULL, (HMENU)NULL, hInstance, NULL);



	ShowWindow(hWnd, nCmdShow);

	UpdateWindow(hWnd);



	while (GetMessage(&Message, 0, 0, 0)) {

		TranslateMessage(&Message);

		DispatchMessage(&Message);

	}



	return Message.wParam;

}

LRESULT CALLBACK WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {

	default_random_engine en(rd());
	uniform_int_distribution<int> ra(0, 360);
	uniform_int_distribution<int> random_place(50, 550);

	PAINTSTRUCT ps;
	static RECT rt;
	static HDC hdc,memdc;
	static screen sc;
	switch (uMsg) {
	case WM_CREATE:
		
		GetClientRect(hwnd, &rt);
		SetTimer(hwnd, 1, 150, NULL);///1000/6010+5

		break;

	case WM_CHAR:

		break;

	case WM_KEYDOWN:
		sc.player_contral(wParam,0);
		break;
	case WM_KEYUP:
		sc.player_contral(wParam, 1);
		break;
	case WM_LBUTTONDOWN:

		break;
	case WM_TIMER:
		
		sc.animation();

		InvalidateRgn(hwnd, NULL, false);
		break;

	case WM_PAINT:
		GetClientRect(hwnd, &rt);

		hdc = BeginPaint(hwnd, &ps);

		sc.print_screen(hdc,&rt);
		
		EndPaint(hwnd, &ps);
		break;

	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hwnd, uMsg, wParam, lParam);

}