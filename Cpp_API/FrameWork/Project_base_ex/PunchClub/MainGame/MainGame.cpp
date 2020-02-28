#include "stdafx.h"
#include "MainGame.h"

HRESULT MainGame::init()
{
	GameNode::init(true);
	return S_OK;
}
void MainGame::release()
{
	GameNode::release();
}
void MainGame::update()
{
	GameNode::update();
}
void MainGame::render()
{
	//흰색 비트맵
	PatBlt(get_memDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//=====================================================

	TIMEMANAGER->render(get_memDC());
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