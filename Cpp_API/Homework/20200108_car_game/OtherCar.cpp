#include "stdafx.h"
#include "OtherCar.h"

#define CAR_W	16 * 2
#define CAR_H	22 * 2

#define LOAD_X	20
#define LOAD_Y	0
#define LOAD_W	180
#define LOAD_H	600

// 자동차의 좌, 우 마젠타 영역 보정을 위한 값이다.
#define MAGENTA_BAND	CAR_W * 0.2

void OtherCar::reinit_posCar()
{
	int coriterion = 300;
	int window_top = 0;
	int window_bottom = WINSIZEY;

	if (_posCar.y < window_top - coriterion)
	{
		init_posCar();
	}//end of if: 윈도우의 top을 기준만큼 벗어나면
	else if (_posCar.y > window_bottom + coriterion)
	{
		init_posCar();
	}//end of if: 윈도우의 bottom을 기준만큼 벗어나면
}
void OtherCar::reinit_posCar(int index)
{
	int coriterion = 300;
	int window_top = 0;
	int window_bottom = WINSIZEY;

	if (_enemy[index].posCar.y < window_top - coriterion)
	{
		_test1 = 100;
		init_posCar(index);
	}//end of if: 윈도우의 top을 기준만큼 벗어나면
	else if (_enemy[index].posCar.y > window_bottom + coriterion)
	{
		_test1 = 100;
		init_posCar(index);
	}//end of if: 윈도우의 bottom을 기준만큼 벗어나면
}

void OtherCar::update_posCar(int speed_player, int maxSpeed)
{
	int speedForCompare = static_cast<int> (maxSpeed * 0.3);
	int speedForSlow[3];
	speedForSlow[0] = static_cast<int> (speedForCompare * 0.3);
	speedForSlow[1] = static_cast<int> (speedForSlow[0] * 0.3);
	speedForSlow[2] = static_cast<int> (speedForSlow[1] * 0.3);

	if (speed_player > speedForCompare)
	{
		// 플레이어의 속도가 maxSpeed * 0.3 보다 빠르다면 다른 차는 뒤로 밀린다.
		_posCar.y++;
	}//end of if: 플레이어가 기준속도보다 빠르다면
	else if (speed_player == speedForCompare)
	{
		// 플레이어의 속도가 maxSpeed * 0.3 과 같다면 
		// 차는 제자리에 있는 것처럼 보인다.
	}//end of if: 플레이어가 기준속도 정도로 달리고 있다면
	else
	{
		// 플레이어의 속도가 maxSpeed * 0.3 보다 느리다면 다른 차는 앞으로 간다.
		// 여기서 3단계 슬로우를 준다.
		if (speedForSlow[0] <= speed_player &&
			speed_player < speedForCompare)
		{
			_posCar.y--;
		}// 1단 슬로우
		else if (speedForSlow[1] <= speed_player &&
			speed_player < speedForSlow[0])
		{
			_posCar.y -= 3;
		}// 2단 슬로우
		else
		{
			_posCar.y -= 5;
		}// 3단 슬로우
	}//end of else: 플레이어가 기준속도보다 느리다면

	// 여기서 윈도우를 기준 거리만큼 벗어나면 위치를 다시 할당
	reinit_posCar();
}
void OtherCar::update_posCar(int speed_player, int maxSpeed, int index)
{
	int speedForCompare = static_cast<int> (maxSpeed * 0.3);
	int speedForSlow[3];
	speedForSlow[0] = static_cast<int> (speedForCompare * 0.3);
	speedForSlow[1] = static_cast<int> (speedForSlow[0] * 0.3);
	speedForSlow[2] = static_cast<int> (speedForSlow[1] * 0.3);

	if (speed_player > speedForCompare)
	{
		// 플레이어의 속도가 maxSpeed * 0.3 보다 빠르다면 다른 차는 뒤로 밀린다.
		_enemy[index].posCar.y++;
	}//end of if: 플레이어가 기준속도보다 빠르다면
	else if (speed_player == speedForCompare)
	{
		// 플레이어의 속도가 maxSpeed * 0.3 과 같다면 
		// 차는 제자리에 있는 것처럼 보인다.
	}//end of if: 플레이어가 기준속도 정도로 달리고 있다면
	else
	{
		// 플레이어의 속도가 maxSpeed * 0.3 보다 느리다면 다른 차는 앞으로 간다.
		// 여기서 3단계 슬로우를 준다.
		if (speedForSlow[0] <= speed_player &&
			speed_player < speedForCompare)
		{
			_enemy[index].posCar.y--;
		}// 1단 슬로우
		else if (speedForSlow[1] <= speed_player &&
			speed_player < speedForSlow[0])
		{
			_enemy[index].posCar.y -= 3;
		}// 2단 슬로우
		else
		{
			_enemy[index].posCar.y -= 5;
		}// 3단 슬로우
	}//end of else: 플레이어가 기준속도보다 느리다면

	// 여기서 윈도우를 기준 거리만큼 벗어나면 위치를 다시 할당
	reinit_posCar(index);

	if (_test1 == 100)
	{
		_test1 = 0;
	}
}
void OtherCar::update_posCarAll(int speed_player, int maxSpeed, int count)
{
	for (int i = 0; i < count; i++)
	{
		update_posCar(speed_player, maxSpeed, i);
	}

	/*if (_test1 == 100)
	{
		_test1 = 0;
	}*/
}

POINT OtherCar::get_posCar()
{
	return _posCar;
}

void OtherCar::init_posCar()
{
	randomFunction rd;

	// _posCar.x는 leftRoad + MAGENTA_BAND 보다 크고,
	// rightRoad - MAGENTA_BAND 보다 작다.
	LONG leftRoad = LOAD_X + MAGENTA_BAND;
	LONG rightRoad = LOAD_X + LOAD_W - (MAGENTA_BAND * 2);

	_posCar.x = rd.getFromIntTo(leftRoad, rightRoad);
	_posCar.y = LOAD_Y;
	//_posCar.y = 300;	// for test
}
void OtherCar::init_posCar(int index)
{
	randomFunction rd;

	// _posCar.x는 leftRoad + MAGENTA_BAND 보다 크고,
	// rightRoad - MAGENTA_BAND 보다 작다.
	LONG leftRoad = LOAD_X + MAGENTA_BAND;
	LONG rightRoad = LOAD_X + LOAD_W - (MAGENTA_BAND * 2);

	_enemy[index].posCar.x =
		rd.getFromIntTo(leftRoad, rightRoad);
	//_enemy[index].posCar.y = LOAD_Y;
	_enemy[index].posCar.y = 500;	// for test
}
void OtherCar::init_posCarAll(int count)
{
	randomFunction rd;

	for (int i = 0; i < count; i++)
	{
		// _posCar.x는 leftRoad + MAGENTA_BAND 보다 크고,
		// rightRoad - MAGENTA_BAND 보다 작다.
		LONG leftRoad = LOAD_X + MAGENTA_BAND;
		LONG rightRoad = LOAD_X + LOAD_W - MAGENTA_BAND;

		_enemy[i].posCar.x = rd.getFromIntTo(leftRoad, rightRoad);
		_enemy[i].posCar.y = LOAD_Y;
	}
	//_posCar.y = 300;	// for test
}

void OtherCar::init_carImage(int index)
{
	int kind = 0;

	kind = randomFunction().getInt(2);
	_enemy[index].carImage = _carImage[kind];
}
void OtherCar::init_carImageAll(int count)
{
	for (int i = 0; i < count; i++)
	{
		init_carImage(i);
	}
}

void OtherCar::release_enemyAll(int count)
{
	for (int i = 0; i < count; i++)
	{
		SAFE_DELETE(_enemy[i].carImage);
	}
}

OtherCar::OtherCar()
{
}
OtherCar::~OtherCar()
{
}

HRESULT OtherCar::init()
{
	// 여기서 차 이미지를 2개 메모리에 올린다.
	_carImage[0] = new image;
	_carImage[0]->init("images/노란자동차X2.bmp", CAR_W, CAR_H, true, RGB(255, 0, 255));
	_carImage[1] = new image;
	_carImage[1]->init("images/파란자동차X2.bmp", CAR_W, CAR_H, true, RGB(255, 0, 255));

	// 여기서 어떤 차를 렌더할지 이미지를 정한다.
	init_carImageAll(_enemyCnt);
	_kind = randomFunction().getInt(2);

	// 차의 초기 위치를 정한다.
	init_posCarAll(_enemyCnt);

	return S_OK;
}

void OtherCar::update(int speed_player, int maxSpeed)
{
	update_posCar(speed_player, maxSpeed);
	update_posCarAll(speed_player, maxSpeed, _enemyCnt);

	/*if (_test1 == 100)
	{
		_test1 = 0;
	}*/
}

void OtherCar::render(HDC hdc)
{
	_carImage[_kind]->render(hdc, _posCar.x, _posCar.y);

	renderAll(hdc, _enemyCnt);
	renderTest(hdc);
}
void OtherCar::renderAll(HDC hdc, int enemy_count)
{
	for (int i = 0; i < enemy_count; i++)
	{
		_enemy[i].carImage->render(hdc,
			_enemy[i].posCar.x, _enemy[i].posCar.y);
	}

	/*if (_test1 == 100)
	{
		_test1 = 0;
	}*/
}

void OtherCar::release()
{
	// 메모리에 올린 차의 이미지를 해제한다.
	SAFE_DELETE(_carImage[0]);
	SAFE_DELETE(_carImage[1]);

	// 다른 자동차를 해제한다.
	release_enemyAll(_enemyCnt);
}

void OtherCar::renderTest(HDC hdc)
{
	char strTest[128];

	/*if (_test1 == 100)
	{
		_test1 = 0;
	}*/

	wsprintf(strTest, "다른 차 1 x, y: %d, %d",
		_enemy[0].posCar.x, _enemy[0].posCar.y);
	TextOut(hdc, 20, 20, strTest, strlen(strTest));
	wsprintf(strTest, "다른 차 2 x, y: %d, %d",
		_enemy[1].posCar.x, _enemy[1].posCar.y);
	TextOut(hdc, 20, 40, strTest, strlen(strTest));
	wsprintf(strTest, "다른 차 3 x, y: %d, %d",
		_enemy[2].posCar.x, _enemy[2].posCar.y);
	TextOut(hdc, 20, 60, strTest, strlen(strTest));
}
