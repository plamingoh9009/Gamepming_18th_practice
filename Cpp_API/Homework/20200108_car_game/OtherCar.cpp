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

POINT OtherCar::get_posCar()
{
	return _posCar;
}

void OtherCar::init_posCar()
{
	// _posCar.x는 leftRoad + MAGENTA_BAND 보다 크고,
	// rightRoad - MAGENTA_BAND 보다 작다.
	LONG leftRoad = LOAD_X;
	LONG rightRoad = LOAD_X + LOAD_W;

	_posCar.x = randomFunction().getInt(LOAD_W - MAGENTA_BAND - LOAD_X);
	_posCar.x += LOAD_X;
	//_posCar.y = LOAD_Y;
	_posCar.y = 300;	// for test
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

	// 여기서 어떤 차를 렌더할지 정한다.
	_kind = randomFunction().getInt(2);

	// 차의 초기 위치를 정한다.
	init_posCar();

	return S_OK;
}

void OtherCar::update(int speed_player, int maxSpeed)
{
	int speedForCompare = static_cast<int> (maxSpeed * 0.3);
	int speedForSlow[3];
	speedForSlow[0] = static_cast<int> (speedForCompare * 0.3);
	speedForSlow[1] = static_cast<int> (speedForSlow[0] * 0.3);
	speedForSlow[2] = static_cast<int> (speedForSlow[1] * 0.3);

	_test1 = speed_player;
	_test2 = speedForCompare;

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


}

void OtherCar::render(HDC hdc)
{
	_carImage[_kind]->render(hdc, _posCar.x, _posCar.y);

	//renderTest(hdc);
}

void OtherCar::release()
{
	SAFE_DELETE(_carImage[0]);
	SAFE_DELETE(_carImage[1]);
}

void OtherCar::renderTest(HDC hdc)
{
	char strTest[128];

	wsprintf(strTest, "플레이어 스피드: %d, 기준속도: %d", _test1, _test2);
	TextOut(hdc, 20, 20, strTest, strlen(strTest));
}
