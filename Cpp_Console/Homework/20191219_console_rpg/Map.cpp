#include "Map.h"


void Map::init_(int stage)
{
	_isStageOver = false;
	// �������� 1�̸� �簢�� ���� �ʱ�ȭ�Ѵ�.
	if (stage == 1)
	{
		// ���� ������ �����.
		// �� ��ü �ʱ�ȭ
		initMaptoZero();

		// ��, �����ڸ�, ���� �ʱ�ȭ�Ѵ�.
		initWall();
		initEdge();
		initDoor();
		initTree();
		initCharactor();

		// ������ �ʿ� �����Ѵ�.
		mapping_();

		draw_map();
	}
}

void Map::update_map(int myKey)
{
	// myKey�� �������� ĳ���Ͱ� �����ϼ� �ִ��� ���θ� Ȯ���Ѵ�.
	bool isMoveOK_ = false;
	bool isPortal_ = false;
	// _posCharactor[1]�� x�� ��ǥ, _posCharactor[0]�� y�� ��ǥ�� �ִ�.
	int y = _posCharactor[0];
	int x = _posCharactor[1];

	if (myKey != 0)
	{
		// myKey�� �Է��� ���� ���
		isMoveOK_ = isMoveOK(myKey);
		isPortal_ = isPortal(myKey);
		//cout << isMoveOK_ << endl;

		// ������ �� �ִٸ� myKey ���� ���� ĳ������ ��ġ�� �Űܼ� ����Ѵ�.
		if (isMoveOK_ == true)
		{
			switch (myKey)
			{
			case KEY_LEFT:
				// x�� - 1
				_map[y][x - 1] = MAP_CHARACTOR;
				_map[y][x] = MAP_PATH;
				_posCharactor[1] = x - 1;
				break;
			case KEY_UP:
				// y�� - 1
				_map[y - 1][x] = MAP_CHARACTOR;
				_map[y][x] = MAP_PATH;
				_posCharactor[0] = y - 1;
				break;
			case KEY_RIGHT:
				// x�� + 1
				_map[y][x + 1] = MAP_CHARACTOR;
				_map[y][x] = MAP_PATH;
				_posCharactor[1] = x + 1;
				break;
			case KEY_DOWN:
				// y�� + 1
				_map[y + 1][x] = MAP_CHARACTOR;
				_map[y][x] = MAP_PATH;
				_posCharactor[0] = y + 1;
				break;
			}// end of switch: ���⿡ ���� ĳ���� ��ġ ��� ����
			// Ű�� �Է¹ް�, ������ �� �������� ���� �׷��ִ°�
			// ���� ���ִµ� ������ �� �� ����.
			draw_map();
		}// end of if: ������ �� ���� ���
		else if (isPortal_ == true)
		{
			// ������ ������ ��Ż�� �ִٸ� ���� ��Ż�� ������.
			if (y < 2)
			{
				cout << "������ ���� ��Ż" << endl;
				Sleep(1000);
			}
			// �Ʒ��� ��Ż�� �ٸ� ������ ����.
			if (y > 8)
			{
				cout << "�ٸ� ���� ���� ��Ż" << endl;
				Sleep(1000);
			}
		}
	} // end of if: Ű �Է��� ���� ���
}

void Map::draw_map()
{
	string myChar = "";
	system("cls");
	cout << "  *** Console RPG *** " << endl;
	cout << endl;
	// ������ �������� ���� �׸���.
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
				myChar = "��";
				cout << setw(2) << myChar;
				break;
			case MAP_EDGE:
				myChar = "��";
				cout << setw(2) << myChar;
				break;
			case MAP_EDGE_POINT:
				myChar = "��";
				cout << setw(2) << myChar;
				break;
			case MAP_DOOR:
				myChar = "��";
				cout << setw(2) << myChar;
				break;
			case MAP_OBJECT_TREE_LEAF:
				myChar = "��";
				cout << setw(2) << myChar;
				break;
			case MAP_OBJECT_TREE_STEM:
				myChar = "��";
				cout << setw(2) << myChar;
				break;
			case MAP_CHARACTOR:
				myChar = "��";
				cout << setw(2) << myChar;
				break;
			default:
				myChar = "X";
				cout << setw(2) << myChar;
				break;
			}
		}// end of for: ���θ��� �׷��� ��
		cout << endl;
	}// end of for: ���� ���� �׷�����
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
	// ���� �ʱ�ȭ �ϴ� �Լ���.
	for (int i = 0; i < 12; i++)
	{
		// ���� ���� �� ����

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
	}// end of for: ���ι��� �� ����

	for (int i = 0; i < 12; i++)
	{
		if (2 <= i && i <= 4)
		{
			_mapWall[6][i] = MAP_OBJECT_WALL;
		}
	}// end of for: ���ι��� �� ����

	// ���� �� ����
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
			// ������ ���κκ� ����
			_mapWall[0][i] = MAP_EDGE;
			_mapWall[11][i] = MAP_EDGE;

			// ������ ���κκ� ����
			_mapWall[i][0] = MAP_EDGE;
			_mapWall[i][11] = MAP_EDGE;
		}
	}// end of for: ���� �����ڸ��� ����

	// ���� �������� ����
	_mapWall[0][0] = MAP_EDGE_POINT;
	_mapWall[0][11] = MAP_EDGE_POINT;
	_mapWall[11][0] = MAP_EDGE_POINT;
	_mapWall[11][11] = MAP_EDGE_POINT;
}

void Map::initDoor()
{
	// ������ ���� ��
	_mapWall[0][6] = MAP_DOOR;
	_mapWall[0][7] = MAP_DOOR;

	// �ٸ� ���� ���� ��
	_mapWall[9][11] = MAP_DOOR;
	_mapWall[10][11] = MAP_DOOR;
}

void Map::initTree()
{
	// ������ ����
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
		// ������ ���� ��� ĳ���� ������ �� �ִ�.
		if (_map[y][x - 1] == MAP_PATH)
		{
			result = true;
		}
		break;
	case KEY_UP:
		// ������ ���� ��� ĳ���� ����
		if (_map[y-1][x] == MAP_PATH)
		{
			result = true;
		}
		break;
	case KEY_RIGHT:
		// �������� ���� ��� ĳ���� ����
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
		// ������ ���� ��� true
		if (_map[y][x - 1] == MAP_DOOR)
		{
			result = true;
		}
		break;
	case KEY_UP:
		// ������ ���� ��� true
		if (_map[y - 1][x] == MAP_DOOR)
		{
			result = true;
		}
		break;
	case KEY_RIGHT:
		// �������� ���� ��� true
		if (_map[y][x + 1] == MAP_DOOR)
		{
			result = true;
		}
		break;
	case KEY_DOWN:
		// �Ʒ����� ���� ��� true
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
