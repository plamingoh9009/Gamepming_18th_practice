#include "stdafx.h"
#include "GymScene.h"


HRESULT GymScene::init()
{
	return S_OK;
}

void GymScene::release()
{
}

void GymScene::update()
{
}

void GymScene::render()
{
	TextOut(get_memDC(), WINSIZEX * 0.5, WINSIZEY * 0.5,
		"ü����", strlen("ü����"));
}

GymScene::GymScene()
{
}


GymScene::~GymScene()
{
}
