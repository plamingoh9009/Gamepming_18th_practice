#pragma once
#include "UI.h"

class Icon: public UI
{
private:
	enum ICON_TYPE
	{
		ICON_EMPTY,
		ICON_HUD_MAP,
		ICON_LEAGUE,
		ICON_SKILLTREE
	};
private:
	Image * _icon_btn_back;
	Image * _hud_map;
	Image * _skillTree;
	Image * _league;
	RECT _hud_map_rc;
	RECT _hud_map_back_rc;
	RECT _skillTree_rc;
	RECT _skillTree_back_rc;
	RECT _league_rc;
	RECT _league_back_rc;
	POINT _icon_center;
protected:
	void init_icons();
	void draw_icons();
	void delete_icons();
	void select_icons(ICON_TYPE type);
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
public:
	Icon();
	~Icon();
};

