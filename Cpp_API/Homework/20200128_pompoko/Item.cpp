#include "stdafx.h"
#include "Item.h"

void Item::init_rect(LONG x, LONG y)
{
	_rect = RectMake(x, y, _width, _height);
}
void Item::show_rect()
{
	FrameRect(getMemDC(), &_rect,
		CreateSolidBrush(RGB(255, 255, 255)));
}

Item::Item()
{
}
Item::~Item()
{
}
HRESULT Item::init()
{
	return S_OK;
}
void Item::release()
{
	_img = nullptr;
}
void Item::update()
{
}
void Item::render()
{
}
