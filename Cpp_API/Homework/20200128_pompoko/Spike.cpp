#include "stdafx.h"
#include "Spike.h"


Spike::Spike()
{
}
Spike::~Spike()
{
}
HRESULT Spike::init()
{
	_width = 24;
	_height = 24;
	_type = "Spike";
	if (IMAGEMANAGER->findImage(_type))
	{
		_img = IMAGEMANAGER->findImage(_type);
	}
	else
	{
		_img = IMAGEMANAGER->addImage(_type,
			"images/Spike.bmp", _width, _height, true, COLOR_MAGENTA);
	}
	return S_OK;
}
void Spike::release()
{
}
void Spike::update()
{
}
void Spike::render()
{
	_img->render(getMemDC(), _rect.left, _rect.top);
}
