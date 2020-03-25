#pragma once
#include "Gauge.h"
#include "Icons/Icon.h"
class HudBack: public UI
{
private:
	typedef vector<Gauge *> Gauges;
private:
	Image * _hud_back;
	// Gauges
	Gauges _hud_gauges;
	Gauge * _health;
	Gauge * _food;
	Gauge * _mood;
	Gauge * _energy;
	
	Gauge * _str;
	Gauge * _agl;
	Gauge * _stm;
	// Icons
	Icon * _icon_str;
	Icon * _icon_agl;
	Icon * _icon_stm;
	// Money
	MyText _money;
	MyText _skillPoint;
protected:
	string Stat(double stat);
	double Exp(double stat);
protected:
	HRESULT init_gauges();
	void delete_gauges();
	void draw_gauges();
	void update_gauges();
	HRESULT init_icons();
	void delete_icons();
	void draw_icons();
	virtual void update();
public:
	void update_datas_fromPlayer();
public:
	virtual HRESULT init();
	virtual void release();
	virtual void render();
public:
	HudBack();
	~HudBack();
};

