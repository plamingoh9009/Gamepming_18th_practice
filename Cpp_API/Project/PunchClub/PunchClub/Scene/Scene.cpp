#include "stdafx.h"
#include "Scene.h"

void Scene::update_checkDebugMode()
{
	if (KEYMANAGER->is_toggleKey(VK_TAB) == true) { _fDebug = true; }
	else if (KEYMANAGER->is_toggleKey(VK_TAB) == false) { _fDebug = false; }
}

HRESULT Scene::init()
{
	return S_OK;
}
void Scene::release()
{
}
void Scene::update()
{
}
void Scene::render()
{
}
Scene::Scene()
{
}
Scene::~Scene()
{
}
void Scene::set_imgPath(string append)
{
	_imgPath = "Images/" + append;
}
