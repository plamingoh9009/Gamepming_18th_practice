#include "stdafx.h"
#include "MainGame.h"

void MainGame::add_scenes_toManager()
{
	SCENEMANAGER->addScene("Title", new TitleScene());
	SCENEMANAGER->addScene("Home", new HomeScene());
	SCENEMANAGER->addScene("HUD", new HUD_Scene());
	SCENEMANAGER->addScene("Gym", new GymScene());
	SCENEMANAGER->addScene("Shop", new ShopScene());
}

HRESULT MainGame::init()
{
	GameNode::init(true);
	add_scenes_toManager();
	SCENEMANAGER->changeScene("Home");
	return S_OK;
}
void MainGame::release()
{
	SCENEMANAGER->release();
	GameNode::release();
}
void MainGame::update()
{
	GameNode::update();
	SCENEMANAGER->update();
}
void MainGame::render()
{
	//흰색 비트맵
	PatBlt(get_memDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//=====================================================
	SCENEMANAGER->render();
	//TIMEMANAGER->render(get_memDC());
	//=====================================================
	//백버퍼의 내용을 HDC에 그린다.(지우지마!!)
	this->get_backBuffer()->render(get_hdc(), 0, 0);
}
MainGame::MainGame()
{
}
MainGame::~MainGame()
{
}