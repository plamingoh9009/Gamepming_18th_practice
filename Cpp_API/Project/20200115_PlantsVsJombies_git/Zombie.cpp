#include "stdafx.h"
#include "Zombie.h"


void Zombie::init_zombiePosition()
{
}

Zombie::Zombie()
{
}
Zombie::~Zombie()
{
}

HRESULT Zombie::init()
{
	_img = IMAGEMANAGER->addFrameImage("Zombie",
		"images/zombies/Zombie_Walk.bmp", 2844, 190,
		12, 1, true, COLOR_MAGENTA);
	_width = 2844;
	_height = 190;
	_maxFrameX = 12;
	_maxFrameY = 1;
	// 프레임 돌릴 정보
	_currentFrameX = 0;
	_currentFrameY = 0;
	_frameDelay = 8;
	_frameCount = 0;
	// 좀비 초기 위치
	_rect.left = 100;
	_rect.top = 100;
	_rect.right = _width / _maxFrameX;
	_rect.bottom = _height / _maxFrameY;
	return S_OK;
}
void Zombie::release()
{
	_img = nullptr;
}
void Zombie::update()
{
	_frameCount++;
	if (_frameCount >= _frameDelay)
	{
		_currentFrameX++;
		if(_currentFrameX >= _maxFrameX)
		{
			_currentFrameX = 0;
		}
		_frameCount = 0;
	}
}
void Zombie::render()
{
	IMAGEMANAGER->frameRender("Zombie", getMemDC(),
		_rect.left, _rect.top, _currentFrameX, _currentFrameY);
}
