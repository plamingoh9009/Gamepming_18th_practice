#include "stdafx.h"
#include "Carrot.h"

Carrot::Carrot()
{
}
Carrot::~Carrot()
{
}
HRESULT Carrot::init()
{
	_width = 50;
	_height = 48;
	_type = "Carrot";
	if (IMAGEMANAGER->findImage(_type))
	{
		_img = IMAGEMANAGER->findImage(_type);
	}
	else
	{
		_img = IMAGEMANAGER->addImage(_type,
			"images/Carrot.bmp", _width, _height, true, COLOR_MAGENTA);
	}
	_fDebug = false;
	return S_OK;
}
void Carrot::release()
{
}
void Carrot::update()
{
}
void Carrot::render()
{
	_img->render(getMemDC(), _rect.left, _rect.top);
}
