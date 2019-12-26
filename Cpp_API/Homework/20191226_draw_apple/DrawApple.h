#pragma once
#include <Windows.h>

class DrawApple
{
private:
	int _xLeaf, _yLeaf;
	int _xGreen, _yGreen;
public:
	void draw_leaf(HDC, int, int);
	void draw_green(HDC, int, int);
	void draw_yello(HDC, int, int);
	void draw_orenge(HDC, int, int);
	void draw_red(HDC, int, int);
	void draw_purple(HDC, int, int);
	void draw_blue(HDC, int, int);
public:
	DrawApple();
	~DrawApple();
};

