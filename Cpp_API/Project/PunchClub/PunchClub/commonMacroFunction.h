#pragma once
inline POINT PointMake(int x, int y)
{
	POINT pt = { x ,y };
	return pt;
}
//선그리는 함수
inline void LineMake(HDC hdc, int x1, int y1, int x2, int y2)
{
	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, x2, y2);
}
inline void LineMake(HDC hdc, POINT p1, POINT p2)
{
	MoveToEx(hdc, p1.x, p1.y, NULL);
	LineTo(hdc, p2.x, p2.y);
}
inline void ColorLine(HDC hdc, int x1, int y1, int x2, int y2, int width = 1, COLORREF color = RGB(1, 1, 1))
{
	// HPEN 생성하는 부분
	HPEN newPen = CreatePen(PS_SOLID, width, color);
	HPEN oldPen = (HPEN)SelectObject(hdc, newPen);
	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, x2, y2);
	// 브러시 해제하는 부분
	SelectObject(hdc, oldPen);
	DeleteObject(newPen);
}
//RECT만들기(좌상단 기준)
inline RECT RectMake(int x, int y, int width, int height)
{
	RECT rc = { x,y, x + width, y + height };
	return rc;
}
//RECT만들기(중심점으로 부터)
inline RECT RectMakeCenter(int x, int y, int width, int height)
{
	RECT rc = { x - width / 2, y - height / 2, x + width / 2, y + height / 2 };

	return rc;
}
inline RECT RectMakeRightBottom(int x, int y, int width, int height)
{
	RECT rc = { x - width, y - height, x, y };
	return rc;
}
//사각형 그리기
inline void RectangleMake(HDC hdc, int x, int y, int width, int height)
{
	Rectangle(hdc, x, y, x + width, y + height);
}
inline void RectangleMake(HDC hdc, RECT rect)
{
	Rectangle(hdc, rect.left, rect.top, rect.right, rect.bottom);
}
//사각형 그리기(중심점)
inline void RectangleMakeCenter(HDC hdc, int x, int y, int width, int height)
{
	Rectangle(hdc, x - (width / 2), y - (height / 2), x + (width / 2), y + (height / 2));
}
//사각형 그리기(Color)
inline void ColorRect(HDC hdc, RECT rc, COLORREF color = RGB(254,254,254))
{
	// 브러시 생성하는 부분
	HBRUSH rectBrush = (HBRUSH)CreateSolidBrush(color);
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, rectBrush);
	// 사각형 그리는 함수
	Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
	// 브러시 해제하는 부분
	SelectObject(hdc, oldBrush);
	DeleteObject(rectBrush);
}
// 빈 사각형 그리기 (Color)
inline void ColorFrameRect(HDC hdc, RECT rc, COLORREF color = RGB(254, 254, 254))
{
	// 브러시 생성하는 부분
	HBRUSH rectBrush = (HBRUSH)CreateSolidBrush(color);
	HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, rectBrush);
	// 사각형 그리는 함수
	FrameRect(hdc, &rc, rectBrush);
	// 브러시 해제하는 부분
	SelectObject(hdc, oldBrush);
	DeleteObject(rectBrush);
}
//원그리기
inline void EllipseMake(HDC hdc, int x, int y, int width, int height)
{
	Ellipse(hdc, x, y, x + width, y + height);
}
//원그리기(중심점)
inline void EllipseMakeCenter(HDC hdc, int x, int y, int width, int height)
{
	Ellipse(hdc, x - (width / 2), y - (height / 2), x + (width / 2), y + (height / 2));

}
// 글자 폰트 바꿔서 출력하는 함수
inline void FontTextOut(HDC hdc, int drawX, int drawY, const char * str,
	char * fontName, int fontSize = 20, COLORREF color = RGB(0, 0, 0))
{
	char * text = const_cast<char*>(str);
	// 글자의 색깔을 바꾸는 부분
	COLORREF oldTextColor = SetTextColor(hdc, color);
	// 글자의 폰트를 바꾸는 부분
	HFONT font = CreateFont(fontSize, 0, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET,
		0, 0, 0, 0, fontName);
	HFONT oldFont = (HFONT)SelectObject(hdc, font);
	// 배경을 투명하게 바꾸는 부분
	SetBkMode(hdc, TRANSPARENT);
	TextOut(hdc, drawX, drawY, text, strlen(text));
	// 바꿨던 글자 색깔을 해제하는 부분
	SetTextColor(hdc, oldTextColor);
	// 폰트를 해제하는 부분
	SelectObject(hdc, oldFont);
	DeleteObject(font);
}
// 그림자를 추가해주는 함수
inline void FontTextShadow(HDC hdc, int drawX, int drawY, const char * str,
	char * fontName, int fontSize = 20, COLORREF color = RGB(0, 0, 0))
{
	int shadow_move = (int)(fontSize * 0.1);
	FontTextOut(hdc, drawX + shadow_move, drawY + shadow_move, str, fontName, fontSize, RGB(1, 1, 1));
	FontTextOut(hdc, drawX, drawY, str, fontName, fontSize, color);
}
