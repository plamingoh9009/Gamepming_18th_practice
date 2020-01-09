#pragma once
#include "gameNode.h"

// 자동차 구조체를 만든다.
struct enemy
{
	image * carImage;
	POINT posCar;
};

class OtherCar : public gameNode
{
private:
	image *	_carImage[2];
	POINT	_posCar;
	int		_kind;

	enemy _enemy[3];
	int _enemyCnt = 3;

	int _test1;
	int _test2;
public:
	void update_posCar(int, int);
	void update_posCar(int, int, int);
	void update_posCarAll(int, int, int);

	POINT get_posCar();
	void reinit_posCar();
	void reinit_posCar(int);

	void init_posCar();
	void init_posCar(int);
	void init_posCarAll(int);

	void init_carImage(int);
	void init_carImageAll(int);

	void release_enemyAll(int);
public:
	OtherCar();
	~OtherCar();

	HRESULT init();
	void update(int maxSpeed, int speed_player);

	void render(HDC hdc);
	void renderAll(HDC hdc, int enemy_count);
	void release();

	void renderTest(HDC);
};

