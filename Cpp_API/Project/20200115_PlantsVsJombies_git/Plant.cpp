#include "stdafx.h"
#include "Plant.h"

RECT Plant::make_oneFrameRect()
{
	int x = _rect.left;
	int y = _rect.top;
	int width = _img->getFrameWidth();
	int height = _img->getFrameHeight();
	RECT oneFrameRect = RectMake(x, y, width, height);
	return oneFrameRect;
}

void Plant::show_plantRect()
{
	// 설치된 공간을 출력
	FrameRect(getMemDC(), &_plantPoint, RGB(0, 0, 0));
	// 객체의 한 프레임을 출력
	FrameRect(getMemDC(), &_oneFrameRect, CreateSolidBrush(RGB(0, 0, 255)));
}
void Plant::move_plant(LONG x, LONG y)
{
	_rect.left = x;
	_rect.top = y;
	_rect.right = x + _width;
	_rect.bottom = y + _height;
	_oneFrameRect = make_oneFrameRect();
}
void Plant::follow_mouseMove()
{
	_rect.left = m_ptMouse.x;
	_rect.top = m_ptMouse.y;
	_oneFrameRect = make_oneFrameRect();
}
void Plant::run_frameImg()
{
	// 여기서 프레임을 돌린다.
	_frameCount++;
	if (_frameCount >= _frameDelay)
	{
		_currentFrameX++;
		if (_currentFrameX >= _maxFrameX) { _currentFrameX = 0; }
		_frameCount = 0;
	}
}

bool Plant::is_plantInRect(RECT rect)
{
	RECT temp;
	if (IntersectRect(&temp, &rect, &_plantPoint))
	{
		return true;
	}
	return false;
}

void Plant::set_plantPoint(RECT plantPoint)
{
	_plantPoint = plantPoint;
}
void Plant::set_plant(string strKey, int x, int y)
{
	_img = IMAGEMANAGER->findImage(strKey);
	_currentFrameX = 0;
	_currentFrameY = 0;
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
		_frameDelay = 4;
		_maxFrameX = 8;
		_maxFrameY = 1;
		_width = 432;
		_height = 36;
		_rect = RectMake(x, y, _width / _maxFrameX, _height / _maxFrameY);
	}//if: PeaShooter는 width 54, height 36
	// 식물 한 프레임 정보를 초기화
	_oneFrameRect = make_oneFrameRect();
}

Plant::Plant()
{
}
Plant::~Plant()
{
}
HRESULT Plant::init()
{
	IMAGEMANAGER->addFrameImage("SunFlower",
		"images/plants/SunFlower_Idle.bmp",
		232, 32, 8, 1, true, COLOR_MAGENTA);
	IMAGEMANAGER->addFrameImage("Wallnut",
		"images/plants/Wallnut_Idle.bmp",
		135, 32, 5, 1, true, COLOR_MAGENTA);
	IMAGEMANAGER->addFrameImage("PeaShooter",
		"images/plants/PeaShooter_Idle.bmp",
		432, 36, 8, 1, true, COLOR_MAGENTA);
	// 마우스를 따라갈지 정하는 변수
	_fMouseFollow = false;
	return S_OK;
}
void Plant::release()
{
	_img = nullptr;
}
void Plant::update()
{
	if (_fMouseFollow == true)
	{
		follow_mouseMove();
	}//if: 마우스를 따라간다.
	else
	{
		run_frameImg();
	}
}
void Plant::render()
{
	IMAGEMANAGER->frameRender(_type, getMemDC(), _rect.left, _rect.top,
		_currentFrameX, _currentFrameY);
}
