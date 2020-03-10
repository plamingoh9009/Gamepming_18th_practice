#include "stdafx.h"
#include "LeagueWaitingScene.h"


void LeagueWaitingScene::init_prefight_window()
{
	string path;
	POINT center;
	path = _imgPath + "prefight_vs.bmp";
	_pfVs = new Image;
	_pfVs->init(path.c_str(), (int)(46 * GAME_MULTIPLE), (int)(34 * GAME_MULTIPLE));
	center.x = (LONG)(WIN_HALF_W);
	center.y = (LONG)(WIN_HALF_H - _pfVs->get_height());
	_pfVs_rc = RectMakeCenter(center.x, center.y, _pfVs->get_width(), _pfVs->get_height());
	_vs_center = center;
	// Window Image
	path = _imgPath + "prefight_window.bmp";
	_pfWindow = new Image;
	_pfWindow->init(path.c_str(), (int)(102 * GAME_MULTIPLE), (int)(108 * GAME_MULTIPLE));
	// Player Side
	center.x = (LONG)(_vs_center.x - _pfWindow->get_width());
	_player_window_rc = RectMakeCenter(center.x, center.y,
		_pfWindow->get_width(), _pfWindow->get_height());
	_player_window_center = center;
	center.x = (LONG)(center.x - _pfWindow->get_width() * 1.375);
	_playerStat = new PrefightStat;
	_playerStat->init();
	_playerStat->set_window(center, "Player");
	_playerStat->set_stat(1, 1, 1);
	// Enemy Side
	center.x = (LONG)(_vs_center.x + _pfWindow->get_width() - 5);
	_enemy_window_rc = RectMakeCenter(center.x, center.y,
		_pfWindow->get_width(), _pfWindow->get_height());
	_enemy_window_center = center;
	center.x = (LONG)(center.x + _pfWindow->get_width() * 1.375 + 5);
	_enemyStat = new PrefightStat;
	_enemyStat->init();
	_enemyStat->set_window(center, "Enemy", false);
	_enemyStat->set_stat(1, 1, 1);
}
void LeagueWaitingScene::draw_prefight_window()
{
	_pfVs->render(get_memDC(), _pfVs_rc.left, _pfVs_rc.top);
	_pfWindow->render(get_memDC(), _player_window_rc.left, _player_window_rc.top);
	_pfWindow->render(get_memDC(), _enemy_window_rc.left, _enemy_window_rc.top);
	_playerStat->render();
	_enemyStat->render();
	if (_fDebug)
	{
		ColorRect(get_memDC(), _pfVs_rc);
		ColorRect(get_memDC(), _player_window_rc);
		ColorRect(get_memDC(), _enemy_window_rc);
	}
}
void LeagueWaitingScene::delete_prefight_window()
{
	_pfVs->release();
	_pfVs = nullptr;
	_pfWindow->release();
	_pfWindow = nullptr;
	_playerStat->release();
	_playerStat = nullptr;
	_enemyStat->release();
	_enemyStat = nullptr;
}

void LeagueWaitingScene::init_picture()
{
	set_imgPath("League/");
	string path = _imgPath + "player_fight_idle.bmp";
	_player = new Image;
	_player->init(path.c_str(), (int)(126 * GAME_MULTIPLE), (int)(75 * GAME_MULTIPLE), 3, 1);
	_player_rc = RectMakeCenter(
		_player_window_center.x, _player_window_center.y,
		_player->get_frameWidth(), _player->get_frameHeight());
	_player->set_frameSection(1, 0, 2, 0.25f);
	path = _imgPath + "enemyA_fight_idle.bmp";
	_enemy = new Image;
	_enemy->init(path.c_str(), (int)(126 * GAME_MULTIPLE), (int)(75 * GAME_MULTIPLE), 3, 1);
	_enemy_rc = RectMakeCenter(
		_enemy_window_center.x, _enemy_window_center.y,
		_enemy->get_frameWidth(), _enemy->get_frameHeight());
	_enemy->set_frameSection(1, 2, 0, 0.3f);
}
void LeagueWaitingScene::draw_picture()
{
	_player->frameRender(get_memDC(), _player_rc.left, _player_rc.top);
	_enemy->frameRender(get_memDC(), _enemy_rc.left, _enemy_rc.top);
}
void LeagueWaitingScene::update_picture()
{
	_player->frameUpdate(false);
	_enemy->frameUpdate(false, true);
}
void LeagueWaitingScene::delete_picture()
{
	_player->release();
	_player = nullptr;
	_enemy->release();
	_enemy = nullptr;
}

HRESULT LeagueWaitingScene::init()
{
	add_currentScene_toList(SCENE_LEAGUE_WAIT);
	set_imgPath("UI/Fight/");
	string path = _imgPath + "Window_back.bmp";
	_bg = new Image;
	_bg->init(path.c_str(), (int)(682 * GAME_MULTIPLE), (int)(383 * GAME_MULTIPLE));
	init_prefight_window();
	// Window Picture
	init_picture();
	// Button
	POINT center;
	center.x = (LONG)(_vs_center.x);
	center.y = (LONG)(WINSIZEY - _pfVs->get_height() * 0.6);
	_fight_button = new Button;
	_fight_button->init(BTN_RED_LONG, center);
	_fight_button->set_text_toButton("ÆÄÀÌÆ®");
	INGAME_UI->init(UI_LEAGUE_WAIT);
	return S_OK;
}
void LeagueWaitingScene::release()
{
	_bg->release();
	_bg = nullptr;
	delete_prefight_window();
	delete_picture();
	_fight_button->release();
	_fight_button = nullptr;
}
void LeagueWaitingScene::update()
{
	update_scene();
	update_picture();
	INGAME_UI->update();
	change_scene();
}
void LeagueWaitingScene::render()
{
	_bg->render(get_memDC(), 0, 0);
	draw_prefight_window();
	draw_picture();
	_fight_button->render();
	INGAME_UI->render();
}
LeagueWaitingScene::LeagueWaitingScene()
{
}
LeagueWaitingScene::~LeagueWaitingScene()
{
}
