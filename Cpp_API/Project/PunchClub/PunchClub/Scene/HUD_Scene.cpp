#include "stdafx.h"
#include "HUD_Scene.h"


HRESULT HUD_Scene::init()
{
	return S_OK;
}

void HUD_Scene::release()
{
}

void HUD_Scene::update()
{
}

void HUD_Scene::render()
{
	TextOut(get_memDC(), WINSIZEX * 0.5, WINSIZEY * 0.5,
		"������", strlen("������"));
}

HUD_Scene::HUD_Scene()
{
}


HUD_Scene::~HUD_Scene()
{
}
