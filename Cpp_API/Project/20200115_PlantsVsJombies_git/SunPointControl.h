#pragma once
#include "gameNode.h"
#include "SunPoint.h"
class SunPointControl: public gameNode
{
private:
	// SunPoint บคลอ
	typedef vector<SunPoint *> vSunPoints_t;
private:
	vSunPoints_t _sunPoints;
	vSunPoints_t::iterator _itSunPoints;
protected:
	void make_sunPoint();
	void delete_sunPointsAll();
	void update_sunPoints();
	void draw_sunPoints();
public:
	void show_sunPointRects();
public:
	SunPointControl();
	~SunPointControl();
	HRESULT init();
	void release();
	void update();
	void render();
};

