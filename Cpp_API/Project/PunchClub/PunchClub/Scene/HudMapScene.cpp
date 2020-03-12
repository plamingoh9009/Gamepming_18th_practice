#include "stdafx.h"
#include "HudMapScene.h"

HRESULT HudMapScene::init_player_pos()
{
	HRESULT result = E_FAIL;
	MAPICON::TYPE type = _player->get_current_location();
	switch (type)
	{
	case MAPICON::ICN_HOME:
		_player->set_center(_home->get_center());
		result = S_OK;
		break;
	case MAPICON::ICN_SHOP:
		_player->set_center(_shop->get_center());
		result = S_OK;
		break;
	case MAPICON::ICN_GYM:
		_player->set_center(_gym->get_center());
		result = S_OK;
		break;
	case MAPICON::ICN_BUILD:
		_player->set_center(_build->get_center());
		result = S_OK;
		break;
	default:
		break;
	}
	return result;
}
HRESULT HudMapScene::init_background()
{
	_bg = new Image;
	string path = _imgPath + "HUD_bg.bmp";
	_bg->init(path.c_str(), (int)(682 * GAME_MULTIPLE), (int)(384 * GAME_MULTIPLE));
	if (_bg != nullptr)
	{
		return S_OK;
	}
	return E_FAIL;
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
HRESULT HudMapScene::init_map_icons()
{
	HRESULT result;
	int result_cnt = 0;
	POINT center;
	// 집
	_home = new MapIcon;
	result = _home->init(MAPICON::ICN_HOME);
	center.x = (LONG)(WIN_HALF_W - WIN_HALF_W * 0.38);
	center.y = (LONG)(WIN_HALF_H + WIN_HALF_H * 0.42);
	_home->set_center(center);
	if (result == S_OK) _icons.push_back(_home);
	else result_cnt++;
	// 수퍼마켓
	_shop = new MapIcon;
	result = _shop->init(MAPICON::ICN_SHOP);
	center.x = (LONG)(WIN_HALF_W + _shop->get_width() * 0.7);
	center.y = (LONG)(WIN_HALF_H + _shop->get_height() * 0.25);
	_shop->set_center(center);
	if (result == S_OK) _icons.push_back(_shop);
	else result_cnt++;
	// 체육관
	_gym = new MapIcon;
	result = _gym->init(MAPICON::ICN_GYM);
	center.x = (LONG)(WIN_HALF_W - _gym->get_width() * 0.85);
	center.y = (LONG)(WIN_HALF_H - _gym->get_height() * 0.3);
	_gym->set_center(center);
	if (result == S_OK) _icons.push_back(_gym);
	else result_cnt++;
	// 공사장
	_build = new MapIcon;
	result = _build->init(MAPICON::ICN_BUILD);
	center.x = (LONG)(WIN_HALF_W - _build->get_width() * 4.3125);
	center.y = (LONG)(WIN_HALF_H - _build->get_height() * 2);
	_build->set_center(center);
	if (result == S_OK) _icons.push_back(_build);
	else result_cnt++;
	// 캐릭터 이미지 로드
	_player = new MapIcon;
	result = _player->init(MAPICON::ICN_PLAYER);
	_player->set_center(_home->get_center());
	_player->set_current_location(MAPICON::ICN_HOME);
	if (result == S_OK) {}
	else result_cnt++;
	// Return
	if (result_cnt == 0) return S_OK;
	else return E_FAIL;
}
void HudMapScene::draw_map_icons()
{
	auto iter = _icons.begin();
	for (; iter != _icons.end(); iter++)
	{
		(*iter)->render();
	}
	_player->render();
}
void HudMapScene::update_map_icons()
{
	auto iter = _icons.begin();
	for (; iter != _icons.end(); iter++)
	{
		(*iter)->update();
	}
	_player->update();
}
void HudMapScene::delete_map_icons()
{
	auto iter = _icons.begin();
	for (; iter != _icons.end();)
	{
		(*iter)->release();
		iter = _icons.erase(iter);
	}
	_home = nullptr;
	_gym = nullptr;
	_shop = nullptr;
	_build = nullptr;
	_player->release();
	_player = nullptr;
	swap(MapIcons(), _icons);
}

HRESULT HudMapScene::init()
{
	HRESULT result;
	int result_cnt = 0;
	add_currentScene_toList(SCENE_HUD_MAP);
	set_imgPath("Hud_map/");
	result = init_background();
	(result == S_OK ? 1 : result_cnt++);
	result = init_map_icons();
	(result == S_OK ? 1 : result_cnt++);
	result = init_player_pos();
	(result == S_OK ? 1 : result_cnt++);
	// 버스 윈도우
	_bus = new Window;
	_bus->init(WINDOW::WND_BUS);
	// UI
	INGAME_UI->init();
	INGAME_UI->set_fRedButton(true);
	// Result
	result = (result_cnt == 0 ? S_OK : E_FAIL);
	return result;
}
void HudMapScene::release()
{
	delete_background();
	delete_map_icons();
	Release(_bus);
}
void HudMapScene::update()
{
	if (_bus->is_openBus() == true) 
	{
		_bus->update();
	}
	else
	{
		update_scene();
		update_map_icons();
		_bus->update_fOpenBus();
		INGAME_UI->update();
		change_scene();
	}
}
void HudMapScene::render()
{
	draw_background();
	draw_map_icons();
	if (_bus->is_openBus() == true)
	{
		Draw(_bus);
	}
	INGAME_UI->render();
}
HudMapScene::HudMapScene()
{
}
HudMapScene::~HudMapScene()
{
}
