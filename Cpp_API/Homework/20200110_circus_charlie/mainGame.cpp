#include "stdafx.h"
#include "mainGame.h"
mainGame::mainGame()
{
}
mainGame::~mainGame()
{
}
HRESULT mainGame::init()
{

	gameNode::init(true);

	// 여기서 게임을 실행한다.
	_game = new GameLoad;
	_game->init();

	return S_OK;
}

void mainGame::release()
{
	gameNode::release();

	// 여기서 게임을 해제한다.
	_game->release();
	SAFE_DELETE(_game);

}

void mainGame::update()
{
	gameNode::update();
	
	// 여기서 게임을 업데이트 한다.
	_game->update();
}

void mainGame::render(HDC hdc)
{
	
	//흰색 비트맵
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);
	//===================================================
	
	_game->render();
	
	//=================================================
	//백버퍼의 내용을 HDC에 그린다.(건드리지말것.)
	this->getBackBuffer()->render(getHDC(), 0, 0);
}

