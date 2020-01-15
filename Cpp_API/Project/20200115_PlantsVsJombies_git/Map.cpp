#include "stdafx.h"
#include "Map.h"

void Map::show_space()
{
	for (int i = 0; i < 5; i++)
	{
		for (int k = 0; k < 9; k++)
		{
			Rectangle(getMemDC(), _space[i][k].left, _space[i][k].top,
				_space[i][k].right, _space[i][k].bottom);
		}
	}
}
void Map::init_space()
{
	int initX = 132;
	int initY = 90;
	int plantWidth = 70;
	int plantHeight = 80;
	int blankWidth = (int)(plantWidth * 0.1429);
	int blankHeight = (int)(plantHeight * 0.2);
	int currentX, currentY;

	currentY = initY;
	for (int i = 0; i < 5; i++)
	{
		currentX = initX;
		for (int k = 0; k < 9; k++)
		{
			_space[i][k] = RectMake(currentX, currentY,
				plantWidth, plantHeight);
			currentX = currentX + plantWidth + blankWidth;
		}//for: �¿� ������ 22�ȼ�
		currentY = currentY + plantHeight + blankHeight;
	}//for: ���� ������ 38�ȼ�
}
void Map::show_mapAll()
{
	// ���� ���������� �����ִ� �Լ�
	if (_distance + WINSIZEX >= _rect.right - 1)
	{
		_distance = 126;
		_isShowMapAll = false;
		_delay++;
		Sleep(2500);
	}//if: �������� ���� �����ϸ� �����.
	else
	{
		_distance += _SPEED;
	}//else: �������� ���� �ƴϸ� �������� �����ش�.
}

Map::Map()
{
}
Map::~Map()
{
}
HRESULT Map::init()
{
	_rect = RectMake(0, 0, 1400, 600);
	_img = IMAGEMANAGER->addImage("Background_Yard", "images/Background_Yard.bmp",
		_rect.right - _rect.left, _rect.bottom - _rect.top, false, COLOR_MAGENTA);
	// ���� ���� �������� ���� ���ϴ� ����
	_isShowMapAll = false;
	_distance = 0;
	// �簢�� Ÿ���� �ʱ�ȭ�ϴ� �Լ�
	init_space();
	// �ʹ� �����̸� ���� ����
	_delay = 0;
	return S_OK;
}
void Map::release()
{
	IMAGEMANAGER->deleteImage("Background_Yard");
}
void Map::update()
{
	if (_delay == 100)
	{
		_isShowMapAll = true;
		// ó���� ���� �� �����ִ� �κ�
		if (_isShowMapAll == true) 
		{ 
			show_mapAll();
		}
	}//if: �����ð��� ���� ��
	else { _delay++; }
}
void Map::render()
{
	// ������ �����ϴ� �κ�
	IMAGEMANAGER->loopRender("Background_Yard", getMemDC(),
		&RectMake(0, 0, WINSIZEX, WINSIZEY), _distance, 0);
	// 1���� ������ �簢�� Ÿ���� �����ش�.
	if (KEYMANAGER->isToggleKey(0X31)) { show_space(); }
}
