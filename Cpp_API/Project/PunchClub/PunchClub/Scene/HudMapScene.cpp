#include "stdafx.h"
#include "HudMapScene.h"

void HudMapScene::init_player_pos()
{
	SCENE_TYPE type;
	auto iter = _sceneList.end();
	type = *(iter - 2);
	switch (type)
	{
	case SCENE_HOME:
		_player_center = _home_center;
		break;
	case SCENE_SHOP:
		_player_center = _shop_center;
		break;
	case SCENE_GYM:
		_player_center = _gym_center;
		break;
	}
	_player_rc = RectMakeCenter(_player_center.x, _player_center.y,
		_player->get_width(), _player->get_height());
}
void HudMapScene::init_background()
{
	_bg = new Image;
	string path = _imgPath + "HUD_bg.bmp";
	_bg->init(path.c_str(), (int)(682 * GAME_MULTIPLE), (int)(384 * GAME_MULTIPLE));
}
void HudMapScene::draw_background()
{
	_bg->render(get_memDC());
}
void HudMapScene::delete_background()
{
	_bg->release();
	_bg = nullptr;
}
void HudMapScene::init_map_icons()
{
	string path;
	POINT center;
	// 지형지물
	path = _imgPath + "Hud_home.bmp";
	_home = new Image;
	_home->init(path.c_str(), (int)(46 * GAME_MULTIPLE), (int)(33 * GAME_MULTIPLE));
	center.x = (LONG)(WIN_HALF_W  - WIN_HALF_W * 0.38);
	center.y = (LONG)(WIN_HALF_H + WIN_HALF_H * 0.42);
	_home_rc = RectMakeCenter(center.x, center.y, _home->get_width(), _home->get_height());
	_home_center = center;
	path = _imgPath + "Hud_shop.bmp";
	_shop = new Image;
	_shop->init(path.c_str(), (int)(46 * GAME_MULTIPLE), (int)(32 * GAME_MULTIPLE));
	center.x = (LONG)(WIN_HALF_W + _shop->get_width() * 0.7);
	center.y = (LONG)(WIN_HALF_H + _shop->get_height() * 0.25);
	_shop_rc = RectMakeCenter(center.x, center.y, _shop->get_width(), _shop->get_height());
	_shop_center = center;
	path = _imgPath + "Hud_gym.bmp";
	_gym = new Image;
	_gym->init(path.c_str(), (int)(48 * GAME_MULTIPLE), (int)(31 * GAME_MULTIPLE));
	center.x = (LONG)(WIN_HALF_W - _gym->get_width() * 0.85);
	center.y = (LONG)(WIN_HALF_H - _gym->get_height() * 0.3);
	_gym_rc = RectMakeCenter(center.x, center.y, _gym->get_width(), _gym->get_height());
	_gym_center = center;
	// 캐릭터 이미지 로드
	path = _imgPath + "Map_player.bmp";
	_player = new Image;
	_player->init(path.c_str(), (int)(30 * GAME_MULTIPLE), (int)(40 * GAME_MULTIPLE));
	_player_center.x = (LONG)(WIN_HALF_W);
	_player_center.y = (LONG)(WIN_HALF_H);
	_player_rc = RectMakeCenter(_player_center.x, _player_center.y, 
		_player->get_width(), _player->get_height());
}
void HudMapScene::draw_map_icons()
{
	_home->render(get_memDC(), _home_rc.left, _home_rc.top);
	_shop->render(get_memDC(), _shop_rc.left, _shop_rc.top);
	_gym->render(get_memDC(), _gym_rc.left, _gym_rc.top);
	_player->render(get_memDC(), _player_rc.left, _player_rc.top);
	if (_fDebug)
	{
		ColorRect(get_memDC(), _home_rc, RGB(244, 180, 41));
		ColorRect(get_memDC(), _shop_rc, RGB(244, 180, 41));
		ColorRect(get_memDC(), _gym_rc, RGB(244, 180, 41));
		ColorRect(get_memDC(), _player_rc, RGB(144, 233, 0));
	}
}
void HudMapScene::delete_map_icons()
{
	_home->release();
	_shop->release();
	_gym->release();
	_player->release();
	_home = nullptr;
	_shop = nullptr;
	_gym = nullptr;
	_player = nullptr;
}

HRESULT HudMapScene::init()
{
	add_currentScene_toList(SCENE_HUD_MAP);
	set_imgPath("Hud_map/");
	init_background();
	init_map_icons();
	init_player_pos();
	// UI
	INGAME_UI->init();
	INGAME_UI->set_fRedButton(true);
	return S_OK;
}
void HudMapScene::release()
{
	delete_background();
	delete_map_icons();
}
void HudMapScene::update()
{
	update_scene();
	INGAME_UI->update();
	change_scene();
}
void HudMapScene::render()
{
	draw_background();
	draw_map_icons();
	INGAME_UI->render();
}
HudMapScene::HudMapScene()
{
}
HudMapScene::~HudMapScene()
{
}
