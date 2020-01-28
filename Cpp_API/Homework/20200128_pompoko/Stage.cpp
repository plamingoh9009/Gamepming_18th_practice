#include "stdafx.h"
#include "Stage.h"


void Stage::show_wallRect()
{
	FrameRect(getMemDC(), &_wall,
		CreateSolidBrush(RGB(255, 255, 255)));
}

Stage::Stage()
{
}
Stage::~Stage()
{
}
HRESULT Stage::init()
{
	_mapImg = IMAGEMANAGER->addImage("Map",
		"images/Pompoko_Stage.bmp", 717, 600, false, COLOR_MAGENTA);
	_itemControl = new ItemControl;
	_itemControl->init();
	_enemyControl = new EnemyControl;
	_enemyControl->init();
	// 벽 초기화
	_wall = RectMake(625, 129, 18, 344);
	return S_OK;
}
void Stage::release()
{
	_enemyControl->release();
	_enemyControl = nullptr;
	_itemControl->release();
	_itemControl = nullptr;
	IMAGEMANAGER->deleteImage("Map");
	_mapImg = nullptr;
}
void Stage::update()
{
	_itemControl->update();
	_enemyControl->update();
}
void Stage::render()
{
	_mapImg->render(getMemDC());
	_itemControl->render();
	_enemyControl->render();

	//show_wallRect();
}
