#include "stdafx.h"
#include "Unit.h"


void Unit::init_rect(int x, int y)
{
	_rect.left = x;
	_rect.top = y;
	_rect.right = x + _width;
	_rect.bottom = y + _height;
}
void Unit::show_rect()
{
	FrameRect(getMemDC(), &_rect,
		CreateSolidBrush(RGB(255, 255, 255)));
}

Unit::Unit()
{
}
Unit::~Unit()
{
}

HRESULT Unit::init()
{
	return S_OK;
}

void Unit::release()
{
}

void Unit::update()
{
}

void Unit::render()
{
}
