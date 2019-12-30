#include "Map.h"


void Map::init_(int stage)
{
	_isStageOver = false;
	// 스테이지 1이면 사각형 맵을 초기화한다.
	if (stage == 1)
	{
		// 맵의 구성을 만든다.
		// 맵 자체 초기화
		initMaptoZero();

		// 벽, 가장자리, 문을 초기화한다.
		initWall();
		initEdge();
		initDoor();
		initTree();
		initCharactor();

		// 원래의 맵에 매핑한다.
		mapping_();

		draw_map();
	}
}

void Map::update_map(int myKey)
{
	// myKey를 바탕으로 캐릭터가 움직일수 있는지 여부를 확인한다.
	bool isMoveOK_ = false;
	bool isPortal_ = false;
	// _posCharactor[1]에 x축 좌표, _posCharactor[0]에 y축 좌표가 있다.
	int y = _posCharactor[0];
	int x = _posCharactor[1];

	if (myKey != 0)
	{
		// myKey에 입력이 있을 경우
		isMoveOK_ = isMoveOK(myKey);
		isPortal_ = isPortal(myKey);
		//cout << isMoveOK_ << endl;

		// 움직일 수 있다면 myKey 값에 따라서 캐릭터의 위치를 옮겨서 계산한다.
		if (isMoveOK_ == true)
		{
			switch (myKey)
			{
			case KEY_LEFT:
				// x축 - 1
				_map[y][x - 1] = MAP_CHARACTOR;
				_map[y][x] = MAP_PATH;
				_posCharactor[1] = x - 1;
				break;
			case KEY_UP:
				// y축 - 1
				_map[y - 1][x] = MAP_CHARACTOR;
				_map[y][x] = MAP_PATH;
				_posCharactor[0] = y - 1;
				break;
			case KEY_RIGHT:
				// x축 + 1
				_map[y][x + 1] = MAP_CHARACTOR;
				_map[y][x] = MAP_PATH;
				_posCharactor[1] = x + 1;
				break;
			case KEY_DOWN:
				// y축 + 1
				_map[y + 1][x] = MAP_CHARACTOR;
				_map[y][x] = MAP_PATH;
				_posCharactor[0] = y + 1;
				break;
			}// end of switch: 방향에 따른 캐릭터 위치 계산 ㅇㅋ
			// 키를 입력받고, 움직일 수 있을때만 맵을 그려주는게
			// 렉을 없애는데 도움이 될 것 같다.
			draw_map();
		}// end of if: 움직일 수 있을 경우
		else if (isPortal_ == true)
		{
			// 가려는 방향이 포탈이 있다면 위쪽 포탈은 보스방.
			if (y < 2)
			{
				cout << "보스방 가는 포탈" << endl;
				Sleep(1000);
			}
			// 아래쪽 포탈은 다른 마을로 간다.
			if (y > 8)
			{
				cout << "다른 마을 가는 포탈" << endl;
				Sleep(1000);
			}
		}
	} // end of if: 키 입력이 있을 경우
}

void Map::draw_map()
{
	string myChar = "";
	system("cls");
	cout << "  *** Console RPG *** " << endl;
	cout << endl;
	// 정보를 바탕으로 맵을 그린다.
	for (int i = 0; i < 12; i++)
	{
		for (int k = 0; k < 12; k++)
		{
			switch (_map[i][k])
			{
			case MAP_PATH:
				myChar = ".";
				cout << setw(2) << myChar;
				break;
			case MAP_OBJECT_WALL:
				myChar = "■";
				cout << setw(2) << myChar;
				break;
			case MAP_EDGE:
				myChar = "▣";
				cout << setw(2) << myChar;
				break;
			case MAP_EDGE_POINT:
				myChar = "□";
				cout << setw(2) << myChar;
				break;
			case MAP_DOOR:
				myChar = "▒";
				cout << setw(2) << myChar;
				break;
			case MAP_OBJECT_TREE_LEAF:
				myChar = "♧";
				cout << setw(2) << myChar;
				break;
			case MAP_OBJECT_TREE_STEM:
				myChar = "‡";
				cout << setw(2) << myChar;
				break;
			case MAP_CHARACTOR:
				myChar = "♀";
				cout << setw(2) << myChar;
				break;
			default:
				myChar = "X";
				cout << setw(2) << myChar;
				break;
			}
		}// end of for: 가로맵을 그렸을 때
		cout << endl;
	}// end of for: 맵을 전부 그렸을때
	Sleep(1000);
	//system("pause");
}

bool Map::get_isStageOver()
{
	return _isStageOver;
}

void Map::set_isStageOver(bool isStageOver)
{
	_isStageOver = isStageOver;
}

void Map::initMaptoZero()
{
	for (int i = 0; i < 12; i++)
	{
		for (int k = 0; k < 12; k++)
		{
			_mapWall[i][k] = 0;
			_map[i][k] = 0;
		}
	}
}

void Map::initWall()
{
	// 벽을 초기화 하는 함수다.
	for (int i = 0; i < 12; i++)
	{
		// 세로 방향 벽 셋팅

		if (1 <= i && i <= 4)
		{
			_mapWall[i][4] = MAP_OBJECT_WALL;
		}

		if (1 <= i && i <= 4)
		{
			_mapWall[i][5] = MAP_OBJECT_WALL;
		}

		if (6 <= i && i <= 9)
		{
			_mapWall[i][6] = MAP_OBJECT_WALL;
		}

		if (1 <= i && i <= 8)
		{
			_mapWall[i][10] = MAP_OBJECT_WALL;
			_mapWall[i][9] = MAP_OBJECT_WALL;
		}
	}// end of for: 세로방향 벽 셋팅

	for (int i = 0; i < 12; i++)
	{
		if (2 <= i && i <= 4)
		{
			_mapWall[6][i] = MAP_OBJECT_WALL;
		}
	}// end of for: 가로방향 벽 셋팅

	// 남은 벽 셋팅
	_mapWall[1][8] = MAP_OBJECT_WALL;
	_mapWall[2][8] = MAP_OBJECT_WALL;
	_mapWall[3][2] = MAP_OBJECT_WALL;
}

void Map::initEdge()
{
	for (int i = 0; i < 12; i++)
	{
		if (1 <= i && i <= 10)
		{
			// 엣지의 가로부분 셋팅
			_mapWall[0][i] = MAP_EDGE;
			_mapWall[11][i] = MAP_EDGE;

			// 엣지의 세로부분 셋팅
			_mapWall[i][0] = MAP_EDGE;
			_mapWall[i][11] = MAP_EDGE;
		}
	}// end of for: 맵의 가장자리를 셋팅

	// 맵의 꼭짓점을 셋팅
	_mapWall[0][0] = MAP_EDGE_POINT;
	_mapWall[0][11] = MAP_EDGE_POINT;
	_mapWall[11][0] = MAP_EDGE_POINT;
	_mapWall[11][11] = MAP_EDGE_POINT;
}

void Map::initDoor()
{
	// 보스방 가는 문
	_mapWall[0][6] = MAP_DOOR;
	_mapWall[0][7] = MAP_DOOR;

	// 다른 마을 가는 문
	_mapWall[9][11] = MAP_DOOR;
	_mapWall[10][11] = MAP_DOOR;
}

void Map::initTree()
{
	// 나뭇잎 셋팅
	for (int i = 1; i < 5; i++)
	{
		if (2 <= i && i <= 4)
		{
			_mapWall[8][i] = MAP_OBJECT_TREE_LEAF;
			_mapWall[9][i] = MAP_OBJECT_TREE_STEM;
		}
	}
}

void Map::initCharactor()
{
	_posCharactor[0] = 1;
	_posCharactor[1] = 1;

	_mapWall[1][1] = MAP_CHARACTOR;
}

void Map::mapping_()
{
	for (int i = 0; i < 12; i++)
	{
		for (int k = 0; k < 12; k++)
		{
			_map[i][k] = _mapWall[i][k];
		}
	}
}

bool Map::isMoveOK(int myKey)
{
	bool result = false;
	int y = _posCharactor[0];
	int x = _posCharactor[1];

	switch (myKey)
	{
	case KEY_LEFT:
		// 왼쪽이 길일 경우 캐릭터 움직일 수 있다.
		if (_map[y][x - 1] == MAP_PATH)
		{
			result = true;
		}
		break;
	case KEY_UP:
		// 위쪽이 길일 경우 캐릭터 무브
		if (_map[y-1][x] == MAP_PATH)
		{
			result = true;
		}
		break;
	case KEY_RIGHT:
		// 오른쪽이 길일 경우 캐릭터 무브
		if (_map[y][x + 1] == MAP_PATH)
		{
			result = true;
		}
		break;
	case KEY_DOWN:
		if (_map[y + 1][x] == MAP_PATH)
		{
			result = true;
		}
		break;
	}

	return result;
}

bool Map::isPortal(int myKey)
{
	bool result = false;
	int y = _posCharactor[0];
	int x = _posCharactor[1];

	switch (myKey)
	{
	case KEY_LEFT:
		// 왼쪽이 문일 경우 true
		if (_map[y][x - 1] == MAP_DOOR)
		{
			result = true;
		}
		break;
	case KEY_UP:
		// 위쪽이 문일 경우 true
		if (_map[y - 1][x] == MAP_DOOR)
		{
			result = true;
		}
		break;
	case KEY_RIGHT:
		// 오른쪽이 문일 경우 true
		if (_map[y][x + 1] == MAP_DOOR)
		{
			result = true;
		}
		break;
	case KEY_DOWN:
		// 아래쪽이 문일 경우 true
		if (_map[y + 1][x] == MAP_DOOR)
		{
			result = true;
		}
		break;
	}

	return result;
}

void Map::exit_()
{
}

Map::Map()
{
}


Map::~Map()
{
}
