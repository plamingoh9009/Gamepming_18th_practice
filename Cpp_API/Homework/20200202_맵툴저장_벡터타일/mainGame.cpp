#include "stdafx.h"
#include "mainGame.h"

void mainGame::setup_tileInfos()
{
	_tileInfos = new TileInfo[_tiles.size()+1];
	for (int i=0; i < (int)(_tiles.size()); i++)
	{
		_tileInfos[i].rc = _tiles[i]->get_rc();
		_tileInfos[i].type = _tiles[i]->get_type();
	}
}
void mainGame::load_tilesFromTileInfo()
{
	int i = 0;
	while (!_tileInfos[i].type.empty())
	{
		make_tile(_tileInfos[i].type,
			_tileInfos[i].rc.left, _tileInfos[i].rc.top, false);
		i++;
	}
}

void mainGame::init_board()
{
	_boardRect = RectMake(250, 100, 600, 400);
}
void mainGame::draw_board()
{
	FrameRect(getMemDC(), &_boardRect, CreateSolidBrush(RGB(0, 0, 0)));
}
void mainGame::init_buttons()
{
	_saveRect = RectMake(30, (int)(WINSIZEY*0.85), 60, 30);
	_loadRect = RectMake(90 + 20, (int)(WINSIZEY*0.85), 60, 30);
}
void mainGame::draw_buttons()
{
	FrameRect(getMemDC(), &_saveRect, CreateSolidBrush(RGB(0, 0, 0)));
	TextOut(getMemDC(), _saveRect.left+5, _saveRect.top+5, "Save", strlen("Save"));

	FrameRect(getMemDC(), &_loadRect, CreateSolidBrush(RGB(0, 0, 0)));
	TextOut(getMemDC(), _loadRect.left+5, _loadRect.top+5, "Load", strlen("Load"));
}
bool mainGame::is_board()
{
	if (PtInRect(&_boardRect, m_ptMouse))
	{
		return true;
	}
	return false;
}
bool mainGame::is_sampleTiles()
{
	auto iter = _sampleTiles.begin();
	for (;iter != _sampleTiles.end();iter++)
	{
		if (PtInRect(&(*iter)->get_rc(), m_ptMouse))
		{
			return true;
		}
	}
	return false;
}
void mainGame::init_sampleTiles()
{
	Tile sample;
	sample.init();
	vector<string> sampleNames = sample.get_sampleNames();
	Tile * tile;
	// 샘플 출력할 위치
	int x, y;
	x = 10, y = 80;
	auto iter = sampleNames.begin();
	for (;iter != sampleNames.end();iter++)
	{
		tile = new Tile;
		tile->init();
		tile->setup_tile((*iter), x, y);
		_sampleTiles.push_back(tile);
		tile = nullptr;
		x += 80;
	}
	// 내가 선택한 타일 초기화
	_currentTileType = "";
}
void mainGame::delete_sampleTiles()
{
	auto iter = _sampleTiles.begin();
	for (;iter != _sampleTiles.end();)
	{
		(*iter)->release();
		iter = _sampleTiles.erase(iter);
	}
	swap(_sampleTiles, vTiles());
}
void mainGame::draw_sampleTiles()
{
	auto iter = _sampleTiles.begin();
	for (;iter != _sampleTiles.end();iter++)
	{
		(*iter)->render();
	}
}
void mainGame::make_tile(string type, int x, int y, bool isCenter=true)
{
	Tile * tile;
	tile = new Tile;
	tile->init();
	tile->setup_tile(type, x, y, isCenter);
	_tiles.push_back(tile);
	tile = nullptr;
}
void mainGame::delete_tilesAll()
{
	auto iter = _tiles.begin();
	for (;iter != _tiles.end();)
	{
		(*iter)->release();
		iter = _tiles.erase(iter);
	}
	swap(_tiles, vTiles());
}
void mainGame::draw_tiles()
{
	auto iter = _tiles.begin();
	for (;iter != _tiles.end();iter++)
	{
		(*iter)->render();
	}
}
void mainGame::setup_tile()
{
	// 샘플을 뒤져서 어느 샘플을 눌렀는지 추출한다.
	RECT mouse = RectMakeCenter(m_ptMouse.x, m_ptMouse.y, 5, 5);
	auto iter = _sampleTiles.begin();
	for (;iter != _sampleTiles.end();iter++)
	{
		if (IntersectRect(&RECT(), &(*iter)->get_rc(), &mouse))
		{
			_currentTileType = (*iter)->get_type();
		}
	}
}
mainGame::mainGame()
{
}
mainGame::~mainGame()
{
}
HRESULT mainGame::init()
{
	gameNode::init(true);
	init_sampleTiles();
	init_board();
	init_buttons();
	return S_OK;
}
void mainGame::release()
{
	delete[] (_tileInfos);
	delete_tilesAll();
	delete_sampleTiles();
	gameNode::release();

}
void mainGame::update()
{
	gameNode::update();
	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		if (is_sampleTiles() == true)
		{
			setup_tile();
		}
		else if (is_board() == true)
		{
			if (_currentTileType.empty() == true) {}
			else
			{
				make_tile(_currentTileType, m_ptMouse.x, m_ptMouse.y);
			}
		}//if: 보드 눌렀으면
		else if(PtInRect(&_saveRect, m_ptMouse))
		{
			save();
		}//if: 세이브 눌렀으면
		else if (PtInRect(&_loadRect, m_ptMouse))
		{
			load();
		}//if: 로드 눌렀으면
	}
}
void mainGame::render(/*HDC hdc*/)
{
	//흰색 비트맵
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//===================================================
	draw_sampleTiles();
	draw_tiles();
	draw_buttons();
	draw_board();
	TIMEMANAGER->render(getMemDC());
	//=================================================
	//백버퍼의 내용을 HDC에 그린다.(건드리지말것.)
	this->getBackBuffer()->render(getHDC(), 0, 0);
}

void mainGame::save()
{
	HANDLE myFile = CreateFile("save/Save.test", GENERIC_WRITE,
		NULL, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL,
		NULL);
	DWORD write;
	// 타일 인포를 셋업하고 저장한다.
	setup_tileInfos();
	_saveBuffer = sizeof(*_tileInfos) * (_tiles.size()+1);
	WriteFile(myFile, &_tileInfos, _saveBuffer, &write, NULL);
	CloseHandle(myFile);
}
//여기도...
void mainGame::load()
{
	HANDLE myFile = CreateFile("save/Save.test", GENERIC_READ,
		NULL, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL,
		NULL);
	DWORD read;
	ReadFile(myFile, &_tileInfos, _saveBuffer, &read, NULL);
	// 타일 인포를 읽어오고, 타일을 새로 만든다.
	delete_tilesAll();
	load_tilesFromTileInfo();
	CloseHandle(myFile);
}