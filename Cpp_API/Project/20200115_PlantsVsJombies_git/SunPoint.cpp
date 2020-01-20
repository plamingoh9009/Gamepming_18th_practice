#include "stdafx.h"
#include "SunPoint.h"

void SunPoint::move_defaultMove()
{
	_fallCount++;
	if (_fallCount >= _fallDelay)
	{
		if (_distance > 0)
		{
			_rect.top += _fallSpeed;
			_rect.bottom += _fallSpeed;
			_distance--;
		}
		_fallCount = 0;
	}
}
void SunPoint::show_rect()
{
	FrameRect(getMemDC(), &_rect,
		CreateSolidBrush(RGB(255, 255, 0)));
}
void SunPoint::init_rect()
{
	// x, y 범위는 라인 4개정도 범위 700, 380 정도
	// 초기 위치는 138, 94
	int x = RND->getFromIntTo(138 - (_width/2), 138 + 700 - (_width/2));
	int y = RND->getFromIntTo(94 - (_height/2), 94 + 380 - (_height/2));
	_rect = RectMake(x, y, _width, _height);
}

SunPoint::SunPoint()
{
}
SunPoint::~SunPoint()
{
}
HRESULT SunPoint::init()
{
	_width = 100;
	_height = 100;
	_img = IMAGEMANAGER->addImage("SunPoint",
		"images/SunPoint.bmp", _width, _height, true, COLOR_MAGENTA);
	// 해가 떨어질 때 쓰는 변수
	_fallCount = 0;
	_fallDelay = 8;
	_fallSpeed = 3;
	return S_OK;
}
void SunPoint::release()
{
	_img = nullptr;
}
void SunPoint::update()
{
	move_defaultMove();
}
void SunPoint::render()
{
	IMAGEMANAGER->render("SunPoint", getMemDC(), _rect.left, _rect.top);
}
