#include "DrawName.h"



void DrawName::draw_name(HDC hdc, int x, int y)
{
	// "이" 를 그리는 곳
	Ellipse(hdc, x, y + 1, x + 10, y + 16 + 1);
	x = x + 10 + 3;
	MoveToEx(hdc, x, y, NULL);
	LineTo(hdc, x, y + 20);

	// "대" 를 그리는 곳
	x = x + 10 + 4;
	MoveToEx(hdc, x, y + 3, NULL);
	LineTo(hdc, x - 8, y + 3);
	LineTo(hdc, x - 8, y + 12 + 3);
	LineTo(hdc, x + 1, y + 12 + 3);

	x = x + 3;
	MoveToEx(hdc, x, y, NULL);
	LineTo(hdc, x, y + 20);
	MoveToEx(hdc, x, y + 10, NULL);
	LineTo(hdc, x + 4, y + 10);
	x = x + 3;
	MoveToEx(hdc, x, y, NULL);
	LineTo(hdc, x, y + 20);

	// "연" 을 그리는 곳
	x = x + 5;
	Ellipse(hdc, x, y + 1, x + 8, y + 12 + 1);

	x = x + 8 + 2;
	MoveToEx(hdc, x, y + 3, NULL);
	LineTo(hdc, x + 4, y + 3);
	MoveToEx(hdc, x, y + 6, NULL);
	LineTo(hdc, x + 4, y + 6);
	MoveToEx(hdc, x + 4, y, NULL);
	LineTo(hdc, x + 4, y + 13);

	x = x - 4;
	MoveToEx(hdc, x, y + 12 + 1 + 2, NULL);
	LineTo(hdc, x, y + 12 + 1 + 2 + 4);
	LineTo(hdc, x + 10, y + 12 + 1 + 2 + 4);
}

DrawName::DrawName()
{
}


DrawName::~DrawName()
{
}
