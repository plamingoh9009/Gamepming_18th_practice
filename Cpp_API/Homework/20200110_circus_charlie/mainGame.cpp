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

	// ���⼭ ������ �����Ѵ�.
	_game = new GameLoad;
	_game->init();

	return S_OK;
}

void mainGame::release()
{
	gameNode::release();

	// ���⼭ ������ �����Ѵ�.
	_game->release();
	SAFE_DELETE(_game);

}

void mainGame::update()
{
	gameNode::update();
	
	// ���⼭ ������ ������Ʈ �Ѵ�.
	_game->update();
}

void mainGame::render(HDC hdc)
{
	
	//��� ��Ʈ��
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, BLACKNESS);
	//===================================================
	
	_game->render();
	
	//=================================================
	//������� ������ HDC�� �׸���.(�ǵ帮������.)
	this->getBackBuffer()->render(getHDC(), 0, 0);
}

