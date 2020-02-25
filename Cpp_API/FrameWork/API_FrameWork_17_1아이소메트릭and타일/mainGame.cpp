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

	IMAGEMANAGER->addFrameImage("tile", "images/tile1.bmp",
		0, 0, 100 * 8, (50 + 50) * 7, 8, 7, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage("tile2", "images/tile3.bmp",
		0, 0, 100 * 21, (50 + 50) * 8, 21, 8, true, RGB(255, 0, 255));

	SubIsoMap* sub = new SubIsoMap;
	SCENEMANAGER->addScene("SubIsoMap", sub);

	IsoMap* map = new IsoMap;
	SCENEMANAGER->addScene("IsoMap", map);
	SUBWIN->SetIsoMap(map);

#ifdef SUBWINOPEN
	SUBWIN->init();
#endif // SUBWINOPEN

#ifdef SUBWINOPEN
	SUBWIN->SetScene(sub);
#endif // SUBWINOPEN

	SCENEMANAGER->changeScene("IsoMap");

	return S_OK;
}

void mainGame::release()
{
	gameNode::release();

}

void mainGame::update()
{
	gameNode::update();
	SCENEMANAGER->update();

#ifdef SUBWINOPEN

	SUBWIN->update();
#endif // SUBWINOPEN


}

void mainGame::render(/*HDC hdc*/)
{
	//흰색 비트맵
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	SCENEMANAGER->render();
#ifdef SUBWINOPEN
	SUBWIN->render();
#endif // SUBWINOPEN
	TIMEMANAGER->render(getMemDC());
	//=====================================================
	//백버퍼의 내용을 HDC에 그린다.(지우지마!!)
	this->getBackBuffer()->render(getHDC(), 0, 0);
}









