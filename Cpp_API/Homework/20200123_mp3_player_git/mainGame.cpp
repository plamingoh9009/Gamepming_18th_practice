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
	_mp3 = new MP3;
	_mp3->init();
	return S_OK;
}

void mainGame::release()
{
	gameNode::release();
	_mp3->release();
}
void mainGame::update()
{
	gameNode::update();
	_mp3->update();
}
void mainGame::render(/*HDC hdc*/)
{
	//��� ��Ʈ��
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//===================================================
	_mp3->render();
	//TIMEMANAGER->render(getMemDC());
	//=================================================
	//������� ������ HDC�� �׸���.(�ǵ帮������.)
	this->getBackBuffer()->render(getHDC(), 0, 0);
}

