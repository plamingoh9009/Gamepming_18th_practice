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
	//��� ��Ʈ��
	PatBlt(get_memDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//=====================================================

	TIMEMANAGER->render(get_memDC());
	//=====================================================
	//������� ������ HDC�� �׸���.(��������!!)
	this->get_backBuffer()->render(get_hdc(), 0, 0);
}
MainGame::MainGame()
{
}
MainGame::~MainGame()
{
}