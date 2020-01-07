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
	gameNode::init();

	_bgImage = new image;
	_bgImage->init("images/마리오_배경.bmp", WINSIZEX, WINSIZEY);

	_cuteStar.init();

	/*_rockman = new image;
	_rockman->init("images/록맨.bmp", WINSIZEX / 2, WINSIZEY / 2, 
		960, 200, 10, 2, true, RGB(255, 0, 255));*/
	return S_OK;
}

void mainGame::release()
{
	gameNode::release();
	SAFE_DELETE(_bgImage);
	//SAFE_DELETE(_rockman);
	_cuteStar.release();
}

void mainGame::update()
{
	gameNode::update();

	_cuteStar.update();
	//if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	//{
	//	_isLeft = true;
	//	_rockman->setX(_rockman->getX() - 2);
	//}
	//if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	//{
	//	_isLeft = false;
	//	_rockman->setX(_rockman->getX() + 2);
	//}

	//if (_isLeft)
	//{
	//	_count++;
	//	_rockman->setFrameY(1);

	//	if (_count % 5 == 0)
	//	{
	//		_count = 0;
	//		_index--;

	//		if (_index < _rockman->getMaxFrameY())
	//		{
	//			_index = 9;
	//		}
	//		_rockman->setFrameX(_index);
	//	}
	//}//end of if:
	//else
	//{
	//	_count++;
	//	_rockman->setFrameY(0);

	//	if (_count % 5 == 0)
	//	{
	//		_count = 0;
	//		_index++;

	//		if (_index >= _rockman->getMaxFrameX())
	//		{
	//			_index = 0;
	//		}
	//		_rockman->setFrameX(_index);
	//	}
	//}
}

void mainGame::render(HDC hdc)
{
	//백버퍼에 뿌리자.
	HDC memDC = this->getBackBuffer()->getMemDC();
	//흰색 비트맵
	PatBlt(memDC, 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//===================================================
	_bgImage->render(memDC);
	_cuteStar.render(memDC);
	/*_rockman->frameRender(memDC, _rockman->getX(), _rockman->getY(),
		_rockman->getFrameX(), _rockman->getFrameY());*/
	//=================================================
	//백버퍼의 내용을 HDC에 그린다.(건드리지말것.)
	this->getBackBuffer()->render(hdc, 0, 0);
}

