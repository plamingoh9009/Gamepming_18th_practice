#include "stdafx.h"
#include "SeedBank.h"


SeedBank::SeedBank()
{
}
SeedBank::~SeedBank()
{
}

HRESULT SeedBank::init()
{
	_rect = RectMake(20, 0, 446, 87);
	_img = IMAGEMANAGER->addImage("SeedBank", "images/SeedBank.bmp",
		_rect.right - _rect.left, _rect.bottom - _rect.top, false, COLOR_MAGENTA);
	return S_OK;
}
void SeedBank::release()
{
	IMAGEMANAGER->deleteImage("SeedBank");
}
void SeedBank::update()
{
}
void SeedBank::render()
{
	if (KEYMANAGER->isToggleKey(VK_TAB)) {}
	else
	{
		IMAGEMANAGER->render("SeedBank", getMemDC(), _rect.left, _rect.top);
	}
}
