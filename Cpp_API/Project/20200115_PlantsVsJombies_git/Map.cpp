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

void Map::show_spaces()
{
	_itSpaces = _spaces.begin();
	for (;_itSpaces != _spaces.end();_itSpaces++)
	{
		Rectangle(getMemDC(), _itSpaces->left, _itSpaces->top,
			_itSpaces->right, _itSpaces->bottom);
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
			// 렉트를 만든다.
			rect = RectMake(currentX, currentY,
				plantWidth, plantHeight);
			// 벡터에 넣는다.
			_spaces.push_back(rect);
			currentX = currentX + plantWidth + blankWidth;
		}//for: 좌우 여백은 22픽셀
		currentY = currentY + plantHeight + blankHeight;
	}//for: 상하 여백은 38픽셀
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
	// 맵이 어디까지인지 보여주는 함수
	if (_distance + WINSIZEX >= _rect.right - 1)
	{
		_distance = 126;
		_isShowMapAll = false;
		_delay++;
		Sleep(2500);
	}//if: 윈도우의 끝에 도달하면 멈춘다.
	else
	{
		_distance += _SPEED;
	}//else: 윈도우의 끝이 아니면 움직여서 보여준다.
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
	// 맵을 전부 보여줄지 말지 정하는 변수
	_isShowMapAll = false;
	_distance = 126;
	// 사각형 타일을 초기화하는 함수
	init_spaces();
	// 초반 딜레이를 위한 변수
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
		// 처음에 맵을 쭉 보여주는 부분
		if (_isShowMapAll == true) 
		{ 
			show_mapAll();
		}
	}//if: 일정시간이 지난 후
	else { _delay++; }
}
void Map::render()
{
	// 마당을 렌더하는 부분
	IMAGEMANAGER->loopRender("Background_Yard", getMemDC(),
		&RectMake(0, 0, WINSIZEX, WINSIZEY), _distance, 0);
}
