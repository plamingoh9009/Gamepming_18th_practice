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

void OtherCar::reinit_posCar()
{
	int coriterion = 300;
	int window_top = 0;
	int window_bottom = WINSIZEY;

	if (_posCar.y < window_top - coriterion)
	{
		init_posCar();
	}//end of if: �������� top�� ���ظ�ŭ �����
	else if (_posCar.y > window_bottom + coriterion)
	{
		init_posCar();
	}//end of if: �������� bottom�� ���ظ�ŭ �����
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
	}//end of if: �������� top�� ���ظ�ŭ �����
	else if (_enemy[index].posCar.y > window_bottom + coriterion)
	{
		_test1 = 100;
		init_posCar(index);
	}//end of if: �������� bottom�� ���ظ�ŭ �����
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

	// ���⼭ �����츦 ���� �Ÿ���ŭ ����� ��ġ�� �ٽ� �Ҵ�
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
		// �÷��̾��� �ӵ��� maxSpeed * 0.3 ���� �����ٸ� �ٸ� ���� �ڷ� �и���.
		_enemy[index].posCar.y++;
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
			_enemy[index].posCar.y--;
		}// 1�� ���ο�
		else if (speedForSlow[1] <= speed_player &&
			speed_player < speedForSlow[0])
		{
			_enemy[index].posCar.y -= 3;
		}// 2�� ���ο�
		else
		{
			_enemy[index].posCar.y -= 5;
		}// 3�� ���ο�
	}//end of else: �÷��̾ ���ؼӵ����� �����ٸ�

	// ���⼭ �����츦 ���� �Ÿ���ŭ ����� ��ġ�� �ٽ� �Ҵ�
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

	// _posCar.x�� leftRoad + MAGENTA_BAND ���� ũ��,
	// rightRoad - MAGENTA_BAND ���� �۴�.
	LONG leftRoad = LOAD_X + MAGENTA_BAND;
	LONG rightRoad = LOAD_X + LOAD_W - (MAGENTA_BAND * 2);

	_posCar.x = rd.getFromIntTo(leftRoad, rightRoad);
	_posCar.y = LOAD_Y;
	//_posCar.y = 300;	// for test
}
void OtherCar::init_posCar(int index)
{
	randomFunction rd;

	// _posCar.x�� leftRoad + MAGENTA_BAND ���� ũ��,
	// rightRoad - MAGENTA_BAND ���� �۴�.
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
		// _posCar.x�� leftRoad + MAGENTA_BAND ���� ũ��,
		// rightRoad - MAGENTA_BAND ���� �۴�.
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
	// ���⼭ �� �̹����� 2�� �޸𸮿� �ø���.
	_carImage[0] = new image;
	_carImage[0]->init("images/����ڵ���X2.bmp", CAR_W, CAR_H, true, RGB(255, 0, 255));
	_carImage[1] = new image;
	_carImage[1]->init("images/�Ķ��ڵ���X2.bmp", CAR_W, CAR_H, true, RGB(255, 0, 255));

	// ���⼭ � ���� �������� �̹����� ���Ѵ�.
	init_carImageAll(_enemyCnt);
	_kind = randomFunction().getInt(2);

	// ���� �ʱ� ��ġ�� ���Ѵ�.
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
	// �޸𸮿� �ø� ���� �̹����� �����Ѵ�.
	SAFE_DELETE(_carImage[0]);
	SAFE_DELETE(_carImage[1]);

	// �ٸ� �ڵ����� �����Ѵ�.
	release_enemyAll(_enemyCnt);
}

void OtherCar::renderTest(HDC hdc)
{
	char strTest[128];

	/*if (_test1 == 100)
	{
		_test1 = 0;
	}*/

	wsprintf(strTest, "�ٸ� �� 1 x, y: %d, %d",
		_enemy[0].posCar.x, _enemy[0].posCar.y);
	TextOut(hdc, 20, 20, strTest, strlen(strTest));
	wsprintf(strTest, "�ٸ� �� 2 x, y: %d, %d",
		_enemy[1].posCar.x, _enemy[1].posCar.y);
	TextOut(hdc, 20, 40, strTest, strlen(strTest));
	wsprintf(strTest, "�ٸ� �� 3 x, y: %d, %d",
		_enemy[2].posCar.x, _enemy[2].posCar.y);
	TextOut(hdc, 20, 60, strTest, strlen(strTest));
}
