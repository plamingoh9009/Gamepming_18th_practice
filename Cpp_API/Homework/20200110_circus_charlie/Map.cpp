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
	_img = IMAGEMANAGER->addImage("���", "images/��Ŀ�����_��������.bmp", 
		0, 0, _sizeMap.x, _sizeMap.y, false, COLOR_MAGENTA);

	// ����â�� �ø���.
	_myStat = new Status;
	_myStat->init();
	return S_OK;
}

void Map::release()
{
	// ����� ������.
	IMAGEMANAGER->deleteImage("���");
	SAFE_DELETE(_img);

	// ����â�� ������.
	_myStat->release();
	SAFE_DELETE(_myStat);
}

void Map::update()
{
}

void Map::render()
{
	IMAGEMANAGER->render("���", getMemDC());
	
	// ����â�� ����.
	_myStat->render();
}

void Map::render(int distance)
{
	IMAGEMANAGER->loopRender("���", getMemDC(), &RectMake(0, 0, WINSIZEX, WINSIZEY),
		distance, 0);

	_myStat->render();
}
