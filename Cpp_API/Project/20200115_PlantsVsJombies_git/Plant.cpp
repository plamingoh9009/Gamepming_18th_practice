#include "stdafx.h"
#include "Plant.h"

void Plant::set_plant(string strKey, int x, int y)
{
	_img = IMAGEMANAGER->findImage(strKey);
	_currentFrameX = 0;
	_currentFrameY = 0;
	_img->setFrameX(_currentFrameX);
	_img->setFrameY(_currentFrameY);
	_frameCount = 0;
	_type = strKey;
	if (_type.compare("SunFlower") == 0)
	{
		_frameDelay = 8;
		_maxFrameX = 8;
		_maxFrameY = 1;
		_width = 232;
		_height = 32;
		_rect = RectMake(x, y, _width / _maxFrameX, _height / _maxFrameY);
	}//if: SunFlower는 width 29, height 32
	else if (_type.compare("Wallnut") == 0)
	{
		_frameDelay = 8;
		_maxFrameX = 5;
		_maxFrameY = 1;
		_width = 135;
		_height = 32;
		_rect = RectMake(x, y, _width / _maxFrameX, _height / _maxFrameY);
	}//if: Wallnut은 width 27, height 32
	else if (_type.compare("PeaShooter") == 0)
	{
		_frameDelay = 8;
		_maxFrameX = 8;
		_maxFrameY = 1;
		_width = 432;
		_height = 36;
		_rect = RectMake(x, y, _width / _maxFrameX, _height / _maxFrameY);
	}//if: PeaShooter는 width 54, height 36
}

Plant::Plant()
{
}
Plant::~Plant()
{
}
HRESULT Plant::init()
{
	IMAGEMANAGER->addFrameImage("SunFlower", "images/SunFlower_Idle.bmp",
		232, 32, 8, 1, true, COLOR_MAGENTA);
	IMAGEMANAGER->addFrameImage("Wallnut", "images/Wallnut_Idle.bmp",
		135, 32, 5, 1, true, COLOR_MAGENTA);
	IMAGEMANAGER->addFrameImage("PeaShooter", "images/PeaShooter_Idle.bmp",
		432, 36, 8, 1, true, COLOR_MAGENTA);
	return S_OK;
}
void Plant::release()
{
	_img = nullptr;
}
void Plant::update()
{
	// 여기서 프레임을 돌린다.
	_frameCount++;
	if (_frameCount >= _frameDelay)
	{
		_currentFrameX++;
		if (_currentFrameX >= _maxFrameX) { _currentFrameX = 0; }
		else
		{
			_img->setFrameX(_currentFrameX);
		}
		_frameCount = 0;
	}
}
void Plant::render()
{
	IMAGEMANAGER->frameRender(_type, getMemDC(), _rect.left, _rect.top,
		_img->getFrameX(), _img->getFrameY());
}
