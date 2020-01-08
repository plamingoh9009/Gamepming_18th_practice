#include "stdafx.h"
#include "Map.h"

#define MAP_W	400
#define MAP_H	600

#define LOAD_X	20
#define LOAD_Y	0
#define LOAD_W	180
#define LOAD_H	600

HRESULT Map::init()
{
	// ��濡 ���� ���� �޸𸮿� �ε��Ѵ�.
	_bgImage = new image;
	_bgImage->init("images/Map_Road_Resize.bmp", MAP_W, MAP_H);

	return S_OK;
}

void Map::update()
{
}

void Map::render(HDC hdc)
{
	// ���⼭ ���� �׸���.
	_bgImage->render(hdc);
}

void Map::render(HDC hdc, int speed_loop)
{
	_bgImage->loopRender(hdc, &RectMake(0, 0, WINSIZEX, WINSIZEY), 
		0, speed_loop);
}

void Map::release()
{
	// �޸𸮸� �����Ѵ�.
	SAFE_DELETE(_bgImage);
}

Map::Map()
{
}


Map::~Map()
{
}
