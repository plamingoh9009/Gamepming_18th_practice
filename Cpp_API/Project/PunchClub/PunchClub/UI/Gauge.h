#pragma once
#include "UI.h"
class Gauge: public UI
{
	// 라운드 이미지
	Image * _round_back;
	Image * _round_fore;
	POINT _round_center;
	RECT _round_back_rc;
	RECT _round_fore_rc;
	string _round_title;
	string _round_desc;
	string _round_num;
	// 싸울때 쓰는 게이지
	Image * _player_back;
	Image * _playerHp_fore;
	Image * _playerNrg_fore;
	Image * _enemy_back;
	Image * _enemyHp_fore;
	Image * _enemyNrg_fore;
	RECT _player_back_rc;
	RECT _playerHp_rc;
	RECT _playerNrg_rc;
	RECT _enemy_back_rc;
	RECT _enemyHp_rc;
	RECT _enemyNrg_rc;
	string _playerHp_str;
	string _playerNrg_str;
	string _enemyHp_str;
	string _enemyNrg_str;
protected:
	void init_player_bars();
	void draw_player_bars();
	void update_player_bars();
	void delete_player_bars();
	void init_enemy_bars();
	void draw_enemy_bars();
	void update_enemy_bars();
	void delete_enemy_bars();
	void init_round();
	void draw_round();
	void update_round();
	void delete_round();
public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();
public:
	Gauge();
	~Gauge();
};

