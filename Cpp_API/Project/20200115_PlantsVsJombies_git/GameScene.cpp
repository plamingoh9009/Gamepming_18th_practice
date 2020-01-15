#include "stdafx.h"
#include "GameScene.h"


GameScene::GameScene()
{
}
GameScene::~GameScene()
{
}

HRESULT GameScene::init()
{
	SCENEMANAGER->addScene("Stage", new Stage);
	SCENEMANAGER->changeScene("Stage");
	return S_OK;
}

void GameScene::release()
{
	SCENEMANAGER->release();
}

void GameScene::update()
{
	SCENEMANAGER->update();
}

void GameScene::render()
{
	SCENEMANAGER->render();
	//TIMEMANAGER->render(getMemDC());
}
