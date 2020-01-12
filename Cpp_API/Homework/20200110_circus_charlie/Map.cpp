#include "stdafx.h"
#include "Map.h"


POINT Map::get_sizeMap()
{
	return _sizeMap;
}

Map::Map()
{
}
Map::~Map()
{
}

HRESULT Map::init()
{
	_img = IMAGEMANAGER->addImage("배경", "images/서커스배경_리사이즈.bmp", 
		0, 0, _sizeMap.x, _sizeMap.y, false, COLOR_MAGENTA);

	// 스탯창을 올린다.
	_myStat = new Status;
	_myStat->init();
	return S_OK;
}

void Map::release()
{
	// 배경을 날린다.
	IMAGEMANAGER->deleteImage("배경");
	SAFE_DELETE(_img);

	// 스탯창을 날린다.
	_myStat->release();
	SAFE_DELETE(_myStat);
}

void Map::update()
{
}

void Map::render()
{
	IMAGEMANAGER->render("배경", getMemDC());
	
	// 스탯창을 띄운다.
	_myStat->render();
}

void Map::render(int distance)
{
	IMAGEMANAGER->loopRender("배경", getMemDC(), &RectMake(0, 0, WINSIZEX, WINSIZEY),
		distance, 0);

	_myStat->render();
}
