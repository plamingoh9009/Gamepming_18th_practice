#include "stdafx.h"
#include "Scene.h"

vSceneList Scene::_sceneList;
void Scene::add_currentScene_toList(SCENE_TYPE sceneType)
{
	_scene_forChange = SCENE_EMPTY;
	switch (sceneType)
	{
	case SCENE_TITLE:
		_sceneList.push_back("Title");
		break;
	case SCENE_HOME:
		_sceneList.push_back("Home");
		break;
	case SCENE_HUD_MAP:
		_sceneList.push_back("HudMap");
		break;
	case SCENE_GYM:
		_sceneList.push_back("Gym");
		break;
	case SCENE_SHOP:
		_sceneList.push_back("Shop");
		break;
	case SCENE_SKILLTREE:
		_sceneList.push_back("SkillTree");
		break;
	default:
		break;
	}
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
