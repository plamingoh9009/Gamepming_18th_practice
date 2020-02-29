#pragma once
#include "UI.h"
class Icon: public UI
{
private:
	Image * _hud;
	Image * _skillTree;
	Image * _league;
	RECT _hud_rc;
	RECT _skillTree_rc;
	RECT _league_rc;
	POINT _icon_center;
protected:
	void init_icons();
	void draw_icons();
	void delete_icons();
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
public:
	Icon();
	~Icon();
};

