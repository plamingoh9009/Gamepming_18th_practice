#include "stdafx.h"
#include "Car.h"

#define LOAD_X	20
#define LOAD_Y	0
#define LOAD_W	180
#define LOAD_H	600

// �ڵ����� ��, ��� �����̴� �Ÿ���.
#define DISTANCE_MOVE	3

HRESULT Car::init()
{
	// ���⼭ ���� �޸𸮿� �ε��Ѵ�.
	_player = new image;
	_player->init("images/������_X2.bmp", _CAR_W, _CAR_H, true, RGB(255, 0, 255));

	// �÷��̾� ���� ��ġ�� �����Ѵ�.
	_posPlayer.x = WINSIZEX / 2 - 60;
	_posPlayer.y = WINSIZEY - _CAR_H;
	_backInRoad = KEY_EMPTY;

	// �÷��̾� ���� �ӵ��� �����Ѵ�.
	_speed = 0;
	_b_speed_up = false;

	return S_OK;
}

void Car::update()
{
	// ����, ������ Ű�� ������ ���� �̵��Ѵ�.
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && isMoveOK())
	{
		_posPlayer.x -= DISTANCE_MOVE;
	}//end of if: ����Ű�� ������ ��
	else if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && isMoveOK())
	{
		_posPlayer.x += DISTANCE_MOVE;
	}//end of if: ������Ű�� ������ ��

	// ���⼭ ���� ����� �ǵ�����.
	if (isMoveOK() == false)
	{
		moveBackInRoad(_backInRoad);
	}

	// ���⼭ ���� �ӵ��� ���Ѵ�.
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		upSpeed();
	}//end of if: ���� Ű�� ������
	else if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		downSpeed(2);
	}
	else
	{
		// ���⼭ ���� �ӵ��� �׻� ��������.
		downSpeed();
	}
}

void Car::render(HDC hdc)
{
	_player->render(hdc, _posPlayer.x, _posPlayer.y);

	// ���� �׽�Ʈ -> ���⼭ ���� ���� ���� Ȯ���Ѵ�.
	//renderTest(hdc);
}

void Car::release()
{
	SAFE_DELETE(_player);
}

const int Car::get_MAGENTA_BAND()
{
	return _MAGENTA_BAND;
}

const int Car::get_CAR_H()
{
	return _CAR_H;
}
const int Car::get_CAR_W()
{
	return _CAR_W;
}
POINT Car::get_posPlayer()
{
	return _posPlayer;
}
int Car::get_speed()
{
	return _speed;
}
const int Car::get_SPEED_FOR_CALC()
{
	return _SPEED_FOR_CALC;
}
const int Car::get_MAX_SPEED()
{
	return _MAX_SPEED;
}

void Car::upSpeed()
{
	int max = _MAX_SPEED * _SPEED_FOR_CALC;

	if (_speed < max)
	{
		if (_speed < static_cast<int>(max * 0.3))
		{
			// �ʹ��� ������� ����� ���� �ν���
			_speed += 3;
		}//end of if: �ӵ��� max�� 1/3 ���� �������� ���ߴٸ�
		else
		{
			_speed++;
		}
	}//end of if: �ӵ��� �ְ� �ӵ��� �������� ���ߴٸ�
}
void Car::downSpeed()
{
	if (_speed > 0)
	{
		_speed -= 1;
	}
}
void Car::downSpeed(int speed)
{
	if (_speed > 0)
	{
		_speed -= speed;
	}
}
void Car::moveBackInRoad(POSITION pos)
{
	switch (pos)
	{
	case KEY_LEFT:
		_posPlayer.x += DISTANCE_MOVE;
		break;
	case KEY_RIGHT:
		_posPlayer.x -= DISTANCE_MOVE;
		break;
	}
}
bool Car::isMoveOK()
{
	LONG leftCar = _posPlayer.x + _MAGENTA_BAND;
	LONG rightCar = _posPlayer.x + _CAR_W - _MAGENTA_BAND;
	LONG leftRoad = LOAD_X;
	LONG rightRoad = LOAD_X + LOAD_W;
	bool result;

	_backInRoad = KEY_EMPTY;

	if (leftRoad >= leftCar)
	{
		result = false;
		_backInRoad = KEY_LEFT;
	}//end of if: �� ���� ������ ���� ���� ���� ��
	else if (rightCar >= rightRoad)
	{
		result = false;
		_backInRoad = KEY_RIGHT;
	}// end of if: �� ���� �������� ���� ���� ���� ��
	else
	{
		result = true;
	}
	return result;
}

void Car::renderTest(HDC hdc)
{
	char strTest[128];

	wsprintf(strTest, "�ӵ�: %d", _speed);
	TextOut(hdc, 20, 20, strTest, strlen(strTest));
}

Car::Car()
{
}
Car::~Car()
{
}
