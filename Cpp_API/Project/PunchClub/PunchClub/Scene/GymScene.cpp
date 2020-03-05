#include "stdafx.h"
#include "GymScene.h"


HRESULT GymScene::init()
{
	add_currentScene_toList(SCENE_GYM);
	INGAME_UI->init();
	INGAME_UI->set_fRedButton(true);
	return S_OK;
}

void GymScene::release()
{
}

void GymScene::update()
{
	update_scene();
	INGAME_UI->update();
	change_scene();
}

void GymScene::render()
{
	TextOut(get_memDC(), WINSIZEX * 0.5, WINSIZEY * 0.5,
		"Ã¼À°°ü", strlen("Ã¼À°°ü"));
	INGAME_UI->render();
}

GymScene::GymScene()
{
}


GymScene::~GymScene()
{
}
