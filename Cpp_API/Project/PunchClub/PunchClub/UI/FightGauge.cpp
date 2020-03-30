#include "stdafx.h"
#include "FightGauge.h"

void FightGauge::init_player_bars()
{
	string path;
	POINT center, pos;
	path = _imgPath + "Player_bars.bmp";
	_player_back = new Image;
	_player_back->init(path.c_str(), (int)(253 * GAME_MULTIPLE), (int)(33 * GAME_MULTIPLE));
	center.x = (LONG)(0 + _player_back->get_width() * 0.6);
	center.y = (LONG)(_round_center.y - 10);
	_player_back_rc = RectMakeCenter(center.x, center.y,
		_player_back->get_width(), _player_back->get_height());
	// ========================================
	// ***		Player Hp bar				***
	// ========================================
	path = _imgPath + "hp_bar.bmp";
	_playerHp_fore = new Image;
	_playerHp_fore->init(path.c_str(), (int)(251 * GAME_MULTIPLE), (int)(18 * GAME_MULTIPLE));
	// 기준은 백 이미지의 left, top
	pos.x = (LONG)(_player_back_rc.left + 2);
	pos.y = (LONG)(_player_back_rc.top + 2);
	_playerHp_rc = RectMake(pos.x, pos.y, _playerHp_fore->get_width(), _playerHp_fore->get_height());
	// ========================================
	// ***		Player energy bar			***
	// ========================================
	path = _imgPath + "energy_bar.bmp";
	_playerNrg_fore = new Image;
	_playerNrg_fore->init(path.c_str(), (int)(139 * GAME_MULTIPLE), (int)(9 * GAME_MULTIPLE));
	// 기준은 백 이미지의 left, bottom
	pos.x = (LONG)(_player_back_rc.left + 2);
	pos.y = (LONG)(_player_back_rc.bottom - _playerNrg_fore->get_height() - 2);
	_playerNrg_rc = RectMake(pos.x, pos.y, _playerNrg_fore->get_width(), _playerNrg_fore->get_height());
}
void FightGauge::draw_player_bars()
{
	_player_back->render(get_memDC(), _player_back_rc.left, _player_back_rc.top);
	_playerHp_fore->render(get_memDC(), _playerHp_rc.left, _playerHp_rc.top);
	_playerNrg_fore->render(get_memDC(), _playerNrg_rc.left, _playerNrg_rc.top);
}
void FightGauge::update_player_bars()
{
}
void FightGauge::delete_player_bars()
{
}
void FightGauge::init_enemy_bars()
{
	string path;
	POINT center, pos;
	path = _imgPath + "Enemy_bars.bmp";
	_enemy_back = new Image;
	_enemy_back->init(path.c_str(), (int)(253 * GAME_MULTIPLE), (int)(33 * GAME_MULTIPLE));
	center.x = (LONG)(WINSIZEX - _enemy_back->get_width() * 0.6);
	center.y = (LONG)(_round_center.y - 10);
	_enemy_back_rc = RectMakeCenter(center.x, center.y,
		_enemy_back->get_width(), _enemy_back->get_height());
	// ========================================
	// ***		Enemy Hp bar				***
	// ========================================
	path = _imgPath + "hp_bar.bmp";
	_enemyHp_fore = new Image;
	_enemyHp_fore->init(path.c_str(), (int)(251 * GAME_MULTIPLE), (int)(18 * GAME_MULTIPLE));
	// 기준은 백 이미지의 right, top
	pos.x = (LONG)(_enemy_back_rc.right - _enemyHp_fore->get_width() - 2);
	pos.y = (LONG)(_enemy_back_rc.top + 2);
	_enemyHp_rc = RectMake(pos.x, pos.y, _enemyHp_fore->get_width(), _enemyHp_fore->get_height());
	// ========================================
	// ***		Enemy energy bar			***
	// ========================================
	path = _imgPath + "energy_bar.bmp";
	_enemyNrg_fore = new Image;
	_enemyNrg_fore->init(path.c_str(), (int)(139 * GAME_MULTIPLE), (int)(9 * GAME_MULTIPLE));
	// 기준은 백 이미지의 right, bottom
	pos.x = (LONG)(_enemy_back_rc.right - _enemyNrg_fore->get_width() - 2);
	pos.y = (LONG)(_enemy_back_rc.bottom - _enemyNrg_fore->get_height() - 2);
	_enemyNrg_rc = RectMake(pos.x, pos.y, _enemyNrg_fore->get_width(), _enemyNrg_fore->get_height());
}
void FightGauge::draw_enemy_bars()
{
	_enemy_back->render(get_memDC(), _enemy_back_rc.left, _enemy_back_rc.top);
	_enemyHp_fore->render(get_memDC(), _enemyHp_rc.left, _enemyHp_rc.top);
	_enemyNrg_fore->render(get_memDC(), _enemyNrg_rc.left, _enemyNrg_rc.top);
}
void FightGauge::update_enemy_bars()
{
}
void FightGauge::delete_enemy_bars()
{
	_enemy_back->release();
	_enemy_back = nullptr;
}

void FightGauge::init_round()
{
	string path;
	POINT center;
	path = _imgPath + "round_counter_back.bmp";
	_round_back = new Image;
	_round_back->init(path.c_str(), (int)(36 * GAME_MULTIPLE), (int)(36 * GAME_MULTIPLE));
	center.x = (LONG)(WIN_HALF_W);
	center.y = (LONG)(0 + _round_back->get_height() * 1);
	_round_back_rc = RectMakeCenter(center.x, center.y, 
		_round_back->get_width(), _round_back->get_height());
	path = _imgPath + "round_counter_full.bmp";
	_round_fore = new Image;
	_round_fore->init(path.c_str(), (int)(34 * GAME_MULTIPLE), (int)(34 * GAME_MULTIPLE));
	_round_fore_rc = RectMakeCenter(center.x, center.y,
		_round_fore->get_width(), _round_fore->get_height());
	_round_center = center;
	// 글씨
	_round_title = "라운드";
	_round_desc = "(총 10 라운드)";
	_round_num = "1";
}
void FightGauge::draw_round()
{
	_round_back->render(get_memDC(), _round_back_rc.left, _round_back_rc.top);
	FontTextOut(get_memDC(), _round_center.x - 10, _round_center.y - 12, _round_num.c_str(),
		"휴먼매직체", 35, RGB(254, 254, 254));
	FontTextOut(get_memDC(), _round_center.x - 25, _round_center.y - 50, _round_title.c_str(),
		"휴먼편지체", 25, RGB(253, 199, 56));
	FontTextOut(get_memDC(), _round_center.x - 55, _round_center.y + 25, _round_desc.c_str(),
		"휴먼편지체", 25, RGB(253, 199, 56));
}
void FightGauge::update_round()
{
}
void FightGauge::delete_round()
{
	_round_back->release();
	_round_back = nullptr;
	_round_fore->release();
	_round_fore = nullptr;
}

HRESULT FightGauge::init()
{
	set_imgPath("UI/Fight/");
	init_round();
	init_player_bars();
	init_enemy_bars();
	return S_OK;
}
void FightGauge::release()
{
	delete_round();
	delete_player_bars();
	delete_enemy_bars();
}
void FightGauge::update()
{
	update_round();
	update_player_bars();
	update_enemy_bars();
}
void FightGauge::render()
{
	draw_round();
	draw_player_bars();
	draw_enemy_bars();
}
FightGauge::FightGauge()
{
}
FightGauge::~FightGauge()
{
}