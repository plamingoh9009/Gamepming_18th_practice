#pragma once
#include "Scene.h"
#include "UI/InGameUI.h"
#include "UI/PrefightStat.h"
class LeagueWaitingScene: public Scene
{
private:
	Image * _bg;
	// Prefight Window
	PrefightStat * _playerStat;
	PrefightStat * _enemyStat;
	Image * _pfWindow;
	Image * _pfVs;
	RECT _player_window_rc;
	RECT _enemy_window_rc;
	RECT _pfVs_rc;
	POINT _vs_center;
	POINT _player_window_center;
	POINT _enemy_window_center;
	// Prefight Picture
	Image * _player;
	Image * _enemy;
	RECT _player_rc;
	RECT _enemy_rc;
	// Button
	Button * _fight_button;
protected:
	void init_prefight_window();
	void draw_prefight_window();
	void delete_prefight_window();
	void init_picture();
	void draw_picture();
	void update_picture();
	void delete_picture();
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
public:
	LeagueWaitingScene();
	~LeagueWaitingScene();
};

