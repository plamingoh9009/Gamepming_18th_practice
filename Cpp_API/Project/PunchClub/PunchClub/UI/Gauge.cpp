#include "stdafx.h"
#include "Gauge.h"
#include "Object/Player.h"

void Gauge::init_fight_stat()
{
	string path;
	switch (_statType)
	{
	case GAUGE::ST_STR:
		_fg = new Image;
		path = _imgPath + "bar_str.bmp";
		_fg->init(path.c_str(), (int)(53 * GAME_MULTIPLE), (int)(14 * GAME_MULTIPLE));
		break;
	case GAUGE::ST_AGL:
		_fg = new Image;
		path = _imgPath + "bar_agl.bmp";
		_fg->init(path.c_str(), (int)(53 * GAME_MULTIPLE), (int)(14 * GAME_MULTIPLE));
		break;
	case GAUGE::ST_STM:
		_fg = new Image;
		path = _imgPath + "bar_stm.bmp";
		_fg->init(path.c_str(), (int)(53 * GAME_MULTIPLE), (int)(14 * GAME_MULTIPLE));
		break;
	}
}

void Gauge::action()
{
	switch (_type)
	{
	case GAUGE::GG_WORK:
		PLAYER->add_money(50);
		PLAYER->action_init();
		break;
	case GAUGE::GG_STAT_SMALL:
		PLAYER->action_init();
		break;
	}
}
void Gauge::run_gauge()
{
	// 일정 시간을 주고, 게이지를 올린다.
	_time += TIMEMANAGER->get_elapsedTime();
	if (1.0f <= _time)
	{
		if (_currentGauge < _maxGauge)
		{
			_currentGauge += _gaugeSpeed;
		}
		// 게이지 value로 width 값을 정의한다.
		sync_gauge_fromValue();

		_time = 0;	// 시간을 초기화
	}

	if (_currentGauge >= _maxGauge)
	{
		_currentGauge = 0;
		action();
	}//if: 현 게이지가 꽉차면 되돌린다.
}

double Gauge::limit_value(double value, bool fZeroSet)
{
	if (value < 0)
	{
		return 0.0;
	}
	else if (value > 1000)
	{
		if (fZeroSet)
		{
			return 0.0;
		}
		else
		{
			return 1000.0;
		}
	}
	return value;
}

void Gauge::sync_gauge_fromValue()
{
	sync_gauge_fromValue(_currentGauge);
}
void Gauge::sync_gauge_fromValue(double value)
{
	double temp;
	double gaugeWidth;

	if (value > _maxGauge)
	{
		action();
	}
	value = limit_value(value);
	gaugeWidth = _fg->get_width();
	temp = (value / _maxGauge) * gaugeWidth;
	// 출력할 게이지 값을 정의
	_currentWidth = temp;
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
		sync_gauge_fromValue(PLAYER->get_stat().workGauge);
		PLAYER->set_playerAction(PLAYER_SET::ACTION_WORK);
		break;
	case GAUGE::GG_STAT_SMALL:
		_fg = new Image;
		path = _imgPath + "hud_bar_small.bmp";
		_fg->init(path.c_str(), (int)(51 * GAME_MULTIPLE), (int)(6 * GAME_MULTIPLE));
		break;
	case GAUGE::GG_STAT_FIGHT:
		init_fight_stat();
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
		sync_gauge_fromValue(PLAYER->get_stat().workGauge);
		break;
	default:
		sync_gauge_fromValue();
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
Gauge::Gauge(GAUGE::STAT statType)
{
	_type = GAUGE::GG_STAT_FIGHT;
	_statType = statType;
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

POINT Gauge::get_center()
{
	if (_fg != nullptr)
	{
		return _fg->get_center();
	}
	return POINT();
}

void Gauge::start()
{
	_fGaugeRun = true;
	PLAYER->action_start();
}

void Gauge::pause()
{
	_fGaugeRun = false;
	PLAYER->action_pause();
}
