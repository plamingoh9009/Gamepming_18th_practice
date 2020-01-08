#include "stdafx.h"
#include "Car.h"

#define LOAD_X	20
#define LOAD_Y	0
#define LOAD_W	180
#define LOAD_H	600

// 자동차가 좌, 우로 움직이는 거리다.
#define DISTANCE_MOVE	3

HRESULT Car::init()
{
	// 여기서 차를 메모리에 로드한다.
	_player = new image;
	_player->init("images/빨간차_X2.bmp", _CAR_W, _CAR_H, true, RGB(255, 0, 255));

	// 플레이어 시작 위치를 정의한다.
	_posPlayer.x = WINSIZEX / 2 - 60;
	_posPlayer.y = WINSIZEY - _CAR_H;
	_backInRoad = KEY_EMPTY;

	// 플레이어 차의 속도를 정의한다.
	_speed = 0;
	_b_speed_up = false;

	return S_OK;
}

void Car::update()
{
	// 왼쪽, 오른쪽 키를 누르면 차가 이동한다.
	if (KEYMANAGER->isStayKeyDown(VK_LEFT) && isMoveOK())
	{
		_posPlayer.x -= DISTANCE_MOVE;
	}//end of if: 왼쪽키를 눌렀을 때
	else if (KEYMANAGER->isStayKeyDown(VK_RIGHT) && isMoveOK())
	{
		_posPlayer.x += DISTANCE_MOVE;
	}//end of if: 오른쪽키를 눌렀을 때

	// 여기서 차가 벗어나면 되돌린다.
	if (isMoveOK() == false)
	{
		moveBackInRoad(_backInRoad);
	}

	// 여기서 차의 속도가 변한다.
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		upSpeed();
	}//end of if: 위쪽 키를 누르면
	else if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		downSpeed(2);
	}
	else
	{
		// 여기서 차의 속도는 항상 떨어진다.
		downSpeed();
	}
}

void Car::render(HDC hdc)
{
	_player->render(hdc, _posPlayer.x, _posPlayer.y);

	// 렌더 테스트 -> 여기서 각종 값을 직접 확인한다.
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
			// 초반의 답답함을 지우기 위한 부스팅
			_speed += 3;
		}//end of if: 속도가 max의 1/3 조차 도달하지 못했다면
		else
		{
			_speed++;
		}
	}//end of if: 속도가 최고 속도에 도달하지 못했다면
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
	}//end of if: 내 차의 왼쪽이 길의 끝에 닿을 때
	else if (rightCar >= rightRoad)
	{
		result = false;
		_backInRoad = KEY_RIGHT;
	}// end of if: 내 차의 오른쪽이 길의 끝에 닿을 때
	else
	{
		result = true;
	}
	return result;
}

void Car::renderTest(HDC hdc)
{
	char strTest[128];

	wsprintf(strTest, "속도: %d", _speed);
	TextOut(hdc, 20, 20, strTest, strlen(strTest));
}

Car::Car()
{
}
Car::~Car()
{
}
