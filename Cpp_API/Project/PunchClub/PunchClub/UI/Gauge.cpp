#include "stdafx.h"
#include "Gauge.h"
#include "Object/Player.h"
void Gauge::run_gauge()
{
	// ���� �ð��� �ְ�, �������� �ø���.
	_time += TIMEMANAGER->get_elapsedTime();
	if (1.0f <= _time)
	{
		if (_currentGauge < _maxGauge)
		{
			_currentGauge += _gaugeSpeed;
		}
		// ������ value�� width ���� �����Ѵ�.
		sync_gauge_fromValue();

		_time = 0;	// �ð��� �ʱ�ȭ
	}

	if (_currentGauge == _maxGauge)
	{
		_currentGauge = 0;
		action();
	}//if: �� �������� ������ �ǵ�����.
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
		value = _maxGauge;
	}
	gaugeWidth = _fg->get_width();
	temp = (value / _maxGauge) * gaugeWidth;
	// ����� ������ ���� ����
	_currentWidth = temp;
}

void Gauge::action()
{
	switch (_type)
	{
	case GAUGE::GG_WORK:
		PLAYER->add_money(50);
		break;
	}
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
		_gaugeSpeed = 80;
		break;
	case GAUGE::GG_STAT_SMALL:
		_fg = new Image;
		path = _imgPath + "hud_bar_small.bmp";
		_fg->init(path.c_str(), (int)(51 * GAME_MULTIPLE), (int)(6 * GAME_MULTIPLE));
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
		if (_fGaugeRun == true)
		{
			run_gauge();
		}
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

void Gauge::start()
{
	_fGaugeRun = true;
}

void Gauge::pause()
{
	_fGaugeRun = false;
}
