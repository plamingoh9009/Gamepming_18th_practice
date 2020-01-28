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
	_stage = new Stage;
	_stage->init();
	return S_OK;
}
void mainGame::release()
{
	_stage->release();
	gameNode::release();
}
void mainGame::update()
{
	gameNode::update();
	_stage->update();
}
void mainGame::render(/*HDC hdc*/)
{
	//��� ��Ʈ��
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//===================================================
	_stage->render();
	//TIMEMANAGER->render(getMemDC());
	//=================================================
	//������� ������ HDC�� �׸���.(�ǵ帮������.)
	this->getBackBuffer()->render(getHDC(), 0, 0);
}

