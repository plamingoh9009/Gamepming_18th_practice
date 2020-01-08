#include "stdafx.h"
#include "OtherCar.h"

#define CAR_W	16 * 2
#define CAR_H	22 * 2

#define LOAD_X	20
#define LOAD_Y	0
#define LOAD_W	180
#define LOAD_H	600

// �ڵ����� ��, �� ����Ÿ ���� ������ ���� ���̴�.
#define MAGENTA_BAND	CAR_W * 0.2

POINT OtherCar::get_posCar()
{
	return _posCar;
}

void OtherCar::init_posCar()
{
	// _posCar.x�� leftRoad + MAGENTA_BAND ���� ũ��,
	// rightRoad - MAGENTA_BAND ���� �۴�.
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
	// ���⼭ �� �̹����� 2�� �޸𸮿� �ø���.
	_carImage[0] = new image;
	_carImage[0]->init("images/����ڵ���X2.bmp", CAR_W, CAR_H, true, RGB(255, 0, 255));
	_carImage[1] = new image;
	_carImage[1]->init("images/�Ķ��ڵ���X2.bmp", CAR_W, CAR_H, true, RGB(255, 0, 255));

	// ���⼭ � ���� �������� ���Ѵ�.
	_kind = randomFunction().getInt(2);

	// ���� �ʱ� ��ġ�� ���Ѵ�.
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
		// �÷��̾��� �ӵ��� maxSpeed * 0.3 ���� �����ٸ� �ٸ� ���� �ڷ� �и���.
		_posCar.y++;
	}//end of if: �÷��̾ ���ؼӵ����� �����ٸ�
	else if (speed_player == speedForCompare)
	{
		// �÷��̾��� �ӵ��� maxSpeed * 0.3 �� ���ٸ� 
		// ���� ���ڸ��� �ִ� ��ó�� ���δ�.
	}//end of if: �÷��̾ ���ؼӵ� ������ �޸��� �ִٸ�
	else
	{
		// �÷��̾��� �ӵ��� maxSpeed * 0.3 ���� �����ٸ� �ٸ� ���� ������ ����.
		// ���⼭ 3�ܰ� ���ο츦 �ش�.
		if (speedForSlow[0] <= speed_player && 
			speed_player < speedForCompare)
		{
			_posCar.y--;
		}// 1�� ���ο�
		else if (speedForSlow[1] <= speed_player &&
			speed_player < speedForSlow[0])
		{
			_posCar.y -= 3;
		}// 2�� ���ο�
		else
		{
			_posCar.y -= 5;
		}// 3�� ���ο�
	}//end of else: �÷��̾ ���ؼӵ����� �����ٸ�


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

	wsprintf(strTest, "�÷��̾� ���ǵ�: %d, ���ؼӵ�: %d", _test1, _test2);
	TextOut(hdc, 20, 20, strTest, strlen(strTest));
}
