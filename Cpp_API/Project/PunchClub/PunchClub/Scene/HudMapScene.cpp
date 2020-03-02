#include "stdafx.h"
#include "HudMapScene.h"

HRESULT HudMapScene::init()
{
	add_currentScene_toList(SCENE_HUD_MAP);
	set_imgPath("Hud_map/");
	_bg = new Image;
	string path = _imgPath + "HUD_bg.bmp";
	_bg->init(path.c_str(), (int)(682 * GAME_MULTIPLE), (int)(384 * GAME_MULTIPLE));
	return S_OK;
}
void HudMapScene::release()
{
}
void HudMapScene::update()
{
	update_checkDebugMode();
}
void HudMapScene::render()
{
	_bg->render(get_memDC());
}
HudMapScene::HudMapScene()
{
}
HudMapScene::~HudMapScene()
{
}
