#include "stdafx.h"
#include "Jar.h"

Jar::Jar()
{
}
Jar::~Jar()
{
}
HRESULT Jar::init()
{
	_width = 50;
	_height = 50;
	_type = "Jar";
	if (IMAGEMANAGER->findImage(_type))
	{
		_img = IMAGEMANAGER->findImage(_type);
	}
	else
	{
		_img = IMAGEMANAGER->addImage(_type,
			"images/Jar.bmp", _width, _height, true, COLOR_MAGENTA);
	}
	return S_OK;
}
void Jar::release()
{
}
void Jar::update()
{
}
void Jar::render()
{
	_img->render(getMemDC(), _rect.left, _rect.top);
}
