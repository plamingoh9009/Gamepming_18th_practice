#include "stdafx.h"
#include "FlagMeter.h"


FlagMeter::FlagMeter()
{
}
FlagMeter::~FlagMeter()
{
}

HRESULT FlagMeter::init()
{
	_rect = RectMake(694, 568, 158, 54);
	_img = IMAGEMANAGER->addFrameImage("FlagMeter", "images/FlagMeter.bmp",
		_rect.right - _rect.left, _rect.bottom - _rect.top, 1, 2, true, COLOR_MAGENTA);
	_img->setFrameX(0);
	_img->setFrameY(0);
	return S_OK;
}

void FlagMeter::release()
{
	IMAGEMANAGER->deleteImage("FlagMeter");
}

void FlagMeter::update()
{
}

void FlagMeter::render()
{
	if (KEYMANAGER->isToggleKey(VK_TAB)) {}
	else
	{
		IMAGEMANAGER->frameRender("FlagMeter", getMemDC(), 
			_rect.left, _rect.top,
			_img->getFrameX(), _img->getFrameY());
	}//else: 탭키를 안눌렀을때 보여준다.
}
