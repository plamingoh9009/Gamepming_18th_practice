#include "stdafx.h"
#include "ShopScene.h"

HRESULT ShopScene::init()
{
	add_currentScene_toList(SCENE_SHOP);
	INGAME_UI->init();
	INGAME_UI->set_fRedButton(true);
	return S_OK;
}

void ShopScene::release()
{
}

void ShopScene::update()
{
	update_scene();
	INGAME_UI->update();
	change_scene();
}

void ShopScene::render()
{
	TextOut(get_memDC(), WINSIZEX * 0.5, WINSIZEY * 0.5,
		"500¿ø", strlen("500¿ø"));
	INGAME_UI->render();
}

ShopScene::ShopScene()
{
}
ShopScene::~ShopScene()
{
}
