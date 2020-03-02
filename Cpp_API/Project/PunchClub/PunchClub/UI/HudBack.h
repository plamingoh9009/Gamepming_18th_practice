#pragma once
#include "UI.h"
class HudBack: public UI
{
private:
	Image * _hud_back;
	RECT _hud_back_rc;
	POINT _hud_back_center;
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
public:
	HudBack();
	~HudBack();
};

