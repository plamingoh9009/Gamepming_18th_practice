#include "stdafx.h"
#include "Gauge.h"

void Gauge::change_width()
{
	double temp = (double)(_currentGauge / _maxGauge * _fg->get_width());
	_currentWidth = (int)(temp);
}

HRESULT Gauge::init()
{
	set_imgPath("UI/Gauge/");
	string path;
	switch (_type)
	{
	case GAUGE::GG_WORK:
		_bg = new Image;
		path = _imgPath + "work_pb_back.bmp";
		_bg->init(path.c_str(), (int)(223 * GAME_MULTIPLE), (int)(20 * GAME_MULTIPLE));
		_fg = new Image;
		path = _imgPath + "work_pb.bmp";
		_fg->init(path.c_str(), (int)(223 * GAME_MULTIPLE), (int)(20 * GAME_MULTIPLE));
		_maxGauge = 100;
		break;
	}
	return S_OK;
}
void Gauge::release()
{
	Release(_bg);
	Release(_fg);
}
void Gauge::update()
{
	switch (_type)
	{
	case GAUGE::GG_WORK:
		change_width();
		break;
	}
}
void Gauge::render()
{
	Draw(_bg, get_memDC());
	if (_fg != nullptr)
	{
		_fg->render(get_memDC(), _fg->get_rect().left, _fg->get_rect().top,
			0, 0, (int)(_currentWidth), _fg->get_height());
	}
}
Gauge::Gauge(GAUGE::TYPE type)
{
	_type = type;
}
Gauge::~Gauge()
{
}

void Gauge::set_center(POINT center)
{
	if (_bg != nullptr)
	{
		_bg->set_center(center);
	}
	if (_fg != nullptr)
	{
		_fg->set_center(center);
	}
}
