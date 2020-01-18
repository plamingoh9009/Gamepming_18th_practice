#include "stdafx.h"
#include "Map.h"

vector<RECT> Map::get_spaces()
{
	return vector<RECT>(_spaces);
}
vector<RECT>::iterator Map::get_itSpaces()
{
	return vector<RECT>::iterator(_itSpaces);
}
vector<RECT> Map::get_lines()
{
	return vector<RECT>(_lines);
}
vector<RECT>::iterator Map::get_itLines()
{
	return vector<RECT>::iterator(_itLines);
}

void Map::show_lines()
{
	_itLines = _lines.begin();
	for (;_itLines != _lines.end();_itLines++)
	{
		FrameRect(getMemDC(), &(*_itLines),
			CreateSolidBrush(RGB(64, 0, 64)));
	}
}
void Map::delete_lines()
{
	_itLines = _lines.begin();
	for (;_itLines != _lines.end();)
	{
		_lines.erase(_itLines++);
	}
	_lines.clear();
}
void Map::show_spaces()
{
	_itSpaces = _spaces.begin();
	for (;_itSpaces != _spaces.end();_itSpaces++)
	{
		FrameRect(getMemDC(), &(*_itSpaces), 
			CreateSolidBrush(RGB(0, 0, 0)));
	}
}
void Map::init_spaces()
{
	int initX = 132;
	int initY = 90;
	int plantWidth = 70;
	int plantHeight = 80;
	int blankWidth = (int)(plantWidth * 0.1429);
	int blankHeight = (int)(plantHeight * 0.2);
	int currentX, currentY;
	RECT rect;
	currentY = initY;
	for (int i = 0; i < 5; i++)
	{
		currentX = initX;
		for (int k = 0; k < 9; k++)
		{
			// ��Ʈ�� �����.
			rect = RectMake(currentX, currentY,
				plantWidth, plantHeight);
			// ���Ϳ� �ִ´�.
			_spaces.push_back(rect);
			currentX = currentX + plantWidth + blankWidth;
		}//for: �¿� ������ 22�ȼ�
		currentY = currentY + plantHeight + blankHeight;
		// ================================================
		// **			_lines ���͸� �ʱ�ȭ				 **
		// ================================================
		_lines.push_back(rect);
	}//for: ���� ������ 38�ȼ�
}
void Map::delete_spaces()
{
	_itSpaces = _spaces.begin();
	for (;_itSpaces != _spaces.end();)
	{
		_spaces.erase(_itSpaces++);
	}
	_spaces.clear();
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
	_distance = 126;
	// �簢�� Ÿ���� �ʱ�ȭ�ϴ� �Լ�
	init_spaces();
	// �ʹ� �����̸� ���� ����
	_delay = 0;
	return S_OK;
}
void Map::release()
{
	IMAGEMANAGER->deleteImage("Background_Yard");
	delete_spaces();
}
void Map::update()
{
	if (_delay == 100)
	{
		_isShowMapAll = false;
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
}
