#include "stdafx.h"
#include "Tile.h"


void Tile::init_allSampleNames()
{
	_sampleNames.push_back("Tree");
	_sampleNames.push_back("Gym");
	_sampleNames.push_back("Pokecenter");
}
void Tile::draw_samples()
{
}
void Tile::setup_tile(string type, int x, int y)
{
	_type = type;
	if (type.compare("Tree") == 0)
	{
		_width = 16;
		_height = 31;
		_img = IMAGEMANAGER->addImage("Tree", "images/Tile_Tree.bmp",
			_width, _height, false, RGB(255, 0, 255));
		_rc = RectMakeCenter(x, y, _width, _height);
	}
	else if (type.compare("Gym") == 0)
	{
		_width = 15;
		_height = 23;
		_img = IMAGEMANAGER->addImage("Gym", "images/Tile_Gym.bmp",
			_width, _height, false, RGB(255, 0, 255));
		_rc = RectMakeCenter(x, y, _width, _height);
	}
	else if (type.compare("Pokecenter") == 0)
	{
		_width = 64;
		_height = 64;
		_img = IMAGEMANAGER->addImage("Pokecenter", "images/Tile_Pokecenter.bmp",
			_width, _height, false, RGB(255, 0, 255));
		_rc = RectMakeCenter(x, y, _width, _height);
	}
}
void Tile::setup_tile(string type, int x, int y, bool isCenter)
{
	_type = type;
	if (type.compare("Tree") == 0)
	{
		_width = 16;
		_height = 31;
		_img = IMAGEMANAGER->addImage("Tree", "images/Tile_Tree.bmp",
			_width, _height, false, RGB(255, 0, 255));
		if (isCenter == true)
		{
			_rc = RectMakeCenter(x, y, _width, _height);
		}
		else
		{
			_rc = RectMake(x, y, _width, _height);
		}
	}
	else if (type.compare("Gym") == 0)
	{
		_width = 15;
		_height = 23;
		_img = IMAGEMANAGER->addImage("Gym", "images/Tile_Gym.bmp",
			_width, _height, false, RGB(255, 0, 255));
		if (isCenter == true)
		{
			_rc = RectMakeCenter(x, y, _width, _height);
		}
		else
		{
			_rc = RectMake(x, y, _width, _height);
		}
	}
	else if (type.compare("Pokecenter") == 0)
	{
		_width = 64;
		_height = 64;
		_img = IMAGEMANAGER->addImage("Pokecenter", "images/Tile_Pokecenter.bmp",
			_width, _height, false, RGB(255, 0, 255));
		if (isCenter == true)
		{
			_rc = RectMakeCenter(x, y, _width, _height);
		}
		else
		{
			_rc = RectMake(x, y, _width, _height);
		}
	}
}
DWORD Tile::get_thisSize()
{
	DWORD totalSize = 0;
	image img;
	img.init("images/Tile_Tree.bmp", 16, 31, false, RGB(255, 0, 255));
	DWORD size = sizeof(img);
	// 모든 변수의 메모리 점유 계산
	totalSize += _msize(_img);
	totalSize += sizeof(_rc);
	totalSize += sizeof(_type);
	totalSize += sizeof(_width);
	totalSize += sizeof(_height);
	totalSize += get_vectorSizes(_sampleNames);
	return totalSize;
}
Tile::Tile()
{
}
Tile::~Tile()
{
}
HRESULT Tile::init()
{
	init_allSampleNames();
	return S_OK;
}

void Tile::release()
{
	_img = nullptr;
}

void Tile::update()
{
}

void Tile::render()
{
	_img->render(getMemDC(), _rc.left, _rc.top);
}
