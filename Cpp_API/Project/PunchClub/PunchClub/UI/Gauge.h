#pragma once
#include "UI.h"
class Gauge: public UI
{
private:
	GAUGE::TYPE _type;
	Image * _bg = nullptr;
	Image * _fg = nullptr;
	double _maxGauge;
	double _currentGauge = 0;
	double _currentWidth = 0;
	bool _fGaugeStart = false;
protected:
	void change_width();
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
public:
	Gauge(GAUGE::TYPE type);
	~Gauge();
public:
	void set_center(POINT center);
	int get_width() { return _bg->get_width(); }
	int get_height() { return _bg->get_height(); }
};

