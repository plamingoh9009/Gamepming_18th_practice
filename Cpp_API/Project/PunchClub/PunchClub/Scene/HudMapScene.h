#pragma once
#include "Scene.h"
class HudMapScene: public Scene
{
private:
	Image * _bg;
	// æ∆¿Ãƒ‹
	Image * _player;
	RECT _player_rc;
	POINT _player_center;
	Image * _home;
	RECT _home_rc;
	POINT _home_center;
	Image * _home_select;
	Image * _gym;
	RECT _gym_rc;
	POINT _gym_center;
	Image * _gym_select;
	Image * _shop;
	RECT _shop_rc;
	POINT _shop_center;
	Image * _shop_select;
protected:
	void init_player_pos();
	void init_background();
	void draw_background();
	void delete_background();
	void init_map_icons();
	void draw_map_icons();
	void delete_map_icons();
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
public:
	HudMapScene();
	~HudMapScene();
};

