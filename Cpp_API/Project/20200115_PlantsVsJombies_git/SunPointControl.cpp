#include "stdafx.h"
#include "SunPointControl.h"

// ================================================
// **				�޺� ��Ʈ��					 **
// ================================================
void SunPointControl::make_sunPoint()
{
	SunPoint * sunPoint = new SunPoint;
	sunPoint->init();
	sunPoint->init_rect();
	_sunPoints.push_back(sunPoint);
	sunPoint = nullptr;
}
void SunPointControl::delete_sunPointsAll()
{
	_itSunPoints = _sunPoints.begin();
	for (;_itSunPoints != _sunPoints.end();)
	{
		_itSunPoints = _sunPoints.erase(_itSunPoints);
	}
	swap(_sunPoints, vSunPoints_t());
}
void SunPointControl::update_sunPoints()
{
	_itSunPoints = _sunPoints.begin();
	for (;_itSunPoints != _sunPoints.end();_itSunPoints++)
	{
		(*_itSunPoints)->update();
	}
}
void SunPointControl::draw_sunPoints()
{
	_itSunPoints = _sunPoints.begin();
	for (;_itSunPoints != _sunPoints.end();_itSunPoints++)
	{
		(*_itSunPoints)->render();
	}
}
// ================================================
// **				����׿� �Լ�					 **
// ================================================
void SunPointControl::show_sunPointRects()
{
	_itSunPoints = _sunPoints.begin();
	for (;_itSunPoints != _sunPoints.end();_itSunPoints++)
	{
		(*_itSunPoints)->show_rect();
	}
}

SunPointControl::SunPointControl()
{
}
SunPointControl::~SunPointControl()
{
}

HRESULT SunPointControl::init()
{
	return S_OK;
}
void SunPointControl::release()
{
	delete_sunPointsAll();
}
void SunPointControl::update()
{
	update_sunPoints();

	if (KEYMANAGER->isOnceKeyDown(0x38))
	{
		make_sunPoint();
	}
}
void SunPointControl::render()
{
	draw_sunPoints();
}
